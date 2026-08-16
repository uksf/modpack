#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Client. Registers or drops this player on the server console-telemetry list.

    Parameter(s):
        0: Key <STRING>
        1: Subscribe <BOOL>

    Return Value:
        None

    Example:
        ["cards", true] call uksf_npc_fnc_consoleSubscribe
*/
if (!hasInterface) exitWith {};
params ["_key", "_state"];
if !(ADMIN_OR_WHITELISTED) exitWith {};
[QGVAR(consoleSubscribe), [player, _key, _state]] call CBA_fnc_serverEvent;
