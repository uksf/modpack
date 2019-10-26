#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Sets allow unconcious on AI (ACE variable "ace_medical_enableUnconsciousnessAI")

    Parameter(s):
        0: Unit <OBJECT>
        1: Value <BOOL>

    Return Value:
        None
*/
params ["_unit", "_value"];

if (isPlayer _unit) exitWith {};

private _state = _unit getVariable ["ace_medical_enableUnconsciousnessAI", ace_medical_enableUnconsciousnessAI];
if (_state != 2) then {
    if (_value) then {
        _unit setVariable ["ace_medical_enableUnconsciousnessAI", 1, true];
    };
};
