/*
    Author:
        Tim Beswick

    Description:
        Kicks player or all players

    Parameter(s):
        0: Kick all <BOOL>
        1: Player <OBJECT> (Optional)

    Return Value:
        None
*/
#include "script_component.hpp"

params ["_kickAll", ["_player", objnull]];

if (_kickAll) then {
    {
        if (isNull _x) then {
            GVAR(curatorObjects) deleteAt (GVAR(curatorObjects) find _x);
        } else {
            [QGVAR(curatorUnassign), [_x]] call CBA_fnc_serverEvent;
            [QEGVAR(common,hint), ["You were kicked"], (getAssignedCuratorUnit _x)] call CBA_fnc_targetEvent;
        };
        false
    } count GVAR(curatorObjects);
    [QEGVAR(common,hint), ["Kicked all"]] call CBA_fnc_localEvent;
} else {
    [QGVAR(curatorUnassign), [(getAssignedCuratorLogic _player)]] call CBA_fnc_serverEvent;
    [QEGVAR(common,hint), ["You were kicked"], _player] call CBA_fnc_targetEvent;
    [QEGVAR(common,hint), [format ["Kicked %1", name _player]]] call CBA_fnc_localEvent;
};
