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
        isObjectHidden _leader ||
        {!(dynamicSimulationEnabled _x) && // 0.0140ms
        {!(isPlayer _leader)} && // 0.0148ms
        {!(_x getVariable [QGVAR(excluded), false])} && // 0.0177ms
        {!((vehicle _leader) isKindOf "Air")} && // 0.0198ms
        {((_leader getVariable [QGVAR(time), 0]) + 15) < diag_tickTime}} // 0.0237ms
    ) then {
        [QGVAR(setDynamicSimulation), [_x, true]] call CBA_fnc_globalEvent;
    };
    false
} count allGroups;
