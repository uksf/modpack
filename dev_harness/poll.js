// Poll /dev-run/{runId}/status until terminal; write full record.
// Usage: node poll.js <runId> [outPath]
//   outPath default D:/Arma/_temp_result_<runId8>.json
// Retries on connection errors and 5xx. Exits on 404 after a few tries.
const fs = require('fs');
const http = require('http');

const runId = process.argv[2];
if (!runId) { console.error('usage: node poll.js <runId> [outPath]'); process.exit(1); }
const out = process.argv[3] || `D:/Arma/_temp_result_${runId.slice(0, 8)}.json`;
const jwt = fs.readFileSync('D:/Arma/_temp_jwt.txt', 'utf8').trim();

const get = path => new Promise((resolve, reject) => {
    const req = http.request({
        hostname: 'localhost', port: 5500, path, method: 'GET',
        headers: { 'Authorization': `Bearer ${jwt}` }
    }, res => {
        let data = '';
        res.on('data', c => data += c);
        res.on('end', () => resolve({ status: res.statusCode, body: data, contentType: res.headers['content-type'] }));
    });
    req.on('error', reject);
    req.setTimeout(15000, () => { req.destroy(new Error('timeout')); });
    req.end();
});

const sleep = ms => new Promise(r => setTimeout(r, ms));

(async () => {
    let miss = 0;
    while (true) {
        let r;
        try {
            r = await get(`/dev-run/${runId}/status`);
        } catch (e) {
            miss++;
            process.stdout.write(`\rconn ${e.message} retry=${miss} `);
            await sleep(Math.min(5000 * miss, 30000));
            continue;
        }
        if (r.status === 404) {
            miss++;
            if (miss >= 6) { console.log('\nSTATUS HTTP 404', r.body); process.exit(1); }
            process.stdout.write(`\r404 retry=${miss} `);
            await sleep(5000);
            continue;
        }
        if (r.status >= 500) {
            miss++;
            process.stdout.write(`\rHTTP ${r.status} retry=${miss} `);
            await sleep(5000);
            continue;
        }
        if (r.status !== 200) { console.log('\nSTATUS HTTP', r.status, r.body); process.exit(1); }
        miss = 0;
        const j = JSON.parse(r.body);
        process.stdout.write(`\rstatus=${j.status} `);
        if (j.status > 1) {
            console.log('\n--- final status ---'); console.log(j);
            let full;
            for (let i = 0; i < 5; i++) {
                try { full = await get(`/dev-run/${runId}`); break; }
                catch (e) { await sleep(3000); }
            }
            if (!full) { console.error('failed to fetch full record'); process.exit(1); }
            fs.writeFileSync(out, full.body);
            console.log(`--- record written to ${out} (${full.contentType}) ---`);
            process.exit(j.status === 2 ? 0 : 1);
        }
        await sleep(5000);
    }
})();
