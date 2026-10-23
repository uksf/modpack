#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Per-frame handler. Shows the white phosphor filter while the driver looks
        through the pilot camera in night vision with the filter turned on.

    Parameter(s):
        0: Arguments <ARRAY>
            0: Vehicle <OBJECT>
        1: Per-frame handler ID <NUMBER>

    Return Value:
        Nothing

    Example:
        [[_vehicle], _idPFH] call uksf_vehicles_fnc_handleWPCamera
*/
params ["_args", "_idPFH"];
_args params ["_vehicle"];

if (!alive _vehicle || {driver _vehicle != ACE_player}) exitWith {
    GVAR(wpCameraCC) ppEffectEnable false;
    [_idPFH] call CBA_fnc_removePerFrameHandler;
    GVAR(wpCameraPFH) = -1;
};

private _enabled = ACE_player getVariable [QGVAR(wpCamera), ace_nightvision_alwaysUseWP];
GVAR(wpCameraCC) ppEffectEnable (_enabled && {cameraView == "GUNNER"} && {currentVisionMode _vehicle == 1});
