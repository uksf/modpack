#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Applies the white phosphor filter while the player looks through vehicle or UAV
        optics in night vision with the ACE white phosphor setting on, and starts the
        camera compass when the player turned it on for a camera that has one.
        Runs on view, vision mode, vehicle and turret changes.

    Parameter(s):
        None

    Return Value:
        Nothing

    Example:
        call uksf_vehicles_fnc_updateCameraOverlay
*/

private _vehicle = call FUNC(cameraOverlayVehicle);
private _nightVision = !isNull _vehicle && {
    currentVisionMode focusOn == 1 || {driver _vehicle == ACE_player && {currentVisionMode _vehicle == 1}}
};
GVAR(wpCameraCC) ppEffectEnable (_nightVision && {ace_nightvision_alwaysUseWP});

if (
    GVAR(compassPFH) == -1
    && {!isNull _vehicle}
    && {ACE_player getVariable [QGVAR(cameraCompass), false]}
    && {[_vehicle] call FUNC(isCompassCamera)}
) then {
    GVAR(compassPFH) = [FUNC(drawCameraCompass), 0, _vehicle] call CBA_fnc_addPerFrameHandler;
};
