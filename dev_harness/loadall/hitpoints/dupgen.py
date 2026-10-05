# Writes the duplicate-hitpoint patch from dupactions.json.
# Every class it re-opens keeps its real parent, read from the game by dupnodes.sqf (parents.txt), so nothing
# is re-parented. python dupgen.py <outdir>: writes the patch, or nodes.sqf when parents are still unknown.
import json, os, sys

acts = json.load(open('dupactions.json'))
parents, nonlocal_, children = {}, set(), {}
display = {}

def K(n):
    n = tuple(n)
    for i in range(1, len(n) + 1):
        display.setdefault(tuple(x.lower() for x in n[:i]), n[i - 1])
    return tuple(x.lower() for x in n)

if os.path.exists('parents.txt'):
    for l in open('parents.txt', encoding='latin1'):
        q = l.rstrip('\n').split('|')
        if q[0] == 'NP':
            node = K(q[1].split('/'))
            p = q[2].replace('\\', '/').split('/')
            s = q[3].replace('\\', '/').split('/')
            own = K(s[s.index('CfgVehicles') + 1:]) if 'CfgVehicles' in s else ()
            # A class the node only inherits is re-opened as a child of that class (class MainTurret : MainTurret).
            if own and own != node:
                parents[node] = own
                nonlocal_.add(node)
            else:
                parents[node] = K(p[p.index('CfgVehicles') + 1:]) if 'CfgVehicles' in p else ()
        elif q[0] == 'NC':
            children[K(q[1].split('/'))] = [x for x in q[2].split(',') if x]
            for x in children[K(q[1].split('/'))]:
                display[K(q[1].split('/') + [x])] = x

def tpath(owner, turrets):
    out = [owner]
    for t in [x for x in turrets.split('/') if x]:
        out += ['Turrets', t]
    return K(out)

body, deletes, shadows = set(), {}, set()
for kind, owner, turrets, name in acts:
    node = tpath(owner, turrets)
    if kind == 'delete':
        node += ('hitpoints',)
        display.setdefault(node, 'HitPoints')
        deletes.setdefault(node, set()).add(name)
    else:
        shadows.add(node)
    for i in range(1, len(node) + 1):
        body.add(node[:i])

externs, unknown = set(), set()

def add_body(n):
    for i in range(1, len(n) + 1):
        if n[:i] not in body:
            body.add(n[:i]); work.append(n[:i])

def chain(scope, target):
    # Classes from scope up its parents to target, or None. HEMTT and the engine find a parent name there.
    out = [scope]
    while scope != target:
        if scope not in parents:
            unknown.add(scope); return None
        scope = parents[scope]
        if not scope or scope in out: return None
        out.append(scope)
    return out

work = list(body)
while work:
    n = work.pop()
    if n not in parents:
        unknown.add(n)
        continue
    pp = parents[n]
    # The engine builds only the turrets a Turrets class holds itself, and a patch that re-declares some of a
    # Turrets class's turrets moves them to the front. Every re-opened Turrets re-declares all its turrets, in order.
    if n[-1] == 'turrets':
        if n not in children:
            unknown.add(n)
        elif n in nonlocal_:
            for t in children[n]:
                add_body(n + (t.lower(),))
        else:
            for t in children[n]:
                if n + (t.lower(),) not in body: externs.add(n + (t.lower(),))
    if not pp:
        continue
    if len(pp) == 1:
        if pp not in body: externs.add(pp)
        continue
    # The parent is found from n's container or one of its outer classes, through their parents.
    target, found = pp[:-1], None
    cont = n[:-1]
    for k in range(len(cont), 0, -1):
        found = chain(cont[:k], target)
        if found: break
    if not found:
        continue
    for c in found:
        add_body(c)
    if pp not in body: externs.add(pp)

if unknown:
    rows = ','.join('[%s]' % ','.join('"%s"' % display.get(n[:i + 1], x) for i, x in enumerate(n)) for n in sorted(unknown))
    open('nodes.sqf', 'w').write('''{
    private _r = configFile >> "CfgVehicles";
    { _r = _r >> _x } forEach _x;
    diag_log text format ["NP|%%1|%%2|%%3", _x joinString "/", str inheritsFrom _r, str _r];
    if (_x select (count _x - 1) == "Turrets") then { diag_log text format ["NC|%%1|%%2", _x joinString "/", (("true" configClasses _r) apply {configName _x}) joinString ","] };
} forEach [%s];
call vc_fnc_done;
''' % rows)
    print('unknown parents', len(unknown), '-> run nodes.sqf, append NP lines to parents.txt, rerun')
    sys.exit(1)

# In an existing (local) Turrets, a re-declared turret whose parent is inherited but shares a sibling's name
# would bind to the sibling. Those containers are reported and their actions dropped by the caller.
blocked = set()
for n in body:
    if len(n) < 2 or n[-2] != 'turrets' or n[:-1] in nonlocal_ or n[:-1] not in children: continue
    pp = parents.get(n)
    if pp and pp[:-1] != n[:-1] and pp[-1] in {t.lower() for t in children[n[:-1]]} and pp[-1] != n[-1]:
        blocked.add(n[:-1])
if blocked:
    json.dump(sorted('/'.join(display.get(b[:i + 1], x) for i, x in enumerate(b)) for b in blocked), open('blocked.json', 'w'))
    print('blocked containers', len(blocked), '-> blocked.json')
    sys.exit(2)

def kids(n):
    ks = sorted({m for m in body | externs if len(m) == len(n) + 1 and m[:len(n)] == n})
    if n in children:
        order = {t.lower(): i for i, t in enumerate(children[n])}
        ks.sort(key=lambda m: order.get(m[-1], len(order)))
    return ks

def ordered(nodes):
    # A parent that is a sibling must come first.
    done, out = set(), []
    def visit(m):
        if m in done: return
        done.add(m)
        pp = parents.get(m)
        if pp and pp in nodes: visit(pp)
        out.append(m)
    for m in nodes: visit(m)
    return out

def emit(n, ind):
    name = display.get(n, n[-1])
    if n in externs and n not in body:
        return [ind + 'class %s;' % name]
    pp = parents.get(n, ())
    head = ind + 'class %s%s {' % (name, ' : ' + display.get(pp, pp[-1]) if pp else '')
    lines = [head]
    if n in shadows:
        lines.append(ind + '    class HitPoints {};')
    for m in ordered(kids(n)):
        if n in shadows and m[-1] == 'hitpoints': continue
        lines += emit(m, ind + '    ')
    for d in sorted(deletes.get(n, ())):
        lines.append(ind + '    delete %s;' % d)
    lines.append(ind + '};')
    return lines

tops = ordered(sorted({n[:1] for n in body | externs}))
blocks = [emit(t, '') for t in tops]
out = sys.argv[1]
os.makedirs(out, exist_ok=True)
for f in os.listdir(out):
    if f.startswith('CfgVehicles_'): os.remove(os.path.join(out, f))
files, cur = [[]], 0
for b in blocks:
    if cur + len(b) > 2800 and files[-1]:
        files.append([]); cur = 0
    files[-1] += b; cur += len(b)
for i, f in enumerate(files, 1):
    open(os.path.join(out, 'CfgVehicles_%d.hpp' % i), 'w', newline='\n').write('\n'.join(f) + '\n')
print('deletes', sum(len(v) for v in deletes.values()), 'shadows', len(shadows), 'classes', len(tops), 'files', len(files))
