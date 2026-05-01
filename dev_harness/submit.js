// Submit SQF blob to dev-run. Strips comments (compileFinal hates them), POSTs, prints runId.
// Usage: node submit.js <sqf_path>   (defaults to D:/Arma/_temp_probe_sqf.txt)
const fs = require('fs');
const http = require('http');

const sqfPath = process.argv[2] || 'D:/Arma/_temp_probe_sqf.txt';
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
    'B:/Steam/steamapps/common/Arma 3/u/uksf_air',
    'B:/Steam/steamapps/common/Arma 3/u/uksf',
    'B:/Steam/steamapps/common/Arma 3/z/ace',
    'B:/Steam/steamapps/common/Arma 3/uksf-dev/@uksf_acre2'
];

const body = JSON.stringify({ sqf, mods, timeoutSeconds: 600 });

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
