import re
import sys

src, dst = sys.argv[1], sys.argv[2]
lines = open(src, encoding="latin-1").read().split("\n")

head_end = next(i for i, l in enumerate(lines) if l == "class CfgVehicles {")
tail_start = max(i for i, l in enumerate(lines) if l == "};")
body = lines[head_end + 1:tail_start]

decl_re = re.compile(r"^    class (\w+);$")
open_re = re.compile(r"^    class (\w+)(?::\s*(\w+))?\s*\{")
blocks = {}
order = []
forwards = []
i = 0
while i < len(body):
    line = body[i]
    m = decl_re.match(line)
    if m:
        forwards.append(m.group(1))
        i += 1
        continue
    m = open_re.match(line)
    if m:
        j = i
        while body[j] != "    };":
            j += 1
        blocks[m.group(1)] = (m.group(2), body[i:j + 1])
        order.append(m.group(1))
        i = j + 1
        continue
    if line.strip():
        raise SystemExit(f"unexpected line {i}: {line}")
    i += 1

emitted = set()
out_body = [
    "    class HouseBase;",
    "    class House: HouseBase {",
    "        class DestructionEffects;",
    "    };",
]
emitted.add("House")
external = {"Land_HouseV2_04": "Land_HouseV2_01A"}


def emit(name):
    if name in emitted:
        return
    if name in external:
        emit(external[name])
        out_body.extend([
            f"    class {name}: {external[name]} {{",
            "        class DestructionEffects;",
            "    };",
        ])
        emitted.add(name)
        return
    base, block = blocks[name]
    if base:
        emit(base)
    out_body.extend(block)
    emitted.add(name)


for name in order:
    emit(name)
unknown = [f for f in forwards if f not in emitted]
if unknown:
    raise SystemExit(f"unresolved forward declarations: {unknown}")

nested_re = re.compile(r"^(\s+)class (\w+)(?::\s*(\w+))?\s*\{\s*(\};)?$")
prop_re = re.compile(r"^\s+(\w+)(\[\])?\s*=")
restore = [
    (re.compile(r"^BrokenGlass\d+S?$"), "BrokenGlass1"),
    (re.compile(r"^Door_[2-9]_sound_source$"), "Door_1_sound_source"),
    (re.compile(r"^OpenDoor_[2-9]$"), "OpenDoor_1"),
]


def props_of(block_lines):
    depth = 0
    props = set()
    for l in block_lines[1:]:
        if depth == 0:
            p = prop_re.match(l)
            if p:
                props.add(p.group(1))
        depth += l.count("{") - l.count("}")
    return props


def class_span(lines_, start):
    depth = 0
    for k in range(start, len(lines_)):
        depth += lines_[k].count("{") - lines_[k].count("}")
        if depth == 0:
            return k
    raise SystemExit("unbalanced")


restored = 0
skipped = []
siblings = {}
for k, l in enumerate(out_body):
    m = nested_re.match(l)
    if not m or m.group(4):
        continue
    indent, name, base = m.group(1), m.group(2), m.group(3)
    siblings[(indent, name)] = k
    if base:
        continue
    for pattern, want in restore:
        if not pattern.match(name) or name == want:
            continue
        ref = siblings.get((indent, want))
        if ref is None or ref > k:
            skipped.append((k, name, "no sibling"))
            break
        base_props = props_of(out_body[ref:class_span(out_body, ref) + 1])
        own_props = props_of(out_body[k:class_span(out_body, k) + 1])
        if not base_props <= own_props:
            skipped.append((k, name, sorted(base_props - own_props)))
            break
        out_body[k] = f"{indent}class {name}: {want} {{"
        restored += 1
        break

text = "\n".join(lines[:head_end + 1] + out_body + lines[tail_start:])
text = text.replace(
    'requiredAddons[] = {"A3_Structures_F_Enoch", "CABuildings"};',
    'requiredAddons[] = {"A3_Structures_F_Enoch", "CABuildings", "CAStructuresHouse_HouseV", "CAStructuresHouse_HouseV2", "CAStructuresHouse_Church_02"};',
)
open(dst, "w", encoding="latin-1", newline="\n").write(text)
print("blocks", len(order), "emitted", len(emitted), "restored", restored, "skipped", len(skipped))
for s in skipped[:10]:
    print(s)
