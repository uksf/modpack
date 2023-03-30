#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Recreates a group
        Modified version of common,spawnGroup

    Parameters:
        0: Group data <ARRAY>
            0: Group type <SCALAR>
            1: Side <SIDE>
            2: Unit Details <ARRA>
            3: Waypoints <ARRAY>
            4: CombatMode <STRING>

    Return value:
        Nothing
*/
#define SPAWN_DELAY 1
#define TIMEOUT 30

params ["_groupData"];
_groupData params ["", "_side"];

private _group = createGroup _side;
[{
    params ["_args", "_idPFH"];
    _args params ["_time", "_group", "_groupData"];
    _groupData params ["", "", "_unitDetails", "_waypoints", "_combatMode", "_formationDirection"];

    if (isNull _group) exitWith {
        TRACE_1("Group deleted whilst recreated",_group);
        [_idPFH] call CBA_fnc_removePerFrameHandler;
    };

    if (_unitDetails isEqualTo [] || {time > (_time + TIMEOUT)}) exitWith {
        DEBUG("Spawn unit all spawned or timeout");
        [_idPFH] call CBA_fnc_removePerFrameHandler;

        _group setCombatMode _combatMode;
        _group setFormDir _formationDirection;
        [_group, _waypoints] call FUNC(addWaypoints);
    };

    private _unitInfo = _unitDetails deleteAt 0;
    _unitInfo params ["_type", "_position", "_direction", "_skill", "_behaviour", "_disabledFeatures", "_stance"];

    private _unit = _group createUnit [_type, [0,0,0], [], 5, "NONE"];
    _unit setDir _direction;
    _unit setPos _position;

    _unit setSkill _skill;
    _unit setBehaviour _behaviour;
    _unit setUnitPos _stance;
    {_unit disableAI _x} forEach _disabledFeatures;
}, SPAWN_DELAY, [time, _group, _groupData]] call CBA_fnc_addPerFrameHandler;
