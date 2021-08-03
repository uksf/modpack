#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Assign the route pickets their patrol routes

    Parameters:
        0: _group <GROUP>

    Return value:
        Nothing
*/

params ["_leader"];

(vehicle _leader) call CBA_fnc_deleteEntity;
{
    _x call CBA_fnc_deleteEntity;
} forEach units (group _leader);

