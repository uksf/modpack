# Load every class

Creates every config class of the loaded mod set in a real client, then attributes each RPT line to the
class being created and to the PBO that owns it. Use it to expose config and model errors that only show
when an object is spawned.

```bash
cd dev_harness/loadall
node drive.js out/mods.txt 5        # about 20 min for ~60,000 classes on 5 clients
python pbomap.py out/mods.txt       # PBO -> prefix and CfgPatches names
python analyse.py                   # out/report.md, out/issues.json, out/models.json
```

Copy `mods.example.txt` to `out/mods.txt`. It uses the same format as `../client/mods/*.txt`. Point the `@uksf` and `@uksf_air` lines at the
builds under test.

## What it loads

| Phase | Classes | How |
|---|---|---|
| `veh` | CfgVehicles except men and logic | `createVehicle`, 100 per batch |
| `man` | CAManBase | `createUnit`, AI off |
| `logic` | Logic and modules | `createVehicle`, run last |
| `wpn` | CfgWeapons | ground weapon holder; vehicle weapons (`type` 65536) via `addWeapon` on a helper vehicle |
| `mag`, `glasses` | CfgMagazines, CfgGlasses | ground weapon holder |
| `ammo` | CfgAmmo | `createVehicle` at 60 m |
| `nonai` | CfgNonAIVehicles | `createSimpleObject` of the model |

No scope or model filter. Scope 0 classes, units created with `createVehicle` and scope-private weapons log
"cannot create" lines; `analyse.py` drops those as loader noise.

## Behaviour

- Each client uses its own profile (`VC_PROFILE`): two clients cannot share one profile, and clients launched
  in the same second cannot find their RPT, so starts are 20 s apart.
- Arma keeps only 10 RPTs. `drive.js` copies each RPT into `out/rpt/` while it is written.
- A class that crashes the client goes to `out/crashes.txt`. The slice resumes after it, and later runs skip it.
- Warnings printed while a batch renders land on the last class of that batch. Lines with a file path are
  attributed by path, and config warnings by their `Last modified by` line, so ownership stays exact.

## Ownership

`managed.json` lists what the website's Workshop system manages: whole mod folders, and PBOs inside
`@uksf_dependencies`. Regenerate it from prod `workshopMods` (`pbos`; an empty list means the whole folder)
before each run. A managed PBO must not be edited, because the next Workshop update replaces it. Fix it from
a UKSF addon instead.
