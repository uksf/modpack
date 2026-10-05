# How do classes that DO define each missing source name define it? -> learned.json
import re, json, pickle, collections
DUMP = 'B:/Steam/steamapps/common/Arma 3/@cache/config_5.23.13.cpp'
L = open(DUMP, encoding='latin1').read().split('\n')
spans, parents, paths = pickle.load(open('cfg.idx', 'rb'))
missing = {l.strip().split('|')[2].lower() for l in open('animsrc.txt') if l.count('|') >= 2}
defs = collections.defaultdict(collections.Counter)
for key, (s, e) in spans.items():
    parts = key.split('/')
    if len(parts) == 4 and parts[0] == 'cfgvehicles' and parts[2] == 'animationsources' and parts[3] in missing:
        props = {}
        for l in L[s + 1:e]:
            m = re.match(r'\s*(source|weapon|hitpoint|animPeriod|initPhase|raw|sound|soundPosition|minValue|maxValue)\s*=\s*"?([^";]*)"?;', l, re.I)
            if m:
                props[m.group(1).lower()] = m.group(2)
        sig = json.dumps({k: props[k] for k in sorted(props) if k in ('source', 'weapon', 'hitpoint', 'raw', 'animperiod', 'initphase')})
        defs[parts[3]][sig] += 1
out = {k: v.most_common(6) for k, v in defs.items()}
json.dump(out, open('learned.json', 'w'), indent=1)
print('missing names', len(missing), 'learned', len(out))
for k in sorted(missing - set(out))[:80]:
    print('  never defined:', k)
