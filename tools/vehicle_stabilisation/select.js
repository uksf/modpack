// Selects the turrets to stabilise from a probe result and writes targets.tsv (class, path, value).
// Usage: node select.js <probe result.json> <config dump> <targets.tsv>
//
// A turret is stabilised when it is unstabilised (stabilizedInAxes = 0), carries a real weapon,
// and is not on an artillery vehicle or an armour main gun. Horns, smoke/flare launchers and safe
// placeholders are not real weapons. An armour main gun is the top-level primary gunner of a Tank or
// Wheeled_APC_F, unless the gunner is exposed and fires turned out (e.g. Mastiff RWS).
// Land vehicles get 3, boats 4.
const fs = require('fs');
const [probeFile, dumpFile, outFile] = process.argv.slice(2);

const probe = JSON.parse(JSON.parse(fs.readFileSync(probeFile, 'utf8')).result.split('\\').join('/'));

// CfgWeapons parents, for isKindOf checks.
const weaponParent = new Map();
{
    let inWeapons = false;
    for (const line of fs.readFileSync(dumpFile, 'utf8').split(/\r?\n/)) {
        if (/^\tclass CfgWeapons/.test(line)) { inWeapons = true; continue; }
        if (inWeapons && /^\t};/.test(line)) break;
        const m = inWeapons && line.match(/^\t\tclass ([A-Za-z0-9_]+)(?::\s*([A-Za-z0-9_]+))?/);
        if (m) weaponParent.set(m[1].toLowerCase(), (m[2] || '').toLowerCase());
    }
}
const isKindOf = (weapon, base) => {
    for (let c = weapon.toLowerCase(), i = 0; c && i < 50; c = weaponParent.get(c), i++) if (c === base) return true;
    return false;
};
const NOT_WEAPONS = new Set(['cup_weapon_mastersafe', 'uk3cb_baf_safe', 'fakeweapon']);
const isRealWeapon = w => !NOT_WEAPONS.has(w.toLowerCase()) && !isKindOf(w, 'carhorn') && !isKindOf(w, 'smokelauncher');

const rows = [];
for (const [cls, isShip, artillery, isArmour, turrets] of probe) {
    if (artillery) continue;
    for (const [path, stab, weapons, primaryGunner, forceHide, outMayFire] of turrets) {
        if (stab !== 0 || !weapons.some(isRealWeapon)) continue;
        const exposed = forceHide === 0 && outMayFire === 1;
        if (isArmour && !path.includes('/') && primaryGunner === 1 && !exposed) continue;
        rows.push(`${cls}\t${path}\t${isShip ? 4 : 3}`);
    }
}
fs.writeFileSync(outFile, rows.join('\n') + '\n');
console.log(`targets ${rows.length}`);
