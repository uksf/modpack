/*
    Author:
        Tim Beswick

    Description:
        Handles caching of AI units

    Parameter(s):
        None

    Return Value:
        None
*/
#include "script_component.hpp"

if !(isServer) exitWith {};

params [["_entity", objNull, [grpNull, objNull]]];

_entity setVariable [QGVAR(excluded), true, true];
if (dynamicSimulationEnabled _entity) then {
    _entity enableDynamicSimulation false;
};
