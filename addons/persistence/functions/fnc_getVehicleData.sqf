#include "script_component.hpp"
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

private _pylonMagazines = getPylonMagazines _vehicle;
private _turretMagazines = (magazinesAllTurrets _vehicle) select {!(_x#0 in _pylonMagazines)};
private _turretPaths = _turretMagazines apply {_x#1};
_turretPaths = _turretPaths arrayIntersect _turretPaths;
private _turretWeapons = _turretPaths apply {[_x, _vehicle weaponsTurret _x]};
private _pylonLoadout = [];
{
    _pylonLoadout pushBack [_x, _vehicle ammoOnPylon (_forEachIndex + 1)];
} forEach _pylonMagazines;

private _data = [
    _vehicle getVariable [QGVAR(persistenceID), ""],
    typeOf _vehicle,
    getPosASL _vehicle,
    [vectorDir _vehicle, vectorUp _vehicle],
    damage _vehicle,
    fuel _vehicle,
    _turretWeapons,
    _turretMagazines,
    _pylonLoadout,
    [getAmmoCargo _vehicle, getFuelCargo _vehicle, getRepairCargo _vehicle],
    _attachedObjects,
    (((([_vehicle] call acre_api_fnc_getVehicleRacks) select {_x != ""}) apply {[_x] call acre_api_fnc_getMountedRackRadio}) select {_x != ""}) apply {[_x] call acre_api_fnc_getRadioChannel},
    [_vehicle] call FUNC(getVehicleCargo),
    [getWeaponCargo _vehicle, getMagazineCargo _vehicle, getItemCargo _vehicle, getBackpackCargo _vehicle]
];
//TRACE_1("Got vehicle data",_data);

_data
