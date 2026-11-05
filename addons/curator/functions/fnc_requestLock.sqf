#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Validates a curator lock request.

    Parameter(s):
        0: Requester <OBJECT>
        1: Locked <BOOL>

    Return Value:
        None

    Example:
        [player, true] remoteExecCall ["uksf_curator_fnc_requestLock", 2]
*/
params [["_player", objNull, [objNull]], ["_locked", false, [false]]];
if (!isServer || {isNull _player} || {!isPlayer _player} || {remoteExecutedOwner != owner _player}) exitWith {};
private _authorised = (admin (owner _player) > 0) || {owner _player == 2 && {hasInterface}} || {(getPlayerUID _player) in CURATOR_WHITELIST};
if (!isMultiplayer || {!_authorised} || {_locked isEqualTo GVAR(curatorsLocked)}) exitWith {};
private _uksf_curatorValidated = true;
[_locked] call FUNC(setCuratorsLocked);
