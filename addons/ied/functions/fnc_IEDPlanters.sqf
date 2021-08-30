#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Sets synchronizedObjects to be IED planters.
        They'll move to random locations and plant IEDs.
        The nearest building will be classed as their 'home' and is where they'll return to after laying IEDs.

    Parameters:
        0: logic <OBJECT>
        1: area <ARRAY>
        2: planterBackpacks <ARRAY>

    Return value:
        Nothing
*/

params ["_module", "_area", "_planterBackpacks"];

if (!(local _module)) exitWith {};

{
    private _planterHome = nearestBuilding _x;

    if (_planterHome == objNull) exitWith {diag_log format ["(UKSF IED ERROR): %1 at position %2 has no nearby building", _x, getPos _x]};

    _x setVariable [QGVAR(planterHome), _planterHome];

    // stored on planter for use in waypoints
    _x setVariable [QGVAR(moduleObject), _module, true];
    _x setVariable [QGVAR(area), _area, true];

    removeGoggles _x;
    _x addBackpack (selectRandom _planterBackpacks);

    [_x] call FUNC(setWaypointPlanter);
} forEach (synchronizedObjects _module);
