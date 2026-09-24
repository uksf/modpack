// Generates addons/vehicles/vehicles_stabilisation/CfgVehicles*.hpp from selected targets.
// Usage: node generate.js <config dump> <targets.tsv> <probe result.json> <out dir>
//
// Procedure (all against the same modpack build):
//   1. Export the game data for the release and use its config_<version>.cpp as the dump.
//   2. Dev-run probe.sqf without the stabilisation addon; save the result JSON.
//   3. node select.js <probe> <dump> targets.tsv
//   4. node generate.js <dump> targets.tsv <probe> addons/vehicles/vehicles_stabilisation
//   5. hemtt check, build, dev-run probe.sqf again, then node verify.js <before> <after> targets.tsv.
//
// Rules the engine enforces (each was measured with verify.js):
//   - A re-opened nested class must restate its real parent; a bare re-open resets it.
//   - A body opened in a class that does not define that member creates a new, parentless class.
//   - A body-less `class X;` is safe only where X already exists through inheritance.
//   - A restated parent that an own sibling of the same name shadows re-links to that sibling.
const fs = require('fs');
const path = require('path');
const { parseCfgVehicles, turretPath, key } = require('./config');

const [dumpFile, targetsFile, probeFile, outDir] = process.argv.slice(2);
const tree = parseCfgVehicles(dumpFile);
const targets = fs.readFileSync(targetsFile, 'utf8').trim().split('\n').map(l => { const [c, p, v] = l.split('\t'); return { c, p, v: Number(v) }; });
const targetKeys = new Set(targets.map(t => key(t.c + ' ' + t.p)));
const probe = JSON.parse(JSON.parse(fs.readFileSync(probeFile, 'utf8')).result.split('\\').join('/'));
const probeTurrets = probe.flatMap(([c, , , , turrets]) => turrets.map(t => ({ c, p: t[0], stab: t[1] })));

// ── Patch points. Prefer the class whose turret body sets the zero; fall back to the vehicle's
// nearest definer when a non-target turret (any path) inherits the preferred point.
const linkMemo = new Map();
const linksOf = (c, p) => {
    if (!linkMemo.has(c + ' ' + p)) linkMemo.set(c + ' ' + p, tree.turretLinks(c, turretPath(p)));
    return linkMemo.get(c + ' ' + p);
};
const sameLink = (a, b) => a.top === b.top && a.segs.join('/') === b.segs.join('/');
const blocked = link => probeTurrets.some(t => t.stab === 0 && !targetKeys.has(key(t.c + ' ' + t.p))
    && tree.chain(t.c).some(n => n.name === link.top) && linksOf(t.c, t.p).some(x => sameLink(x, link)));

const patches = new Map();
const targetLink = new Map();
for (const t of targets) {
    const links = linksOf(t.c, t.p);
    if (!links.length) throw new Error(`no definer for ${t.c} ${t.p}`);
    const source = links.find(l => tree.setsStabilisation(l)) || links[links.length - 1];
    const chosen = [source, links[0]].find(l => !blocked(l));
    if (!chosen) throw new Error(`every patch point for ${t.c} ${t.p} reaches a non-target`);
    const linkKey = key(chosen.top + ' ' + chosen.segs.join('/'));
    patches.set(linkKey, { ...chosen, v: t.v });
    targetLink.set(t, linkKey);
}

// ── Declaration tree. Node: { name, parent, ref (body-less), order, props, kids }.
const root = new Map();
const newNode = (name, parent, ref) => ({ name, parent, ref, order: [], props: [], kids: new Map() });
const refTop = name => {
    if (!root.has(key(name))) root.set(key(name), newNode(tree.cls(name) ? tree.cls(name).name : name, null, true));
    return root.get(key(name));
};
const openTop = name => {
    const n = refTop(name);
    if (n.ref) { n.ref = false; n.parent = tree.cls(name).parent; if (n.parent) refTop(n.parent); }
    n.order = [...tree.cls(name).members.keys()];
    return n;
};

class Unpatchable extends Error {}

// Make `name`, written in top>>segs as the parent of `self`, visible to HEMTT without changing
// what the engine resolves it to.
function ensureVisible(top, segs, name, self) {
    const s = tree.lookup(top, segs, name, self);
    if (!s) { if (tree.cls(name)) { refTop(name); return; } throw new Error(`unresolved ${top} ${segs.join('/')} ${name}`); }
    if (!tree.reachesUndefined(s.top, s.segs)) { declareRef(s.top, s.segs, name); return; }
    // The base is only inherited through a class that does not define the container. HEMTT also
    // searches enclosing scopes, so a class-level reference satisfies it; the engine still resolves
    // the inherited base first, unless an own sibling shadows the name.
    const container = segs.length ? tree.own(top, segs) : tree.cls(top);
    if (self && key(name) !== key(self) && container && container.members.has(key(name))) {
        throw new Unpatchable(`${self} : ${name} is shadowed by a later sibling`);
    }
    declareRef(top, [], name);
}

// Re-open top>>segs level by level. Only levels the class defines are opened, with their parent.
function openPath(top, segs) {
    let node = openTop(top);
    for (let i = 0; i < segs.length; i++) {
        const own = tree.own(top, segs.slice(0, i + 1));
        let kid = node.kids.get(key(segs[i]));
        if (!own) {
            if (!kid) node.kids.set(key(segs[i]), newNode(segs[i], null, true));
            return null;
        }
        if (!kid) { kid = newNode(own.name, own.parent, false); node.kids.set(key(segs[i]), kid); }
        else if (kid.ref) { kid.ref = false; kid.parent = own.parent; }
        kid.order = [...own.members.keys()];
        if (own.parent) ensureVisible(top, segs.slice(0, i), own.parent, segs[i]);
        node = kid;
    }
    return node;
}

function declareRef(top, segs, name) {
    const node = openPath(top, segs);
    if (!node || node.kids.has(key(name))) return;
    const own = tree.own(top, [...segs, name]);
    node.kids.set(key(name), newNode(own ? own.name : name, null, true));
}

// Fallback for an unpatchable base turret: patch each target's class directly below the base instead.
// There `PK_Turret : PK_Turret` names the base's own turret, which no sibling can shadow. The engine
// builds seats only from a Turrets class's own members, so the child's new Turrets re-declares every
// base turret in base order. The child must not define Turrets itself, and no unstabilised non-target
// may inherit from it.
function patchChildren(link, v) {
    const users = targets.filter(t => targetLink.get(t) === key(link.top + ' ' + link.segs.join('/')));
    const children = new Set(users.map(t => {
        const chain = tree.chain(t.c);
        const at = chain.findIndex(n => n.name === link.top);
        if (at < 1) throw new Unpatchable(`${t.c} is the base itself`);
        return chain[at - 1].name;
    }));
    const path = link.segs.join('/');
    if (link.segs.length !== 2) throw new Unpatchable('per-vehicle patch supports top-level turrets only');
    const siblings = [...tree.own(link.top, link.segs.slice(0, 1)).members.values()].map(n => n.name);
    for (const child of children) {
        if (tree.own(child, link.segs.slice(0, 1))) throw new Unpatchable(`${child} defines ${link.segs[0]}`);
        const leak = probeTurrets.find(t => t.stab === 0 && !targetKeys.has(key(t.c + ' ' + t.p))
            && turretPath(t.p).join('/') === path && tree.chain(t.c).some(n => n.name === child));
        if (leak) throw new Unpatchable(`${child} is inherited by non-target ${leak.c}`);
        declareRef(link.top, [], link.segs[0]);
        for (const s of siblings) declareRef(link.top, link.segs.slice(0, 1), s);
        const top = openTop(child);
        if (!top.kids.has(key(link.segs[0]))) top.kids.set(key(link.segs[0]), newNode(link.segs[0], link.segs[0], false));
        const turrets = top.kids.get(key(link.segs[0]));
        turrets.order = siblings.map(key);
        for (const s of siblings) if (!turrets.kids.has(key(s))) turrets.kids.set(key(s), newNode(s, s, false));
        turrets.kids.get(key(link.segs[1])).props = [`stabilizedInAxes = ${v};`];
    }
    return [...children];
}

const snapshot = () => JSON.stringify([...root], (k, v) => (v instanceof Map ? [...v] : v));
const revive = n => ({ ...n, kids: new Map(n.kids.map(([k, v]) => [k, revive(v)])) });
const unpatchable = [];
const unpatchableLinks = new Set();
for (const [linkKey, { top, segs, v }] of patches) {
    const before = snapshot();
    try {
        openPath(top, segs).props = [`stabilizedInAxes = ${v};`];
    } catch (e) {
        if (!(e instanceof Unpatchable)) throw e;
        root.clear();
        for (const [k, n] of JSON.parse(before)) root.set(k, revive(n));
        try {
            const children = patchChildren({ top, segs }, v);
            console.log(`per-vehicle: ${top} ${segs.join('/')} (${e.message}) -> ${children.join(', ')}`);
        } catch (e2) {
            if (!(e2 instanceof Unpatchable)) throw e2;
            root.clear();
            for (const [k, n] of JSON.parse(before)) root.set(k, revive(n));
            unpatchable.push(`${top} ${segs.join('/')}: ${e.message}; per-vehicle: ${e2.message}`);
            unpatchableLinks.add(linkKey);
        }
    }
}

// ── Emit: body-less classes first, then bodies in inheritance order, members in dump order.
const emit = (n, indent) => {
    const head = `${indent}class ${n.name}${n.parent ? ' : ' + n.parent : ''}`;
    if (n.ref && !n.kids.size) return [`${head};`];
    if (!n.props.length && !n.kids.size) return [`${head} {};`];
    const out = [`${head} {`, ...n.props.map(p => `${indent}    ${p}`)];
    const at = k => n.order.indexOf(key(k.name));
    for (const k of [...n.kids.values()].sort((a, b) => at(a) - at(b))) out.push(...emit(k, indent + '    '));
    out.push(`${indent}};`);
    return out;
};
const tops = [...root.values()];
const bare = tops.filter(n => n.ref && !n.kids.size);
const bodies = tops.filter(n => !bare.includes(n)).sort((a, b) => tree.chain(a.name).length - tree.chain(b.name).length || a.name.localeCompare(b.name));
const blocks = [bare.map(n => `class ${n.name};`), ...bodies.map(n => emit(n, ''))];

const MAX_LINES = 280;
const files = [];
for (const b of blocks) {
    if (!files.length || files[files.length - 1].length + b.length > MAX_LINES) files.push([]);
    files[files.length - 1].push(...b);
}
fs.mkdirSync(outDir, { recursive: true });
for (const f of fs.readdirSync(outDir).filter(f => /^CfgVehicles(_\d+)?\.hpp$/.test(f))) fs.unlinkSync(path.join(outDir, f));
files.forEach((f, i) => fs.writeFileSync(path.join(outDir, `CfgVehicles_${i + 1}.hpp`), f.join('\n') + '\n'));
fs.writeFileSync(path.join(outDir, 'CfgVehicles.hpp'), files.map((f, i) => `#include "CfgVehicles_${i + 1}.hpp"`).join('\n') + '\n');
// Targets the generated config covers, for verify.js.
const patched = targets.filter(t => !unpatchableLinks.has(targetLink.get(t)));
fs.writeFileSync(targetsFile.replace(/\.tsv$/, '') + '.patched.tsv', patched.map(t => `${t.c}\t${t.p}\t${t.v}`).join('\n') + '\n');
console.log(`targets ${targets.length}, patched ${patched.length}, patch points ${patches.size}, files ${files.length}, lines ${files.reduce((a, f) => a + f.length, 0)}`);
for (const u of unpatchable) console.log(`unpatchable: ${u}`);
