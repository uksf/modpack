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
    private _leader = leader _x;
    if (dynamicSimulationEnabled _x) then {
        [QGVAR(hideObjectGlobal), [_x, !(simulationEnabled (leader _x))]] call CBA_fnc_localEvent;
    } else {
        if (
            !(isPlayer _leader) &&
            {!(isObjectHidden _leader)} &&
            {!((vehicle _leader) isKindOf "Air")} &&
            {((_leader getVariable [QGVAR(time), 0]) + 15) < CBA_missionTime}
        ) then {
            [QGVAR(setDynamicSimulation), [_x, true]] call CBA_fnc_globalEvent;
            [QGVAR(hideObjectGlobal), [_x, true]] call CBA_fnc_localEvent;
        };
    };
} forEach _groups;
