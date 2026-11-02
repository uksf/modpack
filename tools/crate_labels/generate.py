import argparse
import re
import subprocess
import tempfile
import zlib
from pathlib import Path

import numpy as np
from PIL import Image, ImageDraw, ImageFilter, ImageFont

HERE = Path(__file__).parent
ROOT = HERE.parents[1]
CRATES = ROOT / "addons/resupply/crates"
DATA = ROOT / "addons/resupply/data"
FONT = "C:/Windows/Fonts/STENCIL.TTF"
PAINT = (226, 222, 205)
LONG_GOLFS = ("g3", "g4", "g7")
SKIPPED = ("rf",)

FAMILIES = {
    "romeo": {
        "base": "supplydrop_co.png",
        "items": [
            ("prefix", [98, 498, 280, 580], 90),
            ("suffix", [300, 498, 484, 580], -90),
            ("code", [124, 598, 236, 664], 0),
            ("contents", [348, 594, 464, 664], 0),
        ],
    },
    "golf": {
        "base": "ammobox_signs.png",
        "items": [
            ("code", [756, 806, 926, 890], 0, (833, 849)),
            ("contents", [756, 900, 926, 988], 0, (833, 849)),
            ("code", [423, 280, 593, 364], 0, (500, 517)),
            ("contents", [423, 374, 593, 470], 0, (500, 517)),
        ],
    },
    "golflong": {
        "base": "ammobox_signs.png",
        "items": [
            ("code", [26, 532, 288, 642], 0),
            ("contents", [333, 532, 596, 642], 0),
        ],
    },
    "med": {
        "base": "ace_medcrate.png",
        "erase": [[985, 1764, 1135, 1913], [818, 1698, 886, 1972]],
        "stamp": [([992, 1771, 1128, 1906], [950, 1668, 1045, 1763])],
        "items": [
            ("code", [945, 1770, 1045, 2036], 90),
            ("contents", [1052, 1672, 1185, 2036], 90),
            ("code", [362, 784, 466, 1136], 90),
            ("contents", [470, 784, 606, 1136], 90),
            ("code", [815, 1690, 892, 2030], 90),
        ],
    },
}


def crates():
    out = []
    for f in ["CfgRomeos.hpp", "CfgGolfs.hpp"]:
        text = (CRATES / f).read_text()
        for m in re.finditer(r"class GVAR\((\w+)\)[^{]*\{(.*?)\n\};", text, re.S):
            body = m.group(2)
            name = re.search(r'displayName = "([^"]+)"', body)
            stencil = re.search(r'GVAR\(stencil\) = "([^"]*)"', body)
            if name and stencil and m.group(1) not in SKIPPED:
                out.append((m.group(1), name.group(1).split(" ")[0], stencil.group(1).upper()))
    return out


def family(cls):
    if cls.startswith("g14"):
        return "med"
    if cls in LONG_GOLFS:
        return "golflong"
    if cls.startswith("r"):
        return "romeo"
    return "golf"


def splits(text):
    words = text.split()
    out = [[text]]
    for i in range(1, len(words)):
        out.append([" ".join(words[:i]), " ".join(words[i:])])
    return out


def bbox(t, f):
    return ImageDraw.Draw(Image.new("L", (1, 1))).textbbox((0, 0), t, font=f)


def render(text_lines, w, h, size=None):
    fixed = size is not None
    size = size or 400
    while True:
        f = ImageFont.truetype(FONT, size)
        gap = size * 0.12
        boxes = [bbox(t, f) for t in text_lines]
        tw = max(b[2] - b[0] for b in boxes)
        th = sum(b[3] - b[1] for b in boxes) + gap * (len(boxes) - 1)
        if fixed or (tw <= w and th <= h) or size <= 6:
            break
        size -= 2
    layer = Image.new("L", (w, h), 0)
    d = ImageDraw.Draw(layer)
    y = (h - th) / 2
    for t, b in zip(text_lines, boxes):
        d.text(((w - (b[2] - b[0])) / 2 - b[0], y - b[1]), t, font=f, fill=255)
        y += b[3] - b[1] + gap
    return layer, size


def render_best(text, w, h, many):
    if not many:
        return render([text], w, h)[0]
    return max((render(ls, w, h) for ls in splits(text)), key=lambda r: r[1])[0]


def split_line(t, f, left, right, words):
    best = None
    for k in range(1, len(t)):
        if words and t[k] != " ":
            continue
        a, b = t[:k].rstrip(), t[k:].lstrip()
        if not a or not b:
            continue
        wa, wb = bbox(a, f), bbox(b, f)
        la, lb = wa[2] - wa[0], wb[2] - wb[0]
        if la > left or lb > right:
            continue
        score = max(la, lb) * (0.85 if t[k - 1] == " " or t[k] == " " else 1) + abs(la - lb) * 0.01
        if best is None or score < best[0]:
            best = (score, a, b)
    return best and best[1:]


def split_fit(options, w, h, gap, words):
    g0, g1 = gap
    for size in range(400, 6, -2):
        f = ImageFont.truetype(FONT, size)
        for text_lines in options:
            parts = [split_line(t, f, g0, w - g1, words) for t in text_lines]
            if not all(parts):
                continue
            boxes = [bbox(t, f) for t in text_lines]
            line_gap = size * 0.12
            th = sum(b[3] - b[1] for b in boxes) + line_gap * (len(boxes) - 1)
            if th > h:
                continue
            layer = Image.new("L", (w, h), 0)
            d = ImageDraw.Draw(layer)
            y = (h - th) / 2
            for (a, b), lb in zip(parts, boxes):
                ba, bb = bbox(a, f), bbox(b, f)
                d.text((g0 - ba[2], y - lb[1]), a, font=f, fill=255)
                d.text((g1 - bb[0], y - lb[1]), b, font=f, fill=255)
                y += lb[3] - lb[1] + line_gap
            return layer, size
    if words:
        return None
    raise ValueError(f"cannot fit {options} into {w}x{h}")


def render_around_rib(options, w, h, gap):
    by_word = split_fit(options, w, h, gap, True)
    any_cut = split_fit(options, w, h, gap, False)
    layer = by_word[0] if by_word and by_word[1] >= 0.65 * any_cut[1] else any_cut[0]
    assert not np.asarray(layer)[:, gap[0] + 1:gap[1] - 1].any(), f"stencil crosses the rib: {options}"
    return layer


def erase(img, boxes, stamps):
    if not boxes:
        return img
    import cv2
    src = np.asarray(img).copy()
    rgb = src[..., :3]
    marks = (rgb.min(2) > 150) | ((rgb[..., 0] > 140) & (rgb[..., 1] < 90))
    hole = np.zeros(marks.shape, np.uint8)
    for u0, v0, u1, v1 in boxes:
        hole[v0:v1, u0:u1] = marks[v0:v1, u0:u1]
    hole = cv2.dilate(hole, np.ones((7, 7), np.uint8))
    out = src.copy()
    out[..., :3] = cv2.inpaint(np.ascontiguousarray(rgb), hole, 9, cv2.INPAINT_TELEA)
    res = Image.fromarray(out)
    for (a0, b0, a1, b1), (c0, d0, c1, d1) in stamps:
        patch = Image.fromarray(src[b0:b1, a0:a1]).resize((c1 - c0, d1 - d0), Image.LANCZOS)
        res.paste(patch, (c0, d0))
    return res


def stencil_mask(spec, size, code, cont):
    mask = Image.new("L", size, 0)
    lid = None
    for kind, box, rot, *gap in spec["items"]:
        if kind == "contents" and not cont:
            continue
        w, h = box[2] - box[0], box[3] - box[1]
        if kind in ("prefix", "suffix"):
            lid = lid or min(render([code[0]], h, w)[1], render([code[1:]], h, w)[1])
            text = code[0] if kind == "prefix" else code[1:]
            layer = render([text], h, w, lid)[0].rotate(rot, expand=True)
        elif gap:
            options = [[code]] if kind == "code" else splits(cont)
            layer = render_around_rib(options, w, h, (gap[0][0] - box[0], gap[0][1] - box[0]))
        elif rot:
            layer = render_best(code if kind == "code" else cont, h, w, kind == "contents").rotate(rot, expand=True)
        else:
            layer = render_best(code if kind == "code" else cont, w, h, kind == "contents")
        mask.paste(layer, box[:2], layer)
    return mask


def generate(cls, code, cont):
    spec = FAMILIES[family(cls)]
    img = Image.open(HERE / "bases" / spec["base"]).convert("RGBA")
    img = erase(img, spec.get("erase", []), spec.get("stamp", []))
    mask = stencil_mask(spec, img.size, code, cont)
    rng = np.random.default_rng(zlib.crc32(cls.encode()))
    noise = rng.random((img.size[1] // 4, img.size[0] // 4))
    noise = np.asarray(Image.fromarray((noise * 255).astype(np.uint8)).resize(img.size, Image.BILINEAR)) / 255
    m = np.asarray(mask.filter(ImageFilter.GaussianBlur(0.8))) / 255 * (0.78 + 0.2 * noise)
    a = np.asarray(img).astype(np.float32)
    shade = a[..., :3].mean(2, keepdims=True) / 128
    paint = np.array(PAINT, np.float32) * np.clip(0.75 + 0.25 * shade, 0.7, 1.05)
    a[..., :3] = a[..., :3] * (1 - m[..., None]) + paint * m[..., None]
    a[..., 3] = np.maximum(a[..., 3], m * 255)
    return Image.fromarray(a.clip(0, 255).astype(np.uint8))


def main():
    parser = argparse.ArgumentParser(
        description="Paint Romeo and Golf crate stencils from GVAR(stencil) in the crate configs and write the PAAs into addons/resupply/data. "
        "Run from the repo root: uv run --with pillow --with numpy --with opencv-python-headless python tools/crate_labels/generate.py"
    )
    parser.add_argument("classes", nargs="*", help="crate classes to regenerate, such as r1 g14ba; default all")
    parser.add_argument("--png", type=Path, help="write PNGs to this folder instead of PAAs into the addon")
    args = parser.parse_args()
    with tempfile.TemporaryDirectory() as tmp:
        for cls, code, cont in crates():
            if args.classes and cls not in args.classes:
                continue
            png = (args.png or Path(tmp)) / f"{cls}.png"
            png.parent.mkdir(parents=True, exist_ok=True)
            generate(cls, code, cont).save(png)
            print(cls, code, "|", cont)
            if args.png:
                continue
            paa = DATA / ("romeo" if cls.startswith("r") else "golf") / f"{cls}.paa"
            paa.unlink(missing_ok=True)
            subprocess.run(["hemtt", "utils", "paa", "convert", str(png), str(paa)], check=True, capture_output=True)


if __name__ == "__main__":
    main()
