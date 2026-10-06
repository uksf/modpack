# Wiring undeclared animation sources

Generates `addons/common/common_compat_anims/config.cpp` from a load-all run. A model.cfg animation whose
source no config declares logs `unknown animation source` and never moves. The generator wires each source on
the topmost class that uses the model, the way other mods wire the same source name.

Run from this folder, with the load-all RPTs in `../out/rpt`. Each probe is a template: replace `__LIST__`
with an SQF array of class names, then run it with `../../client/run.js <probe> --mods ../out/mods.txt`
and keep its `CD|`/`RT|`/`RI|`/`RP|`/`RS|`/`CH|` RPT lines. Build the modpack WITHOUT
`common_compat_anims` for the probes, or they read the patched config.

1. `animsrc.txt`: `class|anim|source`, from the RPT `unknown animation source` lines.
2. `dump.sqf` (classes from step 1) -> `classdata2.txt`: hitpoints, turrets, weapons.
3. `roots.sqf` (same classes) -> `rootdata.txt`: topmost class sharing the model (`RT`), its parent and
   AnimationSources facts (`RI`).
4. `roots2.sqf` (roots) -> `rootdata2.txt`: AnimationSources parent paths (`RP`) and existing sources (`RS`).
5. `python learn.py` -> `learned.json`: how the full config dump (`cfg.py`) defines each source name.
6. Window glass: for buildings whose model animates `glass_N_source` but whose config has no `HitPoints`, run
   `glassparents.sqf` -> `gp.txt` and `glass.sqf` -> `gl.txt` (the roots), then
   `python gen_glass.py ../../../addons/common/common_compat_glass`. It writes vanilla-style window hitpoints
   where the hit, `_effects` memory and fire-geometry selections all exist, and `extra_hitpoints.json`, which
   the next step reads so the glass sources are wired. `weapon_map.json` picks the weapon for sources whose
   name says which of several weapons drives them.
7. `python gen_anims.py gen.cpp` once, then `chain.sqf` (each parent the output declares with
   `class AnimationSources;`) -> `chaindata.txt`, then `python gen_anims.py gen.cpp` again.
8. Build, load the game, and check that the only `Updating base class` lines from
   `uksf_common_compat_anims` are `'AnimationSources'->'AnimationSources'` where a new intermediate block now
   carries the same parent. Put any other root in `exclude.txt` and regenerate.

Rules: a `Hit` source is wired only when every class under the root has that hitpoint; a weapon source only
when one weapon clearly matches; user sources copy the commonest definition. `AnimationSources` is declared only
on the class that owns it, with empty re-opens down to the root, so no class gains an entry it did not have.
`anims_report.json` lists what was not wired and why.
