#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Checks groups to virtualise

    Parameter(s):
        0: Groups to check <ARRAY>

    Return Value:
        None
*/
params [["_groups", []]];

// Pre-filter null groups and groups with no units
_groups = _groups select {!isNull _x && count (units _x) > 0};

// To avoid flicker, we'll virtualise groups 200m further away, but recreate 200m closer (400m buffer zone)
private _bufferedDistance = GVAR(distance) + 200;

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
        !(isPlayer _leader)
        && {simulationEnabled _leader || {!(isObjectHidden _leader)}}
        && {!((objectParent _leader) isKindOf "Air")}
        && {!([_leader, GVAR(distance)] call EFUNC(common,anyNearPlayers))}
        // && {[units _x, {vehicle _x != _x}] call EFUNC(common,arrayNone)} // remove this when ready to test vehicles
    ) then {
        [_x] call FUNC(virtualiseGroup);
    };
} forEach _groups;
