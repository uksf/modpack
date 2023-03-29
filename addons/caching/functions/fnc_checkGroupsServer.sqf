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
    /*
    Cases
        0 (base):
            - Not player
            - Timeout > 15 seconds (avoids cache spam) (Within always uncached distance is implied by timeout)
            - Simulated OR object is not hidden
            - Not air vehicle
    */
    private _leader = leader _x;
    if (
        !(isPlayer _leader) &&
        {((_leader getVariable [QGVAR(time), 0]) + 15) < CBA_missionTime &&
        {(simulationEnabled _leader || {!(isObjectHidden _leader)}) &&
        {!((objectParent _leader) isKindOf "Air")}}}
    ) then {
        [QGVAR(cache), [_x]] call CBA_fnc_localEvent;
    };
} forEach _groups;

    // if (isObjectHidden _leader || {!(simulationEnabled _leader)}) then {
    //     [QGVAR(hideObjectGlobal), [_x, false]] call CBA_fnc_localEvent;
    // } else {
    //     if (
    //         !(isPlayer _leader) &&
    //         {!(isObjectHidden _leader) &&
    //         {!((vehicle _leader) isKindOf "Air") &&
    //         {((_leader getVariable [QGVAR(time), 0]) + 15) < CBA_missionTime}}}
    //     ) then {
    //         [QGVAR(hideObjectGlobal), [_x, true]] call CBA_fnc_localEvent;
    //     };
    // };
