import argparse
import re
from pathlib import Path

from PIL import Image

ROOT = Path(__file__).parents[2]
CRATES = ROOT / "addons/resupply/crates"
PREVIEWS = ROOT / "addons/resupply/data/previews"
SIZE = (455, 256)


def crate_classes():
    out = []
    for f in ["CfgRomeos.hpp", "CfgGolfs.hpp"]:
        out += re.findall(r"PREVIEW\((\w+)\);", (CRATES / f).read_text())
    return sorted(set(out))


def to_preview(png, jpg):
    im = Image.open(png).convert("RGB")
    w, h = im.size
    assert abs(w / h - 16 / 9) < 0.01, f"{png} is {w}x{h}, not 16:9; set a 16:9 window before exporting"
    im.resize(SIZE, Image.LANCZOS).save(jpg, "JPEG", quality=90)


def main():
    parser = argparse.ArgumentParser(
        description="Convert BIS_fnc_exportEditorPreviews PNGs of the Romeo and Golf crates into addons/resupply/data/previews. "
        "Export first with export_previews.sqf, using the video settings in README.md."
    )
    parser.add_argument("exported", type=Path, help="the <profile>\\Screenshots\\EditorPreviews folder, or its mod sub-folder")
    args = parser.parse_args()
    pngs = {p.stem.lower(): p for p in args.exported.rglob("uksf_resupply_*.png")}
    missing = []
    for cls in crate_classes():
        png = pngs.get(f"uksf_resupply_{cls}")
        if png is None:
            missing.append(cls)
            continue
        to_preview(png, PREVIEWS / f"uksf_resupply_{cls}.jpg")
        print(cls)
    if missing:
        raise SystemExit(f"no export for: {' '.join(missing)}")


if __name__ == "__main__":
    main()
