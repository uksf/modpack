#include "script_component.hpp"
/*
    Author:
        Beswick.T

    Description:
        Gets and caches ammo configuration values for blast overpressure.
        Returns cached values if previously computed for this ammo type.

    Parameter(s):
        0: Ammo class name <STRING>

    Return Value:
        [indirectHit, indirectHitRange, powerScore, damageMultiplier, isEnabled] or []
*/
params ["_ammo"];

private _cached = GVAR(ammoConfigCache) getOrDefault [_ammo, []];
if (_cached isNotEqualTo []) exitWith { _cached };

private _ammoConfig = configFile >> "CfgAmmo" >> _ammo;

// Check per-ammo blacklist
private _isEnabled = getNumber (_ammoConfig >> QGVAR(enabled));
if (_isEnabled isEqualTo 0) exitWith {
    private _result = [0, 0, 0, 0, false];
    GVAR(ammoConfigCache) set [_ammo, _result];
    _result
};

private _indirectHit = getNumber (_ammoConfig >> "indirectHit");
private _indirectHitRange = getNumber (_ammoConfig >> "indirectHitRange");

if (_indirectHit <= 0 || {_indirectHitRange <= 0}) exitWith {
    private _result = [0, 0, 0, 0, false];
    GVAR(ammoConfigCache) set [_ammo, _result];
    _result
};

private _powerScore = _indirectHit * sqrt _indirectHitRange;

// Per-ammo damage multiplier override (default 1.0 if not set)
private _ammoDamageMultiplier = getNumber (_ammoConfig >> QGVAR(damageMultiplier));
if (_ammoDamageMultiplier isEqualTo 0) then {
    _ammoDamageMultiplier = 1;
};

private _result = [_indirectHit, _indirectHitRange, _powerScore, _ammoDamageMultiplier, true];
GVAR(ammoConfigCache) set [_ammo, _result];

_result
