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
*/

private _id = missionNamespace getVariable [QGVAR(nextID), 0];
missionNamespace setVariable [QGVAR(nextID), _id + 1, true];

_id
