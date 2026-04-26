#include "script_component.hpp"
/*
    Author:
        Bridg, Tim Beswick

    Description:
        Recreates dismounted units for a group. Applies a rebase delta to each
        stored unit position so the recreated unit spawns at the sim-advanced
        location while preserving its prone/stance offset relative to the new ground.

    Parameters:
        0: Group <SCALAR>
        1: Unit details <ARRAY>
        2: Rebase delta <ARRAY> (PositionASL vector)
        3: Completed callback <CODE>
        4: Callback args <ANY>

    Return value:
        Nothing

    Example:
        [_group, _unitDetails, _rebaseDelta, _callback, _callbackArgs] call uksf_virtualisation_fnc_recreateInfantry
*/
#define SPAWN_DELAY 1
#define TIMEOUT 30

params ["_group", "_unitDetails", "_rebaseDelta", "_callback", "_callbackArgs"];

[{
    params ["_args", "_idPFH"];
    _args params ["_time", "_group", "_unitDetails", "_rebaseDelta", "_callback", "_callbackArgs"];

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

    private _shifted = _position vectorAdd _rebaseDelta;
    private _groundZ = getTerrainHeightASL [_shifted#0, _shifted#1];
    private _originalGroundZ = getTerrainHeightASL [_position#0, _position#1];
    private _spawnPosition = [_shifted#0, _shifted#1, _groundZ + (_position#2 - _originalGroundZ)];

    private _unit = _group createUnit [_type, [0,0,0], [], 5, "NONE"];
    _unit setDir _direction;
    _unit setPosASL _spawnPosition;
    _unit setUnitPos _stance;

    _unit setSkill _skill;
    _unit setBehaviour _behaviour;
    {_unit disableAI _x} forEach _disabledFeatures;
    TRACE_2("Recreated unit",_group,_type);
}, SPAWN_DELAY, [time, _group, _unitDetails, _rebaseDelta, _callback, _callbackArgs]] call CBA_fnc_addPerFrameHandler;
