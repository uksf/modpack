#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Copies validated guarded feedback into the local inspector state.
*/
params ["_npcId", "_cooperation", "_pendingWarning", "_burned", "_disclosed", "_eligible", "_mood", "_emote", "_reason", "_evidence", "_classifyMs", "_replyMs"];

private _state = [_npcId] call FUNC(consoleGetState);
_state set ["cooperation", _cooperation];
_state set ["pendingWarning", _pendingWarning];
_state set ["burned", _burned];
_state set ["disclosed", _disclosed];
_state set ["eligible", _eligible];
_state set ["mood", _mood];
_state set ["emote", _emote];
_state set ["reason", _reason];
_state set ["evidence", _evidence];
_state set ["classifyMs", _classifyMs];
_state set ["replyMs", _replyMs];
