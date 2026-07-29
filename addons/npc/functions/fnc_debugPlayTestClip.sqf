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

// loadFile, not a macro or preprocessFile: base64 contains "/" pairs and the preprocessor eats
// everything from a "//" to the end of the line. trim because a trailing newline in the file is
// an invalid base64 symbol and rejects the whole clip.
private _clipB64 = trim (loadFile QPATHTOF(data\test_clip.b64.txt));
if (_clipB64 isEqualTo "") exitWith {
    systemChat "[uksf_npc] Test clip missing from the build.";
    ""
};

private _clipId = format ["debug_%1", diag_tickTime];
[_clipId, _npc, _clipB64] call FUNC(playClip);
