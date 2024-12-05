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

if (_destinations isEqualTo []) exitWith {};

private _time = _logic getVariable [QGVAR(ambientLogisticsInterval), 900];
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
        case 0: { EAST };
        case 1: { WEST };
        case 2: { RESISTANCE };
    };

    // create vehicle and crew
    private _targetPos = selectRandom _destinations;
    private _logiSpawnPos = getPos _logic;
    [_logiSpawnPos, _side, _units, _vehicles, {
        params ["_vehicle", "_turrets"];
        private _count = (_vehicle emptyPositions "driver") + (_vehicle emptyPositions "commander") + count _turrets;
        _count
    }, {
        params ["_args", "_group"];
        _args params ["_targetPos", "_logiSpawnPos"];
        // diag_log format ["---Ambient Logistics--- %1, %2", _group, _targetPos];
        [_group, _targetPos, 10, "MOVE", "SAFE"] call CBA_fnc_addWaypoint;
    }, [_targetPos, _logiSpawnPos]] call EFUNC(common,spawnGroupVehicle);

    // private _vehicle = createVehicle [selectRandom _vehicles, _logiSpawnPos, [], 10, "NONE"];
    // private _group = createGroup _side;
    // private _driverSlot = _vehicle emptyPositions "Driver";
    // private _commanderSlot = _vehicle emptyPositions "Commander";
    // private _gunnerSlot = _vehicle emptyPositions "Gunner";

    // if (_driverSlot > 0) then {
    //     private _unit = _group createUnit [selectRandom _units, [0,0,0], [], 0, "NONE"];
    //     _unit moveInDriver _vehicle;
    // };

    // if (_commanderSlot > 0) then {
    //     private _unit = _group createUnit [selectRandom _units, [0,0,0], [], 0, "NONE"];
    //     _unit moveInCommander _vehicle;
    // };

    // if (_gunnerSlot > 0) then {
    //     private _unit = _group createUnit [selectRandom _units, [0,0,0], [], 0, "NONE"];
    //     _unit moveInGunner _vehicle;
    // };

    // [QEGVAR(virtualisation,exclude), _group] call CBA_fnc_serverEvent;

    // assign waypoints


}, _time, [_destinations, _units, _vehicles, _side, _logic, _numberOfRunsRemaining]] call cba_fnc_addPerFrameHandler;
