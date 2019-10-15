#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Moving target

    Parameter(s):
        0: Target <OBJECT>
        1: Travel direction <SCALAR>
        2: Travel distance <SCALAR>
        3: Travel speed in m/s<SCALAR>
        4: Timout <SCALAR>
        5: Pause <SCALAR>

    Return Value:
        Nothing

    Example:
        [_target, (direction _target) + 90, 10, 2, 10, 2] call uksf_special_fnc_movingTarget;
*/

params ["_target", "_direction", "_distance", "_speed", ["_timeout", 10], ["_pause", 2]];

if (!local _target) exitWith {
    [QGVAR(movingTarget), _this, _target] call CBA_fnc_targetEvent;
};

if (_target getVariable [QGVAR(moving), false]) exitWith {};
_target setVariable [QGVAR(moving), true, true];

private _startPosition = _target getVariable [QGVAR(startPosition), position _target];
private _vectorDir = vectorDir _target;
_vectorDir set [0, sin _direction];
_vectorDir set [1, cos _direction];
_speed = _speed / 60;
private _steps = _distance / _speed;
private _startTime = time;
_pause = (_pause * 15);

[{
    params ["_args", "_idPFH"];
    _args params ["_target", "_startPosition", "_vectorDir", "_speed", "_steps", "_currentSteps", "_step", "_startTime", "_timeout", "_pause"];

    if ((time > (_startTime + _timeout)) && {_currentSteps <= 0}) exitWith {
        _target setVariable [QGVAR(moving), false, true];
        [_idPFH] call CBA_fnc_removePerFrameHandler;
    };

    if (_currentSteps < _steps && {_currentSteps > 0}) then {
        private _newPosition = (_startPosition vectorDiff (_vectorDir vectorMultiply (_currentSteps * _speed)));
        _newPosition set [2, 0];
        _target setPos _newPosition;
    };

    if (_currentSteps >= _steps + _pause) then {
        _args set [6, -1];
    } else {
        if (_currentSteps <= 0 - _pause) then {
            _args set [6, 1];
        };
    };
    _args set [5, _currentSteps + _step];
}, 0, [_target, _startPosition, _vectorDir, _speed, _steps, 1, 1, _startTime, _timeout, _pause]] call CBA_fnc_addPerFrameHandler;
