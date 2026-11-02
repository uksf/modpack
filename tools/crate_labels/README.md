# Crate labels and previews

The Romeo and Golf crate stencils and Eden previews come from the crate configs. To change a label, edit `GVAR(stencil)` in `addons/resupply/crates/CfgRomeos.hpp` or `CfgGolfs.hpp`. The crate code is the first word of `displayName`. An empty `GVAR(stencil)` paints the code only.

## Regenerate the stencil textures

Run from the repo root. The script needs the Stencil font at `C:/Windows/Fonts/STENCIL.TTF` and `hemtt` on the path.

```
uv run --with pillow --with numpy --with opencv-python-headless python tools/crate_labels/generate.py [r1 g16 ...]
```

The script writes `addons/resupply/data/<romeo|golf>/<class>.paa`. Add `--png <folder>` to write PNGs for review instead.

## Regenerate the Eden previews

Each crate has its own `PREVIEW(<class>)` line. The previews use the method in the BI wiki page "Eden Editor: Configuring Asset Previews".

1. Set these video settings before you export. The settings change the look of the previews.
   - A 16:9 window or resolution, with 100% sampling.
   - Brightness 0.5.
   - Object, texture, and shadow quality Very High or better.
   - FSAA 8x.
   - PPAA disabled.
   - Bloom 0.
   - Depth of field above 0, so that the ground plane and the shadow show.
   - `HDRPrecision=16` in `Arma3.cfg`.
2. Load the built modpack and open the Eden Editor on VR.
3. Run `tools/crate_labels/export_previews.sqf` in the debug console. The function writes PNGs to `<profile>\Screenshots\EditorPreviews`.
4. Convert the PNGs:

```
uv run --with pillow python tools/crate_labels/previews.py "<profile>\Screenshots\EditorPreviews"
```

The script writes `addons/resupply/data/previews/uksf_resupply_<class>.jpg` at 455x256 and stops if a crate has no export.
