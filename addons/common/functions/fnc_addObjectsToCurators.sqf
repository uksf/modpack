#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Adds all objects to given curators or all curators
        NOTE: Can only be executed on the server

    Parameter(s):
        0: Curators <ARRAY> (Optional)

    Return Value:
        None
*/

params [["_objects", allMissionObjects "all"], ["_curators", allCurators]];

if (!isServer) exitWith {
    [QGVAR(addObjectsToCurators), _this] call CBA_fnc_serverEvent;
};

{
    [_x, _objects] spawn {
        params ["_curator", "_objects"];

        _curator addCuratorEditableObjects [_objects, true];
        _curator removeCuratorEditableObjects [allCurators, true];
    };
    false
} count _curators;
