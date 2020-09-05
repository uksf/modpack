#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Create an AA vehicle

    Parameters:
        0: AA Site <OBJECT>

    Return value:
        Nothing
*/
params ["_emptyLocation"];

[getPos (selectRandom GVAR(aaSpawns)), 1, 0, EAST, EGVAR(gear,gearCrew), EGVAR(gear,gearVehAA), {
    params ["_vehicle", "_turrets"];

    (_vehicle emptyPositions "driver") + count _turrets
}, {
    params ["_emptyLocation", "_group"];

    [_group, _emptyLocation, 50, "MOVE", "SAFE", "YELLOW", "NORMAL", "", "(vehicle this) setFuel 0; (group this) setBehaviour 'AWARE'"] call CBA_fnc_addWaypoint;
}, [_emptyLocation]] call EFUNC(common,spawnGroup);

