#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Creates destroyed safehouse from persistence data

    Parameters:
        0: Location id <STRING>
        1: Position <ARRAY>
        2: Prefab ID <STRING>

    Return value:
        Nothing
*/
params ["_id", "_position", "_prefabId"];

if !(isServer) exitWith {};

private _selection = [_position, _prefabId] call FUNC(selectPrefabForLocation);
_selection params ["_prefab", "_anchorObject"];
_prefab params ["", "", "_area", "_anchorObjectData"];
_area params ["_a", "_b", "_angle", "_isRectangle", "_c"];

_anchorObjectData params ["_anchorObjectPlacement"];
_anchorObjectPlacement params ["_type", "", "_dir", "_prefabAnchorDir", "_vectorUp"];

if !(isNull _anchorObject) then {
    private _anchorDir = getDir _anchorObject;
    _angle = _angle + (_dir - _anchorDir);
};

private _radius = ((_a ^ 2) + (_b ^ 2)) ^ 0.5;
private _terrainObjects = nearestTerrainObjects [_position, [], _radius, true];
_terrainObjects = _terrainObjects inAreaArray [_position, _a, _b, _angle, _isRectangle, _c];
{hideObjectGlobal _x} forEach _terrainObjects;
if !(isNull _anchorObject) then {
    _terrainObjects deleteAt (_terrainObjects find _anchorObject);
};

if (isNull _anchorObject) then {
    _anchorObject = createVehicle [_type, _position, [], 0, "CAN_COLLIDE"];
    _anchorObject setDir _dir;
    _anchorObject setVectorUp _vectorUp;
};

_anchorObject setDamage [1, false];

GVAR(destroyed) set [_id, [_id, _position, _prefabId]];
