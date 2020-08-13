#include "script_component.hpp"
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
params ["_unit", "_allStates"];
_allStates params ["_unconciousStates", "_variables", "_logVariables", "_stateMachineState"];
_unconciousStates params ["_unconciousState", "_cardiacArrestState"];

if (!local _unit) exitWith {
    WARNING("Serialization of ACE Medical not called locally. This has not run!");
};

[_unit, ace_medical_state_machine, "Dead", _stateMachineState] call CBA_statemachine_fnc_manualTransition;
[_unit, _cardiacArrestState] call ace_medical_status_fnc_setCardiacArrestState;
[_unit, _unconciousState] call ace_medical_status_fnc_setUnconsciousState;

{
    _x params ["_variable", "_state"];

    if (!isNil "_state") then {
        _unit setVariable [_variable, _state, true];
    };
} forEach _variables;

[_unit] call ace_medical_status_fnc_updateWoundBloodLoss;
[_unit] call ace_medical_vitals_fnc_handleUnitVitals;
[_unit] call ace_medical_engine_fnc_updateDamageEffects;
[_unit, true, true, true, true] call ace_medical_engine_fnc_updateBodyPartVisuals;

{
    _x params ["_variable", "_state"];

    _unit setVariable [_variable, _state, true];
} forEach _logVariables;
