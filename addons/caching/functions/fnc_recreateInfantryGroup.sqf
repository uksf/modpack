#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Recreates a group
        Modified version of common,spawnGroup

    Parameters:
        0: uid <STRING>
        1: groupData <ARRAY> [_side, _unitDetailsArray, _waypointsArray, _combatMode]

    Return value:
        Nothing.
*/


#define SPAWN_DELAY 1
#define TIMEOUT 30

params ["_uid", "_groupData"];
_groupData params ["_side", "_unitDetailsArray", "_waypointsArray", "_combatMode"];

private _group = createGroup _side;

[{
    params ["_args", "_idPFH"];
    _args params ["_group", "_unitPool", "_time", "_uid", "_unitDetailsArray", "_waypointsArray"];

    TRACE_1("6) Spawn unit iteration",_args);

    if ((count _unitDetailsArray <= 0) || {time > (_time + TIMEOUT)}) exitWith {
        TRACE_2("6) Spawn unit all spawned or timeout",_unitDetailsArray,time > (_time + TIMEOUT));

        // create waypoints
        [_group, _waypointsArray] call FUNC(addWaypoints);

        // delete the entry from the hashmap
        GVAR(cachedGroupsData) deleteAt _uid;

        [_idPFH] call CBA_fnc_removePerFrameHandler;
    };

    private _unitInfo = _unitDetailsArray deleteAt 0;
    TRACE_1("6) unit info",_unitInfo);
    if (_unitInfo isEqualTo []) exitWith {TRACE_1("6) exited, unit info",_unitInfo);};
    _unitInfo params ["_unitType", "_unitPos", "_unitDir", "_unitSkill", "_unitBehaviour", "_unitFeatures"];
    private _unit = _group createUnit [_unitType, [0,0,0], [], 5, "NONE"];
    _unit setSkill _unitSkill;
    _unit setBehaviour _unitBehaviour;
    _unit setPos _unitPos;
    _unit setDir _unitDir;
    {
        _unit disableai _x;
    } forEach _unitFeatures;

    _unitDetailsArray deleteAt (_unitDetailsArray findIf {(_x#0) isKindOf _unitType});

    TRACE_1("6) Spawn unit created unit",_args);

    _args set [4, _unitDetailsArray];
}, SPAWN_DELAY, [_group, _unitPool, time, _uid, _unitDetailsArray, _waypointsArray]] call CBA_fnc_addPerFrameHandler;
