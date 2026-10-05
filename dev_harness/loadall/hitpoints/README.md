# Removing dead duplicate turret hitpoints

Generates `addons/common/common_compat_hitpoints`. The engine logs `Duplicate HitPoint name` on every spawn of a
vehicle whose turrets repeat `HitTurret`, `HitGun` or `HitCommanderTurret`. Most copies name a selection that the
model's HitPoints LOD does not have, so they never take damage. The patch removes those copies. Where every copy is
dead, the first turret copy stays, because the engine links it to that turret. Live copies are never touched.

Run from this folder with the load-all RPTs in `../out/rpt`. Each probe runs with
`../../client/run.js <probe> --mods ../out/mods.txt`; keep its tagged RPT lines in the named file. Probes marked
"before" must run on a build WITHOUT `common_compat_hitpoints`.

1. `dups.txt`: every `Duplicate HitPoint name '<n>' in '<class>'` line from the RPTs, unique.
2. `duphp.sqf` (`__LIST__` = the classes from step 1) -> `dupdata.txt` (`DH|DV|DM|DS` lines): turret and vehicle
   hitpoints, models, HitPoints LOD selections.
3. `python dupcand.py` -> `dupcand.json`: the copies to remove.
4. `python dupown_gen.py`, run `dupown.sqf` (before) -> `dupown.txt`: owner of each copy and of its turret.
5. `hpown.sqf` (before) -> `hpown.txt`: owners of every such entry in every class, for the exact reach check.
   An ancestor-chain probe over the classes in `hpown.txt` -> `ancall.txt` (`AN|class,parent,...`).
6. `python dupplan.py x` -> `dupactions.json`. `delete` where the entry is local to the HitPoints at its own
   turret path and nothing that keeps it shares it; `class HitPoints {};` on a leaf class's turret where all of
   that turret's hitpoints go. Owners in `excl_owners.txt` are skipped: uksf_air re-parents them, and the modpack
   cannot load after uksf_air.
7. `python dupgen.py gendup` until it exits 0, running the `nodes.sqf` it writes (before) and appending its
   `NP|`/`NC|` lines to `parents.txt` each time.
8. A `configSourceAddonList` probe over the top-level classes in `gendup/` -> `srcadd.txt`, then
   `python dupaddon.py <modpack root>`.
9. Check: `hpall.sqf` before -> `hp_before.txt`, after -> `hp_after.txt`, `python hpdiff.py`. Turret lists and
   order, unplanned removals and other order changes must all be 0, and the startup RPT must have no
   `Updating base class` line from `uksf_common_compat_hitpoints`. If `hpdiff.py` reports unplanned removals,
   `python dupblame.py` adds the actions that can explain them to `dupexclude.json`; go back to step 6.

Engine rules the generator keeps:
- A Turrets class builds only the turrets it holds itself. Re-opening an inherited Turrets in a subclass therefore
  re-declares every turret, in the original order (`class X : X {};`). That is done only on leaf classes, or a
  child's own Turrets would be re-parented.
- A patch that re-declares some turrets of an existing Turrets moves them to the front. In an existing Turrets the
  unchanged turrets are therefore declared as forward references only.
- Every re-opened class keeps the parent the game reports, so nothing is re-parented. Names keep the game's spelling.
