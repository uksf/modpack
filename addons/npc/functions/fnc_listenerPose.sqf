#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Zeus-aware local listener pose for NPC voice spatialisation. Mirrors ACRE:
        when the local player is in the Zeus interface and ACRE is set to
        communicate via the curator camera, the camera is the ear; otherwise the
        controlled unit's eye. Returns [position (ASL), forward, up].

    Parameter(s):
        None

    Return Value:
        [position, forward, up] <ARRAY>

    Example:
        (call uksf_npc_fnc_listenerPose) params ["_position", "_forward", "_up"]
*/
private _camera = curatorCamera;
if (
    !isNull _camera
    && {missionNamespace getVariable ["acre_sys_zeus_zeusCommunicateViaCamera", false]}
    && {!isNil "acre_sys_core_fnc_inZeus"}
    && {call acre_sys_core_fnc_inZeus}
) exitWith {
    [getPosASL _camera, getCameraViewDirection _camera, vectorUp _camera]
};

private _player = call CBA_fnc_currentUnit;
[eyePos _player, eyeDirection _player, vectorUp _player]
