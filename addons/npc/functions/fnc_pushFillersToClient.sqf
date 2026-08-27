#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Server. Sends the cached filler set to one live client.

    Parameter(s):
        0: Player <OBJECT>

    Return Value:
        None

    Example:
        [player] call uksf_npc_fnc_pushFillersToClient
*/
if (!isServer) exitWith {};
params ["_client"];
if (isNull _client || {!(_client in ALL_PLAYERS)}) exitWith {};

{
    private _voiceId = _x;
    {
        _x params ["_fillerId", "_npcId", "_wav", "_durationMs"];
        [QGVAR(fillerChunkSink), [_client], ["filler", _npcId, _voiceId, _fillerId, _durationMs], _wav] call FUNC(pushClipChunks);
    } forEach (GVAR(fillerCache) get _voiceId);
} forEach (keys GVAR(fillerCache));
TRACE_1("pushed cached fillers to client",getPlayerUID _client);
