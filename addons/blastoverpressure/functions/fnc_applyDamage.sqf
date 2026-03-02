#include "script_component.hpp"
/*
    Author:
        Beswick.T

    Description:
        Applies overpressure damage to a target. Routes through ACE medical
        if available, otherwise uses vanilla damage. For vehicles, damages
        crew members scaled by vehicle armour rating.

    Parameter(s):
        0: Target object <OBJECT>
        1: Raw damage value <NUMBER>
        2: Source unit <OBJECT>

    Return Value:
        None
*/
params ["_target", "_rawDamage", "_source"];

#define ARMOUR_THRESHOLD 100

if (_target isKindOf "CAManBase") then {
    // Infantry — check if in vehicle
    private _vehicle = objectParent _target;

    private _finalDamage = _rawDamage;

    if !(isNull _vehicle) then {
        // Unit is in a vehicle — scale by vehicle armour
        private _vehicleArmour = getNumber (configOf _vehicle >> "armor");

        // Open-top check: if vehicle has no roof, no protection
        private _isOpenTop = getNumber (configOf _vehicle >> "openTop");

        if (_isOpenTop isEqualTo 1) then {
            // No protection
        } else {
            // Scale damage by armour: heavier armour = less damage
            if (_vehicleArmour > ARMOUR_THRESHOLD) then {
                _finalDamage = _finalDamage * (ARMOUR_THRESHOLD / _vehicleArmour);
            };
        };
    };

    // Normalise damage to 0-1 range roughly
    // indirectHit values can be 80-200+ for large explosions
    // After attenuation factors, _finalDamage is typically 5-60
    // Scale so ~50 damage = lethal (1.0)
    private _normalisedDamage = (_finalDamage / 50) min 1;

    if (_normalisedDamage <= 0.01) exitWith {};

    // Only apply damage to local units
    if !(local _target) exitWith {};

    // Check damage allowed
    if !(isDamageAllowed _target) exitWith {};
    if !(_target getVariable ["ace_medical_allowDamage", true]) exitWith {};

    // Route through ACE medical if available
    if !(isNil "ace_medical_fnc_addDamageToUnit") then {
        [_target, _normalisedDamage, "body", "explosive_overpressure", _source] call ace_medical_fnc_addDamageToUnit;
    } else {
        _target setDamage ((damage _target) + _normalisedDamage);
    };

    #ifdef DEBUG_MODE_FULL
        diag_log text format [
            "[%1] Applied damage to %2: normalised=%3 raw=%4 inVehicle=%5",
            ADDON, _target, _normalisedDamage, _rawDamage, !(isNull objectParent _target)
        ];
    #endif
} else {
    // Vehicle target — damage crew members
    private _vehicleArmour = getNumber (configOf _target >> "armor");
    private _isOpenTop = getNumber (configOf _target >> "openTop");
    private _crewDamageMultiplier = if (_isOpenTop isEqualTo 1) then {
        1
    } else {
        if (_vehicleArmour > ARMOUR_THRESHOLD) then {
            ARMOUR_THRESHOLD / _vehicleArmour
        } else {
            1
        }
    };

    {
        if (alive _x && {local _x}) then {
            private _crewDamage = _rawDamage * _crewDamageMultiplier;
            private _normalisedCrewDamage = (_crewDamage / 50) min 1;

            if (_normalisedCrewDamage <= 0.01) then { continue };
            if !(isDamageAllowed _x) then { continue };
            if !(_x getVariable ["ace_medical_allowDamage", true]) then { continue };

            if !(isNil "ace_medical_fnc_addDamageToUnit") then {
                [_x, _normalisedCrewDamage, "body", "explosive_overpressure", _source] call ace_medical_fnc_addDamageToUnit;
            } else {
                _x setDamage ((damage _x) + _normalisedCrewDamage);
            };

            #ifdef DEBUG_MODE_FULL
                diag_log text format [
                    "[%1] Applied crew damage to %2: normalised=%3 raw=%4 vehicle=%5",
                    ADDON, _x, _normalisedCrewDamage, _crewDamage, _target
                ];
            #endif
        };
    } forEach crew _target;
};
