#include "script_component.hpp"
/*
    Author:
        Nicholas Clark (SENSEI), Tim Beswick

    Description:
        Get bounding box as polygon for object

    Parameters:
        0: Object <OBJECT>
        1: Bounding box <ARRAY>

    Return value:
        ARRAY

    Example:
        [_object, _boundingBox] call uksf_common_fnc_getBoundingBox
*/
params ["_object", "_boundingBox"];

private _boundingBoxX = [_boundingBox#0#0, _boundingBox#1#0];
private _boundingBoxY = [_boundingBox#0#1, _boundingBox#1#1];
private _boundingBoxResult = [];

{
    private _y = _x;

    {
        _boundingBoxResult pushBack (_object modelToWorld [_x, _y, (_boundingBox#0#2) min (_boundingBox#1#2)]);
    } forEach _boundingBoxX;
    reverse _boundingBoxX;
} forEach _boundingBoxY;

_boundingBoxResult
