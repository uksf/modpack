#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Creates the white phosphor filter for aircraft pilot cameras, adds the
        self-interaction toggle and watches seat changes so the filter runs for
        the driver of any vehicle with a pilot camera.

    Parameter(s):
        None

    Return Value:
        Nothing

    Example:
        call uksf_vehicles_fnc_initWPCamera
*/

GVAR(wpCameraCC) = ppEffectCreate ["ColorCorrections", 2010];
GVAR(wpCameraCC) ppEffectAdjust [1, 1, 0.0, [0, 0, 0, 0], [1.1, 0.8, 1.9, 0.9], [1, 1, 6, 0]];
GVAR(wpCameraCC) ppEffectCommit 0;
GVAR(wpCameraCC) ppEffectForceInNVG true;
GVAR(wpCameraCC) ppEffectEnable false;
GVAR(wpCameraPFH) = -1;

private _action = [
    QGVAR(wpCameraToggle),
    "WP Camera Filter",
    "",
    {
        ACE_player setVariable [QGVAR(wpCamera), !(ACE_player getVariable [QGVAR(wpCamera), ace_nightvision_alwaysUseWP])];
    },
    {call FUNC(isPilotCameraDriver)}
] call ace_interact_menu_fnc_createAction;
["Air", 1, ["ACE_SelfActions"], _action, true] call ace_interact_menu_fnc_addActionToClass;

["vehicle", FUNC(updateWPCamera), true] call CBA_fnc_addPlayerEventHandler;
["turret", FUNC(updateWPCamera)] call CBA_fnc_addPlayerEventHandler;
