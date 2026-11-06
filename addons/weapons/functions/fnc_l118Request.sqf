#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Validates and applies an L118 ammunition request on the server.

    Parameters:
        0: Requester <OBJECT>
        1: Action <STRING>
        2: Gun or piece <OBJECT>
        3: Shell class or charge <STRING or NUMBER> (Optional)

    Return value:
        Nothing

    Example:
        [player, "unload", _gun] remoteExecCall ["uksf_weapons_fnc_l118Request", 2]
*/
params [["_player", objNull, [objNull]], ["_action", "", [""]], ["_target", objNull, [objNull]], ["_selection", "", ["", 0]]];

if (!isServer || {isNull _player} || {!isPlayer _player} || {remoteExecutedOwner != owner _player} || {isNull _target} || {_player distance _target > 3}) exitWith {};

private _pieceClasses = [QGVAR(105mm_shell_he), QGVAR(105mm_shell_smoke), QGVAR(105mm_shell_illum), QGVAR(105mm_charge)];
if (_action isEqualTo "stow") exitWith {
    if (!(typeOf _target in _pieceClasses) || {_target getVariable [QGVAR(claimed), false]} || {_target getVariable ["tbd_mortars_105mm_dpicm_fuse_timer", -1] >= 0}) exitWith {};
    private _item = getText (configOf _target >> QGVAR(item));
    if !(_player canAdd _item) exitWith {};
    _target setVariable [QGVAR(claimed), true];
    [_player, _item] remoteExecCall [QFUNC(l118Deliver), _player];
    deleteVehicle _target;
};

if !(_action in ["shell", "charge", "unload"]) exitWith {};
if !(_target isKindOf "TBD_M119") exitWith {};
if (_target getVariable [QGVAR(l118Busy), false]) exitWith {};
private _magazines = _target magazinesTurret [0];
private _round = _target getVariable [QGVAR(l118Shell), ""];
private _piece = objNull;

if (_action isEqualTo "shell") then {
    if (_selection isEqualType "" && {_selection in (_pieceClasses select [0, 3])} && {_magazines isEqualTo []} && {_round isEqualTo ""}) then {
        _piece = nearestObjects [_player, [_selection], 3] select {typeOf _x isEqualTo _selection && {!(_x getVariable [QGVAR(claimed), false])}} param [0, objNull];
    };
};
if (_action isEqualTo "charge") then {
    if (_selection isEqualType 0 && {_selection in [1, 2, 3, 4, 5, 6, 7]} && {_magazines isEqualTo []} && {_round in ["he", "smoke", "dpicm"]}) then {
        _piece = nearestObjects [_player, [QGVAR(105mm_charge)], 3] select {typeOf _x isEqualTo QGVAR(105mm_charge) && {!(_x getVariable [QGVAR(claimed), false])}} param [0, objNull];
    };
};
if (_action in ["shell", "charge"] && {isNull _piece}) exitWith {};

private _magazine = toLower (_magazines param [0, ""]);
if (_action isEqualTo "unload") then {
    if (_magazine isNotEqualTo "") then {_round = (_magazine splitString "_") param [4, ""]};
};
if (_action isEqualTo "unload" && {!(_round in ["he", "smoke", "dpicm"])}) exitWith {};

_target setVariable [QGVAR(l118Busy), true];
if (!isNull _piece) then {_piece setVariable [QGVAR(claimed), true]};
private _magazineChanged = false;
switch (_action) do {
    case "shell": {
        private _config = configOf _piece;
        _target setVariable [QGVAR(l118Shell), getText (_config >> QGVAR(round)), true];
        _target setVariable [QGVAR(fuseTime), _piece getVariable ["tbd_mortars_105mm_dpicm_fuse_timer", -1], true];
        private _breech = getText (_config >> QGVAR(breech));
        _target animateSource [_breech + "_load_source", 0, true];
        _target animateSource [_breech + "_hide_source", 0, true];
        _target animateSource [_breech + "_load_source", 0.36, 0.2];
    };
    case "charge": {
        private _newMagazine = format ["tbd_mortars_105mm_round_%1_charge_mag_%2", _round, _selection];
        ["tbd_m119_m119_loadShell", [_target, _newMagazine, 0], _target, [0]] call CBA_fnc_turretEvent;
        _target setVariable [QGVAR(l118Shell), nil, true];
        _target animateSource ["magazine_laser_load_source", 0, true];
        _target animateSource ["magazine_laser_hide_source", 0, true];
        _target animateSource ["magazine_laser_load_source", 0.36, 0.2];
        _magazineChanged = true;
    };
    case "unload": {
        if (_magazine isNotEqualTo "") then {
            ["tbd_m119_m119_unloadShell", [_target, 0], _target, [0]] call CBA_fnc_turretEvent;
            createVehicle [QGVAR(105mm_charge), getPosATL _player, [], 0, "NONE"];
            _magazineChanged = true;
        };
        _target setVariable [QGVAR(l118Shell), nil, true];
        [_target] call tbd_m119_m119_fnc_hideShells;
        private _shell = createVehicle [GVAR(l118Shells) get _round, getPosATL _player, [], 0, "NONE"];
        _shell setVariable ["tbd_mortars_105mm_dpicm_fuse_timer", _target getVariable [QGVAR(fuseTime), -1], true];
        _target setVariable [QGVAR(fuseTime), -1, true];
        [_player, _shell] remoteExecCall [QFUNC(l118Deliver), _player];
    };
};
if (!isNull _piece) then {deleteVehicle _piece};
if (_magazineChanged) then {
    [{_this setVariable [QGVAR(l118Busy), false]}, _target, 1] call CBA_fnc_waitAndExecute;
} else {
    _target setVariable [QGVAR(l118Busy), false];
};
