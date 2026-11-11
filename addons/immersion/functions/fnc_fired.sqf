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

    Example:
        [_shooter, _weapon, _ammo, _projectile] call uksf_immersion_fnc_fired
*/
params ["_shooter", "_weapon", "", "", "_ammo", "", "_projectile"];

if (!(isNull (ACE_controlledUAV#0)) || {GVAR(zeusOpen)}) exitWith {};

if ((toLower _weapon) isEqualTo "throw" || {(toLower _weapon) isEqualTo "put"}) exitWith {};

if (isNull _projectile) exitWith {};

private _shotOwner = _projectile getShotInfo 8;
_shooter = (getShotParents _projectile)#1;
_this set [0, _shooter];

[_shooter, _ammo] call FUNC(firedPlayerEffects);
[_ammo, _projectile] call FUNC(firedShockwave);

private _sameSide = (side effectiveCommander (vehicle _shotOwner)) == (side GVAR(suppression_currentUnit));

if (GVAR(closeMiss_enabled) && {!_sameSide} && {_shooter != GVAR(suppression_currentUnit)}) then {
    [_ammo, _projectile] call FUNC(closeMissDetect);
};

if (GVAR(suppression_enabled)) then {
    if (_sameSide) exitWith {};

    private _distance = GVAR(suppression_currentUnit) distance _shooter;
    if (_distance < 2500 && {_distance >= 30 || {!([_shooter, GVAR(suppression_currentUnit)] call EFUNC(common,lineOfSight))}}) then {
        [_ammo, _projectile] call FUNC(firedSuppression);
    };
};
