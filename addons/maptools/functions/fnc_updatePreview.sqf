#include "script_component.hpp"
/*
    Author:
        Beswick.T

    Description:
        Wipes any existing preview markers and rebuilds them from the current
        state-machine geometry. Preview markers are local-only (createMarkerLocal),
        not broadcast to other players. Called by the mouse handlers whenever the
        in-progress shape might have changed (stage transition, drag movement).

    Parameter(s):
        None

    Return Value:
        None

    Example:
        call uksf_maptools_fnc_updatePreview
*/
{ deleteMarkerLocal _x } forEach GVAR(previewMarkers);
GVAR(previewMarkers) = [];

if (GVAR(state) isEqualTo "idle") exitWith {};

private _polylines = [];
private _axisX = (GVAR(stage1End)#0) - (GVAR(stage1Start)#0);
private _axisY = (GVAR(stage1End)#1) - (GVAR(stage1Start)#1);
private _axisLen = sqrt (_axisX * _axisX + _axisY * _axisY);

if (_axisLen > 0) then {
    private _rotationDeg = _axisY atan2 _axisX;
    private _ux = _axisX / _axisLen;
    private _uy = _axisY / _axisLen;
    private _midX = (GVAR(stage1Start)#0 + GVAR(stage1End)#0) / 2;
    private _midY = (GVAR(stage1Start)#1 + GVAR(stage1End)#1) / 2;

    switch (GVAR(state)) do {
        case "stage1": {
            switch (GVAR(currentMode)) do {
                case "circle": {
                    _polylines = [GVAR(stage1Start), _axisLen] call FUNC(buildCircle);
                };
                case "ellipse": {
                    private _semiMajor = _axisLen / 2;
                    private _semiMinor = _semiMajor / 2;
                    _polylines = [[_midX, _midY, 0], _semiMajor, _semiMinor, _rotationDeg] call FUNC(buildEllipse);
                };
                case "racetrack": {
                    private _halfLength = _axisLen / 2;
                    private _halfWidth = _halfLength / 4;
                    private _centre = [
                        _midX + (-_uy) * _halfWidth,
                        _midY + _ux * _halfWidth,
                        0
                    ];
                    _polylines = [_centre, _halfLength, _halfWidth, _rotationDeg] call FUNC(buildRaceTrack);
                };
                case "cone": {
                    _polylines = [GVAR(stage1Start), _axisLen, 7.5, _rotationDeg] call FUNC(buildCone);
                };
            };
        };
        case "stage2": {
            private _toS2X = (GVAR(stage2Pos)#0) - (GVAR(stage1Start)#0);
            private _toS2Y = (GVAR(stage2Pos)#1) - (GVAR(stage1Start)#1);
            private _parallel = _toS2X * _ux + _toS2Y * _uy;
            private _perpSigned = _toS2X * (-_uy) + _toS2Y * _ux;

            switch (GVAR(currentMode)) do {
                case "ellipse": {
                    private _semiMinor = GVAR(stage2DefaultSecondary) + _perpSigned;
                    _polylines = [[_midX, _midY, 0], _axisLen / 2, _semiMinor, _rotationDeg] call FUNC(buildEllipse);
                };
                case "racetrack": {
                    private _fullWidth = GVAR(stage2DefaultSecondary) + _perpSigned;
                    private _halfWidth = (abs _fullWidth) / 2;
                    private _centre = [
                        _midX + (-_uy) * (_fullWidth / 2),
                        _midY + _ux * (_fullWidth / 2),
                        0
                    ];
                    _polylines = [_centre, _axisLen / 2, _halfWidth, _rotationDeg] call FUNC(buildRaceTrack);
                };
                case "cone": {
                    private _halfAngle = GVAR(stage2DefaultSecondary) + (_perpSigned atan2 _parallel);
                    _polylines = [GVAR(stage1Start), _axisLen, _halfAngle, _rotationDeg] call FUNC(buildCone);
                };
            };
        };
    };
};

if (count _polylines == 0) exitWith {};

private _colour = GVAR(activeColour);

{
    private _name = format ["uksf_maptools_preview_%1", _forEachIndex];
    createMarkerLocal [_name, _x select [0, 2]];
    _name setMarkerShapeLocal "POLYLINE";
    _name setMarkerColorLocal _colour;
    _name setMarkerPolylineLocal _x;
    GVAR(previewMarkers) pushBack _name;
} forEach _polylines;
