# Turn removal candidates into config actions on the class that owns each entry.
#   delete: the entry is local in the HitPoints at the same turret path -> "delete H;" there
#   shadow: every entry of an inherited turret HitPoints goes -> local empty "class HitPoints {};" on the turret owner
import collections, json, sys

def split(path):
    parts = path.replace('\\', '/').split('/')
    i = parts.index('CfgVehicles')
    return parts[i + 1], parts[i + 2:]

def turrets(rest):
    # ['Turrets','A','Turrets','B','HitPoints','H'] -> ['A','B'], tail
    out = []
    while len(rest) >= 2 and rest[0] == 'Turrets':
        out.append(rest[1]); rest = rest[2:]
    return out, rest

cand = json.load(open('dupcand.json'))
total = collections.Counter((c, p) for c, p, n, _ in cand)
size = {(c, p): k for c, p, n, k in cand}
own, hps = {}, {}
for l in open('dupown.txt', encoding='latin1'):
    q = l.rstrip('\n').split('|')
    if q[0] == 'DO': own[(q[1], q[2], q[3])] = q[4]
    elif q[0] == 'DP': hps[(q[1], q[2])] = (q[3], q[4])
exclude = set(json.load(open('dupexclude.json'))) if len(sys.argv) > 1 else set()
actions, skipped = set(), collections.Counter()
for c, p, n, _ in cand:
    path = [x for x in p.split('/') if x]
    oe, rest = split(own[(c, p, n)])
    te, tail = turrets(rest)
    hp_path, t_path = hps[(c, p)]
    oh, hrest = split(hp_path)
    th, _ = turrets(hrest)
    if te == path and tail == ['HitPoints', n] and oh == oe and th == path:
        a = ('delete', oe, '/'.join(path), n)
    elif path and total[(c, p)] == size[(c, p)] and (oh, th) != (split(t_path)[0], turrets(split(t_path)[1])[0]):
        ot, trest = split(t_path)
        a = ('shadow', ot, '/'.join(turrets(trest)[0]), '')
    else:
        skipped['inherited, partial'] += 1
        continue
    if '|'.join(a) in exclude:
        skipped['excluded'] += 1
        continue
    actions.add(a)
# Exact reach from hpown.txt (a build without the patch): an action is kept only when every entry it removes,
# in every class, is a planned removal.
def key(path):
    p = path.replace('\\', '/').split('/')
    return tuple(x.lower() for x in p[p.index('CfgVehicles') + 1:]) if 'CfgVehicles' in p else ()
planned = {(c.lower(), p.lower(), n.lower()) for c, p, n, _ in cand}
by_entry, by_turret = collections.defaultdict(list), collections.defaultdict(list)
for l in open('hpown.txt', encoding='latin1'):
    q = l.rstrip('\n').split('|')
    row = (q[1].lower(), q[2].lower().lstrip('/'), q[3].lower())
    by_entry[key(q[4])].append(row)
    if q[5]: by_turret[key(q[5])].append(row)
safe = set()
for a in actions:
    kind, owner, path, name = a
    node = [owner] + sum([['Turrets', t] for t in path.split('/') if t], [])
    if kind == 'delete':
        reach = by_entry[tuple(x.lower() for x in node + ['HitPoints', name])]
    else:
        reach = by_turret[tuple(x.lower() for x in node)]
    if reach and all(r in planned for r in reach):
        safe.add(a)
    else:
        skipped['reaches an entry that stays'] += 1
actions = safe

# Turrets that lose every hitpoint and are not covered yet: shadow on the highest class at or below the turret's
# owner whose every descendant with that turret path also loses all of it.
anc = {}
for l in open('ancall.txt', encoding='latin1'):
    chain = l.rstrip('\n').split('|', 1)[1].split(',')
    anc[chain[0].lower()] = [x.lower() for x in chain]
name_of = {c.lower(): c for c, _, _, _ in cand}
for l in open('ancall.txt', encoding='latin1'):
    for x in l.rstrip('\n').split('|', 1)[1].split(','):
        name_of.setdefault(x.lower(), x)
covered = set()
for a in actions:
    kind, owner, path, name = a
    node = [owner] + sum([['Turrets', t] for t in path.split('/') if t], [])
    covered |= set(by_entry[tuple(x.lower() for x in node + ['HitPoints', name])] if kind == 'delete' else by_turret[tuple(x.lower() for x in node)])
path_case = {p.lower(): p for c, p, n, k in cand}
whole = {(c.lower(), p.lower()) for c, p, n, k in cand if p and total[(c, p)] == size[(c, p)]}
rows_at = collections.defaultdict(set)
turret_owner = {}
for l in open('hpown.txt', encoding='latin1'):
    q = l.rstrip('\n').split('|')
    c, p = q[1].lower(), q[2].lower().lstrip('/')
    rows_at[p].add(c)
    if q[5]: turret_owner[(c, p)] = key(q[5])[0]
has_children = {x for chain in anc.values() for x in chain[1:]}
added = set()
for c, p in sorted(whole):
    if all((c, p, n) in covered for (cc, pp, n) in planned if cc == c and pp == p):
        continue
    # Only on a leaf: re-opening an inherited Turrets in a class with children would re-parent their own Turrets.
    if c in has_children:
        continue
    added.add(('shadow', name_of[c], path_case[p], ''))
skipped['pushed-down shadows'] = len(added)
actions |= added
# uksf_air re-parents these classes; the modpack cannot load after uksf_air, so it must not re-open them.
excl = {x.strip().lower() for x in open('excl_owners.txt') if x.strip()}
actions = {a for a in actions if a[1].lower() not in excl}
json.dump(sorted(actions), open('dupactions.json', 'w'))
print(collections.Counter(a[0] for a in actions), 'owners', len({a[1] for a in actions}), dict(skipped))
