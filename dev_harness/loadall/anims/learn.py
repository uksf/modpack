# How do classes that DO define each missing source name define it? -> learned.json (as written locally) and
# learned_inherited.json (resolved), which gen_anims.py falls back to only where learned.json has no source.
# A source class's properties are resolved through its parents: a sibling in the same AnimationSources
# (class hide_ammo_cans: hide_rear_right_antenna) or the same name in the owner's parent AnimationSources.
import re, json, pickle, collections
DUMP = 'B:/Steam/steamapps/common/Arma 3/@cache/config_5.23.13.cpp'
L = open(DUMP, encoding='latin1').read().split('\n')
spans, parents, paths = pickle.load(open('cfg.idx', 'rb'))
missing = {l.strip().split('|')[2].lower() for l in open('animsrc.txt') if l.count('|') >= 2}
KEYS = ('source', 'weapon', 'hitpoint', 'raw', 'animperiod', 'initphase')
PROP = re.compile(r'\s*(source|weapon|hitpoint|animPeriod|initPhase|raw)\s*=\s*"?([^";]*)"?;', re.I)

def local(key):
    s, e = spans[key]
    props = {}
    for l in L[s + 1:e]:
        m = PROP.match(l)
        if m:
            props.setdefault(m.group(1).lower(), m.group(2))
    return props

def resolve(key, depth=0):
    # key: cfgvehicles/<cls>/animationsources/<src>
    props = local(key)
    if depth > 20:
        return props
    _, cls, _, src = key.split('/')
    par = parents.get(key, '').lower()
    if par:
        sib = f'cfgvehicles/{cls}/animationsources/{par}'
        if sib in spans and sib != key:
            return {**resolve(sib, depth + 1), **props}
    # the same-named or parent-named entry in the owner's parent class
    c = parents.get(f'cfgvehicles/{cls}', '').lower()
    name = par or src
    while c:
        k = f'cfgvehicles/{c}/animationsources/{name}'
        if k in spans:
            return {**resolve(k, depth + 1), **props}
        c = parents.get(f'cfgvehicles/{c}', '').lower()
    return props

defs, rdefs = collections.defaultdict(collections.Counter), collections.defaultdict(collections.Counter)
for key in spans:
    parts = key.split('/')
    if len(parts) == 4 and parts[0] == 'cfgvehicles' and parts[2] == 'animationsources' and parts[3] in missing:
        for props, d in ((local(key), defs), (resolve(key), rdefs)):
            d[parts[3]][json.dumps({k: props[k] for k in sorted(props) if k in KEYS})] += 1
for d, f in ((defs, 'learned.json'), (rdefs, 'learned_inherited.json')):
    json.dump({k: v.most_common(6) for k, v in d.items()}, open(f, 'w'), indent=1)
print('missing names', len(missing), 'learned', len(defs))
