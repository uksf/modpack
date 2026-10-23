#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Starts the white phosphor pilot camera check when the player becomes the
        driver of a vehicle with a pilot camera, and stops it otherwise.

    Parameter(s):
        None

    Return Value:
        Nothing

    Example:
        call uksf_vehicles_fnc_updateWPCamera
*/

if (GVAR(wpCameraPFH) != -1) then {
    [GVAR(wpCameraPFH)] call CBA_fnc_removePerFrameHandler;
    GVAR(wpCameraPFH) = -1;
};
GVAR(wpCameraCC) ppEffectEnable false;

if (call FUNC(isPilotCameraDriver)) then {
    GVAR(wpCameraPFH) = [FUNC(handleWPCamera), 0, [vehicle ACE_player]] call CBA_fnc_addPerFrameHandler;
};
