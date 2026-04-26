# Autoplace

Server-side Eden module that populates a designated area with AI. Mission makers drop the **Autoplace** module, size and shape its area, choose a unit pool and side, and the module builds garrisons, optional static gunners and optional patrols at mission start.

## Design Intent

Missions can contain hundreds of building positions across many Autoplace modules, so the addon is built around three constraints:

1. **Engine group ceiling (288).** Autoplace will happily overshoot this during mission start. It relies on `uksf_virtualisation` to sweep and reclaim group slots. Caching alone keeps groups alive but still slotted, which is why Autoplace refuses to run when virtualisation is disabled — `fnc_runAutoplace` hard-exits with a warning if `EGVAR(virtualisation,enabled)` is false.
2. **Frame-time budget.** Every spawn phase that iterates many positions (garrisons, statics) uses a rolling per-frame handler that performs one chunk of work per tick and backs off when `diag_fps < 20`. No phase does a bulk spawn in a single frame.
3. **Spatial coherence.** Occupants should cluster into sensible groups, not form 288 one-man squads. `fnc_takeChunk` groups nearby positions together so a garrison reads like a squad garrisoning one building rather than unrelated bodies.

Orchestration state is carried through callback args — no `setVariable` relays between phases.

## Module Attributes

| Attribute | Purpose |
|-----------|---------|
| Unit List | Comma-separated classnames (in single quotes) to pull from when creating units |
| Side | OPFOR / Independent / BLUFOR |
| % of Coverage | Percentage of discovered building positions to actually populate; lower values produce sparser layouts |
| Patrols | Toggle patrol-group spawning |
| Number of Patrols | How many patrol groups when patrols are enabled |
| Patrol Radius | Waypoint radius around each patrol spawn point |
| Number of Soldiers in a Patrol | Patrol group size (1–10) |
| Occupy Empty Statics | When on, crew unoccupied static weapons inside the module area |

## Execution Flow

`fnc_moduleAutoplace` runs on the server, marks the logic as processed, and hands off to `fnc_runAutoplace`, which:

1. Reads and sanitises attributes; bails if unit list is empty or virtualisation is disabled.
2. Gathers deduplicated `CBA_BuildingPos` helpers via `fnc_gatherPositions`.
3. Applies `coveragePercent` by one-shot shuffle then resize.
4. If **Occupy Empty Statics** is on, runs `fnc_occupyStatics` and chains garrisons to its completion callback; otherwise skips straight to garrisons.
5. Runs `fnc_spawnGarrisons` over the collected positions.
6. If **Patrols** is on, runs `fnc_spawnPatrols` as the final phase from the garrisons' completion callback.

## Spatial Chunking (`fnc_takeChunk`)

Shared by garrisons and statics. Given a mutable list of position entries:

1. Pop the first entry as a seed.
2. Collect entries within `MAX_CHUNK_RADIUS` (150 m) of the seed, sorted by `distance2D`.
3. Take up to `MAX_GROUP_SIZE - 1` neighbours and remove them from the source list.
4. Reorder the chunk so the centroid-nearest member sits at index 0 (leader spawn point).

`MAX_GROUP_SIZE` is defined in `script_component.hpp` so the chunker and the patrol sizer agree on the same bound.

## Garrison Spawn Pacing (`fnc_spawnGarrisons`)

Single PFH at `delay = 0`. Each tick either picks up a new chunk (creating its group) or spawns one unit into the current chunk's group. `diag_fps < 20` throttles the PFH to at most one action per 0.5s. Units use `createUnit ... "CAN_COLLIDE"` then an explicit `setPosATL` + `setDir` so helper orientation is preserved and the engine does not push units to a nearest free position. The PFH removes itself when the position list and current chunk are both empty, and fires the completion callback.

## Static Occupancy (`fnc_occupyStatics`)

Same rolling-PFH shape as garrisons, one `takeChunk` per tick. Filters statics by `alive`, unoccupied gunner seat, and `objectInArea`. After `assignAsGunner` + `moveInGunner`, any unit that failed to become the gunner is deleted.

## Patrols (`fnc_spawnPatrols`)

Candidate spawn points come from `EFUNC(common,getSafePositionGrid)` with the module's area passed in, so the grid is generated inside the rotated rectangle/ellipse directly and positions on water or clipped into objects are filtered out. Each patrol then calls `EFUNC(common,spawnGroupInfantry)` with `cachingDisable = false` and `virtualisationExclude = false` — patrol groups deliberately stay eligible for both subsystems so they can be swept like any other transient AI. `EFUNC(common,taskPatrol)` is assigned in the completion callback.

Patrols do not apply the player-proximity filtering used by `fnc_dynamicPatrolSpawn`; Autoplace modules are authored geometry, so mission makers own where patrols appear relative to players.

## Failure Modes

- **Virtualisation disabled.** `fnc_runAutoplace` warns and returns. Nothing spawns.
- **Empty unit list.** `fnc_runAutoplace` warns and returns.
- **No safe patrol positions in area.** `fnc_spawnPatrols` warns and skips; garrisons/statics still complete.
- **Logic deleted mid-run.** All rolling PFHs check `isNull _logic` per tick and remove themselves cleanly.
