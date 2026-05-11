// Mint 24h admin JWT for dev-run endpoint. Writes to D:/Arma/_temp_jwt.txt.
// Usage: node mint_jwt.js
const fs = require('fs');
const crypto = require('crypto');

const settings = JSON.parse(fs.readFileSync('E:/workspace/uksf/api/UKSF.Api/appsettings.Development.json', 'utf8'));
const tokenKey = settings.appSettings.secrets.tokenKey;
const sid = '59e38f10594c603b78aa9dbd';
const email = 'contact.tim.here@gmail.com';
const now = Math.floor(Date.now() / 1000);

const header = { alg: 'HS256', typ: 'JWT' };
const payload = {
    'http://schemas.xmlsoap.org/ws/2005/05/identity/claims/emailaddress': email,
    'http://schemas.xmlsoap.org/ws/2005/05/identity/claims/sid': sid,
    'http://schemas.microsoft.com/ws/2008/06/identity/claims/role': 'ADMIN',
    iss: 'uksf-issuer',
    aud: 'uksf-audience',
    nbf: now, iat: now, exp: now + 86400
};

const b64 = o => Buffer.from(JSON.stringify(o)).toString('base64url');
const data = `${b64(header)}.${b64(payload)}`;
const sig = crypto.createHmac('sha256', tokenKey).update(data).digest('base64url');
const jwt = `${data}.${sig}`;

fs.writeFileSync('D:/Arma/_temp_jwt.txt', jwt);
console.log('JWT written to D:/Arma/_temp_jwt.txt');
