/*
    Author:
        Tim Beswick

    Description:
        Checks groups to cache for server

    Parameter(s):
        None

    Return Value:
        None
*/
#include "script_component.hpp"

{
    if (SERVER_CONDITION) then {
        _x enableDynamicSimulation true;
    };
    false
} count allGroups;
