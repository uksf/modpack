// Poll dev-run status, fetch full record once status != Running/Pending.
// Usage: node poll.js <runId>
const fs = require('fs');
const http = require('http');

const runId = process.argv[2];
if (!runId) { console.error('usage: node poll.js <runId>'); process.exit(1); }
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
    req.end();
});

const sleep = ms => new Promise(r => setTimeout(r, ms));

(async () => {
    while (true) {
        const r = await get(`/dev-run/${runId}/status`);
        if (r.status !== 200) { console.log('STATUS HTTP', r.status, r.body); return; }
        const j = JSON.parse(r.body);
        process.stdout.write(`\rstatus=${j.status} `);
        if (j.status > 1) {
            console.log('\n--- final status ---'); console.log(j);
            const full = await get(`/dev-run/${runId}`);
            const out = `D:/Arma/_temp_result.json`;
            fs.writeFileSync(out, full.body);
            console.log(`--- record written to ${out} (${full.contentType}) ---`);
            return;
        }
        await sleep(5000);
    }
})();
