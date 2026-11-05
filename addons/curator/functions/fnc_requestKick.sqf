#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Validates a curator kick request.

    Parameter(s):
        0: Requester <OBJECT>
        1: Kick all <BOOL>
        2: Target name <STRING> (Optional)

    Return Value:
        None

    Example:
        [player, false, "Player"] remoteExecCall ["uksf_curator_fnc_requestKick", 2]
*/
params [["_player", objNull, [objNull]], ["_all", false, [false]], ["_target", "", [""]]];
if (!isServer || {isNull _player} || {!isPlayer _player} || {remoteExecutedOwner != owner _player}) exitWith {};
private _authorised = (admin (owner _player) > 0) || {owner _player == 2 && {hasInterface}} || {(getPlayerUID _player) in CURATOR_WHITELIST};
if (!isMultiplayer || {!_authorised}) exitWith {};
if (!_all && {!((getPlayerUID _player) in WHITELIST)} && {admin (owner _player) == 0} && {!(owner _player == 2 && {hasInterface})}) exitWith {};
if (_all && {({ _x != "" } count GVAR(curatorPlayers)) <= 1}) exitWith {};
private _curators = [];
private _names = [];
{
    if (_x isNotEqualTo "" && {_all || {_x isEqualTo _target}}) then {
        _curators pushBack (GVAR(curatorObjects) param [_forEachIndex, objNull]);
        _names pushBack _x;
    };
} forEach GVAR(curatorPlayers);
private _uksf_curatorValidated = true;
{[_x] call FUNC(curatorUnassign)} forEach _curators;
private _kickedPlayers = ALL_PLAYERS select {(name _x) in _names};
if (_kickedPlayers isNotEqualTo []) then {
    [QEGVAR(common,hint), ["You were kicked"], _kickedPlayers] call CBA_fnc_targetEvent;
};
if (_names isNotEqualTo []) then {
    private _message = if (_all) then {"Kicked all"} else {format ["Kicked %1", _target]};
    [QEGVAR(common,hint), [_message], _player] call CBA_fnc_targetEvent;
};
