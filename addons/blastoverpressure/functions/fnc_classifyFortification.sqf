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

    Example:
        [_className] call uksf_blastoverpressure_fnc_classifyFortification
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

// Check explicit class hashmaps for objects with overly-broad parents
// Hashmaps initialised once in XEH_preInit.sqf
if !(_result#0) then {
    if (_className in GVAR(explicitFortificationTier1)) then {
        _result = [true, 1];
    } else {
        if (_className in GVAR(explicitFortificationTier2)) then {
            _result = [true, 2];
        };
    };
};

GVAR(fortificationClassCache) set [_className, _result];

_result
