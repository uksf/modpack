#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Creates a response from given parameters

    Parameters:
        0: Spawn logics <ARRAY>
        1: Iteration delay <SCALAR>
        2: Iteration count <SCALAR>
        3: Creation function <CODE>
        4: Retry iteration (Optional) <SCALAR>

    Return value:
        Nothing
*/
params ["_spawnLogics", "_delay", "_count", "_creationFunction", ["_retry", 0]];

if (!isServer || {_retry > RESPONSE_MAX_RETRIES} || {count GVAR(responseGroups) > GVAR(groupLimit)}) exitWith {};

private _spawns = [_spawnLogics] call FUNC(getValidResponseParameters);
TRACE_1("",_spawns);
if (_spawns isEqualType false && {!_spawns}) exitWith {}; // Exit without retry, no spawns available

if (_spawns isEqualTo []) exitWith {
    // Retry with some delay
    [{[_spawnLogics, _creationFunction, _retry + 1] call FUNC(response)}, [], (random RESPONSE_RETRY_DELAY) + RESPONSE_RETRY_DELAY] call CBA_fnc_waitAndExecute;
};

[{
    params ["_args", "_idPFH"];
    _args params ["_spawns", "_creationFunction", "_count", ["_currentCount", 0]];

    if (_currentCount >= _count || {count GVAR(responseGroups) > GVAR(groupLimit)}) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
    };

    private _spawn = selectRandom _spawns;
    private _spawnPosition = _spawn#0;
    private _stagingArea = selectRandom (_spawn#1);
    private _stagingAreaPosition = _stagingArea#0;
    private _playerPosition = selectRandom (_stagingArea#1);

    TRACE_5("",_spawns,_spawnPosition,_stagingAreaPosition,_playerPosition,_count);
    [_spawnPosition, _stagingAreaPosition, _playerPosition, _count] call _creationFunction;

    _args set [3, _currentCount + 1];
}, _delay, [_spawns, _creationFunction, _count]] call CBA_fnc_addPerFrameHandler;
