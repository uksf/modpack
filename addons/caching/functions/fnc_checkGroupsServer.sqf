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
    private _leader = (leader _x);
    if (
        !(dynamicSimulationEnabled _x) &&
        {!(isPlayer _leader)} &&
        {!(_x getVariable [QGVAR(excluded), false])} &&
        {!((vehicle _leader) isKindOf "Air")} &&
        {((_leader getVariable [QGVAR(time), 0]) + 15) < diag_tickTime}
    ) then {
        [QGVAR(setDynamicSimulation), [_x, true]] call CBA_fnc_globalEvent;
    };
    false
} count allGroups;
