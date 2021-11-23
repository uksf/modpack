#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Creates safehouse object

    Parameters:
        0: Anchor <OBJECT>
        1: Object data <ARRAY>

    Return value:
        Created object <OBJECT>
*/
params ["_anchorObject", "_objectData"];

if !(isServer) exitWith {};

_objectData params ["_objectPlacement"];
_objectPlacement params ["_type", "_anchorOffset", "_dir", "_prefabAnchorDir", "_vectorUp", "_anchorTerrainHeightDiff"];

private _position = _anchorObject modelToWorld _anchorOffset;
if ((_position#2) < 0) then {
    _position set [2, 0];
};

private _object = createVehicle [_type, [0,0,0], [], 0, "CAN_COLLIDE"];

private _anchorDir = getDir _anchorObject;
_dir = _dir + (_anchorDir - _prefabAnchorDir);
_object setDir _dir;
_object setVectorUp _vectorUp;

_object setPosASL (AGLToASL _position);
_position = getPos _object;
DEBUG_2("Height for created safehouse object %1 is %2",_type,_position#2);
if ((_position#2) > 0.01) then {
    WARNING_2("Height for created safehouse object %1 looks wrong, correcting for terrain from %2",_type,_position#2);
    private _anchorTerrainHeight = getTerrainHeightASL (getPosASL _anchorObject);
    private _terrainHeightAtPosition = getTerrainHeightASL _position;
    private _terrainHeightDiff = _terrainHeightAtPosition - _anchorTerrainHeight;
    DEBUG_4("TH anchor %1.. TH at pos %2.. TH diff %3.. old height %4",_anchorTerrainHeight,_terrainHeightAtPosition,_terrainHeightDiff,_position#2);

    private _prefabTerrainHeightOffset = _terrainHeightDiff - _anchorTerrainHeightDiff;
    _position set [2, (_position#2) + _prefabTerrainHeightOffset];
    DEBUG_3("TH offset %1.. TH anchor diff %2.. new height %3",_prefabTerrainHeightOffset,_anchorTerrainHeightDiff,_position#2);
    _object enableSimulationGlobal false;
};

_position = getPos _object;
DEBUG_2("Height for created safehouse object %1 is %2",_type,_position#2);
if ((_position#2) > 0.01) then {
    WARNING_2("Height for created safehouse object %1 looks floaty, correcting to relative 0 from %2",_type,_position#2);
    _position set [2, 0];
    _object setPos _position;
    _object enableSimulationGlobal false;
};

_object
