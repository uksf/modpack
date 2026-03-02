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
        Whether the object was destroyed <BOOLEAN>
*/
params ["_object", "_damage", "_source", "_tier"];

private _currentDamage = damage _object;
private _newDamage = (_currentDamage + _damage) min 1;

private _destroyed = false;

if (_tier isEqualTo 1) then {
    // Tier 1: good destruction model — let Arma handle it
    _object setDamage [_newDamage, true, _source];
    _destroyed = _newDamage >= 1;

    #ifdef DEBUG_MODE_FULL
        diag_log text format [
            "[%1] Fortification tier 1 damage: %2 (%3) currentDamage=%4 newDamage=%5",
            ADDON, typeOf _object, _object, _currentDamage, _newDamage
        ];
    #endif
} else {
    // Tier 2: bad/no destruction model
    if (_newDamage >= 1) then {
        // Would be destroyed — spawn dust effect on all clients, then delete
        private _position = getPosATL _object;

        [QGVAR(fortificationDustEffect), [_position]] call CBA_fnc_globalEvent;

        deleteVehicle _object;
        _destroyed = true;

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

_destroyed
