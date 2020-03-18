#include "script_component.hpp"
/*
    Author:
        LAxemann, Jokoho482, Tim Beswick

    Description:
        Fired Event

    Parameters:
        Fired Event Parameters

    Return value:
        None
*/
params ["_shooter", "_weapon", "", "", "_ammo", "", "_projectile"];

if (!(isNull (ACE_controlledUAV#0)) || {GVAR(zeusOpen)}) exitWith {};

if ((toLower _weapon) isEqualTo "throw" || {(toLower _weapon) isEqualTo "put"}) exitWith {};

if (isNull _projectile) then {
    _projectile = nearestObject [_shooter, _ammo];
    _this set [6, _projectile];
};

private _ammoConfig = GVAR(ammoConfig) >> _ammo;
_this set [7, _ammoConfig];

call FUNC(firedShockwave);

if (GVAR(firing_force)) then {
    call FUNC(firedForce);
};

if (GVAR(firing_recoil)) then {
    call FUNC(firedRecoil);
};

if (GVAR(suppression_enabled)) then {
    if ((side effectiveCommander (vehicle _unit)) == (side GVAR(suppression_currentUnit))) exitWith {};

    private _distance = GVAR(suppression_currentUnit) distance _unit;
    if (_distance >= 2500) exitWith {};
    if (_distance < 30) exitWith {
        private _pos = worldToScreen (getPosWorld _unit);
        // Maybe implement a hash to act as a cache to redcue checkVisibility calls in quick succession (5 second timeout?)
        private _los = (count _pos) > 0 && {(abs (_pos#0)) < 1.5 && {(abs (_pos#1)) < 1.5 && {([GVAR(suppression_currentUnit), "VIEW", (vehicle GVAR(suppression_currentUnit))] checkVisibility [eyePos GVAR(suppression_currentUnit), eyePos _unit]) > 0}}};
        if (!_los) then {
            call FUNC(firedSuppression);
        };
    };
    call FUNC(firedSuppression);
};


