#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Compute the playback volume scalar for an NPC voice, matching ACRE
        direct-speech: (1 - vehicle attenuation) * terrain/building occlusion *
        ACRE global volume, perceptually cubed, times the clip's base gain.
        Fails OPEN: if ACRE is not loaded (functions/globals nil) the NPC stays
        audible at base gain. Only a genuine underwater listener mutes.

    Parameter(s):
        0: NPC object (the speaker) <OBJECT>
        1: Clip base gain 0..1 <NUMBER>

    Return Value:
        Volume scalar 0..1 <NUMBER>

    Example:
        [_npc, 1] call uksf_npc_fnc_acreVol
*/
params ["_npc", ["_baseGain", 1]];

// Local player in the Zeus interface: free-floating camera, no physical ear, so
// no attenuation/occlusion. Use ACRE's own predicate (the same one its direct-speech
// uses) for coherence with ACRE's Zeus listener handling. Full volume, no muffle.
if (!isNil "acre_sys_core_fnc_inZeus" && {call acre_sys_core_fnc_inZeus}) exitWith { _baseGain };

// Fail open: no ACRE attenuate fn or no listener -> base gain, fully audible.
if (isNil "acre_sys_attenuate_fnc_getUnitAttenuate" || {isNil "ACRE_LISTENER_POS"}) exitWith {
    _baseGain
};

private _att = [_npc] call acre_sys_attenuate_fnc_getUnitAttenuate;
if (isNil "_att") then { _att = 0 };

private _occ = 1;
if (!isNil "acre_sys_core_fnc_findOcclusion") then {
    // ACRE emitter = head position (ASL); findOcclusion self-caches ~0.5s per unit.
    private _emitter = AGLToASL (_npc modelToWorldVisual (_npc selectionPosition "head"));
    _occ = [_emitter, ACRE_LISTENER_POS, _npc] call acre_sys_core_fnc_findOcclusion;
    if (isNil "_occ") then { _occ = 1 };
};

private _directVol = (1 - _att) * _occ;
if (!isNil "ACRE_LISTENER_DIVE" && {ACRE_LISTENER_DIVE == 1}) then { _directVol = 0 };

private _globalVolume = missionNamespace getVariable ["acre_sys_core_globalVolume", 1];
_baseGain * ((_directVol * _globalVolume) ^ 3)
