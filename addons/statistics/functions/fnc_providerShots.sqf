#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Shots provider setup. Installs a FiredMan event handler on the local player
        to capture every shot fired. Each shot is tagged with a unique ID that is
        stored on the projectile so the hits provider can correlate hits to shots.

    Parameters:
        None

    Return Value:
        None

    Example:
        call uksf_statistics_fnc_providerShots
*/
GVAR(shotCounter) = 0;

GVAR(firedManEHId) = player addEventHandler ["FiredMan", {
    params ["_unit", "_weapon", "_muzzle", "_mode", "_ammo", "_magazine", "_projectile", "_vehicle"];

    GVAR(shotCounter) = GVAR(shotCounter) + 1;
    private _shotId = format ["%1_%2", getPlayerUID _unit, GVAR(shotCounter)];

    if (!isNull _projectile) then {
        _projectile setVariable [QGVAR(shotId), _shotId];
    };

    [createHashMapFromArray [
        ["type", "shot"],
        ["shotId", _shotId],
        ["weapon", _weapon],
        ["magazine", _magazine],
        ["fireMode", _mode]
    ]] call FUNC(addEvent);
}];
