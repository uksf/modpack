#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Converts given value to an array

    Parameters:
        0: Value <ARRAY/STRING>

    Return value:
        Array of data <ARRAY>
*/
params [["_value", [], [[], ""]]];

if (_value isEqualType []) exitWith {
    _value
};

if (_value isEqualType "") exitWith {
    parseSimpleArray _value
};

[_value]
