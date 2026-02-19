#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Spawns vehicle group from given unit and vehicle pools. Creates units over time to avoid performance degradation
        Group is disabled from caching and virtualisation

    Parameters:
        0: Position where group will spawn <ARRAY>
        1: Side of group <SIDE>
        2: Unit classname pool <ARRAY>
        3: Vehicle classname pool <ARRAY>
        4: Code to resolve vehicle crew count (Args passed: [_vehicle, _turrets]) <CODE> (Optional)
        5: Callback once spawning complete (Args passed: [callback args, _group, (_vehicle)]) <CODE> (Optional)
        6: Callback arguments <ARRAY> (Optional)

    Return value:
        Nothing
*/
#define SPAWN_DELAY 1
#define TIMEOUT 30

params [["_position", [], [[]]], ["_side", east, [sideUnknown]], ["_unitPool", []], ["_vehiclePool", []], ["_countCode", {-1}, [{}]], ["_callback", {}, [{}]], ["_callbackArgs", [], [[]]]];

TRACE_5("6) Spawn vehicle data",_position,_side,_unitPool,_vehiclePool,_countCode);

private _group = createGroup _side;
[QEGVAR(caching,disableCache), _group] call CBA_fnc_serverEvent;
[QEGVAR(virtualisation,exclude), _group] call CBA_fnc_serverEvent;

_position = +_position;
_position resize 2;

private _vehicle = createVehicle [selectRandom _vehiclePool, _position, [], 0, "NONE"];
_vehicle setVectorUp (surfaceNormal (getPos _vehicle));
_group addVehicle _vehicle;
TRACE_1("6) Spawn vehicle created vehicle",_vehicle);

private _turrets = allTurrets _vehicle;
private _count = [_vehicle, _turrets] call _countCode;
if (_count == -1) then {
    _count = (_vehicle emptyPositions "driver") + count _turrets + round ((_vehicle emptyPositions "cargo") / 1.5);
};
TRACE_2("6) Spawn vehicle position count",_turrets,_count);

[{
    params ["_args", "_idPFH"];
    _args params ["_group", "_vehicle", "_unitPool", "_count", "_turrets", "_time", "_callback", "_callbackArgs"];
    TRACE_1("6) Spawn vehicle iteration",_args);

    private _allSpawned = (count (crew _vehicle)) >= _count;
    if (!(alive _vehicle) || {_allSpawned} || {time > (_time + TIMEOUT)}) exitWith {
        TRACE_3("6) Spawn vehicle vehicle dead or all spawned or timeout",alive _vehicle,_allSpawned,time > (_time + TIMEOUT));
        [_idPFH] call CBA_fnc_removePerFrameHandler;

        if (_allSpawned) then {
            INFO("6) Spawn vehicle all spawned, running callback");
            _group selectLeader (effectiveCommander _vehicle);
            _callbackArgs pushBack _group;
            _callbackArgs pushBack _vehicle;
            _callbackArgs call _callback;
        };
    };

    private _unit = _group createUnit [selectRandom _unitPool, [0, 0, 2000], [], 0, "NONE"];
    INFO("6) Spawn vehicle created unit");

    if ((_vehicle emptyPositions "driver") > 0) exitWith {
        INFO("6) Spawn vehicle set unit as driver");
        _unit assignAsDriver _vehicle;
        _unit moveInDriver _vehicle;
        _unit setVariable [QGVAR(assignedVehicle), assignedVehicle _unit];
    };

    if (isNull (_vehicle turretUnit (_turrets#0))) exitWith {
        INFO("6) Spawn vehicle set unit as turret");
        _unit assignAsTurret [_vehicle, (_turrets#0)];
        _unit moveInTurret [_vehicle, (_turrets#0)];
        _unit setVariable [QGVAR(assignedVehicle), assignedVehicle _unit];
        _turrets deleteAt 0;
    };

    if ((_vehicle emptyPositions "cargo") > 0) exitWith {
        INFO("6) Spawn vehicle set unit as cargo");
        _unit assignAsCargo _vehicle;
        _unit moveInCargo _vehicle;
        _unit setVariable [QGVAR(assignedVehicle), assignedVehicle _unit];
    };
}, SPAWN_DELAY, [_group, _vehicle, _unitPool, _count, _turrets, time, _callback, _callbackArgs]] call CBA_fnc_addPerFrameHandler;
