# Add every action that could explain an unplanned removal to dupexclude.json.
import json
anc = {}
for l in open('ancall.txt', encoding='latin1'):
    chain = l.rstrip('\n').split('|', 1)[1].split(',')
    anc[chain[0]] = set(chain)
un = json.load(open('hpdiff.json'))['unplanned']
acts = json.load(open('dupactions.json'))
ex = set(json.load(open('dupexclude.json')))
new = set()
for c, entries in un.items():
    A = anc.get(c, {c})
    for e in entries:
        path, name = e.rsplit(':', 1)
        path = path.lstrip('/')
        for a in acts:
            kind, owner, apath, aname = a
            if owner not in A:
                continue
            if kind == 'delete' and aname.lower() == name.lower():
                new.add('|'.join(a))
            elif kind == 'shadow' and (apath.lower() == path.lower() or path.lower().startswith(apath.lower() + '/')):
                new.add('|'.join(a))
print('newly excluded', len(new - ex), 'total', len(ex | new))
json.dump(sorted(ex | new), open('dupexclude.json', 'w'))
