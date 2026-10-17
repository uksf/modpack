// One Arma client set at a time on this host, across agent sessions. Every session that starts Arma waits
// while the lock file exists and is under two hours old, writes it with its name, and deletes it at the end.
// A process started by a lock holder (drive.js clients) sets VC_LOCK_HELD=1 and skips the lock.
const fs = require('fs'), path = require('path'), os = require('os');
const LOCK = process.env.ARMA_GPU_LOCK || path.join(os.homedir(), '.agent-scratch', 'arma-gpu.lock');
const STALE_MS = 2 * 3600e3;

const waitForRemoval = () => new Promise((resolve) => {
    const done = () => { clearTimeout(timer); watcher.close(); resolve(); };
    const watcher = fs.watch(path.dirname(LOCK), (_, f) => { if (f === path.basename(LOCK) && !fs.existsSync(LOCK)) done(); });
    const timer = setTimeout(done, 600e3); // re-check the lock's age every ten minutes
});

async function acquire(owner) {
    if (process.env.VC_LOCK_HELD) return () => {};
    fs.mkdirSync(path.dirname(LOCK), { recursive: true });
    for (;;) {
        try {
            if (Date.now() - fs.statSync(LOCK).mtimeMs >= STALE_MS) fs.rmSync(LOCK, { force: true });
        } catch {}
        try {
            fs.writeFileSync(LOCK, `${owner} pid ${process.pid} ${new Date().toISOString()}\n`, { flag: 'wx' });
            break;
        } catch (e) {
            if (e.code !== 'EEXIST') throw e;
        }
        let holder = '';
        try { holder = fs.readFileSync(LOCK, 'utf8').trim().slice(0, 200); } catch {}
        console.error(`waiting for the GPU lock ${LOCK}: ${holder}`);
        await waitForRemoval();
    }
    const release = () => {
        try { if (fs.readFileSync(LOCK, 'utf8').includes(` pid ${process.pid} `)) fs.rmSync(LOCK); } catch {}
    };
    process.on('exit', release);
    for (const s of ['SIGINT', 'SIGTERM']) process.on(s, () => { release(); process.exit(130); });
    return release;
}

module.exports = { acquire, LOCK };
