const fs = require('fs'), path = require('path');
const { spawn } = require('child_process');
const { isRunning, killPid } = require('./lib/arma');

const { sleep, fullKey, order, afterShutdown } = require('./lib/checks');

function spawnBareServer(ctx, name, apiUrl, port) {
  const profiles = path.join(ctx.out, name);
  fs.mkdirSync(profiles, { recursive: true });
  const exe = path.join(ctx.vars.SERVER_PATH_DEV, 'arma3server_x64.exe');
  const child = spawn(exe, [`-port=${port}`, `-profiles=${profiles}`, `-name=${name}`, `-apiUrl=${apiUrl}`, '-world=empty'],
    { cwd: ctx.vars.SERVER_PATH_DEV, detached: true, stdio: 'ignore' });
  child.unref();
  return child.pid;
}

const SCENARIOS = {
  stop: {
    description: 'Website stop with a player and an HC: player drained, save stored, everything exits',
    scenario: { objects: 50 },
    async run(run, ctx) {
      await run.stop();
      const doc = await afterShutdown(run, ctx, { boxes: 50 });
      const types = (doc && doc.typeCounts) || {};
      run.check('editor object without an ID is not saved', !types.Box_NATO_Support_F, JSON.stringify(types));
      run.check('editor object with an Eden ID is saved', types.Box_NATO_Grenades_F === 1, JSON.stringify(types));
      run.check('object spawned in game near the player is saved by the marker scan', types.Box_NATO_Wps_F === 1, JSON.stringify(types));
      const wps = ((doc && doc.positions) || {}).Box_NATO_Wps_F || [];
      run.check('saved position keeps sub-centimetre precision', Math.abs(wps[0] - 2998.1234) < 0.001 && Math.abs(wps[1] - 2991.5678) < 0.001, JSON.stringify(wps));
      const o = order(run, [/\[LC\] playerDisconnected/, /Shutdown save capture started/, /Sending mission_ended/]);
      run.check('player disconnects before capture, capture before mission_ended', o.ok, o.at.join(','));
    },
  },
  'late-player': {
    description: 'The player client freezes 15 s on shutdown and misses the 10 s drain; its state must still be stored',
    scenario: { objects: 20, freeze: 15 },
    async run(run, ctx) {
      await run.stop();
      await afterShutdown(run, ctx, { boxes: 20 });
      run.check('drain timed out (precondition)', run.logs.server.has(/Shutdown timeout/), run.logs.server.lines(/Shutdown timeout|All players disconnected/).join(' | '));
    },
  },
  'api-outage-recover': {
    description: 'API goes down when the stop is sent and returns 30 s later; the save arrives inside the retry window',
    scenario: { objects: 50 },
    async run(run, ctx) {
      await run.stop();
      ctx.api.stop();
      run.note('API down');
      await sleep(30e3);
      await ctx.api.start();
      run.note('API up');
      await afterShutdown(run, ctx, { boxes: 50 });
    },
  },
  'api-outage-lost': {
    description: 'API stays down past the 120 s retry window; the save is reported lost, the server still exits, the restarted API cleans up',
    scenario: { objects: 20 },
    async run(run, ctx) {
      await run.stop();
      ctx.api.stop();
      run.note('API down');
      const exited = await run.logs.server.waitFor(/Shutdown save outcome: (\w+)/, 200e3);
      run.note('outcome', exited && exited[1]);
      await sleep(10e3);
      run.check('server exits while the API is down', run.ownProcesses().every(p => !/-config=/.test(p.commandLine)), run.ownProcesses().map(p => p.pid).join(','));
      await ctx.api.start();
      run.note('API up');
      await afterShutdown(run, ctx, { boxes: 20, saved: false });
      run.check('RPT reports the save was not stored', run.logs.server.has(/Shutdown save was not stored by the API: lost/));
    },
  },
  'end-mission': {
    description: 'endMission command: save delivered before mission_ended and MPEnded',
    scenario: { objects: 30 },
    async run(run, ctx) {
      await run.command('endMission');
      const mp = await run.logs.server.waitFor(/\[LC\] MPEnded/, 200e3);
      run.check('mission ended', mp);
      const o = order(run, [/Save before mission end: delivered/, /Sending mission_ended for \S+, saved: true/, /\[LC\] MPEnded/]);
      run.check('save delivered, then mission_ended saved=true, then MPEnded', o.ok, o.at.join(','));
      const doc = ctx.db('persistence', { key: fullKey(run.scenario.persistenceKey) });
      run.check('API stored 30 boxes', doc && doc.typeCounts.Box_NATO_Ammo_F === 30, JSON.stringify(doc && doc.typeCounts));
    },
  },
  restart: {
    description: '#restart: save before restart, the restarted mission reloads it, a later stop stores both sets',
    scenario: { objects: 25, legacyCopy: 1 },
    async run(run, ctx) {
      await run.command('restart');
      run.check('mission ended for restart', await run.logs.server.waitFor(/\[LC\] MPEnded/, 200e3));
      await run.player.relaunch();
      run.note('player relaunched', `pid ${run.player.pid}`);
      const loads = await run.logs.server.waitForCount(/\[LC\] loaded server /, 2, 300e3);
      const reloaded = loads && loads[1].match(/loaded server [\d.]+ (\w+) (\d+)/);
      run.check('restarted mission reloads the 25 saved boxes plus the Eden-ID and in-game boxes from the load event', reloaded && reloaded[1] === 'event' && +reloaded[2] === 27, loads ? loads.join(' | ') : 'no second load');
      const helipads = await run.logs.server.waitForCount(/\[LC\] helipads /, 2, 60e3);
      run.check('a legacy saved copy of a mission object does not load beside the original', helipads && /helipads server [\d.]+ 1$/.test(helipads[1]), helipads ? helipads.join(' | ') : 'no second count');
      const restartSave = ctx.db('persistence', { key: fullKey(run.scenario.persistenceKey) });
      run.check('API stores the marker with named fields', ((restartSave && restartSave.markerTexts) || []).includes('LC Marker'), JSON.stringify(restartSave && restartSave.markerTexts));
      const markers = await run.logs.server.waitForCount(/\[LC\] markers /, 2, 60e3);
      run.check('restarted mission receives the saved marker from the API in SQF order', markers && /"_USER_DEFINED #0\/990\/1",\[3010\.25,2990\.75,0\],"ICON","hd_dot","Solid",\[1,1\],"ColorRed",1,42\.5,"LC Marker"/.test(markers[1]), markers ? markers.join(' | ') : 'no second marker log');
      const o = order(run, [/Save before mission restart: delivered/, /Sending mission_ended for \S+, saved: true/, /\[LC\] MPEnded/]);
      run.check('save delivered, then mission_ended saved=true, then MPEnded', o.ok, o.at.join(','));
      if (!await run.logs.server.waitForCount(/\[LC\] remoteReady server \S+ client/, 2, 300e3)) {
        run.check('player rejoins after restart', false);
        return;
      }
      await run.stop();
      const doc = await afterShutdown(run, ctx, { boxes: 50 });
      const types = (doc && doc.typeCounts) || {};
      run.check('restart does not duplicate mission objects', !types.Box_NATO_Support_F && !types.Land_HelipadEmpty_F && types.Box_NATO_Grenades_F === 1, JSON.stringify(types));
      const uids = Object.keys((doc && doc.players) || {});
      run.check('only the player is stored, not the HC', uids.length === 1 && uids[0] === run.playerUid, uids.join(','));
    },
  },
  'kill-guards': {
    description: 'Server held in Ending: kill and kill-all refuse without data-loss confirmation, confirmed kill works',
    scenario: { objects: 10, serverFreeze: 90 },
    async run(run, ctx) {
      await run.stop();
      await sleep(15e3);
      const kill = await ctx.api.request('POST', `/gameservers/${run.serverId}/kill`);
      run.check('kill without confirmation refused', kill.status === 400 && /persistence data/.test(kill.text), `${kill.status} ${kill.text.slice(0, 160)}`);
      const killAll = await ctx.api.request('POST', '/gameservers/killall');
      run.check('kill all without confirmation refused', killAll.status === 400 && /persistence data/.test(killAll.text), `${killAll.status} ${killAll.text.slice(0, 160)}`);
      run.check('server still running after refused kills', run.ownProcesses().length > 0);
      const confirmed = await ctx.api.request('POST', `/gameservers/${run.serverId}/kill?confirmDataLoss=true`);
      run.check('confirmed kill accepted', confirmed.status === 200, `${confirmed.status} ${confirmed.text.slice(0, 160)}`);
      run.check('server and HC processes exit', await run.waitForExit(60e3));
      run.check('API record returns to offline', await run.waitForRecordOffline(60e3), run.phasesSeen().join(' > '));
      run.check('API stored nothing', !ctx.db('persistence', { key: fullKey(run.scenario.persistenceKey) }));
    },
  },
  orphans: {
    description: 'An untracked process of this API dies after 5 min; another API\'s process and the tracked server survive; kill-all spares the foreign process',
    scenario: { player: false, headlessClients: 1, waitForMission: false },
    async run(run, ctx) {
      const owned = spawnBareServer(ctx, 'lc_orphan_owned', ctx.api.url, ctx.gamePort + 30);
      const foreign = spawnBareServer(ctx, 'lc_orphan_foreign', 'http://127.0.0.1:5599', ctx.gamePort + 40);
      run.note('orphans spawned', `owned ${owned}, foreign ${foreign}`);
      try {
        await sleep(150e3);
        run.check('owned orphan alive inside the 5 min grace', isRunning(owned));
        await sleep(240e3);
        run.check('owned orphan killed after 5 min', !isRunning(owned));
        run.check('foreign process survives', isRunning(foreign));
        run.check('tracked server and HC survive', run.ownProcesses().length >= 2, run.ownProcesses().map(p => p.pid).join(','));
        const killAll = await ctx.api.request('POST', '/gameservers/killall');
        run.check('kill all accepted with nothing saving', killAll.status === 200, `${killAll.status} ${killAll.text.slice(0, 160)}`);
        run.check('kill all stops the tracked server and HC', await run.waitForExit(60e3));
        run.check('kill all spares the foreign process', isRunning(foreign));
      } finally {
        killPid(owned);
        killPid(foreign);
      }
    },
  },
};

Object.assign(SCENARIOS, require('./scenarios-data').SCENARIOS);

module.exports = { SCENARIOS, fullKey };
