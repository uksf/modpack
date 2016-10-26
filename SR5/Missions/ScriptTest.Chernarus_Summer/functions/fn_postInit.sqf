/*
    Author:
    	Nicholas Clark & Tim Beswick

    Description:
    	Adds main caching PFH

    Parameters:
    	None

    Return value:
    	Nothing

    Called from:
    	PostInit EH;
*/
//Headless clients - offload this to init later down the line
HCs = [];
{
    _id = owner _x;
    HCs = HCs + [_id];
} forEach (entities "HeadlessClient_F");

if (!isServer || !isMultiplayer) exitWith {};
UKSF_Mission_groups = [];

UKSF_Mission_distance = 750;
if ((paramsArray select 0) > 0) then {
	UKSF_Mission_distance = (paramsArray select 0);
};

[{
	private ["_units","_grps","_grp"];

	_units = [];
	_grps = [];

	{
		if ([_x] call FUNC(canCache)) then {
			_grps pushBack _x;
		};
		false
	} count allGroups;

	for "_i" from 0 to (count _grps - 1) do {
		_grp = _grps select _i;

		[leader _grp] call FUNC(addEventhandler);
		_units = units _grp;
		_units = _units select {!(_x isEqualTo leader _x)};

		UKSF_Mission_groups pushBack _grp;
	};

	if !(_units isEqualTo []) then {
		for "_i" from 0 to (count _units - 1) do {
			[_units select _i] call FUNC(cache);
		};
	};

	UKSF_Mission_groups = UKSF_Mission_groups select {!isNull _x}; // remove null elements

	for "_i" from (count UKSF_Mission_groups - 1) to 0 step -1 do {
		_grp = UKSF_Mission_groups select _i;

		if ([_grp] call FUNC(canUncache) then {
			_units = units _grp;
			_units = _units select {!(_x isEqualTo leader _x)};
			{
				[_x] call FUNC(uncache;
			} forEach _units;

			UKSF_Mission_groups deleteAt _i;
		} else {
			{
				if (!(_x isEqualTo leader _x) && {simulationEnabled _x}) then {
					[_x] call FUNC(cache;
				};
			} forEach (units _grp);
		};
	};
}, 15, []] call CBA_fnc_addPerFrameHandler;

//Spawn units on markers
["spawn_1", 25, 50, "Genfor", false] call FUNC(spawnOnMarker;
