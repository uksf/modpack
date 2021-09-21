#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Initialise safehouse prefab

    Parameters:
        0: Module logic <OBJECT>
        1: Area <ARRAY>

    Return value:
        Nothing
*/
params ["_logic", "_area"];
_area params ["_a", "_b", "_angle", "_isRectangle", "_c"];

if !(isServer) exitWith {};

private _centre = getPos _logic;
private _objects = GVAR(missionObjects) inAreaArray [_centre, _a, _b, _angle, _isRectangle, _c];
GVAR(missionObjects) = GVAR(missionObjects) - _objects;

private _sizeOrderedObjects = _objects apply {[(boundingBox _x)#2, _x]};
_sizeOrderedObjects sort false;
_sizeOrderedObjects = _sizeOrderedObjects apply {_x#1};

private _anchorObject = _sizeOrderedObjects#0;
_sizeOrderedObjects deleteAt 0;
_objects = _sizeOrderedObjects;

private _fnc_getPefabObjectData = {
    params ["_object", "_anchor"];

    [
        typeOf _object,
        _anchor worldToModel (getPosATL _object),
        [vectorDir _object, vectorUp _object],
        isObjectHidden _object,
        damage _object,
        fuel _object,
        [getWeaponCargo _object, getMagazineCargo _object, getItemCargo _object, getBackpackCargo _object],
        [_object getVariable ["ace_medical_isMedicalVehicle", false], _object getVariable ["ace_medical_isMedicalFacility", false]],
        [_object getVariable ["ace_isRepairVehicle", 0], _object getVariable ["ace_isRepairFacility", 0]]
    ]
};

private _anchorObjectData = [_anchorObject, _logic] call _fnc_getPefabObjectData;
private _objectData = _objects apply {[_x, _anchorObject] call _fnc_getPefabObjectData};

GVAR(safehousePrefabs) pushBack [_centre, _area, _anchorObjectData, _objectData];

deleteVehicle _logic;
deleteVehicle _anchorObject;
{deleteVehicle _x} forEach _objects;
