/*
    Author:
        Julian Alwandy & Tim Beswick

    Description:
        Spawns AI and gives task

    Parameters:
        0: Marker Name (default: "") <STRING>
        1: Faction Name (default: "") <SCALAR>

    Return value:
        Nothing

    Called from:
        ["MyMarker", "Genfor"] call UKSF_Mission_fnc_spawnAndTask;
*/
params ["_markerName", "_factionName", "_group"];

[_markerName, _randomSpawn, _group] spawn {
	params ["_markerName", "_factionName", "_group"];

	//Spawn units in random place within marker, at least 300m from nearest player
	_markerScale = getMarkerSize _markerName;
	_randomSpawn = [_markerName, (_markerScale select 0)] call CBA_fnc_randPos;
	while {{_x distance _randomSpawn < 300} count (call CBA_fnc_players) > 0} do {
		sleep 2;
		_randomSpawn = [_markerName, (_markerScale select 0)] call CBA_fnc_randPos; //THIS IS UNTESTED
	};

	_rand = random 10;
	if(_rand < 8) then {
		_randomUnit = selectRandom ["4","6","8","10","ATSquad","MGSquad","6_Res","4_Res"];
		_group = [_randomSpawn, EAST, call compile format ["(configFile >> ""CfgGroups"" >> ""East"" >> ""UKSF_%1"" >> ""Infantry"" >> ""%1_%2"")", _factionName, _randomUnit]] call BIS_fnc_spawnGroup;
	} else {
		_randomUnit = selectRandom ["6_Para","4_Para","6_SF","4_SF","2_SF"];
		_group = [_randomSpawn, EAST, call compile format ["(configFile >> ""CfgGroups"" >> ""East"" >> ""UKSF_%1"" >> ""SpecOps"" >> ""%1_%2"")", _factionName, _randomUnit]] call BIS_fnc_spawnGroup;
	};

	//Automatically assign task type
	_taskType = floor(random 3);
	switch (_taskType) do {
		case 0: {[_group, _markerName] call CBA_fnc_taskSearchArea;}; // Will search area
		case 1: {[_group, _markerName, (_markerScale select 0)] call CBA_fnc_taskPatrol;}; // Calls patrol movement
		//case 2: {[_group, _markerName, (_markerScale select 0)] call CBA_fnc_taskPatrol;}; // Garrison nearest building
		//case 3: {[_group,(_markerScale select 0), 2, true] call CBA_fnc_taskDefend;}; // Will fortify a position - Commented out due of not working as of now.
		default {[_group, _markerName, (_markerScale select 0)] call CBA_fnc_taskPatrol;}; // Default value is to patrol.
	};

	_group setBehaviour "SAFE";
	/*_behaviourType = floor(random 4);
	switch(_behaviourType) do {
		case 0: {_group setBehaviour "SAFE";};
		case 1: {_group setBehaviour "AWARE";};
		case 2: {_group setBehaviour "SAFE";};
		case 3: {_group setBehaviour "AWARE";};
	};*/

	//Checker to delete group when all dead
	[{
		({alive _x} count units (_this select 0) < 1)
	}, {
		_currentGroups = missionNamespace getVariable [format ["%1_currentGroups", (_this select 1)], []];
		_currentGroups = _currentGroups - [(_this select 0)];
		missionNamespace setVariable [format ["%1_currentGroups", (_this select 1)], _currentGroups, true];
	}, [_group, _markerName]] call CBA_fnc_waitUntilAndExecute;

	//Pushback group into current groups
	_currentGroups = missionNamespace getVariable [format ["%1_currentGroups", _markerName], []];
	_currentGroups pushBack _group;
	missionNamespace setVariable [format ["%1_currentGroups", _markerName], _currentGroups, true];

	//Update poolsize
	_poolSize = missionNamespace getVariable [format ["%1_poolsize", _markerName], 0];
	_poolSize = _poolSize - 1;
	missionNamespace setVariable [format ["%1_poolsize", _markerName], _poolSize, true];
};
