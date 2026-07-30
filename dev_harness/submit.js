// POST SQF to /dev-run. Strips // and /* */ comments.
// Usage: node submit.js [sqf_path] [ace=dev|build|base|<absPath>] [timeoutSeconds] [worldName]
//   sqf_path default D:/Arma/_temp_probe_sqf.txt
//   ace=dev   → D:/Arma/ace/.hemttout/dev   (default)
//   ace=build → D:/Arma/ace/.hemttout/build
//   ace=base  → D:/Arma/_temp_ace_baseline
//   ace=<path> → that absolute path
const fs = require('fs');
const http = require('http');

const sqfPath = process.argv[2] || 'D:/Arma/_temp_probe_sqf.txt';
const aceSel = process.argv[3] || 'dev';
const timeoutSeconds = parseInt(process.argv[4] || '600', 10);
const worldName = process.argv[5] || null;

const aceMap = {
    dev: 'D:/Arma/ace/.hemttout/dev',
    build: 'D:/Arma/ace/.hemttout/build',
    base: 'D:/Arma/_temp_ace_baseline'
};
const acePath = aceMap[aceSel] || aceSel;

let sqf = fs.readFileSync(sqfPath, 'utf8');
sqf = sqf.replace(/\/\/[^\n]*/g, '').replace(/\/\*[\s\S]*?\*\//g, '');
const jwt = fs.readFileSync('D:/Arma/_temp_jwt.txt', 'utf8').trim();

const mods = [
    'B:/Steam/steamapps/common/Arma 3/uksf-dev/@CBA_A3',
    'B:/Steam/steamapps/common/Arma 3/uksf-dev/@CUP_Terrains_Core',
    'B:/Steam/steamapps/common/Arma 3/uksf-dev/@CUP_Terrains_Maps',
    'B:/Steam/steamapps/common/Arma 3/uksf-dev/@CUP_Terrains_Maps_2',
    'B:/Steam/steamapps/common/Arma 3/uksf-dev/@CUP_Units',
    'B:/Steam/steamapps/common/Arma 3/uksf-dev/@CUP_Vehicles',
    'B:/Steam/steamapps/common/Arma 3/uksf-dev/@CUP_Weapons',
    'B:/Steam/steamapps/common/Arma 3/uksf-dev/@JBad',
    'B:/Steam/steamapps/common/Arma 3/uksf-dev/@uksf_dependencies',
    'D:/Arma/uksf_air/.hemttout/dev',
    'D:/Arma/modpack/.hemttout/dev',
    acePath,
    'B:/Steam/steamapps/common/Arma 3/uksf-dev/@uksf_acre2'
];

const payload = { sqf, mods, timeoutSeconds };
if (worldName) payload.worldName = worldName;
const body = JSON.stringify(payload);
console.log('acePath:', acePath, 'timeout:', timeoutSeconds);

const req = http.request({
    hostname: 'localhost', port: 5500, path: '/dev-run', method: 'POST',
    headers: {
        'Content-Type': 'application/json',
        'Content-Length': Buffer.byteLength(body),
        'Authorization': `Bearer ${jwt}`
    }
}, res => {
    let data = '';
    res.on('data', c => data += c);
    res.on('end', () => { console.log(`STATUS ${res.statusCode}`); console.log(data); });
});
req.on('error', e => console.error('REQ ERROR', e.message));
req.write(body);
req.end();
