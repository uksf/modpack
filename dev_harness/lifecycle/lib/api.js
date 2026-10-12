const fs = require('fs'), path = require('path'), crypto = require('crypto');
const { execFileSync, spawn } = require('child_process');

const CLAIM = {
  email: 'http://schemas.xmlsoap.org/ws/2005/05/identity/claims/emailaddress',
  sid: 'http://schemas.xmlsoap.org/ws/2005/05/identity/claims/sid',
  role: 'http://schemas.microsoft.com/ws/2008/06/identity/claims/role',
};
const ROLES = ['MEMBER', 'CONFIRMED', 'ADMIN', 'COMMAND', 'NCO', 'SERVERS'];
const sleep = ms => new Promise(r => setTimeout(r, ms));
const b64 = value => Buffer.from(typeof value === 'string' ? value : JSON.stringify(value)).toString('base64url');

function settingsPath(apiDir) {
  return path.join(apiDir, 'UKSF.Api', 'appsettings.Development.json');
}

function mintToken(apiDir) {
  const key = JSON.parse(fs.readFileSync(settingsPath(apiDir), 'utf8')).appSettings.secrets.tokenKey;
  const now = Math.floor(Date.now() / 1000);
  const payload = { [CLAIM.email]: 'lifecycle-harness@localhost', [CLAIM.sid]: '6a0000000000000000000001', [CLAIM.role]: ROLES,
    iss: 'uksf-issuer', aud: 'uksf-audience', nbf: now - 60, exp: now + 6 * 3600 };
  const unsigned = `${b64({ alg: 'HS256', typ: 'JWT' })}.${b64(payload)}`;
  return `${unsigned}.${crypto.createHmac('sha256', key).update(unsigned).digest('base64url')}`;
}

function build(apiDir, log) {
  log(`building API in ${apiDir}`);
  execFileSync('dotnet', ['build', path.join(apiDir, 'UKSF.Api', 'UKSF.Api.csproj'), '-c', 'Debug', '-v', 'q', '-nologo'], { stdio: 'ignore' });
}

class Api {
  constructor({ apiDir, port, out, verifyMode, log }) {
    Object.assign(this, { apiDir, port, out, verifyMode, log });
    this.url = `http://127.0.0.1:${port}`;
    this.token = mintToken(apiDir);
    this.pid = 0;
    this.starts = 0;
  }

  async start() {
    const bin = path.join(this.apiDir, 'UKSF.Api', 'bin', 'Debug', 'net10.0');
    const logFile = path.join(this.out, `api-${this.port}-${++this.starts}.log`);
    const output = fs.openSync(logFile, 'a');
    const env = { ...process.env, ASPNETCORE_ENVIRONMENT: 'Development', Kestrel__Endpoints__Http__Url: this.url };
    if (this.verifyMode) env.UKSF_VERIFY_MODE = '1';
    const child = spawn('dotnet', [path.join(bin, 'UKSF.Api.dll')], { cwd: bin, env, stdio: ['ignore', output, output], detached: false });
    this.pid = child.pid;
    const deadline = Date.now() + 180e3;
    while (Date.now() < deadline) {
      if (child.exitCode !== null) throw new Error(`API exited during startup (code ${child.exitCode}), see ${logFile}`);
      try {
        const res = await fetch(`${this.url}/gameservers`, { signal: AbortSignal.timeout(3000) });
        if (res.status === 401 || res.ok) { this.log(`API listening on ${this.url} (pid ${this.pid})`); return; }
      } catch {}
      await sleep(1000);
    }
    throw new Error(`API did not listen on ${this.url} within 180 s, see ${logFile}`);
  }

  stop() {
    if (!this.pid) return;
    try { execFileSync('taskkill', ['/T', '/F', '/PID', String(this.pid)], { stdio: 'ignore' }); } catch {}
    this.log(`API ${this.port} stopped (pid ${this.pid})`);
    this.pid = 0;
  }

  async request(method, route, body) {
    const res = await fetch(`${this.url}${route}`, {
      method, headers: { Authorization: `Bearer ${this.token}`, 'Content-Type': 'application/json' },
      body: body === undefined ? undefined : JSON.stringify(body), signal: AbortSignal.timeout(30e3),
    });
    const text = await res.text();
    let json = null;
    try { json = JSON.parse(text.replace(/[\u0000-\u001f]/g, ' ')); } catch {}
    return { status: res.status, json, text };
  }

  async server(name) {
    const res = await this.request('GET', '/gameservers');
    if (res.status !== 200) throw new Error(`GET /gameservers returned ${res.status}`);
    return res.json.servers.find(s => s.name === name);
  }
}

module.exports = { Api, build, settingsPath };
