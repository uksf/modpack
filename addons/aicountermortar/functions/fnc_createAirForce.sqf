#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Creates air hunter force type

    Parameters:
        0: Spawn position <ARRAY>
        1: Mortar position <ARRAY>

    Return value:
        Nothing
*/
params ["_spawnPosition", "_mortarPosition"];

[_spawnPosition, 1, 0, EAST, GVAR(unitPool), GVAR(airVehiclePool), {
    params ["_vehicle", "_turrets"];

    (_vehicle emptyPositions "driver") + (_vehicle emptyPositions "cargo") + count _turrets
}, {
    params ["_mortarPosition", "", "_vehicle"];

    private _helipad = [_group, _mortarPosition] call FUNC(assignWaypoints);
    _vehicle setUnloadInCombat [true, true];

    // seperate passenger group from initial _pilotGroup
    private _passengerGroup = createGroup EAST;
    (assignedCargo _vehicle) joinSilent _passengerGroup;
    [_passengerGroup, (_helipad getPos [30, random 360]), 0, "MOVE", "AWARE", "YELLOW", "NORMAL", "DIAMOND", "", [40, 50, 60]] call CBA_fnc_addWaypoint;
    [_passengerGroup, _mortarPosition, 0, "SAD", "AWARE", "YELLOW", "NORMAL", "DIAMOND", QUOTE([this] call FUNC(handleDelete)), [40, 50, 60]] call CBA_fnc_addWaypoint;

    _vehicle addMPEventHandler ["MPHit", {
        [{GVAR(counterInProgress) = 0}, [], 900] call CBA_fnc_waitAndExecute; // 15 minute wait time between tasks so mortars dont get spammed each time they fire
    }];
}, [_mortarPosition]] call EFUNC(common,spawnGroup);
