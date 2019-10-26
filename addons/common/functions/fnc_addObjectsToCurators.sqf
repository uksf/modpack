#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Adds all objects to given curators or all curators
        NOTE: Can only be executed on the server

    Parameter(s):
        0: Objects <ARRAY> (Optional)
        1: Curators <ARRAY> (Optional)

    Return Value:
        None
*/
if (!isServer) exitWith {
    [QGVAR(addObjectsToCurators), _this] call CBA_fnc_serverEvent;
};

params [["_objects", allMissionObjects "all"], ["_curators", allCurators]];
_objects = _objects - allCurators;

[{
    params ["_objects", "_curators"];
    {
        _x addCuratorEditableObjects [_objects, true];
        false
    } count _curators;
}, [_objects, _curators]] call CBA_fnc_execNextFrame;
