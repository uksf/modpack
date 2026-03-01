#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Shots provider setup. Installs a FiredMan event handler on the local player
        to capture every shot fired. Each shot is recorded as a raw event.
        Also fires a local event so other providers (e.g. hits) can attach
        projectile-level event handlers.

    Parameters:
        None

    Return Value:
        None
*/
player addEventHandler ["FiredMan", {
    params ["_unit", "_weapon", "_muzzle", "_mode", "_ammo", "_magazine", "_projectile", "_vehicle"];

    [createHashMapFromArray [
        ["type", "shot"],
        ["weapon", _weapon],
        ["magazine", _magazine],
        ["fireMode", _mode]
    ]] call FUNC(addEvent);

    [QGVAR(shotFired), [_unit, _weapon, _projectile]] call CBA_fnc_localEvent;
}];
