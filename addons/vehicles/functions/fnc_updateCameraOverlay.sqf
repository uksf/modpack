#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Applies the white phosphor filter while the player looks through vehicle or UAV
        optics in night vision with the ACE white phosphor setting on, and reconciles the
        camera compass: it stops a running compass whose camera changed or is no longer
        eligible, and starts one when the player turned it on for a camera that has one.
        Runs on view, vision mode, vehicle, turret and white phosphor setting changes,
        and when the twice-a-second check sees the camera, view, controlled unit or seat change.

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

private _compassVehicle = [objNull, _vehicle] select (
    !isNull _vehicle
    && {ACE_player getVariable [QGVAR(cameraCompass), false]}
    && {[_vehicle] call FUNC(isCompassCamera)}
);

if (GVAR(compassPFH) != -1 && {GVAR(compassVehicle) != _compassVehicle}) then {
    [GVAR(compassPFH)] call CBA_fnc_removePerFrameHandler;
    GVAR(compassPFH) = -1;
};

if (GVAR(compassPFH) == -1 && {!isNull _compassVehicle}) then {
    GVAR(compassVehicle) = _compassVehicle;
    GVAR(compassPFH) = [FUNC(drawCameraCompass), 0, _compassVehicle] call CBA_fnc_addPerFrameHandler;
};
