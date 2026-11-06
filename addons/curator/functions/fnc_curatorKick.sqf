#include "script_component.hpp"
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

    Example:
        [_kickAll, _player] call uksf_curator_fnc_curatorKick
*/
params ["_kickAll", ["_player", ""]];

if (_kickAll) then {
    private _kickedNames = [];
    private _kickedCurators = [];
    {
        if (_x != "") then {
            _kickedNames pushBack _x;
            _kickedCurators pushBack (GVAR(curatorObjects) param [_forEachIndex, objNull]);
        };
    } forEach GVAR(curatorPlayers);

    {
        [QGVAR(curatorUnassign), [_x]] call CBA_fnc_serverEvent;
    } forEach _kickedCurators;

    private _kickedPlayers = ALL_PLAYERS select {(name _x) in _kickedNames};
    if (_kickedPlayers isNotEqualTo []) then {
        [QEGVAR(common,hint), ["You were kicked"], _kickedPlayers] call CBA_fnc_targetEvent;
    };
    [QEGVAR(common,hint), ["Kicked all"]] call CBA_fnc_localEvent;
} else {
    private _index = (GVAR(curatorPlayers) find _player);
    if (_index > -1) then {
        [QGVAR(curatorUnassign), [(GVAR(curatorObjects) select _index)]] call CBA_fnc_serverEvent;
        [QEGVAR(common,hint), [format ["Kicked %1", _player]]] call CBA_fnc_localEvent;
        private _targetPlayer = ALL_PLAYERS select {(name _x) isEqualTo _player};
        if (_targetPlayer isNotEqualTo []) then {
            [QEGVAR(common,hint), ["You were kicked"], _targetPlayer select 0] call CBA_fnc_targetEvent;
        };
    };
};
