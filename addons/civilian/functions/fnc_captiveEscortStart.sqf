#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Starts captive escort animations

    Parameters:
        0: Captive unit <OBJECT>

    Return value:
        Nothing
*/
params ["_unit"];

if !(ace_common_isReloading) then {
    private _holdAnim = [QGVAR(holdhvt), QGVAR(holdhvtpistol)] select ((currentWeapon ACE_player) == (handgunWeapon ACE_player));
    ACE_player playActionNow _holdAnim;
};

detach _unit;
_unit attachTo [ACE_player, [-0.2, 0.9, 0]];

[QGVAR(removeAnimChangedEH), [_unit, -3, -2]] call CBA_fnc_targetEvent;

["ace_common_switchMove", [_unit, animationState ACE_player], _unit] call CBA_fnc_targetEvent;
["ace_common_playActionNow", [_unit, QGVAR(hvtdefault)], _unit] call CBA_fnc_targetEvent;

GVAR(escortPFHID) = [{
    params ["_args", "_idPFH"];
    _args params ["_unit"];

    if (stance ACE_player == "PRONE") exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
        [ACE_player, _unit, false] call ace_captives_fnc_doEscortCaptive;
    };

    ["ace_common_playMoveNow", [_unit, animationState ACE_player], _unit] call CBA_fnc_targetEvent;
}, 0, [_unit]] call CBA_fnc_addPerFrameHandler;
