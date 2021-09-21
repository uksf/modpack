#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Loads all saved data

    Parameter(s):
        None

    Return Value:
        None
*/

private _ratingAreas = GVAR(dataNamespace) getVariable [QGVAR(ratingAreas), []];
[_ratingAreas] call EFUNC(arearating,deserializeRatingAreas);

// Get persistent safehouse logic ids
// Get area data and delete terrain objects at location
// Delete all location logics with persistent id

// Get persistent destroyed safehouse ids
// Delete all location logics within Xm of destroyed safehouse ids

[{call FUNC(loadAllObjectData)}] call CBA_fnc_execNextFrame;
