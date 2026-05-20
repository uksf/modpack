#include "script_component.hpp"
/*
    Author:
        Beswick.T

    Description:
        Map control mouse button handler. Owns the shape-draw state
        machine. Returns true to consume the event only when actively
        in a shape stage. RMB during any stage cancels.

    Parameter(s):
        0: Direction (1 = down, 0 = up) <NUMBER>
        1: [control, button, screenPosX, screenPosY, shift, ctrl, alt] <ARRAY>

    Return Value:
        Whether to consume the event <BOOL>

    Example:
        [1, [_ctrl, 0, 0.5, 0.5, false, false, false]] call uksf_maptools_fnc_handleMouseButton
*/
params ["_dir", "_params"];
_params params ["_control", "_button", "_screenPosX", "_screenPosY"];

private _mouseWorld = _control ctrlMapScreenToWorld [_screenPosX, _screenPosY];

if (_button == 1 && {_dir == 1} && {GVAR(state) isNotEqualTo "idle"}) exitWith {
    GVAR(state) = "idle";
    GVAR(drawKeyHeld) = false;
    call FUNC(updatePreview);
    true
};

if (_button != 0) exitWith { false };

if (_dir == 1) then {
    if (GVAR(state) == "stage2") exitWith {
        GVAR(stage2Pos) = _mouseWorld;
        private _polylines = call {
            private _axisX = (GVAR(stage1End)#0) - (GVAR(stage1Start)#0);
            private _axisY = (GVAR(stage1End)#1) - (GVAR(stage1Start)#1);
            private _axisLen = sqrt (_axisX * _axisX + _axisY * _axisY);
            private _rotationDeg = _axisY atan2 _axisX;

            private _toS2X = (GVAR(stage2Pos)#0) - (GVAR(stage1Start)#0);
            private _toS2Y = (GVAR(stage2Pos)#1) - (GVAR(stage1Start)#1);

            private _ux = _axisX / _axisLen;
            private _uy = _axisY / _axisLen;
            private _parallel = _toS2X * _ux + _toS2Y * _uy;
            private _perpSigned = _toS2X * (-_uy) + _toS2Y * _ux;

            switch (GVAR(currentMode)) do {
                case "ellipse": {
                    private _semiMinor = GVAR(stage2DefaultSecondary) + _perpSigned;
                    private _centre = [
                        ((GVAR(stage1Start)#0) + (GVAR(stage1End)#0)) / 2,
                        ((GVAR(stage1Start)#1) + (GVAR(stage1End)#1)) / 2,
                        0
                    ];
                    [_centre, _axisLen / 2, _semiMinor, _rotationDeg] call FUNC(buildEllipse)
                };
                case "racetrack": {
                    private _fullWidth = GVAR(stage2DefaultSecondary) + _perpSigned;
                    private _halfWidth = (abs _fullWidth) / 2;
                    private _midX = (GVAR(stage1Start)#0 + GVAR(stage1End)#0) / 2;
                    private _midY = (GVAR(stage1Start)#1 + GVAR(stage1End)#1) / 2;
                    private _centre = [
                        _midX + (-_uy) * (_fullWidth / 2),
                        _midY + _ux * (_fullWidth / 2),
                        0
                    ];
                    [_centre, _axisLen / 2, _halfWidth, _rotationDeg] call FUNC(buildRaceTrack)
                };
                case "cone": {
                    private _halfAngle = GVAR(stage2DefaultSecondary) + (_perpSigned atan2 _parallel);
                    [GVAR(stage1Start), _axisLen, _halfAngle, _rotationDeg] call FUNC(buildCone)
                };
                default { [] };
            };
        };
        if (count _polylines > 0) then {
            [_polylines] call FUNC(emitShape);
        };
        GVAR(state) = "idle";
        GVAR(drawKeyHeld) = false;
        call FUNC(updatePreview);
        true
    };

    if (GVAR(state) == "idle" && {GVAR(drawKeyHeld)} && {call FUNC(canDrawShape)}) exitWith {
        GVAR(stage1Start) = _mouseWorld;
        GVAR(stage1End) = _mouseWorld;
        GVAR(state) = "stage1";
        call FUNC(updatePreview);
        true
    };

    false
} else {
    if (GVAR(state) == "stage1") exitWith {
        GVAR(stage1End) = _mouseWorld;
        if (GVAR(currentMode) == "circle") then {
            private _radius = GVAR(stage1Start) distance2D GVAR(stage1End);
            private _polylines = [GVAR(stage1Start), _radius] call FUNC(buildCircle);
            [_polylines] call FUNC(emitShape);
            GVAR(state) = "idle";
            GVAR(drawKeyHeld) = false;
            call FUNC(updatePreview);
        } else {
            GVAR(stage2Pos) = GVAR(stage1End);
            private _axisLen = GVAR(stage1Start) distance2D GVAR(stage1End);
            GVAR(stage2DefaultSecondary) = switch (GVAR(currentMode)) do {
                case "ellipse": { _axisLen / 4 };
                case "racetrack": { _axisLen / 4 };
                case "cone": { 7.5 };
                default { 0 };
            };
            GVAR(state) = "stage2";
            call FUNC(updatePreview);
        };
        true
    };
    false
};
