# Fortification Destruction Design

## Problem

Arma's native explosion damage handling is inconsistent for placed fortification objects. Some objects (sandbags, HESCOs) don't take damage properly or have no destruction model. Others have janky destruction animations (rotating sideways). When a building is destroyed beneath floating fortifications, those fortifications remain suspended in the air. A 500lb bomb should obliterate nearby sandbags, but the engine often leaves them untouched.

## Goal

Extend the blast overpressure system to destroy or damage fortification objects within the blast radius of large explosions, using appropriate visual handling per object type. Respect damage-disabled objects. Only process munitions large enough to realistically damage fortifications (81mm mortar and above).

## Scope

- **Large explosions only**: separate configurable threshold, higher than the unit overpressure threshold. Default catches 81mm+ mortar, bombs, large IEDs. Skips grenades, 40mm, 60mm.
- **Fortification objects only**: sandbags, HESCOs, barriers, bunkers, walls, razorwire, hedgehogs, barricades. Not buildings.
- **Server-only execution**: all destruction logic runs on the server. No network traffic for sub-threshold munitions.
- **Integrated into the existing blastoverpressure addon**: new functions, shared hook point.

## Architecture

### Integration with Existing System

`fnc_explosionHandler` already fires for qualifying explosions. A new CBA server event is fired at the end of the handler when the ammo's power score exceeds the fortification threshold. This decouples fortification destruction from unit overpressure processing.

```
explosionHandler (local to projectile)
  ├── existing unit overpressure processing (unchanged)
  └── if powerScore >= fortificationThreshold:
        [QGVAR(processFortifications), [data]] call CBA_fnc_serverEvent
          └── fnc_processFortifications (server only)
                ├── nearObjects to find objects in range
                ├── filter to fortifications (isDamageAllowed, alive, class check)
                ├── classify tier, calculate damage per distance
                └── apply destruction per object per tier
```

### New Functions

| Function | Purpose |
|----------|---------|
| `fnc_processFortifications.sqf` | Server entry: collect objects, filter, iterate, apply damage |
| `fnc_classifyFortification.sqf` | Returns `[isFortification, tier]` for an object class, with caching |
| `fnc_destroyFortification.sqf` | Applies tier-appropriate destruction (setDamage or delete + effects) |

### New CBA Settings

| Setting | Type | Default | Scope | Description |
|---------|------|---------|-------|-------------|
| `fortificationDestructionEnabled` | Checkbox | ON | Server | Master toggle for fortification destruction |
| `fortificationThreshold` | Slider (100-500) | 180 | Server | Minimum power score to process fortifications |

## Fortification Classification

### Tiered Destruction

Objects are classified into two tiers based on destruction model quality:

- **Tier 1 — Good destruction model**: Use `setDamage [_damage, true, _source]`. The `_source` parameter directs debris/fall away from the blast. Arma handles the visual destruction naturally.
- **Tier 2 — Bad/no destruction model**: If damage would destroy the object, spawn a dust particle effect at the object position and `deleteVehicle`. If partial damage, apply `setDamage` with the fractional value.

### Class Identification

Two mechanisms combined:

**isKindOf checks** (for classes with fortification-specific parents):

| Parent class | Tier | What it catches |
|---|---|---|
| `BagFence_base_F` | 2 | All sandbag fences |
| `BagBunker_base_F` | 2 | All sandbag bunkers, pillbox bunkers |
| `HBarrier_base_F` | 2 | All HESCO barriers |
| `Wall_F` | 1 | Military walls, concrete walls, wired fences, pillbox walls, trenches |
| `Bunker_02_base_F` | 1 | Bunker_02 series |
| `Land_Razorwire_F` | 2 | A3 razorwire |
| `Land_HBarrier_large` | 2 | Legacy A2 HESCOs |
| `Fort_RazorWire` | 2 | Legacy razorwire |
| `Fort_Barricade` | 2 | Legacy barricades |
| `Hedgehog` | 2 | Legacy hedgehogs |
| `Fort_EnvelopeSmall` | 2 | Legacy sandbag envelopes |
| `Fort_EnvelopeBig` | 2 | Legacy sandbag envelopes |

**Explicit class hashmap** (for classes that inherit from overly-broad parents like `House_F` or `ThingX`):

| Class | Tier |
|---|---|
| `Land_Bunker_F` | 1 |
| `Land_Bunker_01_big_F` | 1 |
| `Land_Bunker_01_blocks_1_F` | 1 |
| `Land_Bunker_01_blocks_3_F` | 1 |
| `Land_Bunker_01_HQ_F` | 1 |
| `Land_Bunker_01_small_F` | 1 |
| `Land_Bunker_01_tall_F` | 1 |
| `Land_SandbagBarricade_01_F` | 2 |
| `Land_SandbagBarricade_01_half_F` | 2 |
| `Land_SandbagBarricade_01_hole_F` | 2 |
| `Land_Barricade_01_4m_F` | 2 |
| `Land_Barricade_01_10m_F` | 2 |
| `Land_CzechHedgehog_01_F` | 2 |
| `Land_CzechHedgehog_01_old_F` | 2 |
| `Land_CzechHedgehog_01_new_F` | 2 |
| `Land_ConcreteHedgehog_01_F` | 2 |
| `Land_ConcreteHedgehog_01_half_F` | 2 |
| `Land_ConcreteHedgehog_01_palette_F` | 2 |
| `ACE_ConcertinaWireCoil` | 2 |
| `Land_ConcretePipe_F` | 2 |

### Classification Caching

Results are cached in a hashmap keyed by object classname (`GVAR(fortificationClassCache)`). First encounter runs the isKindOf chain + hashmap lookup; subsequent encounters are a single hashmap read. Cache is built lazily at runtime.

## Damage Model

### Calculation

Damage uses the ammo's `indirectHit` value with distance-based falloff:

```
_damage = _indirectHit * (1 - _distance / _effectiveRange)
```

Where `_effectiveRange = indirectHitRange * rangeMultiplier` (same as unit overpressure).

This is then scaled to the 0-1 damage range relative to the object's resilience. Objects accumulate damage — multiple smaller hits can destroy a fortification.

### Application per Tier

**Tier 1** (good destruction model):
- `_object setDamage [(_currentDamage + _damage) min 1, true, _source]`
- Arma handles visual destruction, debris falls away from blast origin

**Tier 2** (bad/no destruction model):
- If `_currentDamage + _damage >= 1`: spawn dust particle effect at object position, then `deleteVehicle _object`
- If `_currentDamage + _damage < 1`: `_object setDamage [(_currentDamage + _damage) min 1, true, _source]` — partial damage state preserved even if visual is imperfect

### Protection Checks (per object, in order)

1. `isDamageAllowed _object` — if false, skip entirely (intentionally protected by Zeus/script)
2. `!alive _object` or `damage _object >= 1` — already destroyed, skip
3. Classification check — is it a known fortification class?
4. Calculate and apply damage

## Performance

- **No network traffic** for sub-threshold munitions: the CBA server event is only fired when `powerScore >= fortificationThreshold`
- **One `nearObjects` call** per qualifying explosion on the server
- **No per-frame spreading**: fortification count is typically low (tens). Process all in one frame.
- **Ammo config**: already cached by existing `fnc_getAmmoConfig`
- **Fortification class**: cached per classname in `GVAR(fortificationClassCache)`, lazy init

## Debug Visualisation

Guarded by `#ifdef DEBUG_MODE_FULL`. Uses the same timing conventions as the existing overpressure debug (game time, 5s duration).

- Red markers on destroyed fortifications
- Yellow markers on partially damaged fortifications with damage values
- Grey markers on protected objects (allowDamage false)

## Future Extensions

- Adjustable tier classification via CBA settings or config overrides
- Per-class damage multipliers (HESCOs more resilient than sandbags)
- Structural chain reactions (destroying support objects causes dependent objects to fall)
