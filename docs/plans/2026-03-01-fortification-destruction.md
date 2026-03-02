# Fortification Destruction Implementation Plan

> **For Claude:** REQUIRED SUB-SKILL: Use superpowers:executing-plans to implement this plan task-by-task.

**Goal:** Extend the blast overpressure system to destroy fortification objects (sandbags, HESCOs, barriers, bunkers, walls) within the blast radius of large explosions, using tiered destruction based on destruction model quality.

**Architecture:** Hooks into the existing `fnc_explosionHandler` to fire a CBA server event when ammo power score exceeds the fortification threshold. Server-side function collects nearby objects via `nearObjects`, classifies them as fortifications using cached `isKindOf` checks + explicit class hashmap, calculates distance-based damage, and applies tier-appropriate destruction (native `setDamage` for objects with good destruction models, `deleteVehicle` + dust effect for janky ones).

**Tech Stack:** SQF, CBA framework, existing blastoverpressure addon infrastructure

**Design doc:** `docs/plans/2026-03-01-fortification-destruction-design.md`

---

### Task 1: Add CBA settings for fortification destruction

Add the two new server-enforced CBA settings to the existing settings file.

**Files:**
- Modify: `addons/blastoverpressure/initSettings.inc.sqf`

**Step 1: Add settings**

Append to the end of `initSettings.inc.sqf`:

```sqf
[
    QGVAR(fortificationDestructionEnabled),
    "CHECKBOX",
    ["Fortification destruction", "Destroy fortification objects (sandbags, barriers, bunkers) within blast radius of large explosions"],
    [COMPONENT_NAME, "Fortifications"],
    true,
    1
] call CBA_Settings_fnc_init;

[
    QGVAR(fortificationThreshold),
    "SLIDER",
    ["Fortification threshold", "Minimum explosion power to destroy fortifications. Higher than overpressure threshold — 81mm mortar and above. Formula: indirectHit * sqrt(indirectHitRange). (100 - 500)"],
    [COMPONENT_NAME, "Fortifications"],
    [100, 500, 180, 0],
    1
] call CBA_Settings_fnc_init;
```

**Step 2: Commit**

```bash
git add addons/blastoverpressure/initSettings.inc.sqf
git commit -m "feat(blastoverpressure): add CBA settings for fortification destruction"
```

---

### Task 2: Create fortification classification function

Create `fnc_classifyFortification.sqf` — takes an object classname, returns `[isFortification, tier]` with caching.

**Files:**
- Create: `addons/blastoverpressure/functions/fnc_classifyFortification.sqf`
- Modify: `addons/blastoverpressure/XEH_PREP.hpp` (add PREP line)
- Modify: `addons/blastoverpressure/XEH_preInit.sqf` (init cache hashmap)

**Step 1: Init the classification cache**

In `XEH_preInit.sqf`, add after the existing `GVAR(ammoConfigCache) = createHashMap;` line:

```sqf
GVAR(fortificationClassCache) = createHashMap;
```

**Step 2: Add PREP**

In `XEH_PREP.hpp`, add:

```sqf
PREP(classifyFortification);
```

**Step 3: Create the function**

Create `addons/blastoverpressure/functions/fnc_classifyFortification.sqf`:

```sqf
#include "script_component.hpp"
/*
    Author:
        Beswick.T

    Description:
        Classifies an object class as a fortification and returns its
        destruction tier. Results are cached per classname.

        Tier 1: Good destruction model — use setDamage with effects.
        Tier 2: Bad/no destruction model — use deleteVehicle + dust effect.

    Parameter(s):
        0: Object classname <STRING>

    Return Value:
        [isFortification, tier] <ARRAY>
*/
params ["_className"];

private _cached = GVAR(fortificationClassCache) getOrDefault [_className, []];
if (_cached isNotEqualTo []) exitWith { _cached };

private _result = [false, 0];

// Check isKindOf-friendly parent classes
// Tier 1: objects with good destruction models
if (_className isKindOf ["Wall_F", configFile >> "CfgVehicles"]
    || {_className isKindOf ["Bunker_02_base_F", configFile >> "CfgVehicles"]}) then {
    _result = [true, 1];
} else {
    // Tier 2: objects with bad/no destruction models
    if (_className isKindOf ["BagFence_base_F", configFile >> "CfgVehicles"]
        || {_className isKindOf ["BagBunker_base_F", configFile >> "CfgVehicles"]}
        || {_className isKindOf ["HBarrier_base_F", configFile >> "CfgVehicles"]}
        || {_className isKindOf ["Land_Razorwire_F", configFile >> "CfgVehicles"]}
        || {_className isKindOf ["Land_HBarrier_large", configFile >> "CfgVehicles"]}
        || {_className isKindOf ["Fort_RazorWire", configFile >> "CfgVehicles"]}
        || {_className isKindOf ["Fort_Barricade", configFile >> "CfgVehicles"]}
        || {_className isKindOf ["Hedgehog", configFile >> "CfgVehicles"]}
        || {_className isKindOf ["Fort_EnvelopeSmall", configFile >> "CfgVehicles"]}
        || {_className isKindOf ["Fort_EnvelopeBig", configFile >> "CfgVehicles"]}) then {
        _result = [true, 2];
    };
};

// Check explicit class hashmap for objects with overly-broad parents
if !(_result#0) then {
    // Tier 1 explicit classes
    private _explicitTier1 = createHashMapFromArray [
        ["Land_Bunker_F", true],
        ["Land_Bunker_01_big_F", true],
        ["Land_Bunker_01_blocks_1_F", true],
        ["Land_Bunker_01_blocks_3_F", true],
        ["Land_Bunker_01_HQ_F", true],
        ["Land_Bunker_01_small_F", true],
        ["Land_Bunker_01_tall_F", true]
    ];

    // Tier 2 explicit classes
    private _explicitTier2 = createHashMapFromArray [
        ["Land_SandbagBarricade_01_F", true],
        ["Land_SandbagBarricade_01_half_F", true],
        ["Land_SandbagBarricade_01_hole_F", true],
        ["Land_Barricade_01_4m_F", true],
        ["Land_Barricade_01_10m_F", true],
        ["Land_CzechHedgehog_01_F", true],
        ["Land_CzechHedgehog_01_old_F", true],
        ["Land_CzechHedgehog_01_new_F", true],
        ["Land_ConcreteHedgehog_01_F", true],
        ["Land_ConcreteHedgehog_01_half_F", true],
        ["Land_ConcreteHedgehog_01_palette_F", true],
        ["ACE_ConcertinaWireCoil", true],
        ["Land_ConcretePipe_F", true]
    ];

    if (_className in _explicitTier1) then {
        _result = [true, 1];
    } else {
        if (_className in _explicitTier2) then {
            _result = [true, 2];
        };
    };
};

GVAR(fortificationClassCache) set [_className, _result];

_result
```

**Step 4: Commit**

```bash
git add addons/blastoverpressure/functions/fnc_classifyFortification.sqf addons/blastoverpressure/XEH_PREP.hpp addons/blastoverpressure/XEH_preInit.sqf
git commit -m "feat(blastoverpressure): add fortification classification with caching"
```

---

### Task 3: Create fortification destruction function

Create `fnc_destroyFortification.sqf` — applies tier-appropriate destruction to a single fortification object.

**Files:**
- Create: `addons/blastoverpressure/functions/fnc_destroyFortification.sqf`
- Modify: `addons/blastoverpressure/XEH_PREP.hpp` (add PREP line)

**Step 1: Add PREP**

In `XEH_PREP.hpp`, add:

```sqf
PREP(destroyFortification);
```

**Step 2: Create the function**

Create `addons/blastoverpressure/functions/fnc_destroyFortification.sqf`:

```sqf
#include "script_component.hpp"
/*
    Author:
        Beswick.T

    Description:
        Applies tier-appropriate destruction to a fortification object.

        Tier 1: setDamage with effects — Arma handles visual destruction,
                debris falls away from blast source.
        Tier 2: If damage would destroy, spawn dust effect and deleteVehicle.
                Otherwise apply fractional setDamage.

    Parameter(s):
        0: Fortification object <OBJECT>
        1: Damage to apply (0-1 scale, relative to object health) <NUMBER>
        2: Source object (blast origin for fall direction) <OBJECT>
        3: Destruction tier (1 or 2) <NUMBER>

    Return Value:
        None
*/
params ["_object", "_damage", "_source", "_tier"];

private _currentDamage = damage _object;
private _newDamage = (_currentDamage + _damage) min 1;

if (_tier isEqualTo 1) then {
    // Tier 1: good destruction model — let Arma handle it
    _object setDamage [_newDamage, true, _source];

    #ifdef DEBUG_MODE_FULL
        diag_log text format [
            "[%1] Fortification tier 1 damage: %2 (%3) currentDamage=%4 newDamage=%5",
            ADDON, typeOf _object, _object, _currentDamage, _newDamage
        ];
    #endif
} else {
    // Tier 2: bad/no destruction model
    if (_newDamage >= 1) then {
        // Would be destroyed — spawn dust effect and delete
        private _position = getPosATL _object;

        // Spawn dust particle effect at object position
        private _dustEffect = "#particlesource" createVehicleLocal _position;
        _dustEffect setParticleParams [
            ["\A3\data_f\ParticleEffects\Universal\Universal.p3d", 16, 12, 8, 0],
            "", "Billboard", 1, 3, [0, 0, 0], [0, 0, 1], 1, 1.275, 1, 0,
            [1, 3, 6], [[0.5, 0.4, 0.3, 0.6], [0.6, 0.5, 0.4, 0.3], [0.7, 0.6, 0.5, 0]],
            [0, 1], 0.1, 0.05, "", "", _object, 0, false, -1, [[3, 3, 3, 0]]
        ];
        _dustEffect setParticleRandom [3, [2, 2, 1], [2, 2, 2], 1, 0.5, [0, 0, 0, 0.1], 0, 0, 360];
        _dustEffect setDropInterval 0.01;

        // Clean up particle source after brief emission
        [{
            deleteVehicle _this;
        }, _dustEffect, 0.5] call CBA_fnc_waitAndExecute;

        deleteVehicle _object;

        #ifdef DEBUG_MODE_FULL
            diag_log text format [
                "[%1] Fortification tier 2 destroyed: %2 (%3) at %4",
                ADDON, typeOf _object, _object, _position
            ];
        #endif
    } else {
        // Partial damage — apply fractional setDamage
        _object setDamage [_newDamage, true, _source];

        #ifdef DEBUG_MODE_FULL
            diag_log text format [
                "[%1] Fortification tier 2 partial damage: %2 (%3) currentDamage=%4 newDamage=%5",
                ADDON, typeOf _object, _object, _currentDamage, _newDamage
            ];
        #endif
    };
};
```

**Step 3: Commit**

```bash
git add addons/blastoverpressure/functions/fnc_destroyFortification.sqf addons/blastoverpressure/XEH_PREP.hpp
git commit -m "feat(blastoverpressure): add tiered fortification destruction function"
```

---

### Task 4: Create fortification processing function

Create `fnc_processFortifications.sqf` — the server-side entry point that collects objects, filters, classifies, calculates damage, and dispatches destruction.

**Files:**
- Create: `addons/blastoverpressure/functions/fnc_processFortifications.sqf`
- Modify: `addons/blastoverpressure/XEH_PREP.hpp` (add PREP line)

**Step 1: Add PREP**

In `XEH_PREP.hpp`, add:

```sqf
PREP(processFortifications);
```

**Step 2: Create the function**

Create `addons/blastoverpressure/functions/fnc_processFortifications.sqf`:

```sqf
#include "script_component.hpp"
/*
    Author:
        Beswick.T

    Description:
        Server-side handler for fortification destruction. Collects objects
        in blast radius, filters to fortifications, classifies by tier,
        calculates distance-based damage, and applies destruction.

    Parameter(s):
        0: Detonation position ASL <ARRAY>
        1: indirectHit value (adjusted) <NUMBER>
        2: indirectHitRange <NUMBER>
        3: Effective range <NUMBER>
        4: Source object (who caused the explosion) <OBJECT>

    Return Value:
        None
*/
if !(isServer) exitWith {};
if !(GVAR(fortificationDestructionEnabled)) exitWith {};

params ["_positionASL", "_indirectHit", "_indirectHitRange", "_effectiveRange", "_source"];

// Collect all objects in effective range
private _positionAGL = ASLToAGL _positionASL;
private _nearbyObjects = _positionAGL nearObjects _effectiveRange;

#ifdef DEBUG_MODE_FULL
    diag_log text format [
        "[%1] Fortification scan: %2 objects in %3m range",
        ADDON, count _nearbyObjects, _effectiveRange
    ];
    private _destroyedCount = 0;
    private _damagedCount = 0;
    private _protectedCount = 0;
#endif

{
    // Skip units and vehicles — handled by the overpressure system
    if (_x isKindOf "CAManBase" || {_x isKindOf "LandVehicle"} || {_x isKindOf "Air"} || {_x isKindOf "Ship"}) then { continue };

    // Skip already destroyed objects
    if !(alive _x) then { continue };
    if (damage _x >= 1) then { continue };

    // Skip damage-protected objects
    if !(isDamageAllowed _x) then {
        #ifdef DEBUG_MODE_FULL
            _protectedCount = _protectedCount + 1;
        #endif
        continue
    };

    // Classify the object
    private _className = typeOf _x;
    private _classification = [_className] call FUNC(classifyFortification);
    _classification params ["_isFortification", "_tier"];

    if !(_isFortification) then { continue };

    // Calculate distance-based damage
    private _objectPositionASL = AGLToASL (getPosATL _x);
    private _distance = _positionASL vectorDistance _objectPositionASL;

    if (_distance >= _effectiveRange) then { continue };

    // Damage falloff: linear from indirectHit at distance 0 to 0 at effectiveRange
    private _rawDamage = _indirectHit * (1 - (_distance / _effectiveRange));

    // Normalise to 0-1 damage scale
    // indirectHit for large munitions is 60-200+, a value of ~80 should destroy most fortifications
    private _normalisedDamage = (_rawDamage / 80) min 1;

    if (_normalisedDamage <= 0.01) then { continue };

    // Apply destruction
    [_x, _normalisedDamage, _source, _tier] call FUNC(destroyFortification);

    #ifdef DEBUG_MODE_FULL
        if (damage _x >= 1 || {!alive _x}) then {
            _destroyedCount = _destroyedCount + 1;
        } else {
            _damagedCount = _damagedCount + 1;
        };
    #endif
} forEach _nearbyObjects;

#ifdef DEBUG_MODE_FULL
    diag_log text format [
        "[%1] Fortification results: destroyed=%2 damaged=%3 protected=%4",
        ADDON, _destroyedCount, _damagedCount, _protectedCount
    ];
    [_positionASL, _effectiveRange, _destroyedCount, _damagedCount, _protectedCount] call FUNC(debugDrawFortifications);
#endif
```

**Step 3: Commit**

```bash
git add addons/blastoverpressure/functions/fnc_processFortifications.sqf addons/blastoverpressure/XEH_PREP.hpp
git commit -m "feat(blastoverpressure): add fortification processing with distance-based damage"
```

---

### Task 5: Hook into explosion handler

Modify `fnc_explosionHandler` to fire the fortification processing event when the ammo power score exceeds the fortification threshold.

**Files:**
- Modify: `addons/blastoverpressure/functions/fnc_explosionHandler.sqf`
- Modify: `addons/blastoverpressure/XEH_preInit.sqf` (register CBA event)

**Step 1: Register the CBA event handler**

In `XEH_preInit.sqf`, add before the `ADDON = true;` line:

```sqf
[QGVAR(processFortifications), {
    _this call FUNC(processFortifications);
}] call CBA_fnc_addEventHandler;
```

**Step 2: Add the server event call to explosion handler**

In `fnc_explosionHandler.sqf`, add at the **end** of the function (after the existing overpressure mode dispatch block, after the closing `};` of the if/else for pressure_wave vs path_trace), just before the final line of the file:

```sqf
// Fortification destruction — fire server event if above fortification threshold
if (GVAR(fortificationDestructionEnabled) && {_powerScore >= GVAR(fortificationThreshold)}) then {
    [QGVAR(processFortifications), [_positionASL, _adjustedIndirectHit, _indirectHitRange, _effectiveRange, _source]] call CBA_fnc_serverEvent;
};
```

Note: `_powerScore`, `_adjustedIndirectHit`, `_indirectHitRange`, `_effectiveRange`, and `_source` are all already defined in the explosion handler scope. `_positionASL` is the first parameter.

**Step 3: Commit**

```bash
git add addons/blastoverpressure/functions/fnc_explosionHandler.sqf addons/blastoverpressure/XEH_preInit.sqf
git commit -m "feat(blastoverpressure): hook fortification destruction into explosion handler"
```

---

### Task 6: Add debug visualisation for fortifications

Create `fnc_debugDrawFortifications.sqf` — draws markers on destroyed/damaged/protected fortifications. Follows the same pattern as `fnc_debugDrawBlastRadius.sqf`.

**Files:**
- Create: `addons/blastoverpressure/functions/fnc_debugDrawFortifications.sqf`
- Modify: `addons/blastoverpressure/XEH_PREP.hpp` (add PREP line)

**Step 1: Add PREP**

In `XEH_PREP.hpp`, add:

```sqf
PREP(debugDrawFortifications);
```

**Step 2: Create the function**

Create `addons/blastoverpressure/functions/fnc_debugDrawFortifications.sqf`:

```sqf
#include "script_component.hpp"
/*
    Author:
        Beswick.T

    Description:
        Debug visualisation for fortification destruction results.
        Draws summary text near detonation point showing counts.

    Parameter(s):
        0: Detonation position ASL <ARRAY>
        1: Effective range <NUMBER>
        2: Destroyed count <NUMBER>
        3: Damaged count <NUMBER>
        4: Protected count <NUMBER>

    Return Value:
        None
*/
params ["_positionASL", "_effectiveRange", "_destroyedCount", "_damagedCount", "_protectedCount"];

private _startTime = CBA_missionTime;
private _duration = 5;
private _positionATL = ASLToATL _positionASL;

[{
    params ["_args", "_perFrameHandlerID"];
    _args params ["_startTime", "_duration", "_positionATL", "_destroyedCount", "_damagedCount", "_protectedCount"];

    if (CBA_missionTime > _startTime + _duration) exitWith {
        [_perFrameHandlerID] call CBA_fnc_removePerFrameHandler;
    };

    private _textPosition = _positionATL vectorAdd [0, 0, 3];
    private _text = format ["Fortifications: %1 destroyed | %2 damaged | %3 protected", _destroyedCount, _damagedCount, _protectedCount];
    drawIcon3D ["\a3\ui_f\data\IGUI\Cfg\Actions\clear_empty_ca.paa", [1, 0.5, 0, 1], _textPosition, 0.5, 0.5, 0, _text, 2, 0.03, "RobotoCondensed"];

}, 0, [
    _startTime, _duration, _positionATL, _destroyedCount, _damagedCount, _protectedCount
]] call CBA_fnc_addPerFrameHandler;
```

**Step 3: Commit**

```bash
git add addons/blastoverpressure/functions/fnc_debugDrawFortifications.sqf addons/blastoverpressure/XEH_PREP.hpp
git commit -m "feat(blastoverpressure): add debug visualisation for fortification destruction"
```

---

### Task 7: Build and smoke test

Verify the addon compiles and the new functions are syntactically valid.

**Step 1: Run SQF validator**

```bash
python3 tools/sqf_validator.py -m blastoverpressure
```

Expected: no errors for the new files.

**Step 2: Run config style checker**

```bash
python3 tools/config_style_checker.py -m blastoverpressure
```

Expected: no errors.

**Step 3: Build dev PBOs**

```bash
hemtt.exe dev
```

Expected: successful build, no errors for blastoverpressure addon.

**Step 4: Commit any fixes**

If validators or build catch issues, fix and commit:

```bash
git add -A addons/blastoverpressure/
git commit -m "fix(blastoverpressure): address validation issues from fortification destruction"
```
