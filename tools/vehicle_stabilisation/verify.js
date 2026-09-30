// Compares probe results without (before) and with (after) the stabilisation addon.
// Usage: node verify.js <before.json> <after.json> <targets.tsv>
// Passes when every vehicle keeps its turret set, each target turret reaches its value with no other
// property changed, and every other turret is unchanged in every property.
const fs = require('fs');
const [beforeFile, afterFile, targetsFile] = process.argv.slice(2);

const load = f => new Map(JSON.parse(JSON.parse(fs.readFileSync(f, 'utf8')).result.split('\\').join('/'))
    .map(([cls, , , , turrets]) => [cls, new Map(turrets.map(t => [t[0], { stab: t[1], hashAll: t[6], hashRest: t[7] }]))]));
const before = load(beforeFile), after = load(afterFile);
const targets = new Map(fs.readFileSync(targetsFile, 'utf8').trim().split('\n').map(l => { const [c, p, v] = l.split('\t'); return [c + ' ' + p, Number(v)]; }));

const failures = [];
let stabilised = 0, unchanged = 0;
if (before.size !== after.size) failures.push(`vehicle count ${before.size} -> ${after.size}`);
for (const [cls, b] of before) {
    const a = after.get(cls);
    if (!a) { failures.push(`${cls} missing`); continue; }
    if ([...b.keys()].join() !== [...a.keys()].join()) { failures.push(`${cls} turrets ${[...b.keys()]} -> ${[...a.keys()]}`); continue; }
    for (const [p, bt] of b) {
        const at = a.get(p);
        const want = targets.get(cls + ' ' + p);
        if (want === undefined) {
            if (at.hashAll !== bt.hashAll) failures.push(`OTHER ${cls} ${p} changed (stab ${bt.stab} -> ${at.stab})`);
            else unchanged++;
        } else if (at.stab !== want) {
            failures.push(`TARGET ${cls} ${p} stab ${bt.stab} -> ${at.stab}, want ${want}`);
        } else if (at.hashRest !== bt.hashRest) {
            failures.push(`TARGET ${cls} ${p} other properties changed`);
        } else stabilised++;
    }
}
console.log(`vehicles ${before.size}, stabilised ${stabilised}/${targets.size}, other turrets unchanged ${unchanged}, failures ${failures.length}`);
for (const f of failures) console.log(f);
process.exit(failures.length ? 1 : 0);
