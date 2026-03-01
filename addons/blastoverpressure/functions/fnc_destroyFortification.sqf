#include "script_component.hpp"
/*
    Author:
        Beswick.T

    Description:
        Applies tier-appropriate destruction to a fortification object.

        Tier 1: setDamage with effects — Arma handles visual destruction,
                debris falls away from blast source.
        Tier 2: If damage would destroy, spawn dust effect and deleteVehicle.
                Otherwise apply fractional setDamage.

    Parameter(s):
        0: Fortification object <OBJECT>
        1: Damage to apply (0-1 scale, relative to object health) <NUMBER>
        2: Source object (blast origin for fall direction) <OBJECT>
        3: Destruction tier (1 or 2) <NUMBER>

    Return Value:
        None
*/
params ["_object", "_damage", "_source", "_tier"];

private _currentDamage = damage _object;
private _newDamage = (_currentDamage + _damage) min 1;

if (_tier isEqualTo 1) then {
    // Tier 1: good destruction model — let Arma handle it
    _object setDamage [_newDamage, true, _source];

    #ifdef DEBUG_MODE_FULL
        diag_log text format [
            "[%1] Fortification tier 1 damage: %2 (%3) currentDamage=%4 newDamage=%5",
            ADDON, typeOf _object, _object, _currentDamage, _newDamage
        ];
    #endif
} else {
    // Tier 2: bad/no destruction model
    if (_newDamage >= 1) then {
        // Would be destroyed — spawn dust effect and delete
        private _position = getPosATL _object;

        // Spawn dust particle effect at object position
        private _dustEffect = "#particlesource" createVehicleLocal _position;
        _dustEffect setParticleParams [
            ["\A3\data_f\ParticleEffects\Universal\Universal.p3d", 16, 12, 8, 0],
            "", "Billboard", 1, 3, [0, 0, 0], [0, 0, 1], 1, 1.275, 1, 0,
            [1, 3, 6], [[0.5, 0.4, 0.3, 0.6], [0.6, 0.5, 0.4, 0.3], [0.7, 0.6, 0.5, 0]],
            [0, 1], 0.1, 0.05, "", "", _object, 0, false, -1, [[3, 3, 3, 0]]
        ];
        _dustEffect setParticleRandom [3, [2, 2, 1], [2, 2, 2], 1, 0.5, [0, 0, 0, 0.1], 0, 0, 360];
        _dustEffect setDropInterval 0.01;

        // Clean up particle source after brief emission
        [{
            deleteVehicle _this;
        }, _dustEffect, 0.5] call CBA_fnc_waitAndExecute;

        deleteVehicle _object;

        #ifdef DEBUG_MODE_FULL
            diag_log text format [
                "[%1] Fortification tier 2 destroyed: %2 (%3) at %4",
                ADDON, typeOf _object, _object, _position
            ];
        #endif
    } else {
        // Partial damage — apply fractional setDamage
        _object setDamage [_newDamage, true, _source];

        #ifdef DEBUG_MODE_FULL
            diag_log text format [
                "[%1] Fortification tier 2 partial damage: %2 (%3) currentDamage=%4 newDamage=%5",
                ADDON, typeOf _object, _object, _currentDamage, _newDamage
            ];
        #endif
    };
};
