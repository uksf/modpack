#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Spawns group based on mode with given unit and vehicle pools. Creates units over time to avoid performance degradation
        Group is disabled from caching

    Parameters:
        0: Position where group will spawn <ARRAY>
        1: Type of group (0 = infantry, 1 = vehicle) <NUMBER>
        2: Number of units in group (only applies for infantry spawn) <NUMBER>
        3: Side of group <SIDE>
        4: Unit classname pool <ARRAY>
        5: Vehicle classname pool <ARRAY>
        6: Code to resolve vehicle crew count (Args passed: [_vehicle, _turrets]) <CODE> (Optional)
        7: Callback once spawning complete (Args passed: [callback args, _group, (_vehicle)]) <CODE> (Optional)
        8: Callback arguments <ARRAY> (Optional)

    Return value:
        Nothing
*/
#define SPAWN_DELAY 1
#define TIMEOUT 30

params [["_position", [], [[]]], ["_type", 0, [0]], ["_count", 1, [0]], ["_side", EAST, [sideUnknown]], ["_unitPool", []], ["_vehiclePool", []], ["_countCode", {-1}, [{}]], ["_callback", {}, [{}]], ["_callbackArgs", [], [[]]]];

private _group = createGroup _side;
_position = +_position;
_position resize 2;

[QEGVAR(caching,disableCache), _group] call CBA_fnc_serverEvent;

if (_type isEqualTo 0) exitWith {
    [{
        params ["_args", "_idPFH"];
        _args params ["_position", "_group", "_unitPool", "_count", "_check", "_time", "_callback", "_callbackArgs"];

        private _allSpawned = (count _check) isEqualTo _count;
        if (_allSpawned || {time > (_time + TIMEOUT)}) exitWith {
            [_idPFH] call CBA_fnc_removePerFrameHandler;

            if (_allSpawned) then {
                _callbackArgs pushBack _group;
                _callbackArgs call _callback;
            };
        };

        (selectRandom _unitPool) createUnit [_position, _group];

        _check pushBack 0;
    }, SPAWN_DELAY, [_position, _group, _unitPool, _count, [], time, _callback, _callbackArgs]] call CBA_fnc_addPerFrameHandler;
};

private _vehicle = createVehicle [selectRandom _vehiclePool, _position, [], 0, "NONE"];
_vehicle setVectorUp (surfaceNormal (getPos _vehicle));
_group addVehicle _vehicle;

private _turrets = allTurrets _vehicle;
_count = [_vehicle, _turrets] call _countCode;
if (_count == -1) then {
    _count = (_vehicle emptyPositions "driver") + count _turrets + round ((_vehicle emptyPositions "cargo") / 1.5);
};

[{
    params ["_args", "_idPFH"];
    _args params ["_group", "_vehicle", "_unitPool", "_count", "_turrets", "_time", "_callback", "_callbackArgs"];

    private _allSpawned = (count (crew _vehicle)) >= _count;
    if (!(alive _vehicle) || {_allSpawned} || {time > (_time + TIMEOUT)}) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;

        if (_allSpawned) then {
            _group selectLeader (effectiveCommander _vehicle);
            _callbackArgs pushBack _group;
            _callbackArgs pushBack _vehicle;
            _callbackArgs call _callback;
        };
    };

    private _unit = _group createUnit [selectRandom _unitPool, [0, 0, 2000], [], 0, "NONE"];

    if ((_vehicle emptyPositions "driver") > 0) exitWith {
        _unit assignAsDriver _vehicle;
        _unit moveInDriver _vehicle;
        _unit setVariable [QGVAR(assignedVehicle), assignedVehicle _unit]; // TODO: Find cleaner way of doing this with no repeated code below
    };

    if (isNull (_vehicle turretUnit (_turrets#0))) exitWith {
        _unit assignAsTurret [_vehicle, (_turrets#0)];
        _unit moveInTurret [_vehicle, (_turrets#0)];
        _unit setVariable [QGVAR(assignedVehicle), assignedVehicle _unit];
        _turrets deleteAt 0;
    };

    if ((_vehicle emptyPositions "cargo") > 0) exitWith {
        _unit assignAsCargo _vehicle;
        _unit moveInCargo _vehicle;
        _unit setVariable [QGVAR(assignedVehicle), assignedVehicle _unit];
    };
}, SPAWN_DELAY, [_group, _vehicle, _unitPool, _count, _turrets, time, _callback, _callbackArgs]] call CBA_fnc_addPerFrameHandler;
