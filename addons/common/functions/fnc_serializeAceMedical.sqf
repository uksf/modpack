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
        Array of ace medical states
*/

params ["_unit"];

if (!local _unit) exitWith {
    WARNING("Serialization of ACE Medical not called locally. This has not run!");
};

[
    ["ace_isunconscious", _unit getVariable ["ACE_isUnconscious", false]],
    ["ace_medical_pain", _unit getVariable ["ace_medical_pain", 0]],
    ["ace_medical_morphine", _unit getVariable ["ace_medical_morphine", 0]],
    ["ace_medical_bloodVolume", _unit getVariable ["ace_medical_bloodVolume", 100]],
    ["ace_medical_tourniquets", _unit getVariable ["ace_medical_tourniquets", [0,0,0,0,0,0]]],
    ["ace_medical_occludedMedications", _unit getVariable ["ace_medical_occludedMedications", nil]],
    ["ace_medical_openWounds", _unit getVariable ["ace_medical_openWounds", []]],
    ["ace_medical_bandagedWounds", _unit getVariable ["ace_medical_bandagedWounds", []]],
    ["ace_medical_lastUniqueWoundID", _unit getVariable ["ace_medical_lastUniqueWoundID", []]],
    ["ace_medical_heartRate", _unit getVariable ["ace_medical_heartRate", 80]],
    ["ace_medical_heartRateAdjustments", _unit getVariable ["ace_medical_heartRateAdjustments", []]],
    ["ace_medical_bloodPressure", _unit getVariable ["ace_medical_bloodPressure", [80, 120]]],
    ["ace_medical_peripheralResistance", _unit getVariable ["ace_medical_peripheralResistance", 100]],
    ["ace_medical_triageLevel", _unit getVariable ["ace_medical_triageLevel", 0]],
    ["ace_medical_triageCard", _unit getVariable ["ace_medical_triageCard", []]],
    ["ace_medical_ivBags", _unit getVariable ["ace_medical_ivBags", nil]],
    ["ace_medical_bodyPartStatus", _unit getVariable ["ace_medical_bodyPartStatus", [0,0,0,0,0,0]]],
    ["ace_medical_inCardiacArrest", _unit getVariable ["ace_medical_inCardiacArrest", false]],
    ["ace_medical_hasLostBlood", _unit getVariable ["ace_medical_hasLostBlood", 0]],
    ["ace_medical_isBleeding", _unit getVariable ["ace_medical_isBleeding", false]],
    ["ace_medical_hasPain", _unit getVariable ["ace_medical_hasPain", false]],
    ["ace_medical_amountOfReviveLives", _unit getVariable ["ace_medical_amountOfReviveLives", ace_medical_amountOfReviveLives]],
    ["ace_medical_painSuppress", _unit getVariable ["ace_medical_painSuppress", 0]],
    ["ace_medical_allUsedMedication", _unit getVariable ["ace_medical_allUsedMedication", []]],
    ["ace_medical_allLogs", _unit getVariable ["ace_medical_allLogs", []]]
]
