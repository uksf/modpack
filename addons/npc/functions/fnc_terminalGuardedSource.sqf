#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Server. A guarded source has died or gone ACE unconscious. Ends the interaction for
        the rest of the session: the talkable flag is cleared and replicated, so the client
        gate stops offering the NPC and the earshot forward stops reaching them. Later
        recovery does not restore it — a source that went down mid-questioning stays down.

        Any in-flight turn is cancelled towards the clients as well, and an open streamed
        reply is closed there, otherwise the filler loop keeps muttering for a reply that will
        never arrive and the last frames already delivered keep the mouth running.

    Parameter(s):
        0: NPC <OBJECT>

    Return Value:
        None

    Example:
        [_npc] call uksf_npc_fnc_terminalGuardedSource
*/
if (!isServer) exitWith {};

params ["_npc"];

if (isNull _npc) exitWith {};
if !(_npc getVariable [QGVAR(talkable), false]) exitWith {};
if ((_npc getVariable [QGVAR(interactionProfile), "conversation"]) isNotEqualTo "guarded") exitWith {};

private _npcId = netId _npc;
GVAR(cancelledNpcIds) set [_npcId, true];
_npc setVariable [QGVAR(talkable), false, true];

GVAR(rooms) deleteAt _npcId;
GVAR(roomTimers) deleteAt _npcId;
GVAR(lastSpeaker) deleteAt _npcId;
GVAR(watchUntil) deleteAt _npcId;
GVAR(activeClips) deleteAt _npcId;

// Close whatever was still being spoken. Without the end the clients hold an open clip that
// no later frame will finish, so the lips run on past the moment the source went down.
private _stream = GVAR(activeStreams) getOrDefault [_npcId, []];
if (_stream isNotEqualTo []) then {
    [QGVAR(streamEndSink), [_npcId, _stream#0], ALL_PLAYERS] call CBA_fnc_targetEvent;
};
GVAR(activeStreams) deleteAt _npcId;

private _talkers = missionNamespace getVariable [QGVAR(talkerNetIds), []];
missionNamespace setVariable [QGVAR(talkerNetIds), _talkers - [_npcId], true];

[QGVAR(turnCancelSink), [_npcId], ALL_PLAYERS] call CBA_fnc_targetEvent;
TRACE_1("guarded source terminal, no longer talkable",_npcId);
