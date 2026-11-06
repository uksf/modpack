#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Completes a matching L118 magazine transaction on the server.

    Parameters:
        0: Gun <OBJECT>
        1: Transaction <NUMBER>

    Return value:
        Nothing

    Example:
        [_gun, 1] remoteExecCall ["uksf_weapons_fnc_l118Acknowledge", 2]
*/
params ["_gun", "_token"];
if (!isServer || {isNull _gun}) exitWith {};
private _pending = _gun getVariable [QGVAR(l118Pending), []];
if (count _pending != 5) exitWith {};
_pending params ["_expectedToken", "_owner", "_action", "_player", "_round"];
if (_token isNotEqualTo _expectedToken) exitWith {};
_gun setVariable [QGVAR(l118Pending), nil];
if (_action isEqualTo "unload") then {
    createVehicle [QGVAR(105mm_charge), getPosATL _player, [], 0, "NONE"];
    _gun setVariable [QGVAR(l118Shell), nil, true];
    [_gun] call tbd_m119_m119_fnc_hideShells;
    private _shell = createVehicle [GVAR(l118Shells) get _round, getPosATL _player, [], 0, "NONE"];
    _shell setVariable ["tbd_mortars_105mm_dpicm_fuse_timer", _gun getVariable [QGVAR(fuseTime), -1], true];
    _gun setVariable [QGVAR(fuseTime), -1, true];
    [_player, _shell] remoteExecCall [QFUNC(l118Deliver), _player];
};
_gun setVariable [QGVAR(l118Busy), false];
