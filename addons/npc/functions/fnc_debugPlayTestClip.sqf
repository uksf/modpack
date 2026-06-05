#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Debug-only. Plays the bundled test clip anchored to the object the
        player is looking at (cursorTarget), or to a given object. Walk around
        it to confirm positional audio. Not shipped behaviour.

    Parameter(s):
        0: Anchor object (Optional, default cursorTarget) <OBJECT>

    Return Value:
        Clip id <STRING>

    Example:
        call uksf_npc_fnc_debugPlayTestClip
*/
params [["_npc", cursorTarget, [objNull]]];

if (isNull _npc) exitWith {
    systemChat "[uksf_npc] No cursorTarget - look at an object and try again.";
    ""
};

private _clipId = format ["debug_%1", diag_tickTime];
[_clipId, _npc, UKSF_NPC_TEST_CLIP_B64] call FUNC(playClip);
