#include "script_component.hpp"
/*
    Author:
        Beswick.T

    Description:
        Applies overpressure damage to a target unit. Routes through ACE medical
        if available, otherwise uses vanilla damage. For units inside vehicles,
        damage is scaled by vehicle armour rating.

    Parameter(s):
        0: Target unit <OBJECT>
        1: Raw damage value <NUMBER>
        2: Source unit <OBJECT>

    Return Value:
        None

    Example:
        [_target, _rawDamage, _source] call uksf_blastoverpressure_fnc_applyDamage
*/
params ["_target", "_rawDamage", "_source"];

#define ARMOUR_THRESHOLD 100

private _finalDamage = _rawDamage;

// Scale by vehicle armour if unit is inside a vehicle
private _vehicle = objectParent _target;
if !(isNull _vehicle) then {
    private _isOpenTop = getNumber (configOf _vehicle >> "openTop") > 0;

    if !(_isOpenTop) then {
        private _vehicleArmour = getNumber (configOf _vehicle >> "armor");
        if (_vehicleArmour > ARMOUR_THRESHOLD) then {
            _finalDamage = _finalDamage * (ARMOUR_THRESHOLD / _vehicleArmour);
        };
    };
};

// Normalise to 0-1 range: ~25 raw damage = lethal (1.0)
private _normalisedDamage = (_finalDamage / 25) min 1;

if (_normalisedDamage <= 0.01) exitWith {};
if !(local _target) exitWith {};
if !(isDamageAllowed _target) exitWith {};
if !(_target getVariable ["ace_medical_allowDamage", true]) exitWith {};

// Route through ACE medical if available
if !(isNil "ace_medical_fnc_addDamageToUnit") then {
    [_target, _normalisedDamage, "body", "MissileBase", _source] call ace_medical_fnc_addDamageToUnit;
} else {
    _target setDamage ((damage _target) + _normalisedDamage);
};

TRACE_3("Applied damage",_target,_normalisedDamage,_rawDamage);
