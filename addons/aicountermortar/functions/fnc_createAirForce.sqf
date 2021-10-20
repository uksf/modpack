#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Creates air hunter force type

    Parameters:
        0: Spawn position <ARRAY>
        1: Target position <ARRAY>

    Return value:
        Nothing
*/
params ["_spawnPosition", "_targetPosition"];

[_spawnPosition, EAST, GVAR(unitPool), GVAR(airVehiclePool), {
    params ["_vehicle", "_turrets"];

    (_vehicle emptyPositions "driver") + count _turrets + (_vehicle emptyPositions "cargo")
}, {
    params ["_targetPosition", "_group", "_vehicle"];

    private _helipad = [_group, _targetPosition] call FUNC(assignWaypoints);
    _vehicle setUnloadInCombat [true, true];

    // seperate passenger group from initial _pilotGroup
    private _passengerGroup = createGroup EAST;
    (assignedCargo _vehicle) joinSilent _passengerGroup;
    [_passengerGroup, (_helipad getPos [30, random 360]), 0, "MOVE", "AWARE", "YELLOW", "NORMAL", "DIAMOND", "", [40, 50, 60]] call CBA_fnc_addWaypoint;
    [_passengerGroup, _targetPosition, 0, "SAD", "AWARE", "YELLOW", "NORMAL", "DIAMOND", QUOTE([this] call FUNC(handleDelete)), [40, 50, 60]] call CBA_fnc_addWaypoint;

    private _index = _vehicle addMPEventHandler ["MPHit", {
        params ["_vehicle"];

        private _index = _vehicle getVariable [QGVAR(hitEHID), -1];
        _vehicle removeMPEventHandler ["MPKilled", _index];

        [{GVAR(counterInProgress) = false}, [], 900] call CBA_fnc_waitAndExecute; // 15 minute wait time between tasks so mortars dont get spammed each time they fire
    }];

    _vehicle setVariable [QGVAR(hitEHID), _index, true];
}, [_targetPosition]] call EFUNC(common,spawnGroupVehicle);
