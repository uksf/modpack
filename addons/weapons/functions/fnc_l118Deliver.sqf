#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Delivers a validated ammunition item or starts carrying a returned shell.

    Parameters:
        0: Recipient <OBJECT>
        1: Item or shell <STRING or OBJECT>

    Return value:
        Nothing

    Example:
        [_player, _shell] remoteExecCall ["uksf_weapons_fnc_l118Deliver", _player]
*/
params ["_player", "_delivery"];
if ((isRemoteExecuted && {remoteExecutedOwner != 2}) || {!isRemoteExecuted && {!isServer}} || {!local _player}) exitWith {};
if (_delivery isEqualType "") exitWith {
    if (_delivery in ["tbd_mortars_105mm_shell_he", "tbd_mortars_105mm_shell_smoke", "tbd_mortars_105mm_shell_dpicm", "tbd_mortars_105mm_casing_charge_7"]) then {_player addItem _delivery};
};
if (_delivery isEqualType objNull && {!isNull _delivery}) then {[_player, _delivery] call ace_dragging_fnc_startCarry};
