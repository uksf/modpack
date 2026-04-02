#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Registers sector control debug provider with Zeus

    Parameter(s):
        None

    Return Value:
        None

    Example:
        call uksf_sectorcontrol_fnc_registerDebugProvider
*/

private _key = QGVAR(debug);
private _menuName = "Sector Control";
private _menuPriority = -30;
private _fnc_menuCondition = {GVAR(enabled)};

private _fnc_serverGetter = {
    private _sectors = GVAR(sectors) select {!isNull _x};

    private _sectorData = _sectors apply {
        private _position = getPosATL _x;
        private _area = _x getVariable ["objectArea", [0, 0, 0, false]];
        private _owner = _x getVariable [QGVAR(currentOwner), 2];
        private _opforScore = _x getVariable [QGVAR(currentOpforScore), 0];
        private _bluforScore = _x getVariable [QGVAR(currentbluforScore), 0];
        private _timeToCapture = _x getVariable [QGVAR(timeToCapture), 60];
        private _contested = _x getVariable [QGVAR(sectorContested), false];
        private _locked = _x getVariable [QGVAR(sectorLocked), false];
        private _name = _x getVariable [QGVAR(displayName), "Sector"];

        [_position, _area, _owner, _opforScore, _bluforScore, _timeToCapture, _contested, _locked, _name]
    };

    [_sectorData]
};

private _fnc_draw3d = {
    params ["_data", "_cameraPosition", "_maxDistance"];
    private _sectors = _data#0;

    {
        _x params ["_position", "_area", "_owner", "_opforScore", "_bluforScore", "_timeToCapture", "_contested", "_locked", "_name"];
        if (_cameraPosition distance2D _position < _maxDistance) then {
            private _colour = switch (_owner) do {
                case 0: { [1,0,0,1] };
                case 1: { [0,0.3,1,1] };
                default { [0.6,0.6,0.6,1] };
            };

            private _opforPercentage = if (_timeToCapture > 0) then {round ((_opforScore / _timeToCapture) * 100)} else {0};
            private _bluforPercentage = if (_timeToCapture > 0) then {round ((_bluforScore / _timeToCapture) * 100)} else {0};

            drawIcon3D ["", _colour, ASLToAGL (ATLToASL _position), 0, 0, 0, _name, 1, 0.025, "TahomaB", "center"];
            drawIcon3D ["", [0,0.3,1,1], ASLToAGL (ATLToASL _position), 0, 0, 0, format ["BLU: %1%2", _bluforPercentage, "%"], 1, 0.02, "TahomaB", "center", false, 0, DEBUG_ICON_SPACING];
            drawIcon3D ["", [1,0,0,1], ASLToAGL (ATLToASL _position), 0, 0, 0, format ["OPF: %1%2", _opforPercentage, "%"], 1, 0.02, "TahomaB", "center", false, 0, DEBUG_ICON_SPACING * 2];
            private _statusOffset = DEBUG_ICON_SPACING * 3;
            if (_contested) then {
                drawIcon3D ["", [1,1,0,1], ASLToAGL (ATLToASL _position), 0, 0, 0, "CONTESTED", 1, 0.02, "TahomaB", "center", false, 0, _statusOffset];
                _statusOffset = _statusOffset + DEBUG_ICON_SPACING;
            };
            if (_locked) then {
                drawIcon3D ["", [0.5,0.5,0.5,1], ASLToAGL (ATLToASL _position), 0, 0, 0, "LOCKED", 1, 0.02, "TahomaB", "center", false, 0, _statusOffset];
            };
        };
    } forEach _sectors;
};

private _fnc_drawMap = {
    params ["_data", "_map"];
    private _sectors = _data#0;

    {
        _x params ["_position", "_area", "_owner", "_opforScore", "_bluforScore", "_timeToCapture", "_contested", "_locked", "_name"];
        _area params ["_halfWidth", "_halfHeight", "_angle", "_isRectangle"];

        private _colour = switch (_owner) do {
            case 0: { [1,0,0,1] };
            case 1: { [0,0.3,1,1] };
            default { [0.6,0.6,0.6,1] };
        };

        private _opforPercentage = if (_timeToCapture > 0) then {round ((_opforScore / _timeToCapture) * 100)} else {0};
        private _bluforPercentage = if (_timeToCapture > 0) then {round ((_bluforScore / _timeToCapture) * 100)} else {0};

        private _status = format ["BLU:%1%2 OPF:%3%2", _bluforPercentage, "%", _opforPercentage];
        if (_contested) then { _status = _status + " [CONTESTED]" };
        if (_locked) then { _status = _status + " [LOCKED]" };

        private _offsetPosition = _position vectorAdd [0, -100, 0];
        _map drawIcon ["#(argb,8,8,3)color(0,0,0,0)", _colour, _offsetPosition, 0, 0, 0, _status, 1, 0.04, "TahomaB", "right"];
        private _outlineColour = _colour select [0, 3];
        _outlineColour pushBack 0.5;
        if (_isRectangle) then {
            _map drawRectangle [_position, _halfWidth, _halfHeight, _angle, _outlineColour, "#(argb,8,8,3)color(1,1,1,0.1)"];
        } else {
            _map drawEllipse [_position, _halfWidth, _halfHeight, _angle, _outlineColour, "#(argb,8,8,3)color(1,1,1,0.1)"];
        };
    } forEach _sectors;
};

[QEGVAR(zeus,registerDebugProvider), [_key, createHashMapFromArray [
    ["draw3d", _fnc_draw3d],
    ["drawMap", _fnc_drawMap],
    ["serverGetter", _fnc_serverGetter],
    ["menuName", _menuName],
    ["menuPriority", _menuPriority],
    ["menuCondition", _fnc_menuCondition]
]]] call CBA_fnc_localEvent;
