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
params ["_markerName", "_factionName"];

[_markerName, _factionName] spawn {
	params ["_markerName", "_factionName", "_group"];

	//Spawn units in random place within marker, at least 500m from nearest player
	_markerScale = getMarkerSize _markerName;
	_randomSpawn = [_markerName, (_markerScale select 0)] call CBA_fnc_randPos;
	while {({_x distance _randomSpawn < 500} count (call CBA_fnc_players)) > 0} do {
		sleep 2;
		_randomSpawn = [_markerName, (_markerScale select 0)] call CBA_fnc_randPos;
	};

	//Select random group based on faction and spawn
	_selectedGroup = [_factionName] call UKSF_Mission_fnc_selectGroup;
	if (count _selectedGroup < 1) exitWith {};
	_group = [_randomSpawn, EAST, _selectedGroup] call BIS_fnc_spawnGroup;

	//Automatically assign task type
	_taskType = 3;
	switch (_taskType) do {
		case 0: {[_group, _markerName] call CBA_fnc_taskSearchArea;}; // Will search area
		case 1: {[_group, _markerName, (_markerScale select 0)] call CBA_fnc_taskPatrol;}; // Calls patrol movement
		case 2: {
			if(count units _group <= 4) then {
				[_group, _markerName, 100, 2, true] call CBA_fnc_taskDefend;
			} else {
				[_group, _markerName, (_markerScale select 0)] call CBA_fnc_taskPatrol;
			};
		}; // Garrison nearest building
		default {
			_group setVariable ["PatrolMarker", _markerName, true];
        	_group setVariable ["PatrolScale", (_markerScale select 0), true];
			[_group, _markerName, (_markerScale select 0)] call CBA_fnc_taskPatrol;
		};
	};

	_group setBehaviour "SAFE";

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
