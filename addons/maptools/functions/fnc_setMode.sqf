#include "script_component.hpp"
/*
    Author:
        Beswick.T

    Description:
        Sets the active shape-draw mode.

    Parameter(s):
        0: Mode key, one of GVAR(modes) <STRING>

    Return Value:
        None

    Example:
        ["ellipse"] call uksf_maptools_fnc_setMode
*/
params [["_mode", "circle", [""]]];

if (!(_mode in GVAR(modes))) exitWith {};
if (_mode isEqualTo GVAR(currentMode)) exitWith {};

GVAR(currentMode) = _mode;
GVAR(currentModeLabel) = switch (_mode) do {
    case "circle": { "Circle" };
    case "ellipse": { "Ellipse" };
    case "racetrack": { "Race-track" };
    case "cone": { "Cone" };
    default { _mode };
};

private _dropdown = uiNamespace getVariable [QGVAR(headerDropdown), controlNull];
if (!isNull _dropdown) then {
    private _index = GVAR(modes) find _mode;
    if (_index >= 0) then {
        _dropdown lbSetCurSel _index;
    };
};
