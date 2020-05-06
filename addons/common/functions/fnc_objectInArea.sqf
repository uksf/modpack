#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Checks if object is within an area

    Parameters:
        0: Object <OBJECT>
        1: Area array <ARRAY>

    Return value:
        Boolean
*/
params ["_object", "_area"];

if (_area isEqualTo []) exitWith {false};

_area params ["_a", "_b", "_angle", "_isRectangle"];
_object inArea [_x, _a, _b, _angle, _isRectangle]
