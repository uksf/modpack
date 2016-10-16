/*
    Author:
    	Julian Alwandy & Tim Beswick

    Description:
    	Spawns AI based on max amount at any time and pool size, remotely on random headless client

    Parameters:
    	0: Marker Name (default: "") <STRING>
    	1: Max enemy spawned at once(default: 50) <SCALAR>
    	2: Enemy pool size(default: 200) <SCALAR>
    	3: Debug(default: false) <BOOLEAN>

    Return value:
    	Nothing

    Called from:
    	_nul = ["MyMarker", 40, 100, false] execVM "spawnMethod.sqf";
*/
params [["_markerName", ""], ["_maxAmount", 50], ["_poolSize", 200], ["_debug", false]];

if (isNil _markerName) exitWith {};
if (!isServer) exitWith {};

//Set poolsize for marker as mission variable
missionNamespace setVariable [format ["%1_poolsize", _markerName], _poolSize, true];

_markerName setMarkerAlpha 0;

//Headless clients - offload this to init later down the line
HCs = [];
{
    _id = owner _x;
    HCs = HCs + [_id];
} forEach (entities "HeadlessClient_F");


_spawnAndTask = {
	params ["_markerName"];

	//Spawn units in random place within marker
	_markerScale = getMarkerSize _markerName;
	_randomSpawn = [_markerName, (_markerScale select 0)] call CBA_fnc_randPos;
	_randomUnit = selectRandom [["Laraka_PKM","Laraka_RPG","Laraka_AK","Laraka_Warlord"],["Laraka_PKP","Laraka_RPG","Laraka_AK","Laraka_AK"]]; // Gives the array for units to be chosen, use example: _x = selectRandom [[Array1],[Array2],[Array3],[Array4]];
	_group = [_randomSpawn, EAST, _randomUnit] call BIS_fnc_spawnGroup; //Spawns Unit

	//Automatically assign task type
	_taskType = floor(random 3);
	switch (_taskType) do {
		case 0: {[_group, _markerName] call CBA_fnc_taskSearchArea;}; // Will search area
		case 1: {[_group, _markerName, (_markerScale select 0)] call CBA_fnc_taskPatrol;}; // Calls patrol movement
		case 2: {[_group, _markerName, (_markerScale select 0)] call CBA_fnc_taskPatrol;}; // Will search area
		//case 2: {[_group,(_markerScale select 0), 2, true] call CBA_fnc_taskDefend;}; // Will fortify a position - Commented out due of not working as of now.
		default {[_group, _markerName, (_markerScale select 0)] call CBA_fnc_taskPatrol;}; // Default value is to patrol.
	};

	//Set latest count
	missionNamespace setVariable [format ["%1_count", _markerName], count (units _group), true];
};

[{
	params ["_args", "_idPFH"];
	_args params ["_markerName", "_maxAmount", "_debug"];

	//Update poolsize
	_poolSize = missionNamespace getVariable [format ["%1_poolsize", _markerName], 0];
	_poolSize = _poolSize - (missionNamespace getVariable [format ["%1_count", _markerName], 0]);
	missionNamespace setVariable [format ["%1_poolsize", _markerName], _poolSize, true];

	//If pool is empty, remove PFH
	if (_poolSize <= 0) exitWith {
		[_idPFH] call CBA_fnc_removePerFrameHandler;
	};

	//Count number of current enemy. If less than threshold, spawn more.
	_totalEnemy = {alive _x && side _x == EAST} count allUnits;
    if (_totalEnemy <= _maxAmount) then {
		//Execute code on one of the headless clients
		[_markerName] remoteExec ["_spawnAndTask", selectRandom HCs, false];
    };

	//If debug is on, add markers to each area
	if (_debug) then {
		{_markerstr = createMarker [format ["%1", floor (random 9999)], leader _x]; _markerstr setMarkerShape "ICON"; _markerstr setMarkerType "hd_dot";} forEach allGroups;
		_markerName setMarkerAlpha 1;
	};
}, 10, [_markerName, _maxAmount, _debug]] call CBA_fnc_addPerFrameHandler;
