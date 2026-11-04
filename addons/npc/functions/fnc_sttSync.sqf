#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Client. Runs speech-to-text only while the mission has a talkable NPC, so
        player speech is never captured or transcribed in missions without NPCs.

    Parameter(s):
        None

    Return Value:
        None

    Example:
        call uksf_npc_fnc_sttSync
*/
if (!GVAR(sttReady)) exitWith {};

private _wanted = (missionNamespace getVariable [QGVAR(talkerNetIds), []]) isNotEqualTo [];
if (_wanted isEqualTo GVAR(sttActive)) exitWith {};

GVAR(sttActive) = _wanted;
if (_wanted) then {
    INFO("NPC STT: start");
    call FUNC(sttStart);
    call FUNC(sttPushNames);
} else {
    INFO("NPC STT: stop, no talkable NPCs");
    call FUNC(sttStop);
};
