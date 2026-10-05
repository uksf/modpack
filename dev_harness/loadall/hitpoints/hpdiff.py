# Compare resolved hitpoints before/after; every removal must be a planned candidate.
import collections, json

def load(f):
    d = collections.defaultdict(str)
    for l in open(f, encoding='latin1'):
        q = l.rstrip('\n').split('|', 2)
        if q[1] != '<done>':
            d[q[1]] += q[2]
    return {k: collections.Counter(v.split(',')) for k, v in d.items()}

def turrets(f):
    d = collections.defaultdict(str)
    for l in open(f, encoding='latin1'):
        q = l.rstrip('\n').split('|', 2)
        if q[1] != '<done>': d[q[1]] += q[2]
    return {k: [e for e in v.split(',') if e.startswith('T/')] for k, v in d.items()}

tb, ta = turrets('hp_before.txt'), turrets('hp_after.txt')
changed = [c for c in set(tb) | set(ta) if tb.get(c, []) != ta.get(c, [])]
print('classes whose turret list or order changed', len(changed), changed[:8])
b, a = load('hp_before.txt'), load('hp_after.txt')
cand = collections.defaultdict(collections.Counter)
for c, p, n, _ in json.load(open('dupcand.json')):
    cand[c]['/' + p + ':' + n if p else ':' + n] += 1
planned_ok, unplanned, added, untouched = 0, collections.defaultdict(list), collections.defaultdict(list), 0
for c in set(b) | set(a):
    bb, aa = b.get(c, collections.Counter()), a.get(c, collections.Counter())
    gone, new = bb - aa, aa - bb
    for e, k in gone.items():
        if e.startswith('T/'): continue
        if cand[c][e] >= k: planned_ok += k
        else: unplanned[c].append(e)
    for e in new: added[c].append(e)
left = sum(1 for c in cand for e, k in cand[c].items() if (b.get(c, collections.Counter())[e] - a.get(c, collections.Counter())[e]) < k)
print('planned removals done', planned_ok, '| candidates left', left)
print('classes with unplanned removals', len(unplanned), '| classes with additions', len(added))
for c in list(unplanned)[:15]: print('  -', c, unplanned[c][:6])
for c in list(added)[:10]: print('  +', c, added[c][:6])
# Order: the before sequence without the planned removals must equal the after sequence.
def seq(f):
    d = collections.defaultdict(str)
    for l in open(f, encoding='latin1'):
        q = l.rstrip('\n').split('|', 2)
        if q[1] != '<done>': d[q[1]] += q[2]
    return {k: [e for e in v.split(',') if e] for k, v in d.items()}
sb, sa = seq('hp_before.txt'), seq('hp_after.txt')
reordered = []
for c in sb:
    left = collections.Counter({e: k for e, k in cand[c].items()})
    kept = []
    for e in sb[c]:
        if left[e] > 0 and e not in sa.get(c, []): left[e] -= 1; continue
        if left[e] > 0 and sb[c].count(e) > sa.get(c, []).count(e): left[e] -= 1; continue
        kept.append(e)
    if kept != sa.get(c, []) and c not in unplanned and c not in added:
        reordered.append(c)
print('classes with other order changes', len(reordered), reordered[:8])
json.dump({'unplanned': unplanned, 'added': added, 'reordered': reordered}, open('hpdiff.json', 'w'))
