#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Creates the white phosphor filter for vehicle optics and the camera compass,
        adds their self-interaction toggles and watches the view, the white phosphor setting, and twice a second
        the camera object, view, controlled unit and seat, so both follow whichever vehicle or UAV camera
        the player looks through, including a switch from one UAV to another.
        The white phosphor toggle sets the ACE night vision "always use white phosphor"
        client setting, so one choice covers goggles and vehicle optics.

    Parameter(s):
        None

    Return Value:
        Nothing

    Example:
        call uksf_vehicles_fnc_initCameraOverlay
*/

GVAR(wpCameraCC) = ppEffectCreate ["ColorCorrections", 2010];
GVAR(wpCameraCC) ppEffectAdjust [1, 1, 0.0, [0, 0, 0, 0], [1.1, 0.8, 1.9, 0.9], [1, 1, 6, 0]];
GVAR(wpCameraCC) ppEffectCommit 0;
GVAR(wpCameraCC) ppEffectForceInNVG true;
GVAR(wpCameraCC) ppEffectEnable false;
GVAR(compassPFH) = -1;
GVAR(compassVehicle) = objNull;

private _wpAction = [
    QGVAR(wpCameraToggle),
    "White Phosphor NV",
    "",
    {
        ["ace_nightvision_alwaysUseWP", !ace_nightvision_alwaysUseWP, 0, "client", true] call CBA_settings_fnc_set;
        call FUNC(updateCameraOverlay);
    },
    {cameraOn != ACE_player && {[cameraOn] call FUNC(hasNightVisionCamera)}}
] call ace_interact_menu_fnc_createAction;

private _compassAction = [
    QGVAR(cameraCompassToggle),
    "Camera Compass",
    "",
    {
        ACE_player setVariable [QGVAR(cameraCompass), !(ACE_player getVariable [QGVAR(cameraCompass), false])];
        call FUNC(updateCameraOverlay);
    },
    {cameraOn != ACE_player && {[cameraOn] call FUNC(isCompassCamera)}}
] call ace_interact_menu_fnc_createAction;

{
    [_x, 1, ["ACE_SelfActions"], _wpAction, true] call ace_interact_menu_fnc_addActionToClass;
} forEach ["Air", "LandVehicle", "Ship"];
["Air", 1, ["ACE_SelfActions"], _compassAction, true] call ace_interact_menu_fnc_addActionToClass;

{
    [_x, FUNC(updateCameraOverlay)] call CBA_fnc_addPlayerEventHandler;
} forEach ["cameraView", "visionMode", "vehicle", "turret"];

["CBA_SettingChanged", {
    params ["_name"];
    if (_name == "ace_nightvision_alwaysUseWP") then {call FUNC(updateCameraOverlay)};
}] call CBA_fnc_addEventHandler;

GVAR(cameraOverlayContext) = [];
[{
    private _context = [cameraOn, cameraView, focusOn, (vehicle focusOn) unitTurret focusOn];
    if (_context isNotEqualTo GVAR(cameraOverlayContext)) then {
        GVAR(cameraOverlayContext) = _context;
        call FUNC(updateCameraOverlay);
    };
}, 0.5] call CBA_fnc_addPerFrameHandler;
