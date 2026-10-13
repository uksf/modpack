const { sleep, fullKey, order, afterShutdown } = require('./lib/checks');
const { probes } = require('./lib/logs');
const { parseSqf, diff } = require('./lib/sqf');

const PLAYER_FIELDS = { vehicle: 1, loadout: 4, earplugs: 7, attached: 8, radios: 9 };

function events(run, name) {
  const out = [];
  let pending = null;
  for (const p of probes(run.logs.server).filter(p => p.event === name)) {
    const part = p.data.match(/^#part (\d+) (\d+) \|(.*)\|$/);
    if (!part) { out.push(p.data); continue; }
    if (+part[1] === 0) pending = '';
    if (pending === null) continue;
    pending += part[3];
    if (+part[1] === +part[2] - 1) { out.push(pending); pending = null; }
  }
  return out;
}

function keyed(lines) {
  return Object.fromEntries(lines.map(line => {
    const space = line.indexOf(' ');
    return [line.slice(0, space), parseSqf(line.slice(space + 1))];
  }));
}

async function waitEvent(run, name, timeoutMs) {
  const hit = await run.logs.server.waitFor(new RegExp(`\\[LC\\] ${name} server `), timeoutMs);
  return hit ? events(run, name)[0] ?? null : null;
}

function sessionId(run) {
  const hit = run.logs.server.text().match(/Sending mission_ended for (\S+), saved/);
  return hit ? hit[1] : null;
}

const SCENARIOS = {
  roundtrip: {
    description: 'Every saved object, player, marker, deletion and custom serializer field survives stop and relaunch',
    scenario: { objects: 5, roundTrip: true, createOnce: true },
    async run(run, ctx) {
      run.check('player prepared and shutdown action triggered', await waitEvent(run, 'rtReady', 180e3) !== null);
      const quadId = await waitEvent(run, 'quadId', 5e3);
      const grenadeIds = parseSqf(await waitEvent(run, 'grenadeIds', 5e3) || '[]');
      await afterShutdown(run, ctx, { boxes: 5 });
      const before = keyed(events(run, 'rtA'));
      const playerBefore = keyed(events(run, 'playerData'));
      run.check('captured objects before shutdown', Object.keys(before).length >= 5, Object.keys(before).length);
      run.check('captured the player at disconnect', playerBefore[run.playerUid], Object.keys(playerBefore).join(','));

      await run.relaunch('phaseA');
      const after = keyed(await run.logs.server.waitForCount(/\[LC\] rtB /, Object.keys(before).length, 120e3).then(() => events(run, 'rtB')));
      for (const [id, data] of Object.entries(before)) {
        const reloaded = after[id];
        const settled = reloaded && diff(data[3], reloaded[3], 0.02).length === 0 ? Object.assign([...reloaded], { 3: data[3] }) : reloaded;
        const problems = reloaded ? diff(data, settled, 2e-3) : ['missing after reload'];
        run.check(`object ${data[1]} round-trips every field`, problems.length === 0, problems.slice(0, 6).join(' | '));
      }
      const extra = Object.keys(after).filter(id => !before[id]);
      run.check('no persistent objects appear that were not saved', extra.length === 0, extra.join(','));
      const deleted = parseSqf((events(run, 'deletedLoaded')[0]) || '[]');
      run.check('destroyed vehicle recorded as deleted', deleted.includes(quadId), `${quadId} in ${JSON.stringify(deleted)}`);
      run.check('deleted Eden object recorded as deleted', grenadeIds.length === 1 && deleted.includes(grenadeIds[0]), JSON.stringify(grenadeIds));
      run.check('deleted Eden object stays deleted after reload', events(run, 'grenadeBoxes')[0] === '0', events(run, 'grenadeBoxes')[0]);

      const markers = parseSqf(events(run, 'markersLoaded')[0] || '[]');
      const poly = markers.find(m => m[0] === '_USER_DEFINED #0/992/1');
      run.check('polyline marker reloads with its points', poly && diff(poly[5], [3000, 3000, 3050.5, 3020.25, 3100, 2990]).length === 0, JSON.stringify(poly));
      run.check('deleted marker does not reload', !markers.some(m => m[0] === '_USER_DEFINED #0/993/1'), markers.map(m => m[0]).join(','));
      const custom = events(run, 'customLoaded')[0];
      const expected = events(run, 'customExpected')[0];
      const customProblems = custom && custom !== '"none"' ? diff(parseSqf(expected), parseSqf(custom), 1e-6) : ['custom serializer data never loaded'];
      run.check('custom serializer data round-trips exactly', customProblems.length === 0, `${customProblems.join(' | ')} loaded ${custom}`);

      const restoredLine = await waitEvent(run, 'playerRestored', 150e3);
      const restored = restoredLine && keyed([restoredLine])[run.playerUid];
      const saved = playerBefore[run.playerUid];
      run.check('player received redeploy data', events(run, 'redeployData').length > 0, events(run, 'noRedeployData').length ? 'client timed out waiting' : '');
      if (restored && saved) {
        for (const [field, index] of Object.entries(PLAYER_FIELDS)) {
          const problems = diff(saved[index], restored[index], 1e-3);
          run.check(`player ${field} restored`, problems.length === 0, problems.slice(0, 4).join(' | '));
        }
        run.check('player position restored within 3 m', diff(saved[0], restored[0], 0).length === 0 || Math.hypot(...saved[0].map((v, n) => v - restored[0][n])) < 3, `${JSON.stringify(saved[0])} vs ${JSON.stringify(restored[0])}`);
        run.check('player wound state restored', JSON.stringify(restored[6]).includes('leftleg') || diff(saved[6], restored[6], 0.05).length === 0, JSON.stringify(restored[6]).slice(0, 300));
      } else {
        run.check('player state captured after redeploy', false, restoredLine || 'no playerRestored line');
      }
      await run.stop();
      await afterShutdown(run, ctx, { boxes: 5 });
    },
  },
  'partial-save': {
    description: 'A capture cut short by the 60 s cap is reported partial and does not erase objects it skipped',
    scenario: { objects: 600, createOnce: true },
    async run(run, ctx) {
      await run.stop();
      await afterShutdown(run, ctx, { boxes: 600 });
      run.scenario.captureFreeze = 61;
      await run.relaunch('phaseA');
      await run.stop();
      const exited = await run.waitForExit(300e3);
      run.check('server and HC processes exit', exited, run.ownProcesses().map(p => p.pid).join(','));
      const capped = run.logs.server.lines(/capture cap|uncaptured/i).join(' | ');
      run.check('capture hit the 60 s cap', capped.length > 0, capped);
      const outcome = run.logs.server.lines(/Shutdown save outcome/).join(' | ');
      run.check('save outcome reported partial', /outcome: partial/.test(outcome), outcome);
      const ended = run.logs.server.lines(/Sending mission_ended/).join(' | ');
      run.check('mission_ended reports saved=false', /saved: false/.test(ended), ended);
      const doc = ctx.db('persistence', { key: fullKey(run.scenario.persistenceKey) });
      run.check('API keeps all 600 boxes after a partial capture', doc && doc.typeCounts.Box_NATO_Ammo_F === 600, JSON.stringify(doc && doc.typeCounts));
    },
  },
  stats: {
    description: 'Shots, hits, kills (player and HC AI), vehicle damage, explosives, medical states and movement reach Mongo with the right totals',
    scenario: { objects: 0, stats: true },
    async run(run, ctx) {
      const done = await waitEvent(run, 'statsDone', 400e3);
      run.check('statistics script completed', done !== null, `fired ${events(run, 'fired')[0]} medical ${events(run, 'medical')[0]} owners ${events(run, 'aiOwners')[0]}`);
      if (done === null) return;
      const [, shots] = parseSqf(done);
      await run.stop();
      await afterShutdown(run, ctx, { boxes: 0 });
      const o = order(run, [/\[LC\] statsDone/, /Sending mission_ended/]);
      run.check('last shots happen before mission_ended', o.ok, o.at.join(','));
      const id = sessionId(run);
      await sleep(10e3);
      const stats = ctx.db('statistics', { sessionId: id });
      run.note('statistics', JSON.stringify(stats).slice(0, 4000));
      const combat = stats.combat.types, lifecycle = stats.lifecycle.types;
      for (const type of ['shot', 'hit', 'kill', 'combatDamage']) run.check(`combat ${type} events stored`, combat[type] > 0, JSON.stringify(combat));
      for (const type of ['unconscious', 'cardiacArrest', 'coma', 'explosivePlaced']) run.check(`lifecycle ${type} events stored`, lifecycle[type] > 0, JSON.stringify(lifecycle));
      const player = stats.players[run.playerUid];
      run.check('player mission stats aggregated', player, Object.keys(stats.players).join(','));
      if (!player) return;
      run.check(`total shots equal the ${shots} the client fired`, player.totalShots === shots, player.totalShots);
      run.check('hits recorded on infantry and the tank', player.totalHits >= 3, JSON.stringify(player.hitsByTargetType));
      run.check('both AI kills credited, including the HC-owned AI', (player.kills.direct + player.kills.indirect) === 2, JSON.stringify(player.kills));
      run.check('explosive placements counted', player.explosivesPlaced >= 1, player.explosivesPlaced);
      run.check('wounds counted', player.timesWounded >= 1, JSON.stringify(player.woundsByBodyPart));
      run.check('unconscious, cardiac arrest and coma counted', player.timesUnconscious >= 1 && player.timesInCardiacArrest >= 1 && player.timesInComa >= 1,
        `${player.timesUnconscious}/${player.timesInCardiacArrest}/${player.timesInComa}`);
      run.check('distance on foot and in vehicle sampled', player.distanceOnFoot > 50 && player.distanceInVehicle > 200, `${player.distanceOnFoot} / ${player.distanceInVehicle}`);
      run.check('fuel use sampled', player.totalFuelLitres > 0, player.totalFuelLitres);
      run.check('vehicle damage dealt recorded', player.totalDamageDealt > 0, player.totalDamageDealt);
    },
  },
};

module.exports = { SCENARIOS };
