#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Creates native inspector children from a cached element spec.
*/
params ["_display", "_group", "_spec"];

private _serial = str _spec;
if ((_group getVariable [QGVAR(lastSpec), ""]) isEqualTo _serial) exitWith {};

{ctrlDelete _x} forEach (_group getVariable [QGVAR(dynControls), []]);

private _controls = [];
private _y = 0;
private _safeH = safeZoneH;
private _safeW = safeZoneW;
private _groupW = (ctrlPosition _group) select 2;
private _rowH = 0.018 * _safeH;
private _gap = 0.004 * _safeH;
private _ledTex = "#(argb,8,8,3)color(1,1,1,1)";

private _fnc_make = {
    params ["_class", "_x", "_y", "_w", "_h"];
    private _ctrl = _display ctrlCreate [_class, -1, _group];
    _ctrl ctrlSetPosition [_x, _y, _w, _h];
    _ctrl ctrlCommit 0;
    _controls pushBack _ctrl;
    _ctrl
};

{
    _x params ["_kind", "_payload"];
    switch (_kind) do {
        case "heading": {
            private _ctrl = ["RscText", 0, _y, _groupW, _rowH] call _fnc_make;
            _ctrl ctrlSetText toUpper _payload;
            _ctrl ctrlSetTextColor [0.39, 0.45, 0.55, 1];
            _ctrl ctrlSetFontHeight (0.012 * _safeH);
            _y = _y + _rowH + _gap;
        };
        case "divider": {
            private _dividerH = 0.001 * _safeH;
            private _ctrl = ["RscText", 0, _y, _groupW, _dividerH] call _fnc_make;
            _ctrl ctrlSetBackgroundColor [0.8, 0.84, 0.88, 0.28];
            _y = _y + _dividerH + _gap;
        };
        case "row": {
            _payload params ["_label", "_value"];
            private _labelW = 0.42 * _groupW;
            private _valueW = _groupW - _labelW;
            private _labelCtrl = ["RscText", 0, _y, _labelW, _rowH] call _fnc_make;
            _labelCtrl ctrlSetText _label;
            _labelCtrl ctrlSetTextColor [0.58, 0.64, 0.72, 1];
            _labelCtrl ctrlSetFontHeight (0.014 * _safeH);
            private _valueCtrl = ["RscStructuredText", _labelW, _y, _valueW, _rowH] call _fnc_make;
            _valueCtrl ctrlSetStructuredText parseText format ["<t color='#ffffff' size='0.85'>%1</t>", _value];
            private _valueH = (ctrlTextHeight _valueCtrl) max _rowH;
            _valueCtrl ctrlSetPosition [_labelW, _y, _valueW, _valueH];
            _valueCtrl ctrlCommit 0;
            _y = _y + ((_rowH max _valueH)) + _gap;
        };
        case "leds": {
            private _xPos = 0;
            {
                _x params ["_label", "_lit"];
                private _dot = ["RscPicture", _xPos, _y + 0.004 * _safeH, 0.008 * _safeW, 0.008 * _safeH] call _fnc_make;
                _dot ctrlSetText _ledTex;
                private _text = ["RscText", _xPos + 0.01 * _safeW, _y, 0.07 * _safeW, _rowH] call _fnc_make;
                _text ctrlSetText toUpper _label;
                _text ctrlSetFontHeight (0.011 * _safeH);
                if (_lit) then {
                    _dot ctrlSetTextColor [0.29, 0.87, 0.5, 1];
                    _text ctrlSetTextColor [0.82, 0.98, 0.9, 1];
                } else {
                    _dot ctrlSetTextColor [0.2, 0.25, 0.33, 1];
                    _text ctrlSetTextColor [0.58, 0.64, 0.72, 1];
                };
                _xPos = _xPos + 0.082 * _safeW;
            } forEach _payload;
            _y = _y + _rowH + _gap;
        };
        case "strip": {
            _payload params ["_items", "_active"];
            private _count = count _items;
            private _cellW = (_groupW - ((_count - 1) * 0.002 * _safeW)) / _count;
            {
                private _xPos = _forEachIndex * (_cellW + 0.002 * _safeW);
                private _cell = ["RscText", _xPos, _y, _cellW, _rowH] call _fnc_make;
                _cell ctrlSetText toUpper _x;
                _cell ctrlSetFontHeight (0.011 * _safeH);
                if (_x isEqualTo _active) then {
                    _cell ctrlSetTextColor [1, 0.83, 0.42, 1];
                    _cell ctrlSetBackgroundColor [0.2, 0.16, 0.08, 1];
                } else {
                    _cell ctrlSetTextColor [0.39, 0.45, 0.55, 1];
                    _cell ctrlSetBackgroundColor [0.08, 0.1, 0.12, 1];
                };
            } forEach _items;
            _y = _y + _rowH + _gap;
        };
        case "chip": {
            private _xPos = 0;
            {
                private _w = ((count _x) max 4) * 0.006 * _safeW;
                if (_xPos + _w > _groupW) then {
                    _xPos = 0;
                    _y = _y + _rowH + _gap;
                };
                private _chip = ["RscText", _xPos, _y, _w, _rowH] call _fnc_make;
                _chip ctrlSetText _x;
                _chip ctrlSetFontHeight (0.012 * _safeH);
                _chip ctrlSetTextColor [0.8, 0.84, 0.88, 1];
                _chip ctrlSetBackgroundColor [0.12, 0.15, 0.18, 1];
                _xPos = _xPos + _w + 0.004 * _safeW;
            } forEach _payload;
            _y = _y + _rowH + _gap;
        };
        case "transcript": {
            _payload params ["_time", "_who", "_text", "_odd"];
            private _pad = 0.004 * _safeW;
            private _bodyW = _groupW - (2 * _pad);
            private _row = ["RscText", 0, _y, _groupW, _rowH] call _fnc_make;
            if (_odd) then {
                _row ctrlSetBackgroundColor [1, 1, 1, 0.03];
            } else {
                _row ctrlSetBackgroundColor [0, 0, 0, 0.18];
            };
            private _meta = ["RscStructuredText", _pad, _y, _bodyW, _rowH] call _fnc_make;
            private _whoColour = switch (toUpper _who) do {
                case "PLAYER": {"#93c5fd"};
                case "SYSTEM": {"#86efac"};
                default {"#ffd36a"};
            };
            _meta ctrlSetStructuredText parseText format [
                "<t color='#64748b' size='0.75'>%1</t> <t color='%2' size='0.75'>%3</t>",
                _time, _whoColour, _who
            ];
            private _body = ["RscStructuredText", _pad, _y + _rowH, _bodyW, _rowH] call _fnc_make;
            _body ctrlSetStructuredText parseText format ["<t color='#e2e8f0' size='0.8'>%1</t>", _text];
            private _bodyH = (ctrlTextHeight _body) max _rowH;
            _body ctrlSetPosition [_pad, _y + _rowH, _bodyW, _bodyH];
            _body ctrlCommit 0;
            _row ctrlSetPosition [0, _y, _groupW, _rowH + _bodyH];
            _row ctrlCommit 0;
            _y = _y + _rowH + _bodyH + _gap;
        };
    };
} forEach _spec;

_group setVariable [QGVAR(dynControls), _controls];
_group setVariable [QGVAR(lastSpec), _serial];
