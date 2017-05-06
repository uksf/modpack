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
#include "script_component.hpp"

params [["_curators", allCurators, []]];

if (!isServer) exitWith {
    [QGVAR(addObjectsToCurators), [_curators]] call CBA_fnc_serverEvent;
};

{
    [_x] spawn {
        (_this select 0) addCuratorEditableObjects [(allMissionObjects "all"), true];
        (_this select 0) removeCuratorEditableObjects [allCurators, true];
    };
    false
} count _curators;
