#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Sets the FPS debug HUD display mode:
        0 = off, 1 = server + HCs, 2 = + low FPS players, 3 = + all players

    Parameter(s):
        0: Mode <NUMBER>

    Return Value:
        None

    Example:
        [1] call uksf_common_fnc_fpsHudSetMode
*/
params [["_mode", 0, [0]]];

GVAR(fpsHudMode) = _mode;

private _control = uiNamespace getVariable [QGVAR(fpsHudControl), controlNull];

if (_mode == 0) exitWith {
    if (!isNull _control) then {
        ctrlDelete _control;
        uiNamespace setVariable [QGVAR(fpsHudControl), controlNull];
    };
    if (GVAR(fpsHudPFH) != -1) then {
        [GVAR(fpsHudPFH)] call CBA_fnc_removePerFrameHandler;
        GVAR(fpsHudPFH) = -1;
    };
};

if (isNull _control) then {
    private _display = findDisplay 46;
    if (isNull _display) exitWith {};

    _control = _display ctrlCreate ["RscStructuredText", -1];
    _control ctrlSetPosition [safeZoneX + 0.01, safeZoneY + safeZoneH - 0.3, 0.25, 0.28];
    _control ctrlSetBackgroundColor [0, 0, 0, 0.5];
    _control ctrlCommit 0;
    uiNamespace setVariable [QGVAR(fpsHudControl), _control];
};

if (GVAR(fpsHudPFH) == -1) then {
    GVAR(fpsHudPFH) = [{
        [QGVAR(fpsHudRequest), [player]] call CBA_fnc_serverEvent;
    }, 1, []] call CBA_fnc_addPerFrameHandler;
};
