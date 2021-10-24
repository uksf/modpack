#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Checks player height. Continues on when height is above 3000m.

    Parameter(s):
        0: Player <OBJECT>

    Return Value:
        None
*/
params ["_player"];

private _startingHeight = (getPosASL player) select 2;
private _oxygenRequiredHeight = _startingHeight + 3000; // should handle higher maps such as takistan

playSound QGVAR(hiss);
[{
    playSound QGVAR(breatheOxygen);
}, 2] call cba_fnc_waitAndExecute;

[{
    params ["_args", "_idPFH"];
    _args params ["_player"];

    if (!alive _player) exitWith {
        [_idPFH] call cba_fnc_removePerFrameHandler;
    };
    private _currentHeight = (getPosASL player) select 2;

    if ((_currentHeight >= _oxygenRequiredHeight) && !GVAR(oxygenConnected)) then {
        [_player] call FUNC(checkOxygenIsConnected);
    };

    if (goggles _target != "G_mas_usl_jumpmask") exitWith {
        // stop sounds and detach oxygen
        GVAR(oxygenConnected) = false;
    };
}, 5, _player, _oxygenRequiredHeight] call CBA_fnc_addPerFrameHandler;
