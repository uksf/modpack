/*
    Author:
        Tim Beswick

    Description:
        Deserializes ace medical state of unit.
        Must be called locally on unit

    Parameter(s):
        0: Unit <OBJECT>
        1: Medical states <ARRAY>

    Return Value:
        Nothing
*/
#include "script_component.hpp"

params ["_unit", "_states"];

if (!local _unit) exitWith {
    WARNING("Serialization of ACE Medical not called locally. This has not run!");
};

{
    _x params ["_variable", "_state"];

    if (!isNil "_state") then {
        _unit setVariable [_variable, _state, true];
    };
} forEach _states;

[_unit] call ace_medical_fnc_handleDamage_advancedSetDamage;
[_unit] call ace_medical_fnc_addVitalLoop;
