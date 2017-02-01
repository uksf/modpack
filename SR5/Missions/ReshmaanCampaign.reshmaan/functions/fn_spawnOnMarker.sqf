/*
    Author:
        Julian Alwandy & Tim Beswick
        
    Description:
        Spawns AI based on max amountof groups at any time and pool size, remotely on random headless client

    Parameters:
        0: Marker Name (default: "") <STRING>
        1: Max enemy groups spawned at once (default: 20) <SCALAR>
        2: Enemy pool size (default: 40) <SCALAR>
        3: Faction (default: "") <STRING>
        4: Debug (default: false) <BOOLEAN>

    Return value:
        Nothing

    Called from:
        ["MyMarker", 20, 40, "Genfor", false] call UKSF_Mission_fnc_spawnOnMarker;
*/
params [["_markerName", ""], ["_maxAmount", 20], ["_poolSize", 40], ["_factionName", ""], ["_debug", false]];
if (_markerName == "") exitWith {};
if (_factionName == "") exitWith {};
if (isMultiplayer && !isServer) exitWith {};

//Set current enemy & poolsize for marker as mission variable
missionNamespace setVariable [format ["%1_currentGroups", _markerName], [], true];
missionNamespace setVariable [format ["%1_poolsize", _markerName], _poolSize, true];
missionNamespace setVariable [format ["%1_markers", _markerName], [], true];
_markerName setMarkerAlpha 0;

[{
    params ["_args", "_idPFH"];
    _args params ["_markerName", "_maxAmount","_factionName", "_debug"];

    //Get and update current groups & poolsize
	_currentGroups = missionNamespace getVariable [format ["%1_currentGroups", _markerName], []];
    _poolSize = missionNamespace getVariable [format ["%1_poolsize", _markerName], 0];

    //If pool is empty, remove PFH
    if (_poolSize <= 0) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
    };

    //Count number of current enemy. If less than threshold, spawn more.
    _totalEnemy = count _currentGroups;
    if (_totalEnemy <= _maxAmount) then {
        //Execute code on one of the headless clients
        [_markerName,_factionName] remoteExec ["UKSF_Mission_fnc_spawnAndTask", selectRandom HCs, false];
    };

    //If debug is on, update markers on each group leader
    if (_debug) then {
		_markers = missionNamespace getVariable [format ["%1_markers", _markerName], []];
		{deleteMarker _x} forEach _markers;
		_markers = [];
        {_markerstr = createMarker [format ["%1_%2", leader _x, _forEachIndex], leader _x]; _markerstr setMarkerShape "ICON"; _markerstr setMarkerType "hd_dot"; _markers pushBack _markerstr;} forEach _currentGroups;
        _markerName setMarkerAlpha 1;
		missionNamespace setVariable [format ["%1_markers", _markerName], _markers, true];
    };
}, 30, [_markerName, _maxAmount, _factionName, _debug]] call CBA_fnc_addPerFrameHandler;