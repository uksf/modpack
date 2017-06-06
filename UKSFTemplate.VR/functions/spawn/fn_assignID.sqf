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
#include "script_component.hpp"

private _ID = missionNamespace getVariable [QGVAR(nextID), 0];
missionNamespace setVariable [QGVAR(nextID), _ID + 1, true];

_ID
