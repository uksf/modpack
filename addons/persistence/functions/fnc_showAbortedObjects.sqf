#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Creates ghost objects of those that aborted loading

    Parameter(s):
        0: Objects <ARRAY>

    Return Value:
        None
*/
params ["_objects"];

GVAR(abortedObjectGhosts) = [];
GVAR(abortedObjectGhostInteractionObjects) = [];
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

    GVAR(abortedObjectGhosts) pushBack [_id, _points, [1,0,0,1]];
    deleteVehicle _object;

    private _interactionObject = "Sign_Sphere25cm_F" createVehicleLocal [0,0,0];
    _interactionObject setPosATL (_points#8);
    _interactionObject enableSimulation false;
    GVAR(abortedObjectGhostInteractionObjects) pushBack [_id, _interactionObject];

    private _action = [QGVAR(actions), "Persistence", "", {}, {true}, {call FUNC(getAbortedObjectInterations)}, [_id], [0,0,0], 10] call ace_interact_menu_fnc_createAction;
    [_interactionObject, 0, [], _action] call ace_interact_menu_fnc_addActionToObject;
} forEach _objects;

GVAR(abortedObjectGhostPFHID) = [{
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
    } forEach GVAR(abortedObjectGhosts);
}, 0] call CBA_fnc_addPerFrameHandler;





// boxPosition1 = ASLToAGL (getPosASL box1);
// boxVector1 = [vectorDir box1, vectorUp box1];
// private _boundingBox1 = 0 boundingBoxReal box1;
// private _top1 = _boundingBox1#1;
// private _bottom1 = _boundingBox1#0;
// boxBoundingBox1 = [
//     box1 modelToWorld _top1, box1 modelToWorld [_bottom1#0, _top1#1, _top1#2], box1 modelToWorld [_bottom1#0, _bottom1#1, _top1#2], box1 modelToWorld [_top1#0, _bottom1#1, _top1#2],
//     box1 modelToWorld _bottom1, box1 modelToWorld [_top1#0, _bottom1#1, _bottom1#2], box1 modelToWorld [_top1#0, _top1#1, _bottom1#2], box1 modelToWorld [_bottom1#0, _top1#1, _bottom1#2],
//     box1 modelToWorld [0,0,0]
// ];
// [abortedObjectGhostPFHID1] call CBA_fnc_removePerFrameHandler;
// abortedObjectGhostPFHID1 = [{
//     boxBoundingBox1 params ["_cornerTop1", "_cornerTop2", "_cornerTop3", "_cornerTop4", "_cornerBottom1", "_cornerBottom2", "_cornerBottom3", "_cornerBottom4", "_centre"];

//     drawIcon3D ["", [1,0,0,1], _centre, 0.5, 0.5, 0, typeOf box1, 0, 0.03, "TahomaB", "center"];

//     drawLine3D [_cornerTop1, _cornerTop2, [1,0,0,1]];
//     drawLine3D [_cornerTop2, _cornerTop3, [1,0,0,1]];
//     drawLine3D [_cornerTop3, _cornerTop4, [1,0,0,1]];
//     drawLine3D [_cornerTop4, _cornerTop1, [1,0,0,1]];
//     drawLine3D [_cornerBottom1, _cornerBottom2, [1,0,0,1]];
//     drawLine3D [_cornerBottom2, _cornerBottom3, [1,0,0,1]];
//     drawLine3D [_cornerBottom3, _cornerBottom4, [1,0,0,1]];
//     drawLine3D [_cornerBottom4, _cornerBottom1, [1,0,0,1]];
//     drawLine3D [_cornerBottom1, _cornerTop3, [1,0,0,1]];
//     drawLine3D [_cornerBottom2, _cornerTop4, [1,0,0,1]];
//     drawLine3D [_cornerBottom3, _cornerTop1, [1,0,0,1]];
//     drawLine3D [_cornerBottom4, _cornerTop2, [1,0,0,1]];
// }, 0] call CBA_fnc_addPerFrameHandler;

// boxPosition2 = ASLToAGL (getPosASL box2);
// boxVector2 = [vectorDir box2, vectorUp box2];
// private _boundingBox2 = 0 boundingBoxReal box2;
// private _top2 = _boundingBox#1;
// private _bottom2 = _boundingBox#0;
// boxBoundingBox2 = [
//     box2 modelToWorld _top2, box2 modelToWorld [_bottom2#0, _top2#1, _top2#2], box2 modelToWorld [_bottom2#0, _bottom2#1, _top2#2], box2 modelToWorld [_top2#0, _bottom2#1, _top2#2],
//     box2 modelToWorld _bottom2, box2 modelToWorld [_top2#0, _bottom2#1, _bottom2#2], box2 modelToWorld [_top2#0, _top2#1, _bottom2#2], box2 modelToWorld [_bottom2#0, _top2#1, _bottom2#2],
//     box2 modelToWorld [0,0,0]
// ];
// [abortedObjectGhostPFHID2] call CBA_fnc_removePerFrameHandler;
// abortedObjectGhostPFHID2 = [{
//     boxBoundingBox2 params ["_cornerTop1", "_cornerTop2", "_cornerTop3", "_cornerTop4", "_cornerBottom1", "_cornerBottom2", "_cornerBottom3", "_cornerBottom4", "_centre"];

//     drawIcon3D ["", [1,0,0,1], _centre, 0.5, 0.5, 0, typeOf box2, 0, 0.03, "TahomaB", "center"];

//     drawLine3D [_cornerTop1, _cornerTop2, [1,0,0,1]];
//     drawLine3D [_cornerTop2, _cornerTop3, [1,0,0,1]];
//     drawLine3D [_cornerTop3, _cornerTop4, [1,0,0,1]];
//     drawLine3D [_cornerTop4, _cornerTop1, [1,0,0,1]];
//     drawLine3D [_cornerBottom1, _cornerBottom2, [1,0,0,1]];
//     drawLine3D [_cornerBottom2, _cornerBottom3, [1,0,0,1]];
//     drawLine3D [_cornerBottom3, _cornerBottom4, [1,0,0,1]];
//     drawLine3D [_cornerBottom4, _cornerBottom1, [1,0,0,1]];
//     drawLine3D [_cornerBottom1, _cornerTop3, [1,0,0,1]];
//     drawLine3D [_cornerBottom2, _cornerTop4, [1,0,0,1]];
//     drawLine3D [_cornerBottom3, _cornerTop1, [1,0,0,1]];
//     drawLine3D [_cornerBottom4, _cornerTop2, [1,0,0,1]];
// }, 0] call CBA_fnc_addPerFrameHandler;




// getBoundingBox = {
//     private _boundingBox = _this#1;
//     private _boundingBoxX = [_boundingBox#0#0, _boundingBox#1#0];
//     private _boundingBoxY = [_boundingBox#0#1, _boundingBox#1#1];
//     private _boundingBoxResult = [];

//     {
//         private _y = _x;
//         {
//             _boundingBoxResult pushBack ((_this#0) modelToWorld [_x, _y, (_boundingBox#0#2) min (_boundingBox#1#2)]);
//         } forEach _boundingBoxX;
//         reverse _boundingBoxX;
//     } forEach _boundingBoxY;
//     _boundingBoxResult
// };

// boxPosition1 = ASLToAGL (getPosASL box1);
// boxVector1 = [vectorDir box1, vectorUp box1];
// boxBoundingBox1 = [box1, boundingBoxReal box1] call getBoundingBox;
// {
//     boxBoundingBox1 set [_forEachIndex, (ASLToAGL [14773.6,16836.9,17.9384]) vectorAdd _x vectorDiff (getPosATL box1)];
// } forEach boxBoundingBox1;
// [abortedObjectGhostPFHID1] call CBA_fnc_removePerFrameHandler;
// abortedObjectGhostPFHID1 = [{
//     boxBoundingBox1 params ["_cornerTop1", "_cornerTop2", "_cornerTop3", "_cornerTop4"];

//     drawLine3D [_cornerTop1, _cornerTop2, [1,0,0,1]];
//     drawLine3D [_cornerTop2, _cornerTop3, [1,0,0,1]];
//     drawLine3D [_cornerTop3, _cornerTop4, [1,0,0,1]];
//     drawLine3D [_cornerTop4, _cornerTop1, [1,0,0,1]];
// }, 0] call CBA_fnc_addPerFrameHandler;

// boxPosition2 = ASLToAGL (getPosASL box2);
// boxVector2 = [vectorDir box2, vectorUp box2];
// boxBoundingBox2 = [box2, boundingBoxReal box2] call getBoundingBox;
// [abortedObjectGhostPFHID2] call CBA_fnc_removePerFrameHandler;
// abortedObjectGhostPFHID2 = [{
//     boxBoundingBox2 params ["_cornerTop1", "_cornerTop2", "_cornerTop3", "_cornerTop4"];

//     drawLine3D [_cornerTop1, _cornerTop2, [0,1,0,1]];
//     drawLine3D [_cornerTop2, _cornerTop3, [0,1,0,1]];
//     drawLine3D [_cornerTop3, _cornerTop4, [0,1,0,1]];
//     drawLine3D [_cornerTop4, _cornerTop1, [0,1,0,1]];
// }, 0] call CBA_fnc_addPerFrameHandler;

// boxPosition1 inPolygon boxBoundingBox2 || boxPosition2 inPolygon boxBoundingBox1 ||
// [boxBoundingBox1, {_x inPolygon boxBoundingBox2}] call uksf_common_fnc_arrayAny || [boxBoundingBox2, {_x inPolygon boxBoundingBox1}] call uksf_common_fnc_arrayAny

// uksf_common_boundingBoxes = uksf_common_boundingBoxes apply {_x apply {private _bb = _x; _bb set [2, (_bb#2) + 1]; _bb}};
// [PFHID] call CBA_fnc_removePerFrameHandler;
// PFHID = [{
//     {
//         _x params ["_cornerTop1", "_cornerTop2", "_cornerTop3", "_cornerTop4"];

//         drawLine3D [_cornerTop1, _cornerTop2, [0,1,0,1]];
//         drawLine3D [_cornerTop2, _cornerTop3, [0,1,0,1]];
//         drawLine3D [_cornerTop3, _cornerTop4, [0,1,0,1]];
//         drawLine3D [_cornerTop4, _cornerTop1, [0,1,0,1]];
//     } forEach uksf_common_boundingBoxes;
// }, 0] call CBA_fnc_addPerFrameHandler;
