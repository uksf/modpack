#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Creates visual for aborted objects

    Parameter(s):
        0: Objects <ARRAY>

    Return Value:
        None
*/
params ["_objects"];

GVAR(abortedObjects) = [];
GVAR(abortedObjectInteractionObjects) = [];
{
    _x params ["_id", "_type", "_position", "_vectorDirAndUp"];

    private _object = _type createVehicleLocal [0,0,0];
    _object enableSimulation false;
    _object setVectorDirAndUp _vectorDirAndUp;
    _object setPosASL _position;

    private _boundingBox = 0 boundingBoxReal _object;
    private _top = _boundingBox#1;
    private _bottom = _boundingBox#0;
    private _points = [
        _object modelToWorld _top, _object modelToWorld [_bottom#0, _top#1, _top#2], _object modelToWorld [_bottom#0, _bottom#1, _top#2], _object modelToWorld [_top#0, _bottom#1, _top#2],
        _object modelToWorld _bottom, _object modelToWorld [_top#0, _bottom#1, _bottom#2], _object modelToWorld [_top#0, _top#1, _bottom#2], _object modelToWorld [_bottom#0, _top#1, _bottom#2],
        _object modelToWorld [0,0,0]
    ];

    GVAR(abortedObjects) pushBack [_id, _points, [1,0,0,1]];
    deleteVehicle _object;

    private _interactionObject = "Sign_Sphere25cm_F" createVehicleLocal [0,0,0];
    _interactionObject setPosATL (_points#8);
    _interactionObject enableSimulation false;
    GVAR(abortedObjectInteractionObjects) pushBack [_id, _interactionObject];

    private _action = [QGVAR(actions), "Persistence", "", {}, {true}, {call FUNC(getAbortedObjectInteractions)}, [_id], [0,0,0], 10] call ace_interact_menu_fnc_createAction;
    [_interactionObject, 0, [], _action] call ace_interact_menu_fnc_addActionToObject;
} forEach _objects;

GVAR(abortedObjectPFHID) = [{
    {
        _x params ["_text", "_points", "_colour"];
        _points params ["_cornerTop1", "_cornerTop2", "_cornerTop3", "_cornerTop4", "_cornerBottom1", "_cornerBottom2", "_cornerBottom3", "_cornerBottom4", "_centre"];

        drawIcon3D ["", [1,0,0,1], _centre, 0.5, 0.5, 0, _text, 0, 0.03, "TahomaB", "center"];

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
    } forEach GVAR(abortedObjects);
}, 0] call CBA_fnc_addPerFrameHandler;
