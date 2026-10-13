const fs = require('fs'), path = require('path'), os = require('os'), crypto = require('crypto');
const { execFileSync, spawn } = require('child_process');

const ARMA = process.env.ARMA || 'B:/Steam/steamapps/common/Arma 3';
const TEMPLATE = 'UKSFTemplate.VR.pbo';
const MISSION = 'LifecycleTest.VR';
const PLAYER_PROFILE = 'uksflifecycle';
const CLIENT_RPTS = path.join(process.env.LOCALAPPDATA, 'Arma 3');
const MISSION_DIR = path.join(__dirname, '..', 'mission');

function packPbo(files) {
  const z = s => Buffer.from(s + '\0', 'latin1');
  const u32 = (...v) => { const x = Buffer.alloc(4 * v.length); v.forEach((n, i) => x.writeUInt32LE(n >>> 0, i * 4)); return x; };
  const head = [z(''), u32(0x56657273, 0, 0, 0, 0), z('')];
  const now = Math.floor(Date.now() / 1000);
  for (const [name, data] of files) head.push(z(name), u32(0, data.length, 0, now, data.length));
  head.push(z(''), u32(0, 0, 0, 0, 0));
  const body = Buffer.concat([...head, ...files.map(f => f[1])]);
  return Buffer.concat([body, Buffer.from([0]), crypto.createHash('sha1').update(body).digest()]);
}

function sqfValue(value) {
  if (typeof value === 'string') return `"${value.replace(/"/g, '""')}"`;
  if (typeof value === 'boolean') return value ? 'true' : 'false';
  if (Array.isArray(value)) return `[${value.map(sqfValue).join(',')}]`;
  return String(value);
}

function buildMission(missionsPath, scenario) {
  const unpacked = fs.mkdtempSync(path.join(os.tmpdir(), 'lifecycle-mission-'));
  try {
    execFileSync('hemtt', ['utils', 'pbo', 'unpack', path.join(missionsPath, TEMPLATE), path.join(unpacked, 'm')], { stdio: 'ignore' });
    const root = path.join(unpacked, 'm');
    const files = new Map(fs.readdirSync(root).filter(f => !['properties.txt', '$PBOPREFIX$'].includes(f)).map(f => [f, fs.readFileSync(path.join(root, f))]));
    const description = files.get('description.ext').toString('latin1')
      .replace(/persistenceKey\s*=\s*"[^"]*";/, `persistenceKey = "${scenario.persistenceKey}";`)
      .replace(/onLoadName\s*=\s*"[^"]*";/, 'onLoadName = "UKSF: Lifecycle Test";')
      .replace(/minPlayers\s*=\s*\d+;/, 'minPlayers = 1;')
      .replace(/respawnOnStart\s*=\s*-?\d+;/, 'respawnOnStart = -1;') + '\r\nskipLobby = 1;\r\njoinUnassigned = 0;\r\n'
      + 'class Extended_PreInit_EventHandlers {\r\n    class lc_harness {\r\n        serverInit = "call compile preprocessFileLineNumbers \'lcPreInit.sqf\'";\r\n    };\r\n};\r\n';
    files.set('description.ext', Buffer.from(description, 'latin1'));
    const settings = Object.entries(scenario).map(([k, v]) => `lc_${k} = ${sqfValue(v)};`).join('\r\n');
    files.set('settings.sqf', Buffer.concat([Buffer.from(settings + '\r\n', 'latin1'), fs.readFileSync(path.join(MISSION_DIR, 'common.sqf'))]));
    for (const file of ['init.sqf', 'initServer.sqf', 'mission.sqm', 'lcPreInit.sqf', 'roundtrip.sqf', 'stats.sqf']) files.set(file, fs.readFileSync(path.join(MISSION_DIR, file)));
    const target = path.join(missionsPath, `${MISSION}.pbo`);
    const pbo = packPbo([...files].map(([name, data]) => [name, data]));
    for (let attempt = 0; ; attempt++) {
      try { fs.writeFileSync(target, pbo); break; } catch (error) {
        if (error.code !== 'EBUSY' || attempt >= 30) throw error;
        execFileSync('powershell', ['-NoProfile', '-Command', 'Start-Sleep -Seconds 1']);
      }
    }
    return `${MISSION}.pbo`;
  } finally {
    fs.rmSync(unpacked, { recursive: true, force: true });
  }
}

const isRunning = pid => {
  try { return execFileSync('tasklist', ['/FI', `PID eq ${pid}`, '/NH'], { encoding: 'utf8' }).includes(` ${pid} `); } catch { return false; }
};
const killPid = pid => { try { execFileSync('taskkill', ['/F', '/PID', String(pid)], { stdio: 'ignore' }); } catch {} };

function armaProcesses() {
  const script = "Get-CimInstance Win32_Process -Filter \"Name like 'arma3%'\" | Select-Object ProcessId,Name,CommandLine | ConvertTo-Json -Compress";
  const out = execFileSync('powershell', ['-NoProfile', '-Command', script], { encoding: 'utf8' }).trim();
  if (!out) return [];
  const parsed = JSON.parse(out);
  return (Array.isArray(parsed) ? parsed : [parsed]).map(p => ({ pid: p.ProcessId, name: p.Name, commandLine: p.CommandLine || '' }));
}

function findClientRpt(since, tag) {
  return fs.readdirSync(CLIENT_RPTS).filter(f => /^arma3_x64_.*\.rpt$/i.test(f)).map(f => path.join(CLIENT_RPTS, f))
    .filter(f => fs.statSync(f).mtimeMs >= since - 2000)
    .find(f => fs.readFileSync(f, 'latin1').slice(0, 12000).includes(tag));
}

class Player {
  constructor({ port, password, mods, log }) {
    Object.assign(this, { port, password, mods, log });
    this.pid = 0;
    this.rpt = null;
  }

  async launch() {
    const argv = ['-window', '-noPause', '-noSound', '-noSplash', '-skipIntro', '-world=empty', `-name=${PLAYER_PROFILE}`,
      '-connect=127.0.0.1', `-port=${this.port}`, `-password=${this.password}`, `-mod=${this.mods.join(';')}`];
    this.startedAt = Date.now();
    this.rpt = null;
    const child = spawn(path.join(ARMA, 'arma3_x64.exe'), argv, { cwd: ARMA, detached: true, stdio: 'ignore' });
    this.pid = child.pid;
    child.unref();
    this.log(`player client started (pid ${this.pid})`);
    const deadline = Date.now() + 90e3;
    while (Date.now() < deadline && !this.rpt) {
      await new Promise(r => setTimeout(r, 1000));
      this.rpt = findClientRpt(this.startedAt, `-name=${PLAYER_PROFILE}`);
    }
    if (!this.rpt) throw new Error('player client wrote no RPT within 90 s');
    const text = fs.readFileSync(this.rpt, 'latin1');
    if (/SteamAPI initialization failed/.test(text)) {
      throw new Error('player client could not initialise SteamAPI: Steam must run non-elevated (see concepts/arma-test-client-needs-non-elevated-steam)');
    }
  }

  alive() { return this.pid && isRunning(this.pid); }

  async relaunch() {
    this.kill();
    for (let attempt = 1; attempt <= 3; attempt++) {
      await new Promise(r => setTimeout(r, 10e3));
      await this.launch();
      await new Promise(r => setTimeout(r, 30e3));
      if (this.alive()) return;
      this.log(`player client exited during startup (attempt ${attempt})`);
    }
    throw new Error('player client exited during startup three times');
  }

  screenshot(file) {
    const script = `Add-Type -AssemblyName System.Drawing; Add-Type -TypeDefinition 'using System;using System.Runtime.InteropServices;public static class W{[DllImport("user32.dll")]public static extern bool PrintWindow(IntPtr h,IntPtr dc,uint f);[DllImport("user32.dll")]public static extern bool GetWindowRect(IntPtr h,out R r);public struct R{public int L,T,Rt,B;}}'; $h=(Get-Process -Id ${this.pid}).MainWindowHandle; $r=New-Object W+R; [W]::GetWindowRect($h,[ref]$r)|Out-Null; $i=New-Object System.Drawing.Bitmap ($r.Rt-$r.L),($r.B-$r.T); $g=[System.Drawing.Graphics]::FromImage($i); $dc=$g.GetHdc(); [W]::PrintWindow($h,$dc,2)|Out-Null; $g.ReleaseHdc($dc); $i.Save('${file.replace(/'/g, "''")}',[System.Drawing.Imaging.ImageFormat]::Jpeg)`;
    try { execFileSync('powershell', ['-NoProfile', '-Command', script], { stdio: 'ignore' }); return file; } catch { return null; }
  }

  kill() {
    if (this.pid && isRunning(this.pid)) { killPid(this.pid); this.log(`player client killed (pid ${this.pid})`); }
    this.pid = 0;
  }
}

module.exports = { ARMA, MISSION, buildMission, armaProcesses, isRunning, killPid, Player };
