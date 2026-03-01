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
