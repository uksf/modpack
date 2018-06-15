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
TRACE_1("Getting vehicle data for",_vehicle);

private _attachedObjects = [];
private _vehicleAttachedObjects = _vehicle getVariable ["ace_attach_attached", []];
if (count _vehicleAttachedObjects > 0) then {
    {
        _x params ["_attachedObject", "_itemClassname"];
        _attachedObjects pushBack [_itemClassname, _vehicle worldToModelVisual (ASLToAGL getPosASL _attachedObject)];
    } forEach _vehicleAttachedObjects;
};

private _data = [
    _vehicle getVariable [QGVAR(persistenceID), ""],
    typeOf _vehicle,
    getPosASL _vehicle,
    [vectorDir _vehicle, vectorUp _vehicle],
    damage _vehicle,
    fuel _vehicle,
    magazinesAllTurrets _vehicle,
    [getAmmoCargo _vehicle, getFuelCargo _vehicle, getRepairCargo _vehicle],
    _attachedObjects,
    (([_vehicle] call acre_api_fnc_getVehicleRacks) apply {[_x] call acre_api_fnc_getMountedRackRadio}) apply {[_x] call acre_api_fnc_getRadioChannel},
    [_vehicle] call FUNC(getVehicleCargo),
    [getWeaponCargo _x, getMagazineCargo _x, getItemCargo _x, getBackpackCargo _x]
];
TRACE_1("Got vehicle data",_data);

_data
