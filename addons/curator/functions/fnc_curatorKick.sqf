/*
    Author:
        Tim Beswick

    Description:
        Kicks player or all players

    Parameter(s):
        0: Kick all <BOOL>
        1: Player <STRING> (Optional)

    Return Value:
        None
*/
#include "script_component.hpp"

params ["_kickAll", ["_player", ""]];

if (_kickAll) then {
    {
        if (_x != "") then {
            [QEGVAR(common,hint), ["You were kicked"], [_x]] call CBA_fnc_targetEvent;
            [QGVAR(curatorUnassign), [(GVAR(curatorObjects) select _forEachIndex)]] call CBA_fnc_serverEvent;
        };
    } forEach GVAR(curatorPlayers);
    [QEGVAR(common,hint), ["Kicked all"]] call CBA_fnc_localEvent;
} else {
    private _index = (GVAR(curatorPlayers) find _player);
    if (_index > -1) then {
        [QGVAR(curatorUnassign), [(GVAR(curatorObjects) select _index)]] call CBA_fnc_serverEvent;
        [QEGVAR(common,hint), [format ["Kicked %1", _player]]] call CBA_fnc_localEvent;
        [QEGVAR(common,hint), ["You were kicked"], (allPlayers select {(name _x) isEqualTo _player}) select 0] call CBA_fnc_targetEvent;
    };
};
