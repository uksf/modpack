/*
    Author:
        Tim Beswick

    Description:
        Gets vehicle data

    Parameter(s):
        0: Vehicle <OBJECT>

    Return Value:
        Data <ARRAY>
*/
#include "script_component.hpp"

params ["_vehicle"];

[
    _vehicle getVariable [QGVAR(persistenceID), ""],
    typeOf _vehicle,
    getPosASL _vehicle,
    [vectorDir _vehicle, vectorUp _vehicle],
    damage _vehicle,
    fuel _vehicle,
    magazinesAllTurrets _vehicle,
    [getAmmoCargo _vehicle, getFuelCargo _vehicle, getRepairCargo _vehicle]
    [(attachedObjects _vehicle) apply {typeOf _x}, (attachedObjects _vehicle) apply {_vehicle worldToModelVisual (ASLToAGL getPosASL _x)}],
    (([_vehicle] call acre_api_fnc_getVehicleRacks) apply {[_x] call acre_api_fnc_getMountedRackRadio}) apply {[_x] call acre_api_fnc_getRadioChannel},
    [_vehicle] call FUNC(getVehicleCargo),
    [getWeaponCargo _x, getMagazineCargo _x, getItemCargo _x, getBackpackCargo _x]
]
// vehicle weapon ammo
// vehicle cargo (fuel, ammo, repair etc)
