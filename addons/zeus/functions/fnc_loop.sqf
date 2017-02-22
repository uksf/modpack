/*
    Author:
        Tim Beswick

    Description:
        Hides zeus icon and stops touching animation

    Parameter(s):
        None

    Return Value:
        None
*/
#include "script_component.hpp"

[{
    private _unit = player;
    if (!isNull(findDisplay 312) && !(_unit getVariable [QGVAR(inZeus), false])) then {
        _unit setVariable [QGVAR(inZeus), true];
        disableSerialization;
        _display = (findDisplay 312);
        _ctrl = _display displayCtrl 15717;
        _ctrl ctrlSetText "";
        _ctrl ctrlCommit 0;

        if (alive _unit && (vehicle _unit == _unit) && !(_unit getVariable ["ACE_isUnconscious", false])) then {
            private _animation = [_unit] call FUNC(getNewAnimation);
            private _unit = player;
            [_unit, _animation] remoteExecCall ["switchMove", 0];

            private _time = diag_tickTime;
            [{
                params ["_args", "_idPFH"];
                _args params ["_unit", "_animation", "_time"];
                if (diag_tickTime - _time > 1) exitWith {
                    [_idPFH] call cba_fnc_removePerFrameHandler;
                };
                [_unit, _animation] remoteExecCall ["switchMove", 0];
            }, 0, [_unit, _animation, _time]] call cba_fnc_addPerFrameHandler;
        };

    } else {
        if (isNull(findDisplay 312)) then {
            _unit setVariable [QGVAR(inZeus), false];
        };
    };
}, 1,[]] call cba_fnc_addPerFrameHandler;
