#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Returns unique ID.

    Parameters:
        None

    Return value:
        Unique ID <SCALAR>

    Example:
        call uksf_mission_fnc_assignID
*/

private _id = missionNamespace getVariable [QGVAR(nextID), 0];
missionNamespace setVariable [QGVAR(nextID), _id + 1, true];

_id
