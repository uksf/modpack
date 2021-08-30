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
private _picketLocations = (synchronizedObjects _module) select {_x isKindOf "uksf_ailogistics_logisticsPicketGroup"};
private _picketBool = _module getVariable [QGVAR(routePickets), false];
private _sideFromModule = _module getVariable [QGVAR(side), 0];


// get side then update the variable with an actual side, get the updated version
if (_sideFromModule isEqualTo 0) then {
    _module setVariable [QGVAR(side), EAST];
} else {
    _module setVariable [QGVAR(side), INDEPENDENT];
};
private _side = _module getVariable [QGVAR(side), EAST];


if (_picketBool) then {
    [_picketLocations] call FUNC(createPickets);
};

[_module] call FUNC(createLogisticVehicle);
