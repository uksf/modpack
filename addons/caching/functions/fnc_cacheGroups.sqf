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
            - Simulated OR object is not hidden
            - Not air vehicle
            - No players near leader
    */
    private _leader = leader _x;
    if (
        !(isPlayer _leader) &&
        {(simulationEnabled _leader || {!(isObjectHidden _leader)})} &&
        {!((objectParent _leader) isKindOf "Air")} &&
        {!([_leader, GVAR(distance)] call EFUNC(common,anyNearPlayers))} &&
        {[units _x, {vehicle _x != _x}] call EFUNC(common,arrayNone)} // remove this when ready to test vehicles
    ) then {
        [_x] call FUNC(storeGroupDataAndDelete);
    };
} forEach _groups;
