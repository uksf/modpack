# Attributes every runtime RPT line from a drive.js run to the class being created and the PBO that owns it.
#   python analyse.py   (needs out/rpt/*.rpt, out/pbomap.json, managed.json) -> out/issues.json, out/models.json, out/report.md
import collections, glob, json, re

pbomap = json.load(open('out/pbomap.json'))
managed_cfg = json.load(open('managed.json'))
MANAGED_FOLDERS = set(managed_cfg['folders'])
MANAGED_PBOS = {p.lower() for p in managed_cfg['pbos']}
PREFIXES = sorted((o for o in pbomap if o['prefix']), key=lambda o: -len(o['prefix']))
BY_PATCH = {p.lower(): o for o in pbomap for p in o['patches']}

LA = re.compile(r'\[vclient\] LA\|L\|(\w+)\|(\d+)\|([^|]+)\|(.*)$')
TS = re.compile(r'^\s?\d{1,2}:\d{2}:\d{2}\s')
PATH = re.compile(r'([A-Za-z0-9_\\/.@-]+\.(?:p3d|rvmat|paa|rtm|wss|ogg|bisurf|sqf))', re.I)
# The loader's own noise: classes that cannot be created this way, and continuation lines of a warning.
HARNESS = re.compile(r'uksf_vclient|LA_SKIP|call vc_fnc_log;|Cannot create non-ai vehicle|Cannot create entity with abstract type|'
                     r'Vehicles with brain cannot be created|with scope=private|^\s*\S*\s*Context: |^->Last modified by|'
                     r'^\[\] L\d+ \(|Error position: |^File .*, line \d+', re.I)
CATEGORIES = [  # (name, fix route, regex)
    ('missing config entry', 'config', r'No entry|is not a value|not an array'),
    ('animation source unknown to config', 'config', r'unknown animation source|Animation source .* not found'),
    ('duplicate HitPoint name', 'config', r'Duplicate HitPoint'),
    ('animation source cannot reach hitpoint', 'config', r'unable to connect anim'),
    ('unit loadout does not fit or item missing', 'config', r"weren't stored|Inventory item with given name|Weapon magazine with given name"),
    ('identity without speaker', 'config', r'No speaker given'),
    ('particle expression error', 'config', r'Error during (evaluation|compilation)|Undefined variable in expression'),
    ('PhysX wheels, gearbox, turret selections', 'config', r'Wheel|gearbox|Turret (body|gun)'),
    ('string missing', 'config', r'String \w+ not found'),
    ('memory point missing', 'config or model', r'point|Render target'),
    ('selection id wrong for shape', 'model', r'SelectionID'),
    ('p3d class property without config class', 'model', r'config class missing'),
    ('geometry LOD', 'model', r'convex|component|Degenerated|normal|invalid uv|UV coordinate|UVSet|Axis has less'),
    ('skeleton and bones', 'model', r'bone|skeleton|weights'),
    ('material and texture', 'model', r'rvmat|\.paa|uvSource|Fresnel|texture|surface info'),
    ('mod script log', 'info', r'^\[(ACE|ACRE|CBA|UKSF)\]'),
    ('other', '?', r'.'),
]


def owner_of_path(path):
    p = path.lower().replace('/', '\\').lstrip('\\')
    for o in PREFIXES:
        if p.startswith(o['prefix'] + '\\'):
            return o
    if p.startswith(('a3\\', 'ca\\')):
        return {'mod': 'vanilla', 'pbo': p.split('\\')[1]}
    return None


def status(o):
    if not o:
        return 'unknown'
    if o['mod'] == 'vanilla':
        return 'vanilla'
    if o['mod'] in MANAGED_FOLDERS:
        return 'managed'
    if o['mod'] == '@uksf_dependencies':
        return 'managed' if o['pbo'].lower() in MANAGED_PBOS else 'unmanaged'
    return 'uksf'


def template(line):
    t = re.sub(r"'[^']*'|\"[^\"]*\"", "'*'", line)
    t = PATH.sub('<file>', t)
    t = re.sub(r'\b\d+(\.\d+)?\b', 'N', t)
    return re.sub(r'\b\w*_\w*\b', '<id>', t).strip()[:140]


issues = collections.defaultdict(lambda: {'n': 0, 'classes': collections.Counter(), 'ex': collections.Counter()})
models = collections.defaultdict(lambda: {'cats': collections.Counter(), 'ex': {}})
harness = 0
CONTEXT = re.compile(r'Context: bin\\config\.bin/(Cfg\w+)/([^/.]+)')
MODIFIED = re.compile(r'^->Last modified by: ([^\s,<]+)')


def record(line, cls, o):
    cat, route = next((c, r) for c, r, rx in CATEGORIES if re.search(rx, line, re.I))
    pth = PATH.search(line)
    if pth:
        o = owner_of_path(pth.group(1)) or o
    key = (cat, route, template(line), (o or {}).get('mod', '?'), (o or {}).get('pbo', '?'), status(o))
    r = issues[key]
    r['n'] += 1
    r['ex'][line[:260]] += 1
    if cls:
        r['classes'][cls] += 1
    if pth and pth.group(1).lower().endswith('.p3d') and route in ('model', 'config or model'):
        mm = models[pth.group(1).lower().lstrip('\\')]
        mm['cats'][cat] += 1
        mm['ex'].setdefault(cat, line[:220])


for f in sorted(glob.glob('out/rpt/*.rpt')):
    cur, started, pending = None, False, None
    for raw in open(f, encoding='latin1'):
        line = TS.sub('', raw.rstrip('\n'))
        # A config warning names its class on the next two lines: Context, then Last modified by <definer>,...
        if pending:
            c, mo = CONTEXT.search(line), MODIFIED.search(line.strip())
            if c:
                pending[1] = c.group(2)
                continue
            if mo:
                record(pending[0], pending[1], BY_PATCH.get(mo.group(1).lower()))
                pending = None
                continue
            record(pending[0], pending[1], BY_PATCH.get(cur[1].lower()) if cur else None)
            pending = None
        m = LA.search(raw)
        if m:
            cur, started = (m.group(3), m.group(4)), True
            continue
        if not started or '[vclient]' in raw or not line.strip():
            continue
        if HARNESS.search(line):
            harness += 1
            continue
        if line.startswith('Warning Message:') and not PATH.search(line):
            pending = [line, cur[0] if cur else None]
            continue
        record(line, cur[0] if cur else None, BY_PATCH.get(cur[1].lower()) if cur else None)

rows = [{'category': k[0], 'route': k[1], 'template': k[2], 'mod': k[3], 'pbo': k[4], 'status': k[5], 'lines': v['n'],
         'classes': len(v['classes']), 'exampleClasses': [c for c, _ in v['classes'].most_common(5)],
         'examples': [l for l, _ in v['ex'].most_common(3)]} for k, v in issues.items()]
rows.sort(key=lambda r: -r['lines'])
json.dump(rows, open('out/issues.json', 'w'), indent=1)
mrows = []
for p, v in models.items():
    o = owner_of_path(p)
    mrows.append({'p3d': p, 'mod': (o or {}).get('mod', '?'), 'pbo': (o or {}).get('pbo', '?'), 'status': status(o),
                  'categories': dict(v['cats']), 'examples': v['ex']})
mrows.sort(key=lambda r: (r['status'], r['mod'], r['p3d']))
json.dump(mrows, open('out/models.json', 'w'), indent=1)

# report.md: categories by owner status, then top owners per category.
STATUSES = ['uksf', 'unmanaged', 'managed', 'vanilla', 'unknown']
cat_tot = collections.defaultdict(collections.Counter)
cat_own = collections.defaultdict(collections.Counter)
for r in rows:
    cat_tot[(r['category'], r['route'])][r['status']] += r['lines']
    cat_own[r['category']][f"{r['mod']}/{r['pbo']} ({r['status']})"] += r['lines']
md = [f'# Load-all RPT report\n\nClasses created: {len({c for r in rows for c in r["exampleClasses"]})}+ (see drive.log). '
      f'Lines dropped as loader noise: {harness}.\n',
      '| Category | Fix route | ' + ' | '.join(STATUSES) + ' |', '|---|---|' + '---|' * len(STATUSES)]
for (c, route), cnt in sorted(cat_tot.items(), key=lambda kv: -sum(kv[1].values())):
    md.append(f'| {c} | {route} | ' + ' | '.join(str(cnt.get(s, 0)) for s in STATUSES) + ' |')
for (c, _), _ in sorted(cat_tot.items(), key=lambda kv: -sum(kv[1].values())):
    md.append(f'\n## {c}\n')
    md += [f'- {n} {o}' for o, n in cat_own[c].most_common(12)]
mst = collections.Counter(m['status'] for m in mrows)
md.append(f'\n## Models needing model-side fixes\n\n{len(mrows)} p3d files: ' + ', '.join(f'{s} {mst[s]}' for s in STATUSES if mst[s]))
open('out/report.md', 'w', encoding='utf-8').write('\n'.join(md) + '\n')
print('\n'.join(md[:30]))
