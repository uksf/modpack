#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Client. Opens ACRE's mic capture for speech-to-text only while a talkable
        NPC is within hearing radius of the player. Starts the extension pipe client
        the first time the gate opens, so missions without NPCs never start it.

    Parameter(s):
        None

    Return Value:
        None

    Example:
        call uksf_npc_fnc_sttSync
*/
if (!GVAR(sttReady)) exitWith {};

private _player = call CBA_fnc_currentUnit;
private _radius = GVAR(hearingRadius);
private _wanted = alive _player && {
    ((missionNamespace getVariable [QGVAR(talkerNetIds), []]) findIf {
        private _npc = objectFromNetId _x;
        !isNull _npc && {alive _npc} && {_npc getVariable [QGVAR(talkable), false]} && {(_player distance _npc) <= _radius}
    }) > -1
};
if (_wanted isEqualTo GVAR(sttGateOpen)) exitWith {};

GVAR(sttGateOpen) = _wanted;
if (_wanted && {!GVAR(sttStarted)}) then {
    INFO("NPC STT: start");
    GVAR(sttStarted) = true;
    call FUNC(sttStart);
    call FUNC(sttPushNames);
};
TRACE_1("stt mic gate",_wanted);
[_wanted] call acre_sys_core_fnc_setMicCaptureGate;
