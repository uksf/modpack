#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Cancels queued, filler, clip, and streamed work for one NPC on the server.
*/
if (!isServer) exitWith {};
params ["_npcId"];

GVAR(cancelledNpcIds) set [_npcId, true];
GVAR(rooms) deleteAt _npcId;
GVAR(roomTimers) deleteAt _npcId;
GVAR(lastSpeaker) deleteAt _npcId;
GVAR(watchUntil) deleteAt _npcId;
GVAR(activeClips) deleteAt _npcId;
private _targets = ALL_PLAYERS select {(getPlayerUID _x) in WHITELIST || {admin (owner _x) > 0}};
[QGVAR(consoleClearPendingSink), [_npcId], _targets] call CBA_fnc_targetEvent;

private _stream = GVAR(activeStreams) getOrDefault [_npcId, []];
if (_stream isNotEqualTo []) then {
    [QGVAR(streamEndSink), [_npcId, _stream#0], ALL_PLAYERS] call CBA_fnc_targetEvent;
};
GVAR(activeStreams) deleteAt _npcId;
[QGVAR(turnCancelSink), [_npcId], ALL_PLAYERS] call CBA_fnc_targetEvent;
