#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Stops captive escort animations

    Parameters:
        0: Captive unit <OBJECT>

    Return value:
        Nothing
*/
params ["_unit"];

[GVAR(escortPFHID)] call CBA_fnc_removePerFrameHandler;

ACE_player playActionNow QGVAR(clearAction);

private _pos = ((getPos ACE_player) vectorAdd ((vectorDir ACE_player) vectorMultiply 2));
_pos set [2, 1.65];
_unit lookAt _pos;

[{
    params ["_unit"];

    if ((stance ACE_player) == "CROUCH") then {
        _unit setUnitPos "MIDDLE";
        ["ace_common_switchMove", [_unit, "amovpknlmstpsraswrfldnon"], _unit] call CBA_fnc_targetEvent;
        ["ace_common_playActionNow", [_unit, QGVAR(hvtdefault)], _unit] call CBA_fnc_targetEvent;
    } else {
        ["ace_common_switchMove", [_unit, "ace_amovpercmstpscapwnondnon"], _unit] call CBA_fnc_targetEvent;
        ["ace_common_playActionNow", [_unit, QGVAR(clearAction)], _unit] call CBA_fnc_targetEvent;
    };
}, _this, 0.2] call CBA_fnc_waitAndExecute;
