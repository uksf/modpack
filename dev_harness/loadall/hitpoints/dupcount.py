import collections, json
def load(f):
    d = collections.defaultdict(str)
    for l in open(f, encoding='latin1'):
        q = l.rstrip('\n').split('|', 2)
        if q[1] != '<done>': d[q[1]] += q[2]
    return d
for f in ['hp_before.txt', 'hp_after.txt']:
    d = load(f)
    n = cl = 0
    for c, s in d.items():
        names = collections.Counter(e.rsplit(':', 1)[1].lower() for e in s.split(',') if ':' in e)
        k = sum(v - 1 for v in names.values() if v > 1)
        n += k; cl += k > 0
    print(f, 'classes with duplicates', cl, 'duplicate entries', n)
