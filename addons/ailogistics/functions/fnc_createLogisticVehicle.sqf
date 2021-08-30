#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Creates the logistical vehicle

    Parameters:
        0: _module <OBJECT>

    Return value:
        Nothing
*/


if (!isServer) exitWith {};

params ["_module"];

private _time = _module getVariable [QGVAR(logisticsTimeout), 0];
// private _logisticsObject = (synchronizedObjects _module) select {!((_x isKindOf "uksf_ailogistics_logisticsPicketGroup") || (_x isKindOf "uksf_ailogistics_logisticsDestination"))};
private _logisticsObject = (synchronizedObjects _module) select {_x isKindOf "Building"};
private _side = _module getVariable [QGVAR(side), EAST];
private _logisticVehiclePoolStringRaw = _module getVariable [QGVAR(logisticVehiclePoolString), ""];
private _driverUnitPoolStringRaw = _module getVariable [QGVAR(driverUnitPoolString), ""];
private _logisticVehiclePoolStringParsed = parseSimpleArray _logisticVehiclePoolStringRaw;
private _driverUnitPoolStringParsed = parseSimpleArray _driverUnitPoolStringRaw;

if (!alive (_logisticsObject select 0)) exitWith {};

// create the logi vehicle
[getPos _module, 1, 1, _side, _driverUnitPoolStringParsed, _logisticVehiclePoolStringParsed, {-1}, {call FUNC(logisticWaypoints)}, [_module]] call EFUNC(common,spawnGroup); // uksf spawn function


[{
    params ["_module"];
    [_module] call FUNC(createLogisticVehicle);
}, [_module], random _time] call cba_fnc_waitAndExecute;

