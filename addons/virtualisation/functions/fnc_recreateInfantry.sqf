#include "script_component.hpp"
/*
    Author:
        Bridg, Tim Beswick

    Description:
        Recreates dismounted units for a group

    Parameters:
        0: Group <SCALAR>
        1: Unit details <ARRAY>
        2: Completed callback <CODE>
        3: Callback args <ANY>

    Return value:
        Nothing
*/
#define SPAWN_DELAY 1
#define TIMEOUT 30

params ["_group", "_unitDetails", "_callback", "_callbackArgs"];

[{
    params ["_args", "_idPFH"];
    _args params ["_time", "_group", "_unitDetails", "_callback", "_callbackArgs"];

    if (isNull _group) exitWith {
        TRACE_1("Group deleted whilst recreating units",_group);
        [_idPFH] call CBA_fnc_removePerFrameHandler;
    };

    if (_unitDetails isEqualTo [] || {time > (_time + TIMEOUT)}) exitWith {
        TRACE_1("All units recreated, or timed out",_group);
        [_idPFH] call CBA_fnc_removePerFrameHandler;

        _callbackArgs call _callback;
    };

    private _unitData = _unitDetails deleteAt 0;
    _unitData params ["_type", "_position", "_direction", "_stance", "_skill", "_behaviour", "_disabledFeatures"];

    private _unit = _group createUnit [_type, [0,0,0], [], 5, "NONE"];
    _unit setDir _direction;
    _unit setPosASL _position;
    _unit setUnitPos _stance;

    _unit setSkill _skill;
    _unit setBehaviour _behaviour;
    {_unit disableAI _x} forEach _disabledFeatures;
    TRACE_2("Recreated unit",_group,_type);
}, SPAWN_DELAY, [time, _group, _unitDetails, _callback, _callbackArgs]] call CBA_fnc_addPerFrameHandler;
