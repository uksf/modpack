#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Validates and applies an NPC console action on the server.

        Unmute restores a living unit, including an ACE-unconscious unit. A dead object
        stays terminal because restoring it needs a new unit and session identity.
*/
if (!isServer) exitWith {};
params ["_player", "_npcId", "_action"];

if (isNull _player || {!(_player in ALL_PLAYERS)}) exitWith {};
private _authorised = (getPlayerUID _player) in WHITELIST || {admin (owner _player) > 0};
if (!_authorised) exitWith {WARNING_1("NPC console refused unauthorised player: %1",getPlayerUID _player)};
if !(_action in ["reset", "cancel", "mute", "unmute"]) exitWith {};

private _npc = objectFromNetId _npcId;
if (isNull _npc) exitWith {};
private _registered = missionNamespace getVariable [QGVAR(registeredNetIds), []];
if !(_npcId in _registered) exitWith {};

switch (_action) do {
    case "reset": {
        if ((_npc getVariable [QGVAR(interactionProfile), "conversation"]) isEqualTo "guarded" && {alive _npc}) then {
            [_npcId] call FUNC(consoleCancelNpc);
            [_npc, true] call FUNC(registerNpc);
            [GVAR(consoleClients), QGVAR(consoleClearStateSink), [_npcId]] call EFUNC(common,streamClientsFanout);
        };
    };
    case "cancel": {[_npcId] call FUNC(consoleCancelNpc)};
    case "mute": {
        [_npcId] call FUNC(consoleCancelNpc);
        _npc setVariable [QGVAR(talkable), false, true];
        [_npcId, false] call FUNC(setTalkerList);
        private _muted = missionNamespace getVariable [QGVAR(mutedNetIds), []];
        _muted pushBackUnique _npcId;
        missionNamespace setVariable [QGVAR(mutedNetIds), _muted, true];
    };
    case "unmute": {
        if (alive _npc && {!(_npc getVariable [QGVAR(playerDropped), false])}) then {
            _npc setVariable [QGVAR(talkable), true, true];
            private _muted = missionNamespace getVariable [QGVAR(mutedNetIds), []];
            missionNamespace setVariable [QGVAR(mutedNetIds), _muted - [_npcId], true];
            [_npcId, true] call FUNC(setTalkerList);
        };
    };
};
TRACE_3("NPC console action",_action,_npcId,getPlayerUID _player);
