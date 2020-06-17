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
    private _jipId = ["ace_common_playActionNow", [ACE_player, _holdAnim]] call CBA_fnc_globalEventJIP;
    [_jipId, ACE_player] call CBA_fnc_removeGlobalEventJIP;
};

detach _unit;
_unit attachTo [ACE_player, [-0.2, 0.9, 0]];
_unit setDir 0;
_unit setPos (getPos ACE_player);

private _animChangedEHID = _unit getVariable ["ace_captives_handcuffAnimEHID", -1];
_unit removeEventHandler ["AnimChanged", _animChangedEHID];
_unit setVariable ["ace_captives_handcuffAnimEHID", -1];

["ace_common_switchMove", [_unit, animationState ACE_player]] call CBA_fnc_globalEvent;
private _jipId = ["ace_common_playActionNow", [_unit, QGVAR(hvtdefault)]] call CBA_fnc_globalEventJIP;
[_jipId, _unit] call CBA_fnc_removeGlobalEventJIP;

GVAR(escortPFHID) = [{
    params ["_args", "_idPFH"];
    _args params ["_unit"];

    if (stance ACE_player == "PRONE") exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
        [ACE_player, _unit, false] call ace_captives_fnc_doEscortCaptive;
    };

    ["ace_common_playActionNow", [_unit, animationState ACE_player]] call CBA_fnc_globalEvent;

    // Might not need this
    // if (stance ACE_player == "PRONE") then {
    //     ACE_player setUnitPos "MIDDLE";
    //     call gge_captives_fnc_grabCaptive;
    // };
}, 0, [_unit]] call CBA_fnc_addPerFrameHandler;
