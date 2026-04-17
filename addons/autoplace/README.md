# Autoplace

`autoplace` is a server-side Eden module that populates an area with AI using `CBA_BuildingPos` helpers, optional static-weapon gunners, and optional patrol groups.

## Flow

`fnc_moduleAutoplace` -> `fnc_runAutoplace` orchestrates:

1. Read and sanitize module attributes.
2. Gather and deduplicate building helper positions.
3. Apply `coveragePercent` reduction:
   - Shuffle once.
   - Resize to target count.
4. Optionally occupy empty statics.
5. Spawn garrisons with rolling PFH pacing.
6. Optionally spawn patrols.

No orchestration state is relayed via `setVariable`; state is passed through callback args.

## Spatial Grouping

Shared helper: `fnc_takeChunk`

- `MAX_GROUP_SIZE = 10`
- `MAX_CHUNK_RADIUS = 150` meters

Chunking behavior:

1. Remove first position as seed.
2. Collect nearby positions within radius, sorted by `distance2D`.
3. Take up to `MAX_GROUP_SIZE - 1` neighbors.
4. Remove selected neighbors from source list.
5. Reorder chunk so centroid-nearest member is index `0` (leader spawn point).

The same chunking logic is used for garrison groups and static-occupancy groups.

## Garrison Spawn Pacing

`fnc_spawnGarrisons` uses one PFH (`delay = 0`) and performs one unit creation per tick.

- If `diag_fps < 20`, spawn rate backs off to at most once every 0.5s.
- Uses `createUnit ... "CAN_COLLIDE"` to avoid nearest-free-position displacement.
- Always follows with `setPosATL` and applies helper direction.
- Stops immediately if logic is null.
- Fires completion callback once all positions/chunks are consumed.

## Patrols

`fnc_spawnPatrols` runs `N` iterations of `EFUNC(common,spawnGroupInfantry)` and assigns `EFUNC(common,taskPatrol)` in an inline callback.

Patrol spawn positions are randomized inside the module area (ellipse or rectangle, including area angle).

## Notes / Caveats

- In very sparse layouts, many small groups can be created temporarily.
- This is expected: virtualisation should reclaim engine group slots quickly during sweep cycles.
- Worst case is players already near the spawn zone at mission start.
