#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Serializes ace medical state of unit.
        Must be called locally on unit

    Parameter(s):
        0: Unit <OBJECT>

    Return Value:
        ACE medical state json string
*/
params ["_unit"];

if (!local _unit) exitWith {
    WARNING("Serialization of ACE Medical not called locally. This has not run!");
};

[_unit] call ace_medical_fnc_serializeState
