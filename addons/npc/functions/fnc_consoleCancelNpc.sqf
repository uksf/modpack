#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Cancels queued, filler, clip, and streamed work for one NPC on the server.
*/
if (!isServer) exitWith {};
params ["_npcId"];
[_npcId] call FUNC(cancelNpc);
