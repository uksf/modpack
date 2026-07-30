// Aggregate seeker A/B results by mode (open/hide) or masked/control.
// Usage: node aggregate.js <result.json>
const fs = require('fs');
const j = JSON.parse(fs.readFileSync(process.argv[2], 'utf8'));
const lines = (j.logs || []).map(l => (typeof l === 'string' ? l : l.line)).filter(Boolean);

const rows = [];
for (const line of lines) {
    // new format: slot N mode=open|hide outcome=...
    let m = line.match(/^\s*slot (\d) mode=(\w+) outcome=(\w+) dT=([\d.-]+) dD=([\d.-]+) events=\[(.*)\]$/);
    if (m) {
        rows.push({ slot: +m[1], mode: m[2], outcome: m[3], dT: +m[4], dD: +m[5], events: m[6] });
        continue;
    }
    // old format: slot N outcome=... (masked = slot < 4)
    m = line.match(/^\s*slot (\d) outcome=(\w+) dT=([\d.-]+) dD=([\d.-]+) events=\[(.*)\]$/);
    if (m) {
        rows.push({ slot: +m[1], mode: +m[1] < 4 ? 'hide' : 'open', outcome: m[2], dT: +m[3], dD: +m[4], events: m[5] });
    }
}
console.log(`shots: ${rows.length}`);
const tally = {};
for (const r of rows) {
    const k = `${r.mode} ${r.outcome}`;
    tally[k] = (tally[k] || 0) + 1;
}
console.log(tally);
for (const mode of ['open', 'hide', 'control', 'masked']) {
    const subset = rows.filter(r => r.mode === mode);
    if (!subset.length) continue;
    console.log(`--- ${mode} ---`);
    for (const r of subset) {
        console.log(`s${r.slot} ${r.outcome.padEnd(10)} dT=${String(r.dT).padStart(6)} dD=${String(r.dD).padStart(6)}  ${r.events}`);
    }
}
