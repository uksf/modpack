// CfgVehicles class tree from a game-data export (config_<version>.cpp), plus the parent
// resolution rules the generator needs. The dump lists each class body with its own members only.
const fs = require('fs');

const key = s => s.toLowerCase();

function parseCfgVehicles(dumpFile) {
    const classes = new Map();
    const lines = fs.readFileSync(dumpFile, 'utf8').split(/\r?\n/);
    let i = lines.findIndex(l => /^\tclass CfgVehicles \{/.test(l)) + 1;
    const stack = [];
    for (; i < lines.length; i++) {
        const line = lines[i];
        if (/^\t};/.test(line)) break;
        const t = line.trim();
        const m = t.match(/^class ([A-Za-z0-9_]+)(?::\s*([A-Za-z0-9_]+))?\s*\{(\s*\};)?$/);
        if (m) {
            const node = { name: m[1], parent: m[2] || null, members: new Map(), props: new Set() };
            (stack.length ? stack[stack.length - 1].members : classes).set(key(m[1]), node);
            if (!m[3]) stack.push(node);
            continue;
        }
        if (t === '};') { stack.pop(); continue; }
        const kv = t.match(/^([A-Za-z0-9_]+)(\[\])?\s*=/);
        if (kv && stack.length) stack[stack.length - 1].props.add(key(kv[1]));
    }
    return new Tree(classes);
}

class Tree {
    constructor(classes) { this.classes = classes; }

    cls(name) { return this.classes.get(key(name)); }

    chain(name) {
        const out = [];
        for (let c = this.cls(name), g = 0; c && g < 100; c = c.parent && this.cls(c.parent), g++) out.push(c);
        return out;
    }

    // Own (not inherited) node at a path inside a top-level class body.
    own(top, segs) {
        let cur = this.cls(top);
        for (const s of segs) cur = cur && cur.members.get(key(s));
        return cur || null;
    }

    definerOf(top, segs) { return this.chain(top).find(n => this.own(n.name, segs)) || null; }

    // Does top>>segs exist after inheritance? Each container follows its real parent, so a
    // container redefined without a parent hides the members its ancestors had.
    exists(top, segs, depth = 0) {
        if (depth > 60 || !this.cls(top)) return false;
        if (!segs.length || this.own(top, segs)) return true;
        let k = -1;
        while (k + 1 < segs.length && this.own(top, segs.slice(0, k + 2))) k++;
        if (k < 0) { const p = this.cls(top).parent; return p ? this.exists(p, segs, depth + 1) : false; }
        const prefix = segs.slice(0, k + 1);
        if (!this.own(top, prefix).parent) return false;
        const b = this.baseOf(top, prefix);
        return b ? this.exists(b.top, [...b.segs, ...segs.slice(k + 1)], depth + 1) : false;
    }

    // Scope that `name`, written in scope top>>segs as the parent of `self`, resolves to:
    // an own sibling defined earlier, the immediate base scope, or an enclosing scope.
    lookup(top, segs, name, self) {
        const container = segs.length ? this.own(top, segs) : this.cls(top);
        if (container && key(name) !== key(self || '')) {
            const order = [...container.members.keys()];
            const at = order.indexOf(key(name)), selfAt = self ? order.indexOf(key(self)) : order.length;
            if (at >= 0 && (selfAt < 0 || at < selfAt)) return { top, segs };
        }
        const b = this.baseOf(top, segs);
        if (b && this.exists(b.top, [...b.segs, name])) return b;
        if (segs.length) return this.lookup(top, segs.slice(0, -1), name, null);
        return null;
    }

    // Base scope of top>>segs: the parent class at top level, else where its parent name lives.
    baseOf(top, segs) {
        if (!segs.length) { const p = this.cls(top).parent; return p ? { top: p, segs: [] } : null; }
        const own = this.own(top, segs);
        const parent = own ? own.parent : segs[segs.length - 1];
        if (!parent) return null;
        const s = this.lookup(top, segs.slice(0, -1), parent, segs[segs.length - 1]);
        return s ? { top: s.top, segs: [...s.segs, parent] } : null;
    }

    // A path that passes through a container its class does not define itself.
    reachesUndefined(top, segs) {
        for (let i = 1; i <= segs.length; i++) if (!this.own(top, segs.slice(0, i))) return true;
        return false;
    }

    // Inheritance links of a turret, from the vehicle's nearest definer up to the root turret class.
    turretLinks(vehicle, full) {
        const links = [];
        let d = this.definerOf(vehicle, full);
        let segs = full;
        for (let g = 0; d && g < 40; g++) {
            links.push({ top: d.name, segs });
            const b = this.baseOf(d.name, segs);
            if (!b) break;
            segs = b.segs;
            d = this.definerOf(b.top, segs);
        }
        return links;
    }

    setsStabilisation(link) { return this.own(link.top, link.segs).props.has('stabilizedinaxes'); }
}

const turretPath = path => path.split('/').flatMap(s => ['Turrets', s]);

module.exports = { parseCfgVehicles, turretPath, key };
