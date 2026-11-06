#include "script_component.hpp"
/*
    Author:
        Tim Beswick, Gruppe Adler https://github.com/gruppe-adler/gruppe_adler_mod/tree/master/addons/ui

    Description:
        Connects to the selected UKSF server.
        Uses the password CBA cached for the server, so a cached password connects with no prompt.
        With no cached password, the game shows its password screen, and CBA caches what the player enters.
        A second click for the same server on the same main menu means the cached password failed,
        so that click sends no password and the game shows its password screen, prefilled by CBA.

    Parameter(s):
        None

    Return Value:
        Nothing

    Example:
        call uksf_menu_fnc_connectToServer
*/

#define SERVER_IP "54.36.165.77"

private _port = uiNamespace getVariable [QGVAR(selectedPort), "2302"];
private _server = format ["%1:%2", SERVER_IP, _port];

private _password = "";
if (uiNamespace getVariable [QGVAR(cachedPasswordServer), ""] == _server) then {
    uiNamespace setVariable [QGVAR(cachedPasswordServer), nil];
} else {
    private _passwordCache = profileNamespace getVariable ["cba_ui_ServerPasswords", [[], []]];
    _password = (_passwordCache select 1) param [(_passwordCache select 0) find _server, ""];
    if (_password != "") then {
        uiNamespace setVariable [QGVAR(cachedPasswordServer), _server];
    };
};

connectToServer [SERVER_IP, parseNumber _port, _password];
