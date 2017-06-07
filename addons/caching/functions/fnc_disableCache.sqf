/*
    Author:
        Tim Beswick

    Description:
        Handles caching of AI units

    Parameter(s):
        0: Group to exclude from caching

    Return Value:
        None
*/
#include "script_component.hpp"

if !(isServer) exitWith {
    [QGVAR(disableCache), this] call CBA_fnc_serverEvent;
};

params [["_group", grpNull, [grpNull]]];

_group setVariable [QGVAR(excluded), true, true];
if (dynamicSimulationEnabled _group) then {
    _group enableDynamicSimulation false;
    {_x enableSimulationGlobal true; false} count (units _group);
};
