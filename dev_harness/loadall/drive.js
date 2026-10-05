// Loads every config class into the game on N parallel clients (see README.md).
//   node drive.js <mods.txt> [workers=5]
// A slice whose client dies resumes after the class it was creating; that class goes to out/crashes.txt
// and is skipped on later runs.
const fs = require('fs'), path = require('path'), { spawn } = require('child_process');
const OUT = path.join(__dirname, 'out'), RUN = path.join(__dirname, '..', 'client', 'run.js');
const MODS = path.resolve(process.argv[2] || ''), N = +(process.argv[3] || 5);
if (!fs.existsSync(MODS)) { console.error('usage: node drive.js <mods.txt> [workers]'); process.exit(2); }
for (const d of ['jobs', 'rpt']) fs.mkdirSync(path.join(OUT, d), { recursive: true });

// Slice ends past the real class count are clamped by the loader.
const slices = (phase, total, size) => Array.from({ length: Math.ceil(total / size) }, (_, i) => ({ phase, start: i * size, end: (i + 1) * size }));
const queue = [
    ...slices('veh', 34400, 4300), ...slices('wpn', 21500, 4300), ...slices('man', 7800, 2600),
    ...slices('mag', 5000, 5000), ...slices('ammo', 3000, 3000), ...slices('glasses', 1000, 1000),
    ...slices('nonai', 1000, 1000), ...slices('logic', 2000, 2000),
];
const crashFile = path.join(OUT, 'crashes.txt');
const skip = () => fs.existsSync(crashFile) ? fs.readFileSync(crashFile, 'utf8').split(/\r?\n/).filter(Boolean).map(l => l.split('\t')[2]) : [];
const loader = fs.readFileSync(path.join(__dirname, 'loader.sqf'), 'utf8');
const log = (s) => { fs.appendFileSync(path.join(OUT, 'drive.log'), `${new Date().toISOString()} ${s}\n`); console.log(s); };

// Arma keeps only 10 RPTs. Copy ours while they are written so rotation cannot delete them.
const RPTS = path.join(process.env.LOCALAPPDATA, 'Arma 3'), t0 = Date.now();
const copyRpts = () => {
    for (const f of fs.readdirSync(RPTS).filter(f => /^arma3_x64_.*\.rpt$/.test(f))) {
        try { if (fs.statSync(path.join(RPTS, f)).mtimeMs > t0) fs.copyFileSync(path.join(RPTS, f), path.join(OUT, 'rpt', f)); } catch {}
    }
};
const copier = setInterval(copyRpts, 10000);

let n = 0;
function runJob(job, worker) {
    return new Promise((resolve) => {
        const id = `${job.phase}_${job.start}_${n++}`, sqf = path.join(OUT, 'jobs', `${id}.sqf`), out = path.join(OUT, 'jobs', `${id}.out`);
        fs.writeFileSync(sqf, `LA_PHASE = "${job.phase}"; LA_START = ${job.start}; LA_END = ${job.end}; LA_SKIP = ${JSON.stringify(skip())};\n` + loader);
        const fd = fs.openSync(out, 'w');
        spawn('node', [RUN, sqf, '--mods', MODS, '--out', path.join(OUT, 'jobs', id), '--timeout', '5400'],
            { stdio: ['ignore', fd, fd], env: { ...process.env, VC_PROFILE: `uksfloadall${worker}` } }).on('exit', () => {
            copyRpts();
            const txt = fs.readFileSync(out, 'utf8');
            const loaded = [...txt.matchAll(/LA\|L\|\w+\|(\d+)\|([^|\s]+)/g)];
            const done = /LA\|END\|/.test(txt);
            log(`${id} done=${done} classes=${loaded.length}`);
            if (!done && !loaded.length && !job.retried) {
                log(`RETRY ${id}: the client never logged a class`);
                queue.unshift({ ...job, retried: true });
            } else if (!done) {
                const last = loaded[loaded.length - 1];
                const at = last ? +last[1] : job.start;
                log(`CRASH ${job.phase} index=${at} class=${last ? last[2] : '?'} state=${(txt.match(/"state":\s*"(\w+)"/) || [])[1]}`);
                if (last) fs.appendFileSync(crashFile, `${job.phase}\t${at}\t${last[2]}\n`);
                if (at + 1 < job.end) queue.unshift({ phase: job.phase, start: at + 1, end: job.end });
            }
            resolve();
        });
    });
}
(async () => {
    await Promise.all(Array.from({ length: N }, async (_, w) => {
        await new Promise(r => setTimeout(r, w * 20000)); // clients launched in the same second cannot find their RPT
        while (queue.length) await runJob(queue.shift(), w);
    }));
    clearInterval(copier);
    log('ALL DONE');
})();
