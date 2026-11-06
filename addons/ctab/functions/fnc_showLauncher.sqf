#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Shows the app launcher in the cTab Android dialog: one button per registered app, in a grid.

    Parameter(s):
        0: cTab display <DISPLAY>
        1: UKSF container group <CONTROL>

    Return Value:
        Nothing

    Example:
        [_display, _container] call uksf_ctab_fnc_showLauncher
*/
params ["_display", "_container"];

private _group = [_display, _container, {}, 1] call FUNC(createContent);
(ctrlPosition _container) params ["", "", "_width", "_height"];

private _margin = _width * 0.03;
private _cellWidth = (_width - _margin * (LAUNCHER_COLUMNS + 1)) / LAUNCHER_COLUMNS;
private _cellHeight = (_height - _margin * (LAUNCHER_ROWS + 1)) / LAUNCHER_ROWS;

if (GVAR(apps) isEqualTo []) exitWith {
    private _text = _display ctrlCreate ["cTab_RscText", -1, _group];
    _text ctrlSetPosition [_margin, _margin, _width - _margin * 2, _cellHeight];
    _text ctrlSetFontHeight (_cellHeight * 0.4);
    _text ctrlSetText "No apps installed";
    _text ctrlCommit 0;
};

{
    _x params ["_id", "_title"];

    private _button = _display ctrlCreate ["cTab_RscButton", -1, _group];
    _button ctrlSetPosition [
        _margin + (_forEachIndex mod LAUNCHER_COLUMNS) * (_cellWidth + _margin),
        _margin + floor (_forEachIndex / LAUNCHER_COLUMNS) * (_cellHeight + _margin),
        _cellWidth,
        _cellHeight
    ];
    _button ctrlSetFontHeight (_cellHeight * 0.3);
    _button ctrlSetText _title;
    _button setVariable [QGVAR(mode), MODE_APP_PREFIX + _id];
    _button ctrlAddEventHandler ["ButtonClick", {
        params ["_button"];

        [FUNC(setMode), [_button getVariable QGVAR(mode)]] call CBA_fnc_execNextFrame;
    }];
    _button ctrlCommit 0;
} forEach GVAR(apps);
