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
} forEach allGroups;

{
	[leader _x] call FUNC(addEventhandler);
	GVAR(groups) pushBack _x;
} forEach _cacheGroups;

GVAR(groups) = GVAR(groups) select {!isNull _x};

{
	{
		[_x] call FUNC(cache);
	} forEach (units _x);

	if ([_x] call FUNC(canUncache)) then {
		_uncacheGroups pushBack _x;
	};
} forEach GVAR(groups);

{
	{
		[_x] call FUNC(uncache);
	} forEach (units _x);

	_index = GVAR(groups) find _x;
	if (_index > -1) then {
		GVAR(groups) deleteAt _index;
	};
} forEach _uncacheGroups;