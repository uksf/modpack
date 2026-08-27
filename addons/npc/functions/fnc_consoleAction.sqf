#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Requests one server-authoritative inspector action for the selected NPC.
*/
params [["_action", "", [""]], ["_npc", objNull, [objNull]]];

if !(ADMIN_OR_WHITELISTED) exitWith {};
if !(_action in ["reset", "cancel", "mute", "unmute"]) exitWith {};
if (isNull _npc) then {_npc = GVAR(consoleInspectorNpc)};
if (isNull _npc) exitWith {};
[QGVAR(consoleAction), [player, netId _npc, _action]] call CBA_fnc_serverEvent;
