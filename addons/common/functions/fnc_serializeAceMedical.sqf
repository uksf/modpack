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

// private _allLogs = _unit getVariable ["ace_medical_allLogs", []];
// private _logVariables = [];
// {
//     _logVariables pushBack [_x, _unit getVariable [_x, []]];
// } forEach _allLogs;

// [
//     [
//         _unit getVariable ["ACE_isUnconscious", false],
//         _unit getVariable ["ace_medical_inCardiacArrest", false]
//     ],
//     [
//         ["ace_medical_bloodVolume", _unit getVariable ["ace_medical_bloodVolume", 6]],
//         ["ace_medical_heartRate", _unit getVariable ["ace_medical_heartRate", 80]],
//         ["ace_medical_bloodPressure", _unit getVariable ["ace_medical_bloodPressure", [80, 120]]],
//         ["ace_medical_peripheralResistance", _unit getVariable ["ace_medical_peripheralResistance", 100]],
//         ["ace_medical_statemachine_cardiacArrestTimeLeft", _unit getVariable ["ace_medical_statemachine_cardiacArrestTimeLeft", -1]],
//         ["ace_medical_hemorrhage", _unit getVariable ["ace_medical_hemorrhage", 0]],

//         ["ace_medical_pain", _unit getVariable ["ace_medical_pain", 0]],
//         ["ace_medical_inPain", _unit getVariable ["ace_medical_inPain", false]],
//         ["ace_medical_painSuppress", _unit getVariable ["ace_medical_painSuppress", 0]],

//         ["ace_medical_openWounds", _unit getVariable ["ace_medical_openWounds", []]],
//         ["ace_medical_bandagedWounds", _unit getVariable ["ace_medical_bandagedWounds", []]],
//         ["ace_medical_stitchedWounds", _unit getVariable ["ace_medical_stitchedWounds", []]],
//         ["ace_medical_isLimping", _unit getVariable ["ace_medical_isLimping", false]],
//         ["ace_medical_fractures", _unit getVariable ["ace_medical_fractures", [0,0,0,0,0,0]]],

//         ["ace_medical_tourniquets", _unit getVariable ["ace_medical_tourniquets", [0,0,0,0,0,0]]],
//         ["ace_medical_occludedMedications", _unit getVariable ["ace_medical_occludedMedications", nil]],
//         ["ace_medical_ivBags", _unit getVariable ["ace_medical_ivBags", nil]],

//         ["ace_medical_triageLevel", _unit getVariable ["ace_medical_triageLevel", 0]],
//         ["ace_medical_triageCard", _unit getVariable ["ace_medical_triageCard", []]],

//         ["ace_medical_bodyPartDamage", _unit getVariable ["ace_medical_bodyPartDamage", [0,0,0,0,0,0]]],

//         ["ace_medical_medications", _unit getVariable ["ace_medical_medications", []]],

//         ["ace_medical_lastWakeUpCheck", _unit getVariable ["ace_medical_lastWakeUpCheck", nil]],

//         ["ace_medical_allLogs", _allLogs]
//     ],
//     _logVariables,
//     [_unit, ace_medical_state_machine] call CBA_statemachine_fnc_getCurrentState
// ]
