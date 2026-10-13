const fs = require('fs'), path = require('path');
const { buildMission, armaProcesses, Player } = require('./arma');
const { serverLogs, probes } = require('./logs');

const PHASES = ['None', 'Ending', 'Saving', 'Stopping', 'Delivering'];
const sleep = ms => new Promise(r => setTimeout(r, ms));

class Run {
  constructor(ctx, scenario) {
    this.ctx = ctx;
    this.scenario = { objects: 0, offset: 0, freeze: 0, serverFreeze: 0, legacyCopy: 0, createOnce: false, roundTrip: false, stats: false, captureFreeze: 0, player: true, headlessClients: 1, ...scenario };
    if (this.scenario.headlessClients !== 1) throw new Error('the test server record has exactly one headless client');
    this.timeline = [];
    this.checks = [];
  }

  note(event, detail = '') {
    const entry = { t: ((Date.now() - this.since) / 1000).toFixed(1), event, detail };
    this.timeline.push(entry);
    this.ctx.log(`  +${entry.t}s ${event} ${detail}`);
  }

  check(name, pass, detail = '') {
    this.checks.push({ name, pass: !!pass, detail: String(detail) });
  }

  ownProcesses() {
    const tag = `${this.ctx.vars.SERVER_PATH_PROFILES}\\${this.ctx.serverName}`.toLowerCase();
    return armaProcesses().filter(p => p.name.toLowerCase().startsWith('arma3server') && p.commandLine.toLowerCase().includes(tag));
  }

  async launch() {
    const { ctx, scenario } = this;
    const record = ctx.serverRecord;
    this.serverId = record.id;
    this.password = record.password;
    this.mods = record.mods;
    const missionName = buildMission(ctx.vars.MISSIONS_PATH, {
      persistenceKey: scenario.persistenceKey, objects: scenario.objects, offset: scenario.offset,
      freeze: scenario.freeze, serverFreeze: scenario.serverFreeze, legacyCopy: scenario.legacyCopy,
      createOnce: scenario.createOnce, roundTrip: scenario.roundTrip, stats: scenario.stats, captureFreeze: scenario.captureFreeze,
    });
    this.since = Date.now();
    this.logs = serverLogs({
      profilesPath: ctx.vars.SERVER_PATH_PROFILES, installPath: ctx.vars.SERVER_PATH_DEV, serverName: ctx.serverName,
      hcNames: ctx.hcNames.slice(0, scenario.headlessClients), apiPort: ctx.serverApiPort, since: this.since,
    });
    const res = await ctx.api.request('POST', `/gameservers/${this.serverId}/launch`, { missionName });
    if (res.status !== 200) throw new Error(`launch returned ${res.status}: ${res.text.slice(0, 400)}`);
    this.note('launched', missionName);
    if (!await this.logs.server.waitFor(/Connected to Steam servers|sessionID:/, 240e3)) throw new Error('server RPT never showed a session');
    this.note('server host created');
    if (scenario.player) {
      this.player = new Player({ port: ctx.gamePort, password: this.password, mods: this.mods, log: ctx.log });
      await this.player.launch();
      this.note('player started', `pid ${this.player.pid}`);
    }
    if (scenario.waitForMission === false) { this.watch(); return; }
    const shots = path.join(ctx.out, scenario.name);
    fs.mkdirSync(shots, { recursive: true });
    let shot = 0;
    const snap = () => {
      if (this.player && (Date.now() - this.since) / 60e3 > shot + 1) this.player.screenshot(path.join(shots, `wait-${++shot}.jpg`));
      return false;
    };
    const ready = await this.logs.server.waitFor(/\[LC\] ready server \S+ (\d+)/, 420e3, snap);
    if (!ready) throw new Error('server never logged [LC] ready');
    this.note('server ready', `${ready[1]} persistent objects`);
    if (scenario.player) {
      const client = await this.logs.server.waitFor(/\[LC\] remoteReady server \S+ client (\S+)/, 300e3, snap);
      if (!client) throw new Error('player never reported ready');
      this.playerUid = client[1];
      this.note('player ready', this.playerUid);
    }
    if (scenario.headlessClients > 0 && !await this.logs.server.waitFor(/\[LC\] remoteReady server \S+ hc /, 300e3)) {
      throw new Error('headless client never reported ready');
    }
    this.watch();
  }

  async relaunch(label) {
    clearInterval(this.watcher);
    if (this.player) this.player.kill();
    this.archive(label);
    await this.launch();
  }

  archive(label) {
    const dir = path.join(this.ctx.out, this.scenario.name, label);
    fs.mkdirSync(dir, { recursive: true });
    for (const log of [this.logs?.server, this.logs?.extension, ...(this.logs?.hcs ?? [])].filter(Boolean)) {
      if (log.file) fs.copyFileSync(log.file, path.join(dir, `${log.name}${path.extname(log.file)}`));
    }
    if (this.player?.rpt) fs.copyFileSync(this.player.rpt, path.join(dir, 'client.rpt'));
  }

  headlessClientPids() {
    return this.ownProcesses().filter(p => /\s-client(\s|$)/.test(p.commandLine)).map(p => p.pid);
  }

  watch() {
    let last = '';
    let busy = false;
    this.watcher = setInterval(async () => {
      if (busy) return;
      busy = true;
      try {
        const server = await this.ctx.api.server(this.ctx.serverName);
        const s = server.status;
        const state = `${PHASES[s.stopPhase] ?? s.stopPhase} running=${s.running} launching=${s.launching} pid=${server.processId ?? '-'}`;
        if (state !== last) { this.note('state', state); last = state; }
        this.lastServer = server;
      } catch (error) {
        if (last !== 'api-unreachable') { this.note('state', `api-unreachable ${error.message}`); last = 'api-unreachable'; }
      } finally { busy = false; }
    }, 1000);
  }

  phasesSeen() {
    return this.timeline.filter(e => e.event === 'state').map(e => e.detail.split(' ')[0]);
  }

  async stop() {
    const res = await this.ctx.api.request('POST', `/gameservers/${this.serverId}/stop`);
    this.note('stop requested', res.status);
    return res;
  }

  async command(name) {
    const res = await fetch(`http://127.0.0.1:${this.ctx.serverApiPort}/command`, { method: 'POST', body: JSON.stringify([name]) });
    this.note('command sent', `${name} ${res.status}`);
    return res.status;
  }

  async waitForExit(timeoutMs) {
    const deadline = Date.now() + timeoutMs;
    while (Date.now() < deadline) {
      if (this.ownProcesses().length === 0) { this.note('all server and HC processes exited'); return true; }
      await sleep(2000);
    }
    return false;
  }

  async waitForRecordOffline(timeoutMs) {
    const deadline = Date.now() + timeoutMs;
    while (Date.now() < deadline) {
      const s = this.lastServer;
      if (s && !s.status.running && !s.status.launching && s.status.stopPhase === 0 && !s.processId) return true;
      await sleep(1000);
    }
    return false;
  }

  frames(fromTick) {
    return probes(this.logs.server).filter(p => p.event === 'frame' && p.tick >= fromTick).map(p => +p.data.split(' ')[1]);
  }

  tickOf(pattern) {
    const hit = probes(this.logs.server).find(p => pattern.test(`${p.event} ${p.data}`));
    return hit ? hit.tick : null;
  }

  async cleanup() {
    clearInterval(this.watcher);
    if (this.player) this.player.kill();
    if (this.ownProcesses().length > 0) {
      try { await this.ctx.api.request('POST', '/gameservers/killall?confirmDataLoss=true'); } catch {}
      await sleep(3000);
      for (const p of this.ownProcesses()) require('./arma').killPid(p.pid);
    }
    this.archive('.');
    const dir = path.join(this.ctx.out, this.scenario.name);
    fs.writeFileSync(path.join(dir, 'timeline.json'), JSON.stringify({ scenario: this.scenario, timeline: this.timeline, checks: this.checks }, null, 1));
  }
}

module.exports = { Run, PHASES };
