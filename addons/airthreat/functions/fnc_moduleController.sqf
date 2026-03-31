#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Initialises the air threat controller from 3DEN module attributes.
        Reads configuration values and stores them in global variables.
        Server only.

    Parameters:
        0: Arguments <ARRAY>
        1: Module logic <OBJECT>

    Return Value:
        Nothing

    Example:
        [_this, _logic] call uksf_airthreat_fnc_moduleController
*/

(_this select 1) params ["_logic"];

if !(local _logic) exitWith {};
if !(isServer) exitWith {};

if (GVAR(controllerInitialised)) exitWith {
    WARNING("Multiple air threat controller modules placed - only the first is used");
};

GVAR(capReconBaseTime) = _logic getVariable [QGVAR(capReconBaseTime), 1200];
GVAR(capReconOffsetTime) = _logic getVariable [QGVAR(capReconOffsetTime), 600];
GVAR(initialDelay) = _logic getVariable [QGVAR(initialDelay), 1800];
GVAR(initialDelayOffset) = _logic getVariable [QGVAR(initialDelayOffset), 900];
GVAR(interceptCooldown) = _logic getVariable [QGVAR(interceptCooldown), 600];
GVAR(interceptCooldownOffset) = _logic getVariable [QGVAR(interceptCooldownOffset), 600];
GVAR(maxConcurrentMissions) = _logic getVariable [QGVAR(maxConcurrentMissions), 3];
// Classname arrays — validate type since these come from Eden string fields
{
    _x params ["_varName", "_gvar"];
    private _value = _logic getVariable [_varName, []];
    if (_value isEqualType []) then {
        missionNamespace setVariable [_gvar, _value];
    } else {
        WARNING_1("Invalid classname array for %1 — expected array, using empty",_varName);
        missionNamespace setVariable [_gvar, []];
    };
} forEach [
    [QGVAR(fighterClassnames), QGVAR(fighterClassnames)],
    [QGVAR(casClassnames), QGVAR(casClassnames)],
    [QGVAR(strikeClassnames), QGVAR(strikeClassnames)],
    [QGVAR(reconClassnames), QGVAR(reconClassnames)],
    [QGVAR(excludedClasses), QGVAR(excludedClasses)],
    [QGVAR(exclusionMarkers), QGVAR(exclusionMarkers)]
];
GVAR(capTimeout) = _logic getVariable [QGVAR(capTimeout), 900];
GVAR(reconTimeout) = _logic getVariable [QGVAR(reconTimeout), 600];
GVAR(casTimeout) = _logic getVariable [QGVAR(casTimeout), 600];
GVAR(strikeTimeout) = _logic getVariable [QGVAR(strikeTimeout), 600];
GVAR(interceptTimeout) = _logic getVariable [QGVAR(interceptTimeout), 600];

GVAR(controllerInitialised) = true;

INFO("Air threat controller initialised");
