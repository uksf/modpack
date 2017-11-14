/*
    Author:
        Tim Beswick

    Description:
        Creates curator and assigns to player

    Parameter(s):
        None

    Return Value:
        None
*/
#include "script_component.hpp"

if ((name player) in GVAR(curatorPlayers)) then {
    [QGVAR(curatorAssign), [player]] call CBA_fnc_serverEvent;
    private _message = format ["%1 logged in", name player];
    [QEGVAR(common,hint), [_message]] call CBA_fnc_localEvent;
    [QEGVAR(common,hint), [_message, true]] call CBA_fnc_globalEvent;
    [QEGVAR(common,log), [_message]] call CBA_fnc_serverEvent;
};
