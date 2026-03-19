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

    Example:
        [_objects, _state] call uksf_cleanup_fnc_setCleanupState
*/
if (!GVAR(enabled)) exitWith {};

params [["_objects", [], [objNull, []]], "_state"];

if (_objects isEqualType objNull) then {
    _objects = [_objects];
};

{
    _x setVariable [QGVAR(excluded), _state, true];
    if (!_state && {!(_x getVariable [QGVAR(handled), false] || alive _x)}) then {
        [_x] call FUNC(handleKilled);
    };
} forEach _objects;
