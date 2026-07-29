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

if (isNull _projectile) then {
    _projectile = nearestObject [_shooter, _ammo];
    _this set [6, _projectile];
};

private _shotParents = getShotParents _projectile;
if (_shotParents isEqualTo []) exitWith {};

_shooter = _shotParents#1;
_this set [0, _shooter];

[_shooter, _ammo] call FUNC(firedPlayerEffects);
[_ammo, _projectile] call FUNC(firedShockwave);

private _sameSide = (side effectiveCommander (vehicle _shooter)) == (side GVAR(suppression_currentUnit));

if (GVAR(closeMiss_enabled) && {!_sameSide} && {_shooter != GVAR(suppression_currentUnit)}) then {
    [_ammo, _projectile] call FUNC(closeMissDetect);
};

if (GVAR(suppression_enabled)) then {
    if (_sameSide) exitWith {};

    private _distance = GVAR(suppression_currentUnit) distance _shooter;
    // If shooter is close and not in line of sight of unit, run suppression effects
    if (_distance < 2500 && {_distance >= 30 || {!([_shooter, GVAR(suppression_currentUnit)] call EFUNC(common,lineOfSight))}}) then {
        [_ammo, _projectile] call FUNC(firedSuppression);
    };
};
