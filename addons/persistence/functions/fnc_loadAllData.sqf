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

[{call FUNC(loadAllObjectData)}] call CBA_fnc_execNextFrame;
