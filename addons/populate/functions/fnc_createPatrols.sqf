#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Spawns a unit at the passed position

    Parameters:
        0: _numberOfUnitsToSpawn <NUMBER>
        1: _module <OBJECT>
        2: _group <GROUP>

    Return value:
        Nothing
*/

params ["_numberOfUnitsToSpawn", "_side", "_module", "_unitPoolArray"];

private _group = grpNull;
private _currenGrouptUnitCount = 0;
private _patrolSize = _module getVariable [QGVAR(patrolSize), 0];
private _patrolRadius = _module getVariable [QGVAR(patrolRadius), 0];

[{
	params ["_args", "_idPFH"];
	_args params ["_numberOfUnitsToSpawn", "_side", "_module", "_unitPoolArray", "_currenGrouptUnitCount", "_patrolRadius", "_group", "_patrolSize"];

    if (_numberOfUnitsToSpawn <= 0) exitWith {
        [_idPFH] call cba_fnc_removePerFrameHandler;
    };

    // create a group if the _currenGrouptUnitCount is == 0, set previous group to patrol
    if (_currenGrouptUnitCount == 0) then {
        _group = createGroup _side;
    };

    private _unitType = selectRandom _unitPoolArray;
    private _unit = _group createUnit [_unitType, [0,0,0], [], 0, "NONE"];
    _unit setPos (getPos _module);

    _currenGrouptUnitCount = _currenGrouptUnitCount + 1;
    _numberOfUnitsToSpawn = _numberOfUnitsToSpawn - 1;
    if (_currenGrouptUnitCount == _patrolSize) then {
        // [_group, _group, _patrolRadius, 5, "SAFE"] call cba_fnc_taskPatrol;
        [_group, _group, _patrolRadius, 6] call lambs_wp_fnc_taskPatrol; // infantry only
        _currenGrouptUnitCount = 0;
    };

    _args set [0, _numberOfUnitsToSpawn];
    _args set [4, _currenGrouptUnitCount];
    _args set [6, _group];

}, 1, [_numberOfUnitsToSpawn, _side, _module, _unitPoolArray, _currenGrouptUnitCount, _patrolRadius, _group, _patrolSize]] call cba_fnc_addPerFrameHandler;

// TODO: exclude virtualization until the group is spawned, then set to true


