#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Recreates a vehicle group
        Modified version of common,spawnGroupVehicle

    Parameters:
        0: Group data <ARRAY>
            0: Group type <SCALAR>
            1: Side <SIDE>
            2: Unit Details <ARRA>
            3: Waypoints <ARRAY>
            4: CombatMode <STRING>

    Return value:
        Nothing
*/
#define SPAWN_DELAY 1
#define TIMEOUT 30

params ["_groupData"];
_groupData ["", "_side", "_vehicleDetails", "_waypoints", "_combatMode"];
_vehicleDetails params ["_type", "_position", "_direction", "_engineState", "_fuel", "_crewTypes"];

private _group = createGroup _side;
private _vehicle = createVehicle [_type, [0,0,0], [], 0, "NONE"];
_vehicle setDir _direction;
_vehicle setPos _position;
_vehicle setVectorUp (surfaceNormal (getPos _vehicle));
_vehicle setFuel _fuel;
_vehicle engineOn _engineState;
TRACE_1("Spawn vehicle created vehicle",_vehicle);

_group addVehicle _vehicle;
_group setCombatMode _combatMode;

private _turrets = allTurrets _vehicle;
// private _count = [_vehicle, _turrets] call _countCode;
// if (_count == -1) then {
//     _count = (_vehicle emptyPositions "driver") + count _turrets + round ((_vehicle emptyPositions "cargo") / 1.5);
// };
// TRACE_2("Spawn vehicle position count",_turrets,_count);

[{
    params ["_args", "_idPFH"];
    _args params ["_time", "_group", "_vehicle", "_crewTypes", "_turrets", "_waypoints"];
    TRACE_1("Spawn vehicle iteration",_args);

    if ((count _crewTypes == 0) || {time > (_time + TIMEOUT)}) exitWith {
        TRACE_2("Spawn unit all spawned or timeout",_crewTypes,time > (_time + TIMEOUT));
        [_idPFH] call CBA_fnc_removePerFrameHandler;

        [_group, _waypoints] call FUNC(addWaypoints);
    };

    private _crewType = _crewTypes deleteAt 0;
    private _unit = _group createUnit [_crewType, [0,0,0], [], 0, "NONE"];

    // TODO: This isn't accurate to how the crew of the vehicle actually were before virtualisation
    // Should be making proper use of fullCrew and its info to set these units accurately
    if ((_vehicle emptyPositions "commander") > 0) exitWith {
        DEBUG("Spawn vehicle set unit as commander");
        _unit assignAsCommander _vehicle;
        _unit moveInCommander _vehicle;
    };

    if ((_vehicle emptyPositions "driver") > 0) exitWith {
        DEBUG("Spawn vehicle set unit as driver");
        _unit assignAsDriver _vehicle;
        _unit moveInDriver _vehicle;
    };

    if (isNull (_vehicle turretUnit (_turrets#0))) exitWith {
        DEBUG("Spawn vehicle set unit as turret");
        _unit assignAsTurret [_vehicle, (_turrets#0)];
        _unit moveInTurret [_vehicle, (_turrets#0)];
        _turrets deleteAt 0;
    };

    if ((_vehicle emptyPositions "cargo") > 0) exitWith {
        DEBUG("Spawn vehicle set unit as cargo");
        _unit assignAsCargo _vehicle;
        _unit moveInCargo _vehicle;
    };

    // Fallback for units that haven't been moved inside the vehicle for whatever reason
    _unit setPos (getPos _vehicle);
}, SPAWN_DELAY, [time, _group, _vehicle, _crewTypes, _turrets, _waypoints]] call CBA_fnc_addPerFrameHandler;
