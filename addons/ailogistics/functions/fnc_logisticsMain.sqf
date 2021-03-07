#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Main function

    Parameters:


    Return value:
        Nothing
*/


if (!isServer) exitWith {};

(_this select 1) params ["_module"];


// get all modules parameters
private _destinations = synchronizedObjects _module;
private _time = _module getVariable [QGVAR(logisticsTimeout),0];
private _groupSize = _module getVariable [QGVAR(picketGroupSize),0];
private _picketUnits = _module getVariable [QGVAR(picketUnitPoolString),[]];
private _sideFromModule = _module getVariable [QGVAR(side),0];

// get side then update the variable with an actual side, get the updated version
if (_sideFromModule == 0) then {
    _module setVariable [QGVAR(side),EAST];
} else {
    _module setVariable [QGVAR(side),INDEPENDENT];
};
private _side = _module getVariable [QGVAR(side),EAST];



// establish the route
private _agent = createAgent ["C_Man_1", getPos _module, [], 0, "NONE"];
private _car = "B_Quadbike_01_F" createVehicle (getPos _module);
_agent moveInDriver _car;

_agent setVariable [QGVAR(module),_module];

// workaround ai spawning at the end the route due to double execution bug of pathCalculated EH.
// if this is called twice by sync-ing more than one destination module, it only picks route. Seems that you have to wait until the path calc's once before you can do it again.
// if there is a way to do the above, one start module could support multiple destinations 1, would also require multi vehicle support

_agent setDestination [(_destinations select 0), "LEADER PLANNED", true];

_agent addEventHandler ["PathCalculated", {
    params ["_agent", "_path"];
    private _module = _agent getVariable [QGVAR(module),objNull];
    if ((_module getVariable [QGVAR(routePickets),false]) == false) exitWith {};
    private _picketLocationsRaw = _module getVariable [QGVAR(picketLocations),[0.5]]; // "[0.4,0.7]"
    private _picketLocationsParsed = parseSimpleArray _picketLocationsRaw;

    // this prevents looping
    deleteVehicle (vehicle _agent);
    deleteVehicle _agent;

    // workout the points in _path
    private _picketPoints = [];
    {
        private _percent = (round(count _path) * _x);
        _picketPoints pushBack (_path select _percent);
    } forEach _picketLocationsParsed;

    // create the pickets
    private _groupSize = _module getVariable [QGVAR(picketGroupSize),0];
    private _side = _module getVariable [QGVAR(side),EAST];
    private _picketUnitsRaw = _module getVariable [QGVAR(picketUnitPoolString),[]];
    private _picketUnitsParsed = parseSimpleArray _picketUnitsRaw;

    {
        [_x, 0, _groupSize, _side, _picketUnitsParsed, [], {}, {call FUNC(patrol)}] call EFUNC(common,spawnGroup); // uksf spawn function
    } forEach _picketPoints;

}];

private _fnc_createLogisticVehicle = {

    params ["_module","_fnc_createLogisticVehicle"];

    // private _vehicleNumber = _module getVariable [QGVAR(logisticalVehicleNumber),"0"];
    // private _vehicleNumberParsed = parseNumber _vehicleNumber;
    private _time = _module getVariable [QGVAR(logisticsTimeout),0];
    private _logisticsObject = missionNamespace getVariable [QGVAR(logisticsObject), ObjNull];
    private _side = _module getVariable [QGVAR(side),EAST];
    private _logisticVehiclePoolStringRaw = _module getVariable [QGVAR(logisticVehiclePoolString),""];
    private _driverUnitPoolStringRaw = _module getVariable [QGVAR(driverUnitPoolString),""];
    private _logisticVehiclePoolStringParsed = parseSimpleArray _logisticVehiclePoolStringRaw;
    private _driverUnitPoolStringParsed = parseSimpleArray _driverUnitPoolStringRaw;

    if ((_vehicleNumberParsed <= 0) || (!alive _logisticsObject) || (isNull _logisticsObject)) exitWith {};

    // create the logi vehicle
    [getPos _module, 1, 1, _side, _driverUnitPoolStringParsed, _logisticVehiclePoolStringParsed, {-1}, {call FUNC(logisticWaypoints)}, [_module]] call EFUNC(common,spawnGroup); // uksf spawn function

    [{
        params ["_module","_fnc_createLogisticVehicle"];
        [_module,_fnc_createLogisticVehicle] call _fnc_createLogisticVehicle;
    }, [_module,_fnc_createLogisticVehicle], random _time] call cba_fnc_waitAndExecute;
};

[{
    params ["_module","_fnc_createLogisticVehicle"];
    [_module,_fnc_createLogisticVehicle] call _fnc_createLogisticVehicle;
}, [_module,_fnc_createLogisticVehicle], random _time] call cba_fnc_waitAndExecute;
