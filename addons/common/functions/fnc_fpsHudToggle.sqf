#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Toggles the FPS debug HUD through display modes:
        0 = off, 1 = server + HCs, 2 = server + HCs + low FPS players, 3 = server + HCs + all players

    Parameter(s):
        None

    Return Value:
        None

    Example:
        call uksf_common_fnc_fpsHudToggle
*/

GVAR(fpsHudMode) = (GVAR(fpsHudMode) + 1) mod 4;

private _control = uiNamespace getVariable [QGVAR(fpsHudControl), controlNull];

if (GVAR(fpsHudMode) isEqualTo 0) exitWith {
    if (!isNull _control) then {
        ctrlDelete _control;
        uiNamespace setVariable [QGVAR(fpsHudControl), controlNull];
    };
    if (GVAR(fpsHudPFH) != -1) then {
        [GVAR(fpsHudPFH)] call CBA_fnc_removePerFrameHandler;
        GVAR(fpsHudPFH) = -1;
    };
};

// Create HUD control if not already created
if (isNull _control) then {
    private _display = findDisplay 46;
    _control = _display ctrlCreate ["RscStructuredText", -1];
    _control ctrlSetPosition [safeZoneX + 0.01, safeZoneY + safeZoneH - 0.3, 0.25, 0.28];
    _control ctrlSetBackgroundColor [0, 0, 0, 0.5];
    _control ctrlCommit 0;
    uiNamespace setVariable [QGVAR(fpsHudControl), _control];
};

// Start update PFH if not already running
if (GVAR(fpsHudPFH) isEqualTo -1) then {
    GVAR(fpsHudPFH) = [{
        [QGVAR(fpsHudRequest), [player]] call CBA_fnc_serverEvent;
    }, 1, []] call CBA_fnc_addPerFrameHandler;
};
