#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Spawns garrisons using rolling one-unit-per-tick PFH pacing.

    Parameters:
        0: Module logic <OBJECT>
        1: Mutable positions [[positionATL, direction], ...] <ARRAY>
        2: Group side <SIDE>
        3: Unit class pool <ARRAY>
        4: Completion callback <CODE>
        5: Callback args <ARRAY>

    Return Value:
        Nothing

    Example:
        [_logic, _positions, _side, _unitList, _callback, _callbackArgs] call uksf_autoplace_fnc_spawnGarrisons
*/
params ["_logic", "_positions", "_side", "_unitList", ["_callback", {}], ["_callbackArgs", []]];

if (isNull _logic) exitWith {};
if (_unitList isEqualTo []) exitWith {
    private _doneArgs = +_callbackArgs;
    _doneArgs pushBack _positions;
    _doneArgs call _callback;
};

[{
    params ["_args", "_idPFH"];
    _args params ["_logic", "_positions", "_side", "_unitList", "_currentGroup", "_lastSpawn", "_callback", "_callbackArgs"];

    if (isNull _logic) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
    };

    if (_positions isEqualTo [] && {_currentGroup isEqualTo []}) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
        private _doneArgs = +_callbackArgs;
        _doneArgs pushBack _positions;
        _doneArgs call _callback;
    };

    if (diag_fps < 20 && {_lastSpawn > CBA_missionTime}) exitWith {};

    if (_currentGroup isEqualTo []) then {
        private _chunk = [_positions] call FUNC(takeChunk);
        if (_chunk isNotEqualTo []) then {
            private _group = createGroup _side;
            _group deleteGroupWhenEmpty true;
            _currentGroup = [_group, _chunk];
            _args set [4, _currentGroup];
        };
    };

    if (_currentGroup isEqualTo []) exitWith {};

    _currentGroup params ["_group", "_chunk"];
    private _positionData = _chunk deleteAt 0;
    _positionData params ["_position", "_direction"];

    private _unit = _group createUnit [selectRandom _unitList, _position, [], 0, "CAN_COLLIDE"];
    if (!isNull _unit) then {
        _unit setPosATL _position;
        _unit setDir _direction;
        _unit disableAI "PATH";
    };

    if (_chunk isEqualTo []) then {
        _args set [4, []];
    };

    _args set [5, CBA_missionTime + 0.5];
}, 0, [_logic, _positions, _side, _unitList, [], 0, _callback, _callbackArgs]] call CBA_fnc_addPerFrameHandler;
