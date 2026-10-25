#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Unloads the L118 breech. Gives back the shell with its fuse time, and the charge if one is loaded.
        The player carries the shell.

    Parameters:
        0: Gun <OBJECT>
        1: Player <OBJECT>

    Return value:
        Nothing

    Example:
        [_gun, player] call uksf_weapons_fnc_l118Unload
*/
params ["_gun", "_player"];

private _magazine = toLower (_gun magazinesTurret [0] param [0, ""]);
private _round = [(_magazine splitString "_") param [4, ""], _gun getVariable [QGVAR(l118Shell), ""]] select (_magazine isEqualTo "");
if (_round isEqualTo "") exitWith {};

if (_magazine isNotEqualTo "") then {
    ["tbd_m119_m119_unloadShell", [_gun, 0], _gun, [0]] call CBA_fnc_turretEvent;
    createVehicle [QGVAR(105mm_charge), getPosATL _player, [], 0, "NONE"];
};
_gun setVariable [QGVAR(l118Shell), nil, true];
[_gun] call tbd_m119_m119_fnc_hideShells;

private _shell = createVehicle [GVAR(l118Shells) get _round, getPosATL _player, [], 0, "NONE"];
_shell setVariable ["tbd_mortars_105mm_dpicm_fuse_timer", _gun getVariable [QGVAR(fuseTime), -1], true];
_gun setVariable [QGVAR(fuseTime), -1, true];
[_player, _shell] call ace_dragging_fnc_startCarry;
