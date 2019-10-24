#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Sets cleanup state for object or array of objects

    Parameters:
        0: Object <OBJECT/ARRAY>
        1: State <BOOLEAN>

    Return value:
        Nothing
*/
if (!GVAR(enabled)) exitWith {};

params [["_objects", [], [objNull, []]], "_state"];

if (_objects isEqualType objNull) then {
    _objects = [_objects];
};

{
    _x setVariable [QGVAR(excluded), _state, true];
    if (!(_x getVariable [QGVAR(handled), false] || alive _x)) then {
        [_x] call FUNC(handleKilled);
    };
    false
} count _objects;
