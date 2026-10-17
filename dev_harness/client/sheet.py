#!/usr/bin/env python3
"""Labelled contact sheet of screenshots, for reading as one image.
usage: sheet.py <out.jpg> <png...> [--cols 3] [--width 2400] [--crop x0,y0,x1,y1 (fractions)]"""
import sys, math, os
from PIL import Image, ImageDraw, ImageFont

a = sys.argv[1:]
def opt(k, d):
    if k in a: i = a.index(k); v = a[i + 1]; del a[i:i + 2]; return v
    return d
cols, width, crop = int(opt('--cols', 3)), int(opt('--width', 2400)), opt('--crop', None)
out, files = a[0], a[1:]
ims = []
for f in files:
    im = Image.open(f).convert('RGB')
    if crop:
        x0, y0, x1, y1 = map(float, crop.split(',')); w, h = im.size
        im = im.crop((int(x0 * w), int(y0 * h), int(x1 * w), int(y1 * h)))
    ims.append((os.path.splitext(os.path.basename(f))[0], im))
cw = width // min(cols, len(ims)); ch = int(cw * ims[0][1].size[1] / ims[0][1].size[0])
rows = math.ceil(len(ims) / cols)
sheet = Image.new('RGB', (cw * min(cols, len(ims)), ch * rows), (30, 30, 30))
try: font = ImageFont.truetype('arialbd.ttf', max(14, cw // 28))
except OSError: font = ImageFont.load_default()
d = ImageDraw.Draw(sheet)
for k, (name, im) in enumerate(ims):
    x, y = k % cols * cw, k // cols * ch
    sheet.paste(im.resize((cw, ch), Image.LANCZOS), (x, y))
    d.text((x + 8, y + 6), name, fill=(255, 255, 0), font=font, stroke_width=2, stroke_fill=(0, 0, 0))
sheet.save(out, quality=88)
print(out, sheet.size)
