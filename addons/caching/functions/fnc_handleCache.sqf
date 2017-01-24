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

private _cacheGroups = [];
private _uncacheGroups = [];

{
    if ([_x] call FUNC(canCache)) then {
        _cacheGroups pushBack _x;
    };
    false
} count allGroups;

{
    [leader _x] call FUNC(addEventhandler);
    GVAR(groups) pushBack _x;
    false
} count _cacheGroups;

GVAR(groups) = GVAR(groups) select {!isNull _x};

{
    if ([_x] call FUNC(canUncache)) then {
        _uncacheGroups pushBack _x;
    } else {
        {
            [_x] call FUNC(cache);
            false
        } count (units _x);
    };
    false
} count GVAR(groups);

{
    {
        [_x] call FUNC(uncache);
        false
    } count (units _x);

    GVAR(groups) deleteAt (GVAR(groups) find _x);
    false
} count _uncacheGroups;