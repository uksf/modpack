// Summarise a dev-run record: log tail + result table.
// Usage: node summarize.js <result.json>
const fs = require('fs');
const j = JSON.parse(fs.readFileSync(process.argv[2] || 'D:/Arma/_temp_result.json', 'utf8'));
const logs = j.logs || [];
console.log('status:', j.status, 'logCount:', logs.length);
if (j.resultPreview) console.log('resultPreview:', String(j.resultPreview).slice(0, 500));
console.log('--- log tail ---');
console.log(logs.slice(-30).map(l => typeof l === 'string' ? l : JSON.stringify(l)).join('\n'));
let results = j.result && j.result.results;
if (!results && typeof j.result === 'string') {
    try { results = JSON.parse(j.result).results; } catch (e) { console.log('result parse fail'); }
}
if (results) {
    console.log('--- results ---');
    for (const r of results) {
        console.log(`v${r.volley} s${r.slot} masked=${r.masked} range=${r.range} fired=${r.fired} outcome=${r.outcome} dT=${(r.distToTarget||0).toFixed(1)} dD=${(r.distToDistractor||0).toFixed(1)} finalMT=${r.finalMT} events=[${(r.events||[]).join(' | ')}]`);
    }
}
