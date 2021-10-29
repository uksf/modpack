#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Initialise safehouse prefab

    Parameters:
        0: Prefab ID <OBJECT>
        1: Module logic <OBJECT>
        2: Area <ARRAY>

    Return value:
        Nothing
*/
params ["_id", "_logic", "_area"];

if !(isServer) exitWith {};

private _fnc_getPefabObjectData = {
    params ["_object", "_anchor"];

    [
        [
            typeOf _object,
            _anchor worldToModel (getPos _object),
            getDir _object,
            getDir _anchor,
            vectorUp _object
        ],
        [
            isObjectHidden _object,
            isDamageAllowed _object,
            simulationEnabled _object,
            damage _object,
            fuel _object,
            [getWeaponCargo _object, getMagazineCargo _object, getItemCargo _object, getBackpackCargo _object],
            [_object getVariable ["ace_medical_isMedicalVehicle", false], _object getVariable ["ace_medical_isMedicalFacility", false]],
            [_object getVariable ["ace_isRepairVehicle", 0], _object getVariable ["ace_isRepairFacility", 0]]
        ]
    ]
};

([GVAR(missionObjects), _logic, _area] call FUNC(getPrefabAnchor)) params ["_anchorObject", "_objects"];
GVAR(missionObjects) = GVAR(missionObjects) - _objects;

private _anchorObjectData = [_anchorObject, _logic] call _fnc_getPefabObjectData;
private _objectData = _objects apply {[_x, _anchorObject] call _fnc_getPefabObjectData};
_objectData = _objectData apply {[_x#0#1#2, _x]};
_objectData sort true;
_objectData = _objectData apply {_x#1};

private _centre = getPos _logic;
GVAR(prefabs) set [_id, [_id, _centre, _area, _anchorObjectData, _objectData]];

deleteVehicle _logic;
deleteVehicle _anchorObject;
{deleteVehicle _x} forEach _objects;
