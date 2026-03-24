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

GVAR(capReconBaseTime) = parseNumber (_logic getVariable [QGVAR(capReconBaseTime), "1200"]);
GVAR(capReconOffsetTime) = parseNumber (_logic getVariable [QGVAR(capReconOffsetTime), "600"]);
GVAR(initialDelay) = parseNumber (_logic getVariable [QGVAR(initialDelay), "1800"]);
GVAR(initialDelayOffset) = parseNumber (_logic getVariable [QGVAR(initialDelayOffset), "900"]);
GVAR(interceptCooldown) = parseNumber (_logic getVariable [QGVAR(interceptCooldown), "600"]);
GVAR(interceptCooldownOffset) = parseNumber (_logic getVariable [QGVAR(interceptCooldownOffset), "600"]);
GVAR(maxConcurrentMissions) = parseNumber (_logic getVariable [QGVAR(maxConcurrentMissions), "3"]);
GVAR(fighterClassnames) = _logic getVariable [QGVAR(fighterClassnames), []];
GVAR(casClassnames) = _logic getVariable [QGVAR(casClassnames), []];
GVAR(strikeClassnames) = _logic getVariable [QGVAR(strikeClassnames), []];
GVAR(reconClassnames) = _logic getVariable [QGVAR(reconClassnames), []];
GVAR(excludedClasses) = _logic getVariable [QGVAR(excludedClasses), []];
GVAR(exclusionMarkers) = _logic getVariable [QGVAR(exclusionMarkers), []];
GVAR(capTimeout) = parseNumber (_logic getVariable [QGVAR(capTimeout), "900"]);
GVAR(reconTimeout) = parseNumber (_logic getVariable [QGVAR(reconTimeout), "600"]);
GVAR(casTimeout) = parseNumber (_logic getVariable [QGVAR(casTimeout), "600"]);
GVAR(strikeTimeout) = parseNumber (_logic getVariable [QGVAR(strikeTimeout), "600"]);
GVAR(interceptTimeout) = parseNumber (_logic getVariable [QGVAR(interceptTimeout), "600"]);

GVAR(controllerInitialised) = true;

INFO("Air threat controller initialised");
