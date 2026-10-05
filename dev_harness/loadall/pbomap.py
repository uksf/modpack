# Maps every PBO of a mod set to its prefix and CfgPatches names: python pbomap.py <mods.txt> -> out/pbomap.json
import glob, json, os, struct, sys

ARMA = 'B:/Steam/steamapps/common/Arma 3'


def cstr(b, i):
    j = b.index(b'\0', i)
    return b[i:j].decode('latin1'), j + 1


def read_pbo(path):
    with open(path, 'rb') as f:
        head = f.read(4 * 1024 * 1024)
    i, props, entries = 0, {}, []
    while True:
        name, i = cstr(head, i)
        mime, orig, _, _, size = struct.unpack_from('<5I', head, i)
        i += 20
        if name == '' and mime == 0x56657273:  # 'Vers' entry carries the header properties
            while True:
                k, i = cstr(head, i)
                if not k:
                    break
                props[k], i = cstr(head, i)
            continue
        if name == '':
            return props, entries, i
        entries.append((name, mime, orig, size))


def config_bin(path, entries, offset):
    for name, mime, orig, size in entries:
        if name.lower() == 'config.bin':
            if mime != 0 and orig != size:
                return None  # compressed
            with open(path, 'rb') as f:
                f.seek(offset)
                return f.read(size)
        offset += size
    return None


def patches(b):
    """First-level class names under CfgPatches in a rapified config."""
    if not b or b[:4] != b'\0raP':
        return []

    def cint(i):
        v = s = 0
        while True:
            c = b[i]
            i += 1
            v |= (c & 0x7f) << s
            s += 7
            if c < 0x80:
                return v, i

    def skip_array(i):
        k, i = cint(i)
        for _ in range(k):
            t = b[i]
            i += 1
            if t == 0:
                _, i = cstr(b, i)
            elif t == 3:
                i = skip_array(i)
            else:
                i += 4
        return i

    def body(off):
        _, i = cstr(b, off)
        n, i = cint(i)
        out = []
        for _ in range(n):
            t = b[i]
            i += 1
            if t == 0:
                name, i = cstr(b, i)
                out.append((name, struct.unpack_from('<I', b, i)[0]))
                i += 4
            elif t == 1:
                sub = b[i]
                _, i = cstr(b, i + 1)
                i = cstr(b, i)[1] if sub == 0 else i + 4
            elif t in (2, 5):
                _, i = cstr(b, i + (4 if t == 5 else 0))
                i = skip_array(i)
            else:
                _, i = cstr(b, i)
        return out

    for name, off in body(16):
        if name.lower() == 'cfgpatches':
            return [n for n, _ in body(off)]
    return []


def main():
    mods = [l.strip() for l in open(sys.argv[1]) if l.strip() and not l.startswith('#')]
    files = [(os.path.basename(m.rstrip('/\\')), p) for m in mods for p in glob.glob(os.path.join(m, '**', '*.pbo'), recursive=True)]
    files += [('vanilla', p) for p in glob.glob(os.path.join(ARMA, '*', 'Addons', '*.pbo')) + glob.glob(os.path.join(ARMA, 'Addons', '*.pbo'))
              if '@' not in p and 'uksf' not in p.lower()]
    out = []
    for mod, p in files:
        try:
            props, entries, offset = read_pbo(p)
            out.append({'mod': mod, 'pbo': os.path.basename(p), 'prefix': props.get('prefix', '').lower().strip('\\'),
                        'patches': patches(config_bin(p, entries, offset))})
        except Exception as e:
            out.append({'mod': mod, 'pbo': os.path.basename(p), 'prefix': '', 'patches': [], 'error': str(e)})
    os.makedirs('out', exist_ok=True)
    json.dump(out, open('out/pbomap.json', 'w'), indent=0)
    print(len(out), 'pbos,', sum(1 for o in out if o['patches']), 'with CfgPatches,', sum(1 for o in out if 'error' in o), 'unreadable')


if __name__ == '__main__':
    main()
