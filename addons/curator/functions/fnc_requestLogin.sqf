#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Validates a curator login request.

    Parameter(s):
        0: Requester <OBJECT>

    Return Value:
        None

    Example:
        [player] remoteExecCall ["uksf_curator_fnc_requestLogin", 2]
*/
params [["_player", objNull, [objNull]]];
if (!isServer || {isNull _player} || {!isPlayer _player} || {remoteExecutedOwner != owner _player}) exitWith {};
private _authorised = (admin (owner _player) > 0) || {owner _player == 2 && {hasInterface}} || {(getPlayerUID _player) in CURATOR_WHITELIST};
if (!_authorised && {GVAR(curatorsLocked)}) exitWith {};
if ((name _player) in GVAR(curatorPlayers) || {!("" in GVAR(curatorPlayers))}) exitWith {};
private _uksf_curatorValidated = true;
[_player] call FUNC(curatorAssign);
