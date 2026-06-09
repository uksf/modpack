#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Compute the playback volume scalar for an NPC voice, mirroring ACRE
        direct-speech: (1 - vehicle attenuation) * terrain/building occlusion *
        ACRE global volume, perceptually cubed, times the clip's base gain.
        Occlusion/attenuation are measured to the Zeus-aware listener (the curator
        camera in Zeus). Returns 0 (mute) when the listener is underwater or deaf,
        or the NPC is underwater. Fails OPEN: if ACRE is not loaded the NPC stays
        audible at base gain.

    Parameter(s):
        0: NPC object (the speaker) <OBJECT>
        1: Clip base gain 0..1 <NUMBER>

    Return Value:
        Volume scalar 0..1 <NUMBER>

    Example:
        [_npc, 1] call uksf_npc_fnc_acreVol
*/
params ["_npc", ["_baseGain", 1]];

// Underwater / deaf listener: no listening. Cheapest checks first — short-circuit
// before any ACRE attenuation or the findOcclusion raycast.
if (!isNil "ACRE_LISTENER_DIVE" && {ACRE_LISTENER_DIVE == 1}) exitWith { 0 };
if (missionNamespace getVariable ["acre_sys_core_isDeaf", false]) exitWith { 0 };

// NPC underwater: no talking. (ACRE emitter = head position, ASL.)
private _emitter = AGLToASL (_npc modelToWorldVisual (_npc selectionPosition "head"));
if ((_emitter # 2) < -0.2) exitWith { 0 };

// Fail open: ACRE not loaded -> base gain, fully audible.
if (isNil "acre_sys_attenuate_fnc_getUnitAttenuate") exitWith { _baseGain };

private _att = [_npc] call acre_sys_attenuate_fnc_getUnitAttenuate;
if (isNil "_att") then { _att = 0 };

private _occ = 1;
if (!isNil "acre_sys_core_fnc_findOcclusion") then {
    // findOcclusion self-caches ~0.5s per unit. Listener = Zeus-aware ear (camera in Zeus).
    private _listenerPos = (call FUNC(listenerPose)) # 0;
    _occ = [_emitter, _listenerPos, _npc] call acre_sys_core_fnc_findOcclusion;
    if (isNil "_occ") then { _occ = 1 };
};

private _directVol = (1 - _att) * _occ;
private _globalVolume = missionNamespace getVariable ["acre_sys_core_globalVolume", 1];
_baseGain * ((_directVol * _globalVolume) ^ 3)
