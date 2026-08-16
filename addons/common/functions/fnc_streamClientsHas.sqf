#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Returns whether a live player is on a stream-client list, optionally
        for one key.

    Parameter(s):
        0: List <ARRAY>
        1: Player <OBJECT>
        2: Key <STRING> (Optional)

    Return Value:
        Whether the player is subscribed <BOOL>

    Example:
        [_list, _player, "inspector"] call uksf_common_fnc_streamClientsHas
*/
params ["_list", "_player", ["_key", "", [""]]];
if (isNull _player) exitWith {false};

private _index = _list findIf {(_x select 0) isEqualTo _player};
if (_index == -1) exitWith {false};
if (_key isEqualTo "") exitWith {true};

_key in ((_list select _index) select 1)
