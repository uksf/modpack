#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Gets object data

    Parameter(s):
        0: Object <OBJECT>

    Return Value:
        Data <ARRAY>
            Field layout (indices defined in script_component.hpp as IDX_OBJ_*):
             0: ID              - persistenceID string
             1: Type            - typeOf classname
             2: Position        - getPosASL
             3: VectorDirUp     - [vectorDir, vectorUp]
             4: Damage          - damage scalar
             5: Fuel            - fuel scalar
             6: TurretWeapons   - [[turretPath, weapons], ...]
             7: TurretMagazines - magazinesAllTurrets (minus pylons)
             8: PylonLoadout    - [[magazine, ammo], ...]
             9: Logistics       - [ammoCargo, fuelCargo, repairCargo]
            10: Attached        - [[classname, offset], ...]
            11: RackChannels    - ACRE rack radio channels
            12: AceCargo        - nested cargo objects
            13: Inventory       - [weapons, magazines, items, backpacks]
            14: AceFortify      - [isAceFortification, side]
            15: AceMedical      - [medicClass, medicalVehicle, medicalFacility]
            16: AceRepair       - [repairVehicle, repairFacility]
            17: CustomName      - ace_cargo_customName string
            18: FailedLastLoad  - bool (set by loadAllObjectData retry system, not saved)
*/
params ["_object"];
TRACE_1("Getting object data for",_object);

private _attachedObjects = [];
private _objectAttachedObjects = _object getVariable ["ace_attach_attached", []];
if (count _objectAttachedObjects > 0) then {
    {
        _x params ["_attachedObject", "_itemClassname"];
        _attachedObjects pushBack [_itemClassname, _object worldToModelVisual (ASLToAGL getPosASL _attachedObject)];
    } forEach _objectAttachedObjects;
};

private _pylonMagazines = getPylonMagazines _object;
private _turretMagazines = (magazinesAllTurrets _object) select {!(_x#0 in _pylonMagazines)};
private _turretPaths = _turretMagazines apply {_x#1};
_turretPaths = _turretPaths arrayIntersect _turretPaths;
private _turretWeapons = _turretPaths apply {[_x, _object weaponsTurret _x]};
private _pylonLoadout = [];
{
    _pylonLoadout pushBack [_x, _object ammoOnPylon (_forEachIndex + 1)];
} forEach _pylonMagazines;

private _data = [
    _object getVariable [QGVAR(persistenceID), ""],
    typeOf _object,
    getPosASL _object,
    [vectorDir _object, vectorUp _object],
    damage _object,
    fuel _object,
    _turretWeapons,
    _turretMagazines,
    _pylonLoadout,
    [getAmmoCargo _object, getFuelCargo _object, getRepairCargo _object],
    _attachedObjects,
    (((([_object] call acre_api_fnc_getVehicleRacks) select {_x != ""}) apply {[_x] call acre_api_fnc_getMountedRackRadio}) select {_x != ""}) apply {[_x] call acre_api_fnc_getRadioChannel},
    [_object] call FUNC(getObjectCargo),
    [getWeaponCargo _object, getMagazineCargo _object, getItemCargo _object, getBackpackCargo _object],
    [_object getVariable [QGVAR(isAceFortification), false], _object getVariable [QGVAR(aceFortifySide), west]],
    [_object getVariable ["ace_medical_medicClass", 0], _object getVariable ["ace_medical_isMedicalVehicle", false], _object getVariable ["ace_medical_isMedicalFacility", false]],
    [_object getVariable ["ace_isRepairVehicle", 0], _object getVariable ["ace_isRepairFacility", 0]],
    _object getVariable ["ace_cargo_customName", ""]
];
TRACE_1("Got object data",_data);

_data
