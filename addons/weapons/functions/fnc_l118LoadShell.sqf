#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Loads the nearest L118 shell of the chosen type into the breech. Keeps the shell type and fuse time on the gun until a charge is loaded.

    Parameters:
        0: Gun <OBJECT>
        1: Player <OBJECT>
        2: Shell class <STRING>

    Return value:
        Nothing

    Example:
        [_gun, player, "uksf_weapons_105mm_shell_smoke"] call uksf_weapons_fnc_l118LoadShell
*/
params ["_gun", "_player", "_class"];

private _shell = nearestObjects [_player, [_class], 3] select {typeOf _x isEqualTo _class} param [0, objNull];
if (isNull _shell) exitWith {};

private _config = configOf _shell;
_gun setVariable [QGVAR(l118Shell), getText (_config >> QGVAR(round)), true];
_gun setVariable [QGVAR(fuseTime), _shell getVariable ["tbd_mortars_105mm_dpicm_fuse_timer", -1], true];
deleteVehicle _shell;

private _breech = getText (_config >> QGVAR(breech));
_gun animateSource [_breech + "_load_source", 0, true];
_gun animateSource [_breech + "_hide_source", 0, true];
_gun animateSource [_breech + "_load_source", 0.36, 0.2];
