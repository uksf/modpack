const fs = require('fs'), path = require('path');

const sleep = ms => new Promise(r => setTimeout(r, ms));
const fullKey = key => `uksf_persistence_key_VR_${key}`;

function apiLogText(ctx) {
  return fs.readdirSync(ctx.out).filter(f => /^api-.*\.log$/.test(f)).map(f => fs.readFileSync(path.join(ctx.out, f), 'utf8')).join('\n');
}

function order(run, patterns) {
  const text = run.logs.server.text();
  const at = patterns.map(p => text.search(p));
  return { ok: at.every(i => i >= 0) && at.every((i, n) => n === 0 || i > at[n - 1]), at };
}

async function afterShutdown(run, ctx, { boxes, saved = true, player = true }) {
  const exited = await run.waitForExit(240e3);
  run.check('server and HC processes exit', exited, run.ownProcesses().map(p => p.pid).join(','));
  run.check('API record returns to offline', await run.waitForRecordOffline(90e3), run.phasesSeen().join(' > '));
  const outcome = run.logs.server.lines(/Shutdown save outcome/).join(' | ');
  run.check(`save outcome ${saved ? 'delivered' : 'not delivered'}`, saved === /outcome: delivered/.test(outcome), outcome);
  const ended = run.logs.server.lines(/Sending mission_ended/).join(' | ');
  run.check(`mission_ended reports saved=${saved}`, new RegExp(`saved: ${saved}`).test(ended), ended);
  const doc = ctx.db('persistence', { key: fullKey(run.scenario.persistenceKey) });
  if (saved) {
    run.check(`API stored ${boxes} boxes`, doc && doc.typeCounts.Box_NATO_Ammo_F === boxes, JSON.stringify(doc && doc.typeCounts));
    if (player) run.check('API stored the player', doc && doc.players[run.playerUid], JSON.stringify(doc && doc.players));
  } else {
    run.check('API stored nothing', !doc, JSON.stringify(doc));
  }
  const start = run.tickOf(/^shutdownStarted/);
  const frames = start === null ? [] : run.frames(start);
  run.check('server frame time stays under 1000 ms during shutdown', frames.length > 0 && Math.max(...frames) < 1000, `max ${Math.max(...frames)} ms over ${frames.length} samples`);
  run.check('no automatic force-kill', !/exceeded .* ceiling|force-killing/i.test(apiLogText(ctx)));
  return doc;
}

module.exports = { sleep, fullKey, apiLogText, order, afterShutdown };
