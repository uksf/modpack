#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Shots provider setup. Listens to ACE fired events to capture every round
        fired by the local player, both on foot and in vehicles.
        Records weapon, ammo classname, magazine, and fire mode.
        Tags each projectile with a unique shotId so the hits provider can
        correlate hits to shots and deduplicate.

    Parameters:
        None

    Return Value:
        None

    Example:
        call uksf_statistics_fnc_providerShots
*/
GVAR(shotCounter) = 0;

private _handleFired = {
    params ["_unit", "_weapon", "_muzzle", "_mode", "_ammo", "_magazine", "_projectile"];
    private _startTime = diag_tickTime;

    // Store launch position locally for distance tracking by combat damage provider
    _unit setVariable [QGVAR(lastFiredPosition), getPosASL _unit];

    GVAR(shotCounter) = GVAR(shotCounter) + 1;
    private _shotId = format ["%1_%2", getPlayerUID _unit, GVAR(shotCounter)];

    if (!isNull _projectile) then {
        _projectile setVariable [QGVAR(shotId), _shotId];
        _projectile setVariable [QGVAR(weapon), _weapon];
    };

    [createHashMapFromArray [
        ["type", "shot"],
        ["shotId", _shotId],
        ["weapon", _weapon],
        ["ammo", _ammo],
        ["magazine", _magazine],
        ["fireMode", _mode]
    ]] call FUNC(addEvent);

    ["shots", _startTime] call FUNC(addProviderTiming);
};

["ace_firedPlayer", _handleFired] call CBA_fnc_addEventHandler;
["ace_firedPlayerVehicle", _handleFired] call CBA_fnc_addEventHandler;
