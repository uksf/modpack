const fs = require('fs');
const os = require('os');
const path = require('path');
const { spawn } = require('child_process');

function startFocusGuard({ token, log, seconds = 86400 }) {
  const pidFile = path.join(os.tmpdir(), `focus-guard-${process.pid}.pids`);
  fs.writeFileSync(pidFile, '');
  const args = ['-NoProfile', '-ExecutionPolicy', 'Bypass', '-File', path.join(__dirname, 'keep-focus.ps1'),
    '-PidFile', pidFile, '-Seconds', String(seconds), '-ParentPid', String(process.pid)];
  if (token && !/^[A-Za-z0-9_-]+$/.test(token)) throw new Error(`focus guard token must be [A-Za-z0-9_-]: ${token}`);
  if (token) args.push('-Match', token);
  if (log) args.push('-Log', log);
  const child = spawn('powershell', args, { stdio: 'ignore', windowsHide: true });
  child.unref();
  return {
    track: pids => fs.writeFileSync(pidFile, pids.filter(Boolean).join('\n')),
    stop: () => { child.kill(); fs.rmSync(pidFile, { force: true }); },
  };
}

module.exports = { startFocusGuard };
