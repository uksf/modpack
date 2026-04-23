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
    WARNING("Multiple air threat controller modules placed — only the first is used");
    if (is3DEN) then {
        ["Multiple (AT) Controller modules placed — only the first is used"] call BIS_fnc_3DENNotification;
    };
};

GVAR(capReconMinTime) = _logic getVariable [QGVAR(capReconMinTime), 1200];
GVAR(capReconMaxTime) = _logic getVariable [QGVAR(capReconMaxTime), 1800];
GVAR(initialDelayMin) = _logic getVariable [QGVAR(initialDelayMin), 1800];
GVAR(initialDelayMax) = _logic getVariable [QGVAR(initialDelayMax), 2700];
GVAR(interceptCooldownMin) = _logic getVariable [QGVAR(interceptCooldownMin), 600];
GVAR(interceptCooldownMax) = _logic getVariable [QGVAR(interceptCooldownMax), 1200];
GVAR(casStrikeCooldownMin) = _logic getVariable [QGVAR(casStrikeCooldownMin), 300];
GVAR(casStrikeCooldownMax) = _logic getVariable [QGVAR(casStrikeCooldownMax), 600];
GVAR(maxConcurrentMissions) = _logic getVariable [QGVAR(maxConcurrentMissions), 3];

// Clamp max < min to min (mission maker error)
{
    _x params ["_minVar", "_maxVar"];
    private _minValue = missionNamespace getVariable _minVar;
    private _maxValue = missionNamespace getVariable _maxVar;
    if (_maxValue < _minValue) then {
        WARNING_3("%1 (%2) < %3 — clamping max to min",_maxVar,_maxValue,_minVar);
        missionNamespace setVariable [_maxVar, _minValue];
    };
} forEach [
    [QGVAR(capReconMinTime), QGVAR(capReconMaxTime)],
    [QGVAR(initialDelayMin), QGVAR(initialDelayMax)],
    [QGVAR(interceptCooldownMin), QGVAR(interceptCooldownMax)],
    [QGVAR(casStrikeCooldownMin), QGVAR(casStrikeCooldownMax)]
];

// Classname arrays — stored as strings in Eden, parse here
{
    private _raw = _logic getVariable [_x, "[]"];
    private _parsed = if (_raw isEqualType "") then {
        call compile _raw
    } else {
        _raw
    };
    if (!(_parsed isEqualType [])) then {
        WARNING_1("Invalid classname array for %1 — expected array, using empty",_x);
        _parsed = [];
    };
    missionNamespace setVariable [_x, _parsed];
    TRACE_2("Parsed classname array",_x,_parsed);
} forEach [
    QGVAR(fighterClassnames),
    QGVAR(helicopterClassnames),
    QGVAR(jetClassnames),
    QGVAR(reconClassnames),
    QGVAR(excludedClasses)
];

GVAR(capTimeout) = _logic getVariable [QGVAR(capTimeout), 900];
GVAR(reconTimeout) = _logic getVariable [QGVAR(reconTimeout), 600];
GVAR(casTimeout) = _logic getVariable [QGVAR(casTimeout), 600];
GVAR(strikeTimeout) = _logic getVariable [QGVAR(strikeTimeout), 600];
GVAR(interceptTimeout) = _logic getVariable [QGVAR(interceptTimeout), 600];

GVAR(controllerInitialised) = true;
publicVariable QGVAR(controllerInitialised);

DEBUG("Air threat controller initialised");
