#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Spawns infantry group with given unit pool. Creates units over time to avoid performance degradation
        Group is disabled from caching and virtualisation

    Parameters:
        0: Position where group will spawn <ARRAY>
        1: Number of units in group <NUMBER>
        2: Side of group <SIDE>
        3: Unit classname pool <ARRAY>
        4: Callback once spawning complete (Args passed: [callback args, _group, (_vehicle)]) <CODE> (Optional)
        5: Callback arguments <ARRAY> (Optional)

    Return value:
        Nothing
*/
#define SPAWN_DELAY 1
#define TIMEOUT 30

params [["_position", [], [[]]], ["_count", 1, [0]], ["_side", east, [sideUnknown]], ["_unitPool", []], ["_callback", {}, [{}]], ["_callbackArgs", [], [[]]]];

TRACE_4("6) Spawn unit data",_position,_count,_side,_unitPool);

private _group = createGroup _side;
[QEGVAR(caching,disableCache), _group] call CBA_fnc_serverEvent;
[QEGVAR(virtualisation,exclude), _group] call CBA_fnc_serverEvent;

_position = +_position;
_position resize 2;

[{
    params ["_args", "_idPFH"];
    _args params ["_position", "_group", "_unitPool", "_count", "_check", "_time", "_callback", "_callbackArgs"];
    TRACE_1("6) Spawn unit iteration",_args);

    private _allSpawned = _check >= _count;
    if (_allSpawned || {time > (_time + TIMEOUT)}) exitWith {
        TRACE_2("6) Spawn unit all spawned or timeout",_allSpawned,time > (_time + TIMEOUT));
        [_idPFH] call CBA_fnc_removePerFrameHandler;

        if (_allSpawned) then {
            INFO("6) Spawn unit all spawned, running callback");
            _callbackArgs pushBack _group;
            _callbackArgs call _callback;
        };
    };

    _group createUnit [(selectRandom _unitPool), _position, [], 5, "NONE"];
    TRACE_1("6) Spawn unit created unit",_args);

    _args set [4, _check + 1];
}, SPAWN_DELAY, [_position, _group, _unitPool, _count, 0, time, _callback, _callbackArgs]] call CBA_fnc_addPerFrameHandler;
