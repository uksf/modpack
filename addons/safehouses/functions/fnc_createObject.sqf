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
_objectPlacement params ["_type", "_anchorOffset", "_dir", "_prefabAnchorDir", "_vectorUp"];

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

_object
