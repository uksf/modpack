# Duplicate turret hitpoints to remove: dead copies when a live copy exists, else every dead copy but the first.
import collections, json
hp = collections.defaultdict(list); model = {}; sel = collections.defaultdict(set)
for l in open('dupdata.txt', encoding='latin1'):
    p = l.rstrip('\n').split('|')
    if p[0] == 'DV': hp[p[1]].append(('', p[2], p[3].lower()))
    elif p[0] == 'DH': hp[p[1]].append((p[2], p[3], p[4].lower()))
    elif p[0] == 'DM': model[p[1]] = p[2]
    elif p[0] == 'DS' and p[2] != '<nocreate>': sel[p[1]] |= {x.lower() for x in p[2].split(',') if x}
cand = []
for c, lst in hp.items():
    if model.get(c) not in sel: continue
    S = sel[model[c]]
    names = collections.defaultdict(list)
    for i, (path, n, s) in enumerate(lst): names[n.lower()].append(i)
    for n, idx in names.items():
        if len(idx) < 2: continue
        live = [i for i in idx if lst[i][2] in S]
        dead = [i for i in idx if lst[i][2] not in S]
        # All dead: keep one, preferring a turret copy, which the engine links to that turret.
        keep = next((i for i in dead if lst[i][0]), dead[0] if dead else None)
        for i in (dead if live else [i for i in dead if i != keep]):
            cand.append([c, lst[i][0], lst[i][1], len([j for j in range(len(lst)) if lst[j][0] == lst[i][0]])])
json.dump(cand, open('dupcand.json', 'w'))
print(len(cand), 'removals in', len({c[0] for c in cand}), 'classes')
