#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Draws bounding boxes for safehouse prefab

    Parameters:

    Return value:
        Nothing
*/

if !(is3DEN) exitWith {};

private _modules = (get3DENSelected "logic") select {typeOf _x == QGVAR(modulePrefabArea)};
if (_modules isEqualTo []) exitWith {};

private _logic = _modules#0;
private _anchorObject = _logic getVariable [QGVAR(anchorObject), objNull];
if (isNull _anchorObject) exitWith {};

private _boundingPoints = _anchorObject getVariable [QGVAR(boundingPoints), []];
if (_boundingPoints isEqualTo []) then {
    private _boundingBox = 0 boundingBoxReal _anchorObject;
    private _top = _boundingBox#1;
    private _bottom = _boundingBox#0;
    _boundingPoints = [
        _anchorObject modelToWorld _top, _anchorObject modelToWorld [_bottom#0, _top#1, _top#2], _anchorObject modelToWorld [_bottom#0, _bottom#1, _top#2], _anchorObject modelToWorld [_top#0, _bottom#1, _top#2],
        _anchorObject modelToWorld _bottom, _anchorObject modelToWorld [_top#0, _bottom#1, _bottom#2], _anchorObject modelToWorld [_top#0, _top#1, _bottom#2], _anchorObject modelToWorld [_bottom#0, _top#1, _bottom#2]
    ];

    _anchorObject setVariable [QGVAR(boundingPoints), _boundingPoints];
};

_boundingPoints params ["_cornerTop1", "_cornerTop2", "_cornerTop3", "_cornerTop4", "_cornerBottom1", "_cornerBottom2", "_cornerBottom3", "_cornerBottom4"];

private _colour = [1,0,1,1];
drawLine3D [_cornerTop1, _cornerTop2, _colour];
drawLine3D [_cornerTop2, _cornerTop3, _colour];
drawLine3D [_cornerTop3, _cornerTop4, _colour];
drawLine3D [_cornerTop4, _cornerTop1, _colour];
drawLine3D [_cornerBottom1, _cornerBottom2, _colour];
drawLine3D [_cornerBottom2, _cornerBottom3, _colour];
drawLine3D [_cornerBottom3, _cornerBottom4, _colour];
drawLine3D [_cornerBottom4, _cornerBottom1, _colour];
drawLine3D [_cornerBottom1, _cornerTop3, _colour];
drawLine3D [_cornerBottom2, _cornerTop4, _colour];
drawLine3D [_cornerBottom3, _cornerTop1, _colour];
drawLine3D [_cornerBottom4, _cornerTop2, _colour];

drawLine3D [_logic, _anchorObject, _colour];
