#include "script_component.hpp"
/*
    Author:
        Beswick.T

    Description:
        Debug visualisation for blast radius ring and summary info.
        Draws a circle at ground level showing effective range.

    Parameter(s):
        0: Detonation position ASL <ARRAY>
        1: indirectHitRange <NUMBER>
        2: Effective range <NUMBER>
        3: Ammo class name <STRING>
        4: Total shielded targets <NUMBER>
        5: Shielded targets array <ARRAY>

    Return Value:
        None
*/
params ["_positionASL", "_indirectHitRange", "_effectiveRange", "_ammo", "_totalShielded", "_shieldedTargets"];

private _startTime = CBA_missionTime;
private _duration = 5;
private _positionATL = ASLToATL _positionASL;
private _segments = 36; // Circle resolution

// Pre-calculate circle points for both radii
private _innerCircle = [];
private _outerCircle = [];
for "_i" from 0 to _segments do {
    private _angle = (_i / _segments) * 360;
    private _innerPoint = _positionATL vectorAdd [sin _angle * _indirectHitRange, cos _angle * _indirectHitRange, 0.1];
    private _outerPoint = _positionATL vectorAdd [sin _angle * _effectiveRange, cos _angle * _effectiveRange, 0.1];
    _innerCircle pushBack _innerPoint;
    _outerCircle pushBack _outerPoint;
};

// Collect shielded target positions for green lines
private _shieldedPositions = _shieldedTargets apply {
    _x params ["_target"];
    ASLToATL (eyePos _target)
};

[{
    params ["_args", "_perFrameHandlerID"];
    _args params [
        "_startTime", "_duration", "_positionATL",
        "_innerCircle", "_outerCircle", "_segments",
        "_ammo", "_totalShielded", "_shieldedPositions"
    ];

    if (CBA_missionTime > _startTime + _duration) exitWith {
        [_perFrameHandlerID] call CBA_fnc_removePerFrameHandler;
    };

    // Draw inner circle (indirectHitRange) in white
    for "_i" from 0 to (_segments - 1) do {
        drawLine3D [_innerCircle select _i, _innerCircle select (_i + 1), [1, 1, 1, 0.6]];
    };

    // Draw outer circle (effectiveRange) in yellow
    for "_i" from 0 to (_segments - 1) do {
        drawLine3D [_outerCircle select _i, _outerCircle select (_i + 1), [1, 1, 0, 0.4]];
    };

    // Draw detonation marker
    drawIcon3D ["\a3\ui_f\data\IGUI\Cfg\Actions\clear_empty_ca.paa", [1, 0.2, 0, 1], _positionATL vectorAdd [0, 0, 0.5], 1, 1, 0, format ["%1 | %2 shielded", _ammo, _totalShielded], 2, 0.04, "RobotoCondensed"];

    // Draw green lines to shielded targets (before damage processing determines colour)
    {
        drawLine3D [_positionATL vectorAdd [0, 0, 0.1], _x, [0, 1, 0, 0.3]];
    } forEach _shieldedPositions;

}, 0, [
    _startTime, _duration, _positionATL,
    _innerCircle, _outerCircle, _segments,
    _ammo, _totalShielded, _shieldedPositions
]] call CBA_fnc_addPerFrameHandler;
