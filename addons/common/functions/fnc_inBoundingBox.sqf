#include "script_component.hpp"
/*
    Author:
        Nicholas Clark (SENSEI), Tim Beswick

    Description:
        Check for bounding box intersection between two objects

    Parameters:
        0: Object or array containing object1 and position to check (array required if object1 is not at desired position) <OBJECT, ARRAY>
        1: Object to check against (object2) <OBJECT>
        2: Direction of object1 to rotate bounding box by

    Return value:
        Boolean
*/
params [["_object1", objNull, [objNull, []]], ["_object2", objNull, [objNull]], ["_object1Direction", -1, [0]]];

private _boundingBox2 = boundingBoxReal _object2;
private _width2 = (abs (((_boundingBox2#1)#0) - ((_boundingBox2#0)#0))) * 0.5;
private _length2 = (abs (((_boundingBox2#1)#1) - ((_boundingBox2#0)#1))) * 0.5;
private _height2 = (abs (((_boundingBox2#1)#2) - ((_boundingBox2#0)#2))) * 0.5;

private _object1Source = _object1;
private _position = [0,0,0];
if (_object1 isEqualType objNull) then {
    _position = getPosATL _object1;
} else {
    _position = _object1#1;
    _object1 = _object1#0;
};

private _boundingBox1 = boundingBoxReal _object1;
private _width1 = (abs (((_boundingBox1#1)#0) - ((_boundingBox1#0)#0))) * 0.5;
private _length1 = (abs (((_boundingBox1#1)#1) - ((_boundingBox1#0)#1))) * 0.5;
private _height1 = (abs (((_boundingBox1#1)#2) - ((_boundingBox1#0)#2))) * 0.5;

if (_position inArea [_object2, _width2, _length2, getDir _object2, true, _height2]) exitWith {
    TRACE_2("Position is inside another object's bounding box",_position,_object2);
    true
};

if (_object1Direction == -1) then {
    _object1Direction = getDir _object1;
};

if (_object2 inArea [_position, _width1, _length1, _object1Direction, true,_height1]) exitWith {
    TRACE_2("Another object would be inside bounding box at position",_position,_object2);
    true
};

_boundingBox1 = [_object1, _boundingBox1] call FUNC(getBoundingBox);
_boundingBox2 = [_object2, _boundingBox2] call FUNC(getBoundingBox);

if (_object1Source isEqualType []) then {
    {
        _boundingBox1 set [_forEachIndex, _position vectorAdd _x vectorDiff (getPosATL _object1)];
    } forEach _boundingBox1;
};

_position inPolygon _boundingBox2 || (getPosATL _object2) inPolygon _boundingBox1 ||
[_boundingBox1, {_x inPolygon _boundingBox2}] call FUNC(arrayAny) || [_boundingBox2, {_x inPolygon _boundingBox1}] call FUNC(arrayAny)
