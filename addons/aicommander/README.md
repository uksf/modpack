# AI Commander (`addons/aicommander`) 

This addon currently implements a deterministic, module-driven battlefield controller.
The short version is:

1. `Objective` modules continuously evaluate local control state and maintain a force pool.
2. A `Commander` module periodically reads those objective snapshots.
3. The commander ranks objectives into action intents (`reinforce`, `attack`, `defend`, `recon`).
4. Intents are normalized into action requests, then converted into a bounded spawn queue.
5. A fast dispatcher drains that queue at a fixed cadence, spawning validated `CfgGroups` entries from a faction catalog.
6. Spawned groups are tracked as managed assets and sent toward their target objective.

The system is intentionally conservative: hard caps on concurrent actions, wave sizes, and total managed groups keep behavior predictable and prevent runaway spawning.

---

## Runtime Architecture

### Core runtime objects

- `GVAR(commanders)`: all initialized commander modules.
- `GVAR(objectives)`: all initialized objective modules.
- Per-commander state (key fields):
  - `side`, `managedGroups`, `managedGroupsCap`
  - `maxConcurrentActions` (currently fixed to `3` in `fnc_moduleCommander.sqf`)
  - `maxWave` (clamped to `1..3` at runtime)
  - `spawnQueue`, `actionRequests`, `groupCatalog`
  - `nextSpawnAt`, `spawnPhaseOffset`
- Per-objective state (key fields):
  - `objectiveName`, `priority`
  - `ownerSide`, `currentState`
  - `forcePoolGroups`, `forcePoolStartGroups`
  - `snapshot`
  - `safeSpawnPoints`

### Event/init flow

- `XEH_preInit.sqf`: initializes addon globals and preps functions.
- `XEH_postInit.sqf`: registers Zeus debug provider (`fnc_registerDebugProvider`).
- Module placement then drives runtime:
  - `fnc_moduleObjective`: initializes objective state + starts eval PFHs.
  - `fnc_moduleCommander`: initializes commander state + starts assess/dispatch PFHs.

---

## Objective Pipeline (`fnc_moduleObjective` -> `fnc_evalObjective`)

Each objective evaluates on `evalInterval` seconds (default `10`):

1. Read its area (`objectArea`) and count alive `CAManBase` units inside by side.
2. Compute state from side presence:
   - `not_owned`: no owner/no units
   - `owned_secure`: single-side control or preserved configured owner with no units
   - `contested`: multiple sides present
   - `contested_losing`: owner is present but enemy:friendly ratio exceeds `contestedLosingThreshold`
3. Persist snapshot hash map (`objectiveName`, counts, state, owner, force pool, timestamp).
4. Refresh safe spawn points periodically (default every `180s`) via `fnc_refreshObjectiveSafeSpawns`.

Safe spawn points are sampled inside objective area and filtered away from water, terrain obstacles, and clustered duplicates.

---

## Commander Pipeline

### 1) Commander initialization (`fnc_moduleCommander`)

After a short delay (`10s`) the commander:

- Builds faction group catalog (`fnc_buildGroupCatalog`).
- Refreshes managed groups.
- Runs one immediate assessment.
- Starts two PFHs:
  - Assess loop every `loopInterval` (default `60s`, min `5s`).
  - Dispatch loop every `0.5s` (actual spawn gated by `nextSpawnAt`, effectively ~`2s` spacing).

### 2) Assessment (`fnc_assessCommander`)

The commander reads all synced objectives and converts objective-local states to commander-relative view:

- If objective is securely held by enemy -> `enemy_owned` (relative state)
- Securely held by commander/unknown owner -> `owned_secure` / fallback logic
- Enemy-owned contested-losing is normalized to `contested`

It then computes candidate actions with scores:

- `contested_losing` -> `reinforce` (highest urgency)
- `contested` -> `reinforce`
- `enemy_owned` -> `attack`
- `not_owned` -> `defend`
- `owned_secure` -> `recon`
- Fallback -> `hold`

Score = state base + priority scaling. Additional guardrail:

- If objective force pool is low (`<2`) and action is offensive (`attack`/flanks), downgrade to `recon`.

Top `maxConcurrentActions` actions are selected and passed to execution.

### 3) Execution planning (`fnc_executeCommander`)

- Active actions are normalized via `fnc_submitCommanderAction`.
- Existing queue entries are pruned to only still-active action IDs.
- Global capacity is computed as:
  - `managedGroupsCap - aliveManagedGroups - queuedEntries`
- For each action, enqueue only the deficit to reach `desiredGroups`.
- Queue entries include action metadata and `waveIndex`.

This stage is what ties strategic intent to concrete spawn jobs.

### 4) Queue dispatch/spawn (`fnc_dispatchSpawnQueue`)

Every dispatch tick:

1. Respect spawn interval (`nextSpawnAt`).
2. Stop if managed cap reached.
3. Pop one job from queue head.
4. Select weighted group from catalog (`fnc_selectCatalogGroup`) based on action type + current infantry/vehicle mix.
5. Spawn through `fnc_spawnGroupFromCatalog`.

On specific transient failures (`staging_pool_empty`, `no_staging_objective`), job is retried up to 3 requeues (`attempts < 4`).

---

## Spawn and Staging Logic

`fnc_spawnGroupFromCatalog` does the heavy lifting:

1. Resolve target objective from job.
2. Find staging objective via `fnc_findStagingObjective`:
   - nearest synced objective that is both commander-owned and `owned_secure`.
3. Check staging objective force pool (`forcePoolGroups >= 1`).
4. Pick spawn location from safe spawn cache (`fnc_pickSafeSpawnPos`).
5. Validate `CfgGroups` path and infer group type.
6. Spawn group (`BIS_fnc_spawnGroup` wrappers for man/car/apc/tank).
7. Decrement staging objective force pool by 1 token.
8. Register managed group metadata on commander.
9. Set group vars (`commander`, `actionId`, `targetObjectiveName`) and assign MOVE waypoint to target objective.

Important tie-in: objective force pools are currently both strategic signal (in assessment) and hard logistical currency (required for actual spawns).

---

## Faction Catalog and Group Selection

### Catalog build (`fnc_buildGroupCatalog`)

Commander attributes provide:

- `faction` (e.g. `OPF_F`)
- `groups` (array/string list of specific `CfgGroups` class names)

The builder:

- resolves side branch (`West` / `East` / `Indep`)
- validates faction exists
- includes only requested group classes that exist
- filters unsupported air/sea groups via `fnc_inferGroupType`

Result is stored in `commander.groupCatalog`.

### Weighted selection (`fnc_selectCatalogGroup`)

At spawn time, each catalog entry gets action-dependent weight.

- `reinforce/defend` bias infantry
- `attack` allows heavier armor mix
- `recon` favors infantry + light vehicles

A balancing term then penalizes excessive vehicle ratio relative to infantry for the same action ID.

---

## Reporting and Grid Intel

Runtime reporting now tracks contact and awareness outside objective circles.

- Contact trigger source is `uksf_mission_hitRaw` (subscribed by `aicommander` on server).
- First hit for a managed group starts a delayed confirmation window (`contactConfirmDelaySec`, default `20s`).
- If group is wiped before confirmation, no contact report is emitted (ambush suppression).
- Follow-up contact reports are throttled per group by `followupContactCooldownSec` (default `30s`).

Contact report enemy picture is built from two sources:

- Shooter set collected during hit session (ground truth from incoming fire).
- Group known/spotted contacts (`nearTargets`) to reduce single-shooter under-reporting.

Each report logs:

- Enemy buckets (`man`, `car`, `apc`, `tank`, `air`, `other`)
- Estimated enemy unit and group counts
- Confidence summary (`shooter` vs `knownTargets` contributors)
- Friendly and enemy grid references (when positions are available)

Commander keeps a grid intel map (`intelGrid`) with stale decay:

- Enemy-present cells age out to `unknown` after `intelStaleTtlSec` (default `600s`).
- Decay operations emit `INTEL_DECAY` logs.

SITREPs are group-owned loops (not commander-wide polling):

- Each spawned managed group starts its own SITREP loop.
- Interval is configured on commander via `sitrepIntervalSec` (default `180s`).
- SITREP logs include alive count, casualty ratio, grid, task, and target objective.
- If casualty ratio crosses `ineffectiveCasualtyThreshold` (default `0.5`), system logs `RTB_RECOMMENDED` (recommendation only, no auto-retask yet).
- If group dies, loop ends and a `GROUP_STATUS` KIA event is logged.

---

## Logging and Debug Surfaces

### RPT logs

- `fnc_logAssessment`: `[AIC][ASSESS]...` objective picture + pool + managed/queue metrics.
- `fnc_logDecision`: `[AIC][DECIDE]...` selected actions, scores, rationale.
- `fnc_logExecution`: `[AIC][EXEC]...` catalog/spawn outcomes and reasons.

This is enough to reconstruct why the commander did or did not spawn at any tick.

### Zeus debug provider (`fnc_registerDebugProvider`)

Registers an `AI Commander` debug action and renders:

- Objective icons with state/priority/pool.
- Managed groups with commander/action/type/target and waypoint line.

---

## Practical Setup Notes For Mission Makers

1. Place one or more `(AIC) Objective` modules and configure:
   - name, priority, initial owner, force pool, eval interval, area.
2. Place `(AIC) Commander` module and configure:
   - side, faction, allowed group class list, loop interval, managed cap, wave size.
3. Sync commander to objectives it should reason about.
4. Ensure requested groups exist under configured `CfgGroups` faction+side.

If `groups` is empty or invalid, no spawn catalog is built and commander will never spawn.

---

## Current Constraints / Known Behaviors

- `maxConcurrentActions` is hard-coded to `3` in commander init.
- Runtime clamp forces `maxWave` to `<=3` even though module UI offers up to `5`.
- Queue dispatch is one job per ~2 seconds per commander (phase-offset to reduce burst syncing).
- Spawn job retry only handles staging/objective-availability failures.
- Spawn wrappers are currently identical (`BIS_fnc_spawnGroup`), typed split is for extension.
- Objective eval counts `CAManBase` in area using vehicle position of each unit.

---

## Extension Points (Where To Change What)

- Decision policy/state scoring:
  - `functions/fnc_assessCommander.sqf`
- Intent-to-queue allocation behavior:
  - `functions/fnc_executeCommander.sqf`
- Spawn cadence/cap/backoff:
  - `functions/fnc_dispatchSpawnQueue.sqf`
- Catalog filtering and weighting:
  - `functions/fnc_buildGroupCatalog.sqf`
  - `functions/fnc_selectCatalogGroup.sqf`
- Staging and spawn placement rules:
  - `functions/fnc_findStagingObjective.sqf`
  - `functions/fnc_refreshObjectiveSafeSpawns.sqf`
  - `functions/fnc_pickSafeSpawnPos.sqf`

This should give the next developer enough context to reason about both the strategic loop and the low-level spawn mechanics without reverse-reading every function first.
