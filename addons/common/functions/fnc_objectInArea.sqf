#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Checks if object is within an area

    Parameters:
        0: Object <OBJECT>
        1: Center position <ARRAY/OBJECT>
        2: Area array <ARRAY>

    Return value:
        Boolean
*/
params ["_object", ["_center", [0,0,0], [objNull, [0,0,0]]], "_area"];

if (_area isEqualTo []) exitWith {false};

_area params ["_a", "_b", "_angle", "_isRectangle"];
_object inArea [_center, _a, _b, _angle, _isRectangle]
