#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Stop a clip started by uksf_npc_fnc_playClip and deregister it from the
        per-frame tick.

    Parameter(s):
        0: Clip id <STRING>

    Return Value:
        None

    Example:
        ["npc1"] call uksf_npc_fnc_stopClip
*/
params [["_clipId", "", [""]]];

GVAR(active) = GVAR(active) select {(_x select 0) isNotEqualTo _clipId};
"uksf" callExtension ["audioStop", [_clipId]];
