#!/usr/bin/env node
const fs = require('fs'), path = require('path'), os = require('os');
const { execFileSync, spawn } = require('child_process');
const { acquire } = require('../client/gpulock');
const { Api, build, settingsPath } = require('./lib/api');
const { Run } = require('./lib/session');
const { SCENARIOS } = require('./scenarios');

const USAGE = `usage: node run.js <scenario...|all|list> --api <api checkout> [--uksf <@uksf build>] [--mod-root <repo with every @mod>] [--out <dir>] [--no-build] [--keep-data] [--allow-focus]

Runs lifecycle scenarios against a local API (port 5510, devLocal) that launches a cloned
"LifecycleTest" server record. Needs non-elevated Steam for the player client. Harness Arma windows are pushed back when they take
focus unless --allow-focus is given.`;

function parseArgs(argv) {
  const opts = { names: [], build: true, keepData: false, keepFocus: true };
  for (let i = 0; i < argv.length; i++) {
    const a = argv[i];
    if (a === '--api') opts.apiDir = argv[++i];
    else if (a === '--uksf') opts.uksfPath = argv[++i];
    else if (a === '--mod-root') opts.modRoot = argv[++i];
    else if (a === '--out') opts.out = argv[++i];
    else if (a === '--no-build') opts.build = false;
    else if (a === '--keep-data') opts.keepData = true;
    else if (a === '--allow-focus') opts.keepFocus = false;
    else if (a === '--help' || a === '-h') { console.log(USAGE); process.exit(0); }
    else opts.names.push(a);
  }
  return opts;
}

(async () => {
  const opts = parseArgs(process.argv.slice(2));
  if (opts.names[0] === 'list') {
    for (const [name, s] of Object.entries(SCENARIOS)) console.log(`${name.padEnd(20)} ${s.description}`);
    return;
  }
  const names = opts.names.includes('all') ? Object.keys(SCENARIOS) : opts.names;
  const unknown = names.filter(n => !SCENARIOS[n]);
  if (!names.length || unknown.length || !opts.apiDir) { console.error(unknown.length ? `unknown scenario: ${unknown.join(', ')}` : USAGE); process.exit(2); }

  const stamp = new Date().toISOString().replace(/[:.]/g, '-').slice(0, 19);
  const out = path.resolve(opts.out || path.join(os.homedir(), '.agent-scratch', 'lifecycle', stamp));
  fs.mkdirSync(out, { recursive: true });
  const log = msg => { const line = `[${new Date().toISOString().slice(11, 19)}] ${msg}`; console.log(line); fs.appendFileSync(path.join(out, 'run.log'), line + '\n'); };
  const settings = settingsPath(opts.apiDir);
  const db = (op, args = {}) => JSON.parse(execFileSync('python', [path.join(__dirname, 'lib', 'db.py'), settings, op, JSON.stringify(args)], { encoding: 'utf8' }));

  const vars = db('vars', { keys: ['SERVER_PATH_PROFILES', 'SERVER_PATH_DEV', 'MISSIONS_PATH', 'SERVER_HEADLESS_NAMES', 'SERVER_COMMAND_PASSWORD'] });
  const ctx = {
    out, log, db, vars, serverName: 'LifecycleTest', hcNames: String(vars.SERVER_HEADLESS_NAMES).split(',').map(s => s.trim()), gamePort: 2412, serverApiPort: 7100,
    modRoot: opts.modRoot ? path.resolve(opts.modRoot) : null,
    uksfPath: path.resolve(opts.uksfPath || (opts.modRoot ? path.join(opts.modRoot, '@uksf') : path.join(__dirname, '..', '..', '.hemttout', 'dev'))),
  };
  if (!fs.existsSync(path.join(ctx.uksfPath, 'addons'))) { console.error(`no @uksf build at ${ctx.uksfPath}`); process.exit(2); }

  const release = await acquire('lifecycle harness');
  fs.rmSync(path.join(vars.SERVER_PATH_PROFILES, ctx.serverName, 'Users', ctx.serverName, `${ctx.serverName}.vars.Arma3Profile`), { force: true });
  const dismisser = spawn('powershell', ['-NoProfile', '-ExecutionPolicy', 'Bypass', '-File', path.join(__dirname, 'lib', 'dismiss-acre.ps1'),
    '-Seconds', '86400', '-Log', path.join(out, 'acre-dialogs.log')], { stdio: 'ignore', windowsHide: true });
  const focusGuard = opts.keepFocus && spawn('powershell', ['-NoProfile', '-ExecutionPolicy', 'Bypass', '-File', path.join(__dirname, 'lib', 'keep-focus.ps1'),
    '-Seconds', '86400', '-Log', path.join(out, 'focus.log')], { stdio: 'ignore', windowsHide: true });
  const originalPassword = vars.SERVER_COMMAND_PASSWORD;
  const results = [];
  try {
    if (opts.build) build(opts.apiDir, log);
    db('setvar', { key: 'SERVER_COMMAND_PASSWORD', value: 'brexit' });
    ctx.serverRecord = db('upsert-server', { uksf: ctx.uksfPath, modRoot: ctx.modRoot, port: ctx.gamePort, apiPort: ctx.serverApiPort, headlessClients: 1 });
    ctx.api = new Api({ apiDir: opts.apiDir, port: 5510, out, verifyMode: false, log });
    await ctx.api.start();
    for (const name of names) {
      const def = SCENARIOS[name];
      const key = `lc_${name.replace(/-/g, '_')}_${Date.now().toString(36)}`;
      const run = new Run(ctx, { name, persistenceKey: key, ...def.scenario });
      log(`=== ${name}: ${def.description}`);
      try {
        await run.launch();
        await def.run(run, ctx);
      } catch (error) {
        run.check('scenario ran to completion', false, error.message);
      } finally {
        if (!ctx.api.pid) await ctx.api.start().catch(e => log(`API restart failed: ${e.message}`));
        await run.cleanup();
        if (!opts.keepData) db('delete-persistence', { prefix: `uksf_persistence_key_VR_${key}` });
      }
      for (const c of run.checks) log(`  ${c.pass ? 'PASS' : 'FAIL'} ${c.name}${c.detail ? ` (${c.detail})` : ''}`);
      results.push({ name, pass: run.checks.length > 0 && run.checks.every(c => c.pass) });
    }
  } finally {
    ctx.api?.stop();
    db('setvar', { key: 'SERVER_COMMAND_PASSWORD', value: originalPassword });
    db('delete-server');
    fs.rmSync(path.join(vars.MISSIONS_PATH, 'LifecycleTest.VR.pbo'), { force: true });
    dismisser.kill();
    if (focusGuard) focusGuard.kill();
    release();
  }
  log(`=== results (${out})`);
  for (const r of results) log(`  ${r.pass ? 'PASS' : 'FAIL'} ${r.name}`);
  process.exit(results.every(r => r.pass) ? 0 : 1);
})().catch(error => { console.error(error); process.exit(1); });
