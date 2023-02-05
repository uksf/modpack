#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Recreates a vehicle group
        Modified version of common,spawnGroupVehicle

    Parameters:
        0: uid <STRING>
        1: groupData <ARRAY> [_side, _unitDetailsArray, _waypointsArray, _combatMode]

    Return value:
        Nothing.
*/


#define SPAWN_DELAY 1
#define TIMEOUT 30

params ["_uid", "_groupData"];
_groupData params ["_side", "_unitDetailsArray", "_waypointsArray", "_combatMode"];
_unitDetailsArray params ["_vehiclePos", "_vehicleDir", "_vehicleType", "_engineState", "_fuelLevel", "_fullCrew", "_commanderSkill"];

private _crewUnitPool = [];
{_crewUnitPool pushBack (_x#0)} forEach _fullCrew;

TRACE_5("6) Spawn vehicle data",_position,_side,_unitPool,_vehiclePool,_countCode);

private _group = createGroup _side;
private _vehicle = createVehicle [_vehicleType, [0,0,0], [], 0, "NONE"];
_vehicle setPos _vehiclePos;
_vehicle setDir _vehicleDir;
_vehicle setVectorUp (surfaceNormal (getPos _vehicle));
_vehicle setFuel _fuelLevel;
_vehicle engineOn _engineState;
_group addVehicle _vehicle;

TRACE_1("6) Spawn vehicle created vehicle",_vehicle);

private _turrets = allTurrets _vehicle;
// private _count = [_vehicle, _turrets] call _countCode;
// if (_count == -1) then {
//     _count = (_vehicle emptyPositions "driver") + count _turrets + round ((_vehicle emptyPositions "cargo") / 1.5);
// };
TRACE_2("6) Spawn vehicle position count",_turrets,_count);

[{
    params ["_args", "_idPFH"];
    _args params ["_group", "_vehicle", "_crewUnitPool", "_turrets", "_time", "_waypointsArray", "_combatMode", "_uid"];
    TRACE_1("6) Spawn vehicle iteration",_args);

    if ((count _crewUnitPool == 0) || {time > (_time + TIMEOUT)}) exitWith {
        TRACE_2("6) Spawn unit all spawned or timeout",_crewUnitPool,time > (_time + TIMEOUT));

        // set group combat mode
        _group setCombatMode _combatMode;

        // create waypoints
        [_group, _waypointsArray] call FUNC(addWaypoints);

        // delete the entry from the hashmap
        GVAR(cachedGroupsData) deleteAt _uid;

        [_idPFH] call CBA_fnc_removePerFrameHandler;
    };
    private _crewUnit = _crewUnitPool deleteAt 0;
    private _unit = _group createUnit [_crewUnit, [0, 0, 2000], [], 0, "NONE"];
    INFO("6) Spawn vehicle created unit");

    if ((_vehicle emptyPositions "commander") > 0) exitWith {
        INFO("6) Spawn vehicle set unit as commander");
        _unit assignAsCommander _vehicle;
        _unit moveInCommander _vehicle;
        _args set [2, _crewUnitPool];
    };

    if ((_vehicle emptyPositions "driver") > 0) exitWith {
        INFO("6) Spawn vehicle set unit as driver");
        _unit assignAsDriver _vehicle;
        _unit moveInDriver _vehicle;
        _args set [2, _crewUnitPool];
    };

    if (isNull (_vehicle turretUnit (_turrets#0))) exitWith {
        INFO("6) Spawn vehicle set unit as turret");
        _unit assignAsTurret [_vehicle, (_turrets#0)];
        _unit moveInTurret [_vehicle, (_turrets#0)];
        _turrets deleteAt 0;
        _args set [2, _crewUnitPool];
    };

    if ((_vehicle emptyPositions "cargo") > 0) exitWith {
        INFO("6) Spawn vehicle set unit as cargo");
        _unit assignAsCargo _vehicle;
        _unit moveInCargo _vehicle;
        _args set [2, _crewUnitPool];
    };
}, SPAWN_DELAY, [_group, _vehicle, _crewUnitPool, _turrets, time, _waypointsArray, _combatMode, _uid]] call CBA_fnc_addPerFrameHandler;
