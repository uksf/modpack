#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Deserializes ace medical state of unit.
        Must be called locally on unit

    Parameter(s):
        0: Unit <OBJECT>
        1: Medical state <STRING>

    Return Value:
        Nothing
*/
params ["_unit", "_state"];

if (!local _unit) exitWith {
    WARNING("Deserialization of ACE Medical not called locally. This has not run!");
};

if (_state isEqualType []) exitWith {
    WARNING("Deserialization of ACE Medical attempted with invalid format");
};

[_unit, _state] call ace_medical_fnc_deserializeState;
