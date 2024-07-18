#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Creates a logistics run every x amount of seconds
        Will stop when all the 'runs' have been used up

    Parameters:
        0: The module logic <OBJECT>

    Return value:
        Nothing
*/
(_this select 1) params ["_logic"];

private _destinations = synchronizedObjects _logic;
private _time = _logic getVariable [QGVAR(ambientLogisticsInterval), 0];
private _units = parseSimpleArray (_logic getVariable [QGVAR(ambientLogisticsUnitPoolString), []]);
private _vehicles = parseSimpleArray (_logic getVariable [QGVAR(ambientLogisticsVehiclePoolString), []]);
private _side = _logic getVariable [QGVAR(ambientLogisticsSide), 0];
private _numberOfRunsRemaining = _logic getVariable [QGVAR(ambientLogisticsNumberOfRuns), 0];

[{
    params ["_args", "_idPFH"];
    _args params ["_destinations", "_units", "_vehicles", "_side", "_logic", "_numberOfRunsRemaining"];

    if (_numberOfRunsRemaining <= 0) exitWith {
        [_idPFH] call cba_fnc_removePerFrameHandler;
    };

    _args set [5, _numberOfRunsRemaining - 1];

    _side = switch (_side) do {
        case 0: { east };
        case 1: { west };
        case 2: { resistance };
    };

    // create vehicle and crew
    private _logiSpawnPos = getPos _logic;
    private _vehicle = createVehicle [selectRandom _vehicles, _logiSpawnPos, [], 10, "NONE"];
    private _group = createGroup _side;
    private _driverSlot = _vehicle emptyPositions "Driver";
    private _commanderSlot = _vehicle emptyPositions "Commander";
    private _gunnerSlot = _vehicle emptyPositions "Gunner";

    if (_driverSlot > 0) then {
        private _unit = _group createUnit [selectRandom _units, [0,0,0], [], 0, "NONE"];
        _unit moveInDriver _vehicle;
    };

    if (_commanderSlot > 0) then {
        private _unit = _group createUnit [selectRandom _units, [0,0,0], [], 0, "NONE"];
        _unit moveInCommander _vehicle;
    };

    if (_gunnerSlot > 0) then {
        private _unit = _group createUnit [selectRandom _units, [0,0,0], [], 0, "NONE"];
        _unit moveInGunner _vehicle;
    };

    [QEGVAR(virtualisation,exclude), _group] call CBA_fnc_serverEvent;

    // assign waypoints
    private _targetPos = selectRandom _destinations;
    [_group, _targetPos, 10, "MOVE", "SAFE"] call CBA_fnc_addWaypoint;
    [_group, _logiSpawnPos, 10, "MOVE", "SAFE", "", "", "", "{deleteVehicle _x} forEach crew (vehicle this) + [(vehicle this)];"] call CBA_fnc_addWaypoint;

}, _time, [_destinations, _units, _vehicles, _side, _logic, _numberOfRunsRemaining]] call cba_fnc_addPerFrameHandler;
