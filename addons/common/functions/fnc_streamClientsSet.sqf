#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Adds or removes a player on a stream-client list. Each entry is
        [player, [keys]]. A player with no remaining keys is dropped.
        Null players are pruned first.

    Parameter(s):
        0: List <ARRAY>
        1: Player <OBJECT>
        2: Key <STRING>
        3: Subscribe <BOOL>

    Return Value:
        None

    Example:
        [_list, _player, "cards", true] call uksf_common_fnc_streamClientsSet
*/
params ["_list", "_player", "_key", "_state"];
if (isNull _player || {_key isEqualTo ""}) exitWith {};

[_list] call FUNC(streamClientsPrune);

private _index = _list findIf {(_x select 0) isEqualTo _player};
if (_state) exitWith {
    if (_index == -1) then {
        _list pushBack [_player, [_key]];
    } else {
        ((_list select _index) select 1) pushBackUnique _key;
    };
};

if (_index == -1) exitWith {};
private _keys = (_list select _index) select 1;
_keys deleteAt (_keys find _key);
if (_keys isEqualTo []) then {
    _list deleteAt _index;
};
