#include "script_component.hpp"
/*
    Author:
        Beswick.T

    Description:
        Creates the cursor-following hint controls on the open map display
        (12) and starts a per-frame handler that follows the mouse, refreshes
        hint text from the current state, and self-destructs when state
        returns to idle and the draw key is released, or the map closes.
        Idempotent; calling while visible is a no-op.

    Parameter(s):
        None

    Return Value:
        None

    Example:
        call uksf_maptools_fnc_renderHint
*/
if (GVAR(hintVisible)) exitWith {};

private _display = findDisplay 12;
if (isNull _display) exitWith {};

private _layout = [
    [QGVAR(HintPanel), ""],
    [QGVAR(HintText), ""],
    [QGVAR(HintText), ""],
    [QGVAR(HintIcon), "\z\ace\addons\interaction\UI\mouse_left_ca.paa"],
    [QGVAR(HintText), ""],
    [QGVAR(HintIcon), "\z\ace\addons\interaction\UI\mouse_right_ca.paa"],
    [QGVAR(HintText), ""],
    [QGVAR(HintText), ""],
    [QGVAR(HintText), ""]
];

private _ctrls = [];
{
    _x params ["_class", "_initText"];
    private _ctrl = _display ctrlCreate [_class, -1];
    if (_initText isNotEqualTo "") then { _ctrl ctrlSetText _initText };
    _ctrls pushBack _ctrl;
} forEach _layout;

uiNamespace setVariable [QGVAR(hintCtrls), _ctrls];

private _cycleEntry = ["UKSF", "cycleShapeMode"] call CBA_fnc_getKeybind;
private _cycleKeyName = if (isNil "_cycleEntry") then { "" } else {
    (_cycleEntry select 5) call CBA_fnc_localizeKey
};
_cycleKeyName = _cycleKeyName regexReplace ["OEM 102", "\"];
uiNamespace setVariable [QGVAR(cycleKeyName), _cycleKeyName];

GVAR(hintVisible) = true;

GVAR(hintPFH) = [{
    params ["", "_idPFH"];

    private _ctrls = uiNamespace getVariable [QGVAR(hintCtrls), []];
    private _shouldHide = !visibleMap || {
        (GVAR(state) isEqualTo "idle") && {!GVAR(drawKeyHeld)}
    };

    if (_shouldHide) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
        GVAR(hintPFH) = -1;
        GVAR(hintVisible) = false;
        { ctrlDelete _x } forEach _ctrls;
        uiNamespace setVariable [QGVAR(hintCtrls), []];
    };

    if (count _ctrls != 9) exitWith {};

    getMousePosition params ["_mouseX", "_mouseY"];
    private _anchorX = _mouseX + 0.015;
    private _anchorY = _mouseY + 0.015;
    private _offsets = [
        [0,     0,     0.22,  0.148],
        [0.004, 0.004, 0.212, 0.028],
        [0.004, 0.032, 0.212, 0.028],
        [0.004, 0.060, 0.028, 0.028],
        [0.036, 0.060, 0.180, 0.028],
        [0.004, 0.088, 0.028, 0.028],
        [0.036, 0.088, 0.180, 0.028],
        [0.004, 0.116, 0.060, 0.028],
        [0.068, 0.116, 0.148, 0.028]
    ];
    {
        _x params ["_dx", "_dy", "_w", "_h"];
        private _ctrl = _ctrls#_forEachIndex;
        _ctrl ctrlSetPosition [_anchorX + _dx, _anchorY + _dy, _w, _h];
        _ctrl ctrlCommit 0;
    } forEach _offsets;

    private _line1 = "";
    private _line2 = "";
    private _lmb = "";
    private _rmb = "";
    private _extraName = "";
    private _extraText = "";

    switch (GVAR(state)) do {
        case "idle": {
            _line1 = format ["Mode: %1", GVAR(currentModeLabel)];
            _lmb = "Drag to start";
            _extraName = uiNamespace getVariable [QGVAR(cycleKeyName), ""];
            _extraText = "Cycle mode";
        };
        case "stage1": {
            private _length = GVAR(stage1Start) distance2D GVAR(stage1End);
            switch (GVAR(currentMode)) do {
                case "circle": {
                    _line1 = format ["Radius: %1m", round _length];
                    _lmb = "Release to commit";
                };
                default {
                    _line1 = format ["Length: %1m", round _length];
                    _lmb = "Release to set primary";
                };
            };
            _rmb = "Cancel";
        };
        case "stage2": {
            private _axisDx = (GVAR(stage1End)#0) - (GVAR(stage1Start)#0);
            private _axisDy = (GVAR(stage1End)#1) - (GVAR(stage1Start)#1);
            private _axisLength = sqrt (_axisDx * _axisDx + _axisDy * _axisDy);
            if (_axisLength > 0) then {
                private _unitX = _axisDx / _axisLength;
                private _unitY = _axisDy / _axisLength;
                private _toS2x = (GVAR(stage2Pos)#0) - (GVAR(stage1Start)#0);
                private _toS2y = (GVAR(stage2Pos)#1) - (GVAR(stage1Start)#1);
                private _parallel = _toS2x * _unitX + _toS2y * _unitY;
                private _perpSigned = _toS2x * (-_unitY) + _toS2y * _unitX;

                switch (GVAR(currentMode)) do {
                    case "ellipse": {
                        private _semiMinor = GVAR(stage2DefaultSecondary) + _perpSigned;
                        _line1 = format ["Length: %1m", round _axisLength];
                        _line2 = format ["Width: %1m", round (abs (_semiMinor * 2))];
                    };
                    case "racetrack": {
                        private _fullWidth = GVAR(stage2DefaultSecondary) + _perpSigned;
                        _line1 = format ["Length: %1m", round _axisLength];
                        _line2 = format ["Width: %1m", round (abs _fullWidth)];
                    };
                    case "cone": {
                        private _halfAngle = GVAR(stage2DefaultSecondary) + (_perpSigned atan2 _parallel);
                        _line1 = format ["Length: %1m", round _axisLength];
                        _line2 = format ["Angle: %1 deg", round (abs _halfAngle * 2)];
                    };
                };
            };
            _lmb = "Click to commit";
            _rmb = "Cancel";
        };
    };

    (_ctrls#1) ctrlSetText _line1;
    (_ctrls#2) ctrlSetText _line2;
    (_ctrls#4) ctrlSetText _lmb;
    (_ctrls#6) ctrlSetText _rmb;
    (_ctrls#7) ctrlSetText _extraName;
    (_ctrls#8) ctrlSetText _extraText;
}, 0, []] call CBA_fnc_addPerFrameHandler;
