# Offline lookups in the Arma config dump. python cfg.py <cmd> ...
#   block <path> [maxlines]     resolved-as-written block of one class path (e.g. CfgVehicles/X/Turrets)
#   kids <CfgRoot> <class>      classes whose parent chain includes <class>, with scope
#   grep <regex> [max]          dump lines matching regex, with class path
import os, pickle, re, sys

DUMP = 'B:/Steam/steamapps/common/Arma 3/@cache/config_5.23.13.cpp'
IDX = os.path.join(os.path.dirname(__file__), 'cfg.idx')
sys.stdout.reconfigure(encoding='utf-8', errors='replace')
L = open(DUMP, encoding='latin1').read().split('\n')
if os.path.exists(IDX):
    spans, parents, paths = pickle.load(open(IDX, 'rb'))
else:
    stack, spans, parents, paths = [], {}, {}, [None] * len(L)
    for i, l in enumerate(L):
        m = re.match(r'\s*class (\w+)\s*(?::\s*(\w+))?\s*\{', l)
        if m:
            stack.append((m.group(1), i))
            p = '/'.join(n for n, _ in stack)
            parents[p.lower()] = m.group(2) or ''
            paths[i] = p
            if l.rstrip().endswith('};'):
                spans[p.lower()] = (i, i); stack.pop()
            continue
        paths[i] = '/'.join(n for n, _ in stack)
        if re.match(r'\s*\};', l) and stack:
            spans['/'.join(n for n, _ in stack).lower()] = (stack[-1][1], i); stack.pop()
    pickle.dump((spans, parents, paths), open(IDX, 'wb'))

cmd = sys.argv[1]
if cmd == 'block':
    s, e = spans[sys.argv[2].lower()]
    print('\n'.join(L[s:min(e + 1, s + int(sys.argv[3]) if len(sys.argv) > 3 else e + 1)]))
elif cmd == 'kids':
    root, base = sys.argv[2], sys.argv[3].lower()
    top = {p.split('/')[1]: par for p, par in parents.items() if p.count('/') == 1 and p.startswith(root.lower() + '/')}
    def chain(c):
        seen = []
        while c and c not in seen:
            seen.append(c); c = top.get(c, '').lower()
        return seen
    for c in sorted(top):
        if base in chain(c)[1:]:
            s, e = spans[f'{root.lower()}/{c}']
            sc = next((x.strip() for x in L[s:e] if re.match(r'\t\t\tscope\s*=', x)), '')
            print(c, ':', top[c], '|', sc)
elif cmd == 'grep':
    rx, mx = re.compile(sys.argv[2]), int(sys.argv[3]) if len(sys.argv) > 3 else 50
    n = 0
    for i, l in enumerate(L):
        if rx.search(l):
            print(i + 1, paths[i], '|', l.strip()[:160]); n += 1
            if n >= mx: break
