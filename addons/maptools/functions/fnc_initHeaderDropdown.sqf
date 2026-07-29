#include "script_component.hpp"
/*
    Author:
        Beswick.T

    Description:
        Creates a shape mode dropdown on the open map display (12) inside the
        TopRight controls group (idc 2302), positioned to the left of the
        vanilla marker colour combo. Selecting an option updates the active
        shape mode via setMode. Run on visibleMap=true.

    Parameter(s):
        None

    Return Value:
        None

    Example:
        call uksf_maptools_fnc_initHeaderDropdown
*/
private _display = findDisplay 12;
if (isNull _display) exitWith {};

private _topRight = _display displayCtrl 2302;
if (isNull _topRight) exitWith {};

private _dropdown = _display ctrlCreate ["RscCombo", -1, _topRight];
uiNamespace setVariable [QGVAR(headerDropdown), _dropdown];

private _gridW = ((safezoneW / safezoneH) min 1.2) / 40;
private _gridH = ((safezoneW / safezoneH) min 1.2) / 1.2 / 25;
_dropdown ctrlSetPosition [
    6.55 * _gridW,
    0.1 * _gridH,
    4.95 * _gridW,
    1.2 * _gridH
];
_dropdown ctrlSetTooltip "Shape draw mode";
_dropdown ctrlCommit 0;

private _selectedIndex = 0;
{
    private _label = switch (_x) do {
        case "circle": { "Circle" };
        case "ellipse": { "Ellipse" };
        case "racetrack": { "Race-track" };
        case "cone": { "Cone" };
        default { _x };
    };
    private _index = _dropdown lbAdd _label;
    _dropdown lbSetData [_index, _x];
    if (_x isEqualTo GVAR(currentMode)) then { _selectedIndex = _index };
} forEach GVAR(modes);

_dropdown lbSetCurSel _selectedIndex;
_dropdown ctrlAddEventHandler ["LBSelChanged", {
    params ["_ctrl", "_idx"];
    private _mode = _ctrl lbData _idx;
    if (_mode isNotEqualTo GVAR(currentMode)) then {
        [_mode] call FUNC(setMode);
    };
}];
