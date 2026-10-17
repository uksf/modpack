const fs = require('fs'), path = require('path');

const sleep = ms => new Promise(r => setTimeout(r, ms));

function newestFile(dir, pattern, since) {
  if (!fs.existsSync(dir)) return null;
  const files = fs.readdirSync(dir).filter(f => pattern.test(f)).map(f => path.join(dir, f))
    .map(f => ({ f, t: fs.statSync(f).mtimeMs })).filter(x => x.t >= since - 2000).sort((a, b) => b.t - a.t);
  return files.length ? files[0].f : null;
}

class Log {
  constructor(name, locate) {
    this.name = name;
    this.locate = locate;
    this.file = null;
  }

  text() {
    if (!this.file) this.file = this.locate();
    return this.file && fs.existsSync(this.file) ? fs.readFileSync(this.file, 'latin1') : '';
  }

  lines(pattern) {
    return this.text().split(/\r?\n/).filter(l => pattern.test(l));
  }

  has(pattern) {
    return pattern.test(this.text());
  }

  async waitForCount(pattern, count, timeoutMs) {
    const deadline = Date.now() + timeoutMs;
    while (Date.now() < deadline) {
      const hits = this.lines(pattern);
      if (hits.length >= count) return hits;
      await sleep(1000);
    }
    return null;
  }

  async waitFor(pattern, timeoutMs, abort) {
    const deadline = Date.now() + timeoutMs;
    while (Date.now() < deadline) {
      const match = this.text().match(pattern);
      if (match) return match;
      if (abort && abort()) return null;
      await sleep(1000);
    }
    return null;
  }
}

function serverLogs({ profilesPath, installPath, serverName, hcNames, apiPort, since }) {
  const rpt = /^arma3server_x64_.*\.rpt$/i;
  const server = new Log('server', () => newestFile(path.join(profilesPath, serverName), rpt, since));
  const hcs = hcNames.map(hc => new Log(`hc-${hc}`, () => newestFile(path.join(profilesPath, `${serverName}${hc}`), rpt, since)));
  const extension = new Log('extension', () => {
    const dir = path.join(installPath, 'logs');
    if (!fs.existsSync(dir)) return null;
    return fs.readdirSync(dir).filter(f => /^uksf_.*\.log$/.test(f)).map(f => path.join(dir, f))
      .filter(f => fs.statSync(f).mtimeMs >= since - 2000)
      .find(f => fs.readFileSync(f, 'latin1').includes(`Found API port: ${apiPort}`)) || null;
  });
  return { server, hcs, extension };
}

function probes(log) {
  return log.lines(/\[LC\] /).map(line => {
    const match = line.match(/\[LC\] (\S+) (\S+) ([\d.]+) (.*)$/);
    return match ? { event: match[1], role: match[2], tick: +match[3], data: match[4].trim() } : null;
  }).filter(Boolean);
}

module.exports = { Log, serverLogs, probes, newestFile };
