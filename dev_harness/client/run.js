#!/usr/bin/env node
// Runs SQF in a real, windowed Arma 3 client (no server, no BattlEye) and collects its log lines and
// screenshots. Use it for anything visual: models, textures, UI, cameras, particles, lights.
//
//   node run.js <test.sqf> [--mods <file|preset>] [--world VR] [--timeout 240] [--out <dir>] [--sheet] [--keep]
//
// The test SQF runs scheduled in a generated mission, after the player and camera exist. It uses the
// helpers in mission/init.sqf (vc_fnc_log, vc_fnc_shot, vc_fnc_cam, vc_fnc_done) and must end with
// `call vc_fnc_done`. The mission is packed into a PBO in a temporary mod, so nothing is written to
// the Arma folder. Screenshots land in the dedicated profile "uksfdevclient" and are moved to --out.
const fs = require('fs'), path = require('path'), os = require('os'), crypto = require('crypto');
const { execFileSync, spawn } = require('child_process');

const ARMA = process.env.ARMA || 'B:/Steam/steamapps/common/Arma 3';
// VC_PROFILE lets parallel clients run: two clients cannot share one profile.
const PROFILE = process.env.VC_PROFILE || 'uksfdevclient';
const PREFIX = 'uksf_vclient';
const SHOTS = path.join(os.homedir(), 'Documents', 'Arma 3 - Other Profiles', PROFILE, 'Screenshots');
const RPTS = path.join(process.env.LOCALAPPDATA, 'Arma 3');

const args = process.argv.slice(2);
const opt = (k, d) => { const i = args.indexOf(k); return i >= 0 ? args[i + 1] : d; };
const test = args[0];
if (!test || test.startsWith('--')) { console.error('usage: run.js <test.sqf> [--mods <file|preset>] [--world VR] [--timeout 240] [--out <dir>] [--sheet] [--keep]'); process.exit(2); }
const world = opt('--world', 'VR');
const timeout = +opt('--timeout', 240) * 1000;
const out = path.resolve(opt('--out', path.join(path.dirname(path.resolve(test)), 'shots')));
const mods = loadMods(opt('--mods', 'vanilla'));
const runId = 'vc' + crypto.randomBytes(4).toString('hex');

function loadMods(m) {
  if (m === 'vanilla') return [];
  const file = fs.existsSync(m) ? m : path.join(__dirname, 'mods', m + '.txt');
  return fs.readFileSync(file, 'utf8').split(/\r?\n/).map(s => s.trim()).filter(s => s && !s.startsWith('#'));
}

// Minimal PBO writer: uncompressed entries, prefix header, SHA1 trailer.
function packPbo(files, prefix) {
  const z = s => Buffer.from(s + '\0', 'latin1');
  const u32 = (...v) => { const x = Buffer.alloc(4 * v.length); v.forEach((n, i) => x.writeUInt32LE(n >>> 0, i * 4)); return x; };
  const head = [z(''), u32(0x56657273, 0, 0, 0, 0), z('prefix'), z(prefix), z('')];
  const now = Math.floor(Date.now() / 1000);
  for (const [name, data] of files) head.push(z(name), u32(0, data.length, 0, now, data.length));
  head.push(z(''), u32(0, 0, 0, 0, 0));
  const body = Buffer.concat([...head, ...files.map(f => f[1])]);
  return Buffer.concat([body, Buffer.from([0]), crypto.createHash('sha1').update(body).digest()]);
}

// Only this run's process is touched: other sessions (or Tim) may have their own Arma open.
let pid = 0;
const isRunning = () => { try { return execFileSync('tasklist', ['/FI', `PID eq ${pid}`, '/NH'], { encoding: 'utf8' }).includes(String(pid)); } catch { return false; } };
const kill = () => { try { execFileSync('taskkill', ['/F', '/PID', String(pid)], { stdio: 'ignore' }); } catch {} };
// Windows marks a window "Not Responding" when its message loop stalls (a freeze, or an engine hang).
const responding = () => { try { return !/Not Responding/i.test(execFileSync('tasklist', ['/V', '/FI', `PID eq ${pid}`, '/FO', 'CSV', '/NH'], { encoding: 'utf8' })); } catch { return true; } };
const sleep = ms => new Promise(r => setTimeout(r, ms));
const { LOCK } = require('./gpulock');
// Arma is detached, so an aborted run would leave it on the GPU after the lock is released.
process.on('exit', () => { if (pid && isRunning()) kill(); });
for (const s of ['SIGINT', 'SIGTERM', 'SIGHUP']) process.on(s, () => process.exit(130));
// This run's RPT: written after the launch, and its command line names our profile.
// This run's RPT: written after the launch, and its command line names this run's temporary mod.
const findRpt = (since, tag) => fs.readdirSync(RPTS).filter(f => /^arma3_x64_.*\.rpt$/i.test(f)).map(f => path.join(RPTS, f))
  .filter(f => fs.statSync(f).mtimeMs >= since - 2000)
  .find(f => fs.readFileSync(f, 'latin1').slice(0, 8000).includes(tag));

(async () => {
  await require('./gpulock').acquire(process.env.VC_LOCK_OWNER || `dev_harness ${PROFILE}`);
  const mission = `vclient.${world}`;
  const dir = path.join(__dirname, 'mission');
  const sqm = fs.readFileSync(path.join(dir, 'mission.sqm'), 'utf8');
  const files = [
    [`${mission}\\mission.sqm`, Buffer.from(sqm)],
    [`${mission}\\description.ext`, fs.readFileSync(path.join(dir, 'description.ext'))],
    [`${mission}\\init.sqf`, Buffer.concat([Buffer.from(`vc_runId = "${runId}";\r\n`), fs.readFileSync(path.join(dir, 'init.sqf'))])],
    [`${mission}\\test.sqf`, fs.readFileSync(test)],
  ];
  const tmp = fs.mkdtempSync(path.join(os.tmpdir(), `vclient-${runId}-`));
  const mod = path.join(tmp, '@' + PREFIX);
  fs.mkdirSync(path.join(mod, 'addons'), { recursive: true });
  fs.writeFileSync(path.join(mod, 'addons', PREFIX + '.pbo'), packPbo(files, PREFIX));

  // Several runs (other sessions) share the profile: every file carries its run id, and only this
  // run's files are touched. Leftovers of crashed runs are removed after a day.
  fs.mkdirSync(SHOTS, { recursive: true });
  // Arma refuses screenshots once the folder holds 250 MB (about 16 full-size PNGs); raise the cap.
  const prof = path.join(path.dirname(SHOTS), `${PROFILE}.Arma3Profile`);
  // The profile is shared with parallel runs, which lock it: write only when the cap is missing.
  try {
    const ptxt = fs.existsSync(prof) ? fs.readFileSync(prof, 'latin1') : '';
    if (!/maxScreenShotFolderSizeMB\s*=\s*4000;/.test(ptxt))
      fs.writeFileSync(prof, `maxScreenShotFolderSizeMB=4000;\r\n` + ptxt.replace(/maxScreenShotFolderSizeMB\s*=\s*\d+;\r?\n?/, ''), 'latin1');
  } catch (e) { console.error(`run.js: could not set the screenshot cap (${e.code}); a parallel run may hold the profile`); }
  for (const f of fs.readdirSync(SHOTS)) {
    const p = path.join(SHOTS, f);
    try { if (/^vc[0-9a-f]{8}_/.test(f) && Date.now() - fs.statSync(p).mtimeMs > 864e5) fs.rmSync(p); } catch {}
  }
  const modArg = [...mods, mod].map(p => path.resolve(p)).join(';');
  const argv = ['-window', '-noPause', '-noSound', '-noSplash', '-skipIntro', '-world=empty', `-name=${PROFILE}`,
    `-mod=${modArg}`, `-init=playMission['','\\${PREFIX}\\${mission}']`];
  const t0 = Date.now();
  const child = spawn(path.join(ARMA, 'arma3_x64.exe'), argv, { cwd: ARMA, detached: true, stdio: 'ignore' });
  pid = child.pid; child.unref();
  // A hard-killed run.js runs no exit handler; a watchdog ends Arma once run.js is gone. Node kills its own
  // children with it (job object) and a detached PowerShell has no console, so the attached PowerShell starts
  // the watchdog as its own child, which leaves the job.
  const watch = `Wait-Process -Id ${process.pid} -ErrorAction SilentlyContinue; ` +
    `Get-Process -Id ${pid} -ErrorAction SilentlyContinue | Where-Object ProcessName -eq 'arma3_x64' | Stop-Process -Force; ` +
    `$l = '${LOCK}'; if ((Test-Path $l) -and ((Get-Content $l -Raw) -match ' pid ${process.pid} ')) { Remove-Item $l }`;
  spawn('powershell', ['-NoProfile', '-Command',
    `Start-Process powershell -WindowStyle Hidden -ArgumentList '-NoProfile','-Command','${watch.replace(/'/g, "''")}'`],
    { stdio: 'ignore', windowsHide: true }).unref();

  let rpt;
  while (Date.now() - t0 < 60000 && !(rpt = findRpt(t0, path.basename(tmp)))) await sleep(1000);
  if (!rpt) { kill(); console.error('run.js: no RPT for this run; Arma did not start'); process.exit(3); }
  const read = () => fs.readFileSync(rpt, 'latin1');
  fs.mkdirSync(out, { recursive: true });
  const shots = [], seen = {};
  // Moves this run's finished screenshots (size unchanged since the last poll) to --out.
  const collect = (all) => {
    for (const f of fs.readdirSync(SHOTS).filter(f => f.startsWith(runId + '_'))) {
      const p = path.join(SHOTS, f), size = fs.statSync(p).size;
      if (!all && seen[f] !== size) { seen[f] = size; continue; }
      const to = path.join(out, f.slice(runId.length + 1));
      try { fs.renameSync(p, to); shots.push(to); } catch {}
    }
  };
  let state = 'loading', hungSince = 0, lastCheck = 0;
  while (Date.now() - t0 < timeout) {
    await sleep(1000);
    collect(false);
    const r = read();
    if (/\[vclient\] done/.test(r)) { state = 'done'; break; }
    if (!isRunning()) { state = 'exited'; break; }
    // A missing required addon opens a modal dialog during loading that nothing dismisses.
    if (state === 'loading' && !/\[vclient\] start/.test(r) && /Warning Message: Addon '[^']+' requires addon/.test(r)) { state = 'missing-addon'; break; }
    // An error in the test file stops that script, so vc_fnc_done never runs.
    if (/File uksf_vclient\\vclient\.VR\\test\.sqf/.test(r)) { state = 'script-error'; break; }
    // Loading blocks the window legitimately (ACRE scans every PBO, much slower on a cold disk
    // cache), so the hang check starts only once the test is running.
    if (/\[vclient\] start/.test(r) && Date.now() - lastCheck > 5000) {
      lastCheck = Date.now();
      if (responding()) hungSince = 0; else if (!hungSince) hungSince = Date.now();
      if (hungSince && Date.now() - hungSince > 45000) { state = 'hung'; break; }
    }
  }
  if (state === 'loading') state = 'timeout';
  kill(); await sleep(2000);

  const r = read();
  const lines = r.split(/\r?\n/).filter(l => /\[vclient\]|Error in expression|Error position|Error \w+:|Cannot load|Cannot save file|Warning Message/.test(l));
  collect(true);
  const failed = lines.filter(l => /\[vclient\] shot \S+ false/.test(l));
  if (failed.length) console.error(`run.js: ${failed.length} screenshot(s) failed; see "Cannot save file" in the RPT`);
  if (!args.includes('--keep')) fs.rmSync(tmp, { recursive: true, force: true });
  if (args.includes('--sheet') && shots.length) {
    try { execFileSync('python', [path.join(__dirname, 'sheet.py'), path.join(out, 'sheet.jpg'), ...shots.sort()], { stdio: 'ignore' }); shots.push(path.join(out, 'sheet.jpg')); }
    catch { console.error('run.js: sheet.py failed (needs Python with Pillow)'); }
  }
  console.log(lines.join('\n'));
  console.log(JSON.stringify({ state, seconds: Math.round((Date.now() - t0) / 1000), rpt, shots }, null, 1));
  if (state === 'script-error') console.error('run.js: the test script hit an SQF error; see the Error lines above');
  else if (state === 'missing-addon') console.error("run.js: a loaded addon requires one that is not loaded; see the 'requires addon' line");
  else if (state === 'hung') console.error('run.js: Arma stopped responding for 45 s and was killed; the last [vclient] line shows where');
  else if (state === 'timeout') console.error('run.js: timed out while Arma still responded; the test never reached vc_fnc_done (a stalled or long script?)');
  if (state === 'exited' && !/Shutdown normally|Exception code/.test(r))
    console.error('run.js: Arma vanished without a shutdown line; another process killed it (a script that kills arma3_x64 by name?)');
  else if (!/Mission directory:/.test(r)) console.error('run.js: the mission never loaded (wrong playMission path makes Arma quit silently)');
  process.exit(state === 'done' && !failed.length ? 0 : 1);
})();
