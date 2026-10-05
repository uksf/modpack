# Wires model.cfg animation sources that configs never declared, at the topmost class sharing the model.
# Inputs: animsrc.txt (class|anim|source), classdata.txt (CD|...), rootdata.txt (RT|, RI|), learned.json.
import json, re, collections, sys

def arr(s):
    return json.loads(s) if s else []

unknown = collections.defaultdict(set)
for l in open('animsrc.txt', encoding='latin1'):
    p = l.rstrip('\n').split('|')
    if len(p) >= 3:
        unknown[p[0]].add(p[2].strip().lower())

info = collections.defaultdict(lambda: {'sim': '', 'hp': {}, 'tur': [], 'wpn': []})
for l in open('classdata2.txt', encoding='latin1'):
    p = l.rstrip('\n').split('|')
    if p[0] == 'CD':
        info[p[1]]['sim'] = p[3]; info[p[1]]['wpn'] = arr(p[4])
    elif p[0] == 'CDH':
        info[p[1]]['hp'][p[2].lower()] = p[2]
    elif p[0] == 'CDT':
        info[p[1]]['tur'].append([p[2], p[3], p[4], arr(p[5])])
info = dict(info)

root_of, rinfo = {}, {}
for l in open('rootdata.txt', encoding='latin1'):
    p = l.rstrip('\n').split('|')
    if p[0] == 'RT':
        root_of[p[1]] = p[2]
    else:
        rinfo[p[1]] = {'parent': p[2], 'gparent': p[3], 'local': p[4] == 'true', 'asParent': p[5],
                       'parentLocal': p[6] == 'true', 'addons': arr(p[7])}

learned = json.load(open('learned.json'))
import os
EXCLUDE = set(open('exclude.txt').read().split()) if os.path.exists('exclude.txt') else set()
rp, existing = {}, collections.defaultdict(set)
for l in open('rootdata2.txt', encoding='latin1'):
    p = l.rstrip('\n').split('|')
    if p[0] == 'RP':
        rp[p[1]] = (p[2], p[3])
    elif p[0] == 'RS':
        existing[p[1]].add(p[2])

def as_mode(r):
    # 'inherit': class AnimationSources : AnimationSources (parent declares it); 'new': parentless; None: skip
    rAS, pAS = rp[r]
    if rinfo[r]['local']:
        if rAS == '<NULL-config>':
            return 'new'
        return 'inherit' if rAS == pAS else None
    return 'inherit' if pAS != '<NULL-config>' else 'new'

SKIPW = re.compile(r'mastersafe|cmflare|flare|smoke|laserdesignator|horn|fakeweapon|cmlauncher|searchlight', re.I)
ROCKET = re.compile(r'rocket|ffar|hydra|s5|s8|ub32|crv|launcher|mlrs|grad|missile|atgm|tow|hellfire|kornet|konkurs', re.I)

def weapons_of(c):
    w = list(info[c]['wpn'])
    for t in info[c]['tur']:
        w += t[3]
    return [x for x in w if not SKIPW.search(x)]

def best(name):
    for sig, n in learned.get(name, []):
        d = json.loads(sig)
        if d.get('source'):
            return d
    return None

decided, report = collections.defaultdict(dict), collections.defaultdict(list)
groups = collections.defaultdict(list)
for c, r in root_of.items():
    if c in info:
        groups[r].append(c)
for root, kids in groups.items():
    srcs = set().union(*(unknown[k] for k in kids))
    for s in sorted(srcs - existing.get(root, set())):
        d = best(s)
        if d is None:
            report['never defined anywhere'].append((root, s)); continue
        src = d['source'].lower()
        if src == 'hit':
            hp = d.get('hitpoint', '').lower()
            if hp and all(hp in info[k]['hp'] for k in kids):
                decided[root][s] = {'source': 'Hit', 'hitpoint': info[kids[0]]['hp'][hp], 'raw': 1}
            else:
                report['hitpoint not on vehicle'].append((root, s, d.get('hitpoint')))
        elif src in ('revolving', 'reloadmagazine', 'reload', 'ammo', 'ammorandom', 'isempty'):
            common = set(weapons_of(kids[0]))
            for k in kids[1:]:
                common &= set(weapons_of(k))
            want_rocket = bool(re.search(r'rocket', s))
            cand = sorted(w for w in common if bool(ROCKET.search(w)) == want_rocket)
            lw = d.get('weapon')
            if lw in common:
                pick = lw
            elif len(cand) == 1:
                pick = cand[0]
            else:
                report['weapon ambiguous or absent'].append((root, s, cand)); continue
            decided[root][s] = {'source': d['source'], 'weapon': pick}
        else:
            dd = {k: d[k] for k in ('source', 'animperiod', 'initphase') if k in d}
            decided[root][s] = dd

def emit(root, srcs):
    ri = rinfo[root]
    out = []
    head = 'class AnimationSources : AnimationSources {' if as_mode(root) == 'inherit' else 'class AnimationSources {'
    out.append(f"class {root} : {ri['parent']} {{")
    out.append('    ' + head)
    for s, d in sorted(srcs.items()):
        out.append(f'        class {s} {{')
        for k, v in d.items():
            key = {'animperiod': 'animPeriod', 'initphase': 'initPhase'}.get(k, k)
            out.append(f'            {key} = ' + (f'"{v}"' if k in ('source', 'weapon', 'hitpoint') else str(v)) + ';')
        out.append('        };')
    out.append('    };')
    out.append('};')
    return out, as_mode(root) == 'inherit'

# Every patched root needs its parent declared; a parent needs AnimationSources declared when a root
# inherits it. Nodes are emitted parent-first; a class is declared exactly once.
patched = {r for r in decided if decided[r] and r in rinfo and as_mode(r) and r not in EXCLUDE}
skipped = [r for r in decided if decided[r] and r not in patched]
chains = {}
for l in open('chaindata.txt', encoding='latin1'):
    p = l.rstrip('\n').split('|')
    chains[p[1]] = (p[2], p[3], json.loads(p[4]))
nodes = {}
for r in patched:
    lines, needs = emit(r, decided[r])
    nodes[r] = {'parent': rinfo[r]['parent'], 'lines': lines, 'patch': True}

def declare(name, parent, lines):
    if name in nodes and (nodes[name].get('patch') or nodes[name].get('owner')):
        return
    nodes[name] = {'parent': parent, 'lines': lines, 'owner': any('AnimationSources;' in l for l in lines)}

for r in patched:
    p = rinfo[r]['parent']
    if as_mode(r) != 'inherit':
        if p not in nodes:
            nodes[p] = {'parent': None, 'lines': [f'class {p};']}
        continue
    owner, oparent, chain = chains.get(p, (p, rinfo[r]['gparent'], []))
    # The owner holds AnimationSources itself; every class below it up to the root's parent is re-opened empty.
    declare(owner, oparent or None, [f'class {owner} : {oparent} {{', '    class AnimationSources;', '};'] if oparent else [f'class {owner} {{', '    class AnimationSources;', '};'])
    for c, cp in chain:
        declare(c, cp, [f'class {c} : {cp} {{}};'])
externs = sorted({n['parent'] for n in nodes.values() if n['parent'] and n['parent'] not in nodes})
order, done = [], set(externs)
while len(order) < len(nodes):
    progressed = False
    for name in sorted(nodes):
        n = nodes[name]
        if name not in done and (n['parent'] is None or n['parent'] in done):
            order.append(name); done.add(name); progressed = True
    assert progressed, 'cycle'
bodies = [[f'class {e};'] for e in externs] + [nodes[n]['lines'] for n in order]
decl = []
addons = sorted({a for r in patched for a in rinfo[r]['addons']})
json.dump({'patched': len(patched), 'skippedOddParent': skipped, 'report': {k: v for k, v in report.items()}}, open('anims_report.json', 'w'), indent=1)
L = ['#include "script_component.hpp"', '',
     '// Generated by dev_harness/loadall: animation sources that a model.cfg animates but no config declared,',
     '// wired on the topmost class that uses the model, as other mods wire the same source names.',
     'class CfgPatches {', '    class ADDON {', '        name = COMPONENT_NAME;', '        units[] = {};', '        weapons[] = {};',
     '        requiredVersion = REQUIRED_VERSION;', '        requiredAddons[] = {', '            "uksf_common",']
L += [f'            "{a}",' for a in addons]
L += ['        };', '    };', '};', '', 'class CfgVehicles {']
# Arma configs stay under 3,000 lines: the class list goes into ordered include files, split between classes.
import os
outdir = os.path.dirname(os.path.abspath(sys.argv[1]))
chunks, cur = [[]], 0
for b in bodies:
    if cur + len(b) > 2800 and chunks[-1]:
        chunks.append([]); cur = 0
    chunks[-1] += b; cur += len(b)
for n, ch in enumerate(chunks, 1):
    open(os.path.join(outdir, f'CfgVehicles_{n}.hpp'), 'w', newline='\n').write('\n'.join(ch) + '\n')
    L.append(f'#include "CfgVehicles_{n}.hpp"')
L.append('};')
open(sys.argv[1], 'w', newline='\n').write('\n'.join(L) + '\n')
print('patched roots', len(patched), 'sources', sum(len(decided[r]) for r in patched), 'skipped odd parent', len(skipped), 'files', len(chunks))
for k, v in report.items():
    print(k, len(v))
