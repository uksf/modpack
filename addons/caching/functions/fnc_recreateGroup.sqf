#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Recreates a group
        Modified version of common,spawnGroup

    Parameters:
        None.

    Return value:
        Nothing.
*/


#define SPAWN_DELAY 1
#define TIMEOUT 30

params ["_uid", "_groupData"];

private _side = _groupData#0;
private _unitDetailsArray = _groupData#1; // [[unit type, [posATL], dir, skill, behaviour, [disabled AI Features]], [..........]]
private _waypointsArray = _groupData#2;
private _combatMode = _groupData#3;

private _group = createGroup _side;

[{
    params ["_args", "_idPFH"];
    _args params ["_group", "_unitPool", "_time", "_uid", "_unitDetailsArray", "_waypointsArray", "_callback", "_callbackArgs"];
    TRACE_1("6) Spawn unit iteration",_args);

    if ((count _unitDetailsArray <= 0) || {time > (_time + TIMEOUT)}) exitWith {
        TRACE_2("6) Spawn unit all spawned or timeout",_unitDetailsArray,time > (_time + TIMEOUT));

        // create waypoints
        [_group, _waypointsArray] call FUNC(addWaypoints);

        // delete the entry from the hashmap
        GVAR(cachedGroupsData) deleteAt _uid;

        [_idPFH] call CBA_fnc_removePerFrameHandler;
    };

    private _unitInfo = selectRandom _unitDetailsArray; // [unit type, [posATL], dir, skill, behaviour]
    private _unit = _group createUnit [_unitInfo#0, [0,0,0], [], 5, "NONE"];
    _unit setPos _unitInfo#1;
    _unit setDir _unitInfo#2;
    _unit setSkill _unitInfo#3;
    _unit setBehaviour _unitInfo #4;
    {
        _unit disableai _x;
    } forEach _unitInfo#5;

    _unitDetailsArray deleteAt (_unitDetailsArray findIf {(_x#0) isKindOf _unitInfo#0});

    systemChat format ["pos: %1, group: %2, uda count: %3", _unitInfo#1, _group, count _unitDetailsArray];

    TRACE_1("6) Spawn unit created unit",_args);

    _args set [4, _unitDetailsArray];
}, SPAWN_DELAY, [_group, _unitPool, time, _uid, _unitDetailsArray, _waypointsArray, _callback, _callbackArgs]] call CBA_fnc_addPerFrameHandler;
