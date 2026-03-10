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

// Tier 1: objects with good destruction models
private _tier1Parents = ["Wall_F", "Bunker_02_base_F"];

if (_tier1Parents findIf { _className isKindOf [_x, configFile >> "CfgVehicles"] } isNotEqualTo -1) then {
    _result = [true, 1];
} else {
    // Tier 2: objects with bad/no destruction models
    private _tier2Parents = [
        "BagFence_base_F", "BagBunker_base_F", "HBarrier_base_F",
        "Land_Razorwire_F", "Land_HBarrier_large", "Fort_RazorWire",
        "Fort_Barricade", "Hedgehog", "Fort_EnvelopeSmall", "Fort_EnvelopeBig"
    ];

    if (_tier2Parents findIf { _className isKindOf [_x, configFile >> "CfgVehicles"] } isNotEqualTo -1) then {
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
