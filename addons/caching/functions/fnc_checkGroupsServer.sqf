#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Checks groups to cache for server

    Parameter(s):
        0: Groups to check <ARRAY>

    Return Value:
        None
*/
params [["_groups", []]];

{
    private _leader = (leader _x);
    if (
        !(dynamicSimulationEnabled _x) && // 0.0140ms
        {!(isPlayer _leader)} && // 0.0148ms
        {!(_x getVariable [QGVAR(excluded), false])} && // 0.0177ms
        {!(isObjectHidden _leader)} &&
        {!((vehicle _leader) isKindOf "Air")} && // 0.0198ms
        {((_leader getVariable [QGVAR(time), 0]) + 17) < diag_tickTime} // 0.0237ms
    ) then {
        [QGVAR(setDynamicSimulation), [_x, true]] call CBA_fnc_globalEvent;
        [QGVAR(hideObjectGlobal), [_x, true]] call CBA_fnc_localEvent;
    };
    false
} count _groups;
