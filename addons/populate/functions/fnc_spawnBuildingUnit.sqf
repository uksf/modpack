#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Spawns a unit at the passed position

    Parameters:
        0: _spawnPos <POSITION>
        1: _module <OBJECT>
        2: _group <GROUP>

    Return value:
        Nothing
*/

params ["_spawnPositions", "_numberOfUnitsToSpawn", "_numberOfPositionsToOccupy", "_side", "_module", "_unitPoolArray", "_currenGrouptUnitCount"];

private _group = grpNull;

[{
	params ["_args", "_idPFH"];
	_args params ["_spawnPositions", "_numberOfUnitsToSpawn", "_numberOfPositionsToOccupy", "_side", "_module", "_unitPoolArray", "_currenGrouptUnitCount", "_group"];

    if (_numberOfPositionsToOccupy <= 0) exitWith {
        [_idPFH] call cba_fnc_removePerFrameHandler;
        if (_numberOfUnitsToSpawn > 0) then {
            [_numberOfUnitsToSpawn, _side, _module, _unitPoolArray, _currenGrouptUnitCount, _patrolRadius] call FUNC(createPatrols);
        ;}
    };

    // create a group if the _currenGrouptUnitCount is == 0, set previous group to patrol
    if (_currenGrouptUnitCount == 0) then {
        _group = createGroup _side;
    };

    private _unitType = selectRandom _unitPoolArray;
    private _unit = _group createUnit [_unitType, [0,0,0], [], 0, "NONE"];
    private _spawnPos = selectRandom _spawnPositions;
    // private _spawnPos = getPos _spawn;
    _unit setPos _spawnPos;
    TRACE_3("", _spawn, _spawnPos, _spawnPositions);

    _unit disableAI "PATH";

    _currenGrouptUnitCount = _currenGrouptUnitCount + 1;
    _numberOfUnitsToSpawn = _numberOfUnitsToSpawn - 1;
    _numberOfPositionsToOccupy = _numberOfPositionsToOccupy - 1;
    if (_currenGrouptUnitCount == 10) then {
        _currenGrouptUnitCount = 0;
    };

    _args set [6, _currenGrouptUnitCount];
    _args set [2, _numberOfPositionsToOccupy];
    _args set [7, _group];

}, 1, [_spawnPositions, _numberOfUnitsToSpawn, _numberOfPositionsToOccupy, _side, _module, _unitPoolArray, _currenGrouptUnitCount, _group]] call cba_fnc_addPerFrameHandler;

// TODO: exclude virtualization until the group is spawned, then set to true
