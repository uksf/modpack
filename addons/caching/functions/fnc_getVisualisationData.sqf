#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Returns caching visualisation data for Zeus.

    Parameter(s):
        None

    Return Value:
        Array of caching data
*/

private _cachedGroups = [];
private _totalActive = 0;
private _totalCached = 0;

{
    private _leader = leader _x;
    if (!isNull _leader && {!isPlayer _leader} && {!(_x getVariable [QGVAR(excluded), false])}) then {
        if (_leader getVariable [QGVAR(hiddenByCaching), false]) then {
            _totalCached = _totalCached + 1;
            _cachedGroups pushBack [getPosATL _leader, side _x, count units _x];
        } else {
            _totalActive = _totalActive + 1;
        };
    };
} forEach allGroups;

[_cachedGroups, GVAR(distance), _totalActive, _totalCached]
