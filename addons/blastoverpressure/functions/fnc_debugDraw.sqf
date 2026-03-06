#include "script_component.hpp"
/*
    Author:
        Beswick.T

    Description:
        Debug visualisation for a single target's overpressure result.
        Draws path lines and floating damage text. Uses game time for
        duration so slow-motion time acceleration works correctly.

    Parameter(s):
        0: Target object <OBJECT>
        1: Detonation position ASL <ARRAY>
        2: Target position ASL <ARRAY>
        3: Intermediate/bounce point ASL <ARRAY>
        4: Damage applied <NUMBER>
        5: Path type string <STRING>

    Return Value:
        None
*/
params ["_target", "_detonationPositionASL", "_targetPositionASL", "_intermediatePointASL", "_damage", "_pathType"];

private _startTime = CBA_missionTime;
private _duration = 5; // 5 seconds game time

// Colour based on damage: bright red for high damage, orange for low
private _normalisedDamage = (_damage / 33) min 1;
private _colour = [1, 0.3 * (1 - _normalisedDamage), 0, 1]; // red to orange

// Path colour: orange for overhead, cyan for bounce
private _pathColour = if (_pathType isEqualTo "overhead") then {
    [1, 0.6, 0, 1]
} else {
    [0, 0.8, 1, 1]
};

private _detonationPositionATL = ASLToATL _detonationPositionASL;
private _targetPositionATL = ASLToATL _targetPositionASL;
private _intermediatePositionATL = ASLToATL _intermediatePointASL;

// Per-frame draw handler
[{
    params ["_args", "_perFrameHandlerID"];
    _args params [
        "_startTime", "_duration", "_colour", "_pathColour",
        "_detonationPositionATL", "_targetPositionATL", "_intermediatePositionATL",
        "_damage", "_pathType"
    ];

    if (CBA_missionTime > _startTime + _duration) exitWith {
        [_perFrameHandlerID] call CBA_fnc_removePerFrameHandler;
    };

    // Draw path segments
    drawLine3D [_detonationPositionATL vectorAdd [0, 0, 0.1], _intermediatePositionATL vectorAdd [0, 0, 0.1], _pathColour];
    drawLine3D [_intermediatePositionATL vectorAdd [0, 0, 0.1], _targetPositionATL vectorAdd [0, 0, 0.1], _pathColour];

    // Draw damage line (detonation to target, coloured by damage)
    drawLine3D [_detonationPositionATL vectorAdd [0, 0, 0.2], _targetPositionATL vectorAdd [0, 0, 0.2], _colour];

    // Draw intermediate point marker
    private _markerSize = 0.3;
    drawLine3D [
        _intermediatePositionATL vectorAdd [- _markerSize, 0, 0],
        _intermediatePositionATL vectorAdd [_markerSize, 0, 0],
        [1, 1, 0, 1]
    ];
    drawLine3D [
        _intermediatePositionATL vectorAdd [0, - _markerSize, 0],
        _intermediatePositionATL vectorAdd [0, _markerSize, 0],
        [1, 1, 0, 1]
    ];
    drawLine3D [
        _intermediatePositionATL vectorAdd [0, 0, - _markerSize],
        _intermediatePositionATL vectorAdd [0, 0, _markerSize],
        [1, 1, 0, 1]
    ];

    // Floating text at target
    private _textPosition = _targetPositionATL vectorAdd [0, 0, 2];
    private _damageText = format ["%1 | %2", _damage toFixed 1, _pathType];
    drawIcon3D ["\a3\ui_f\data\IGUI\Cfg\Actions\clear_empty_ca.paa", _colour, _textPosition, 0.5, 0.5, 0, _damageText, 2, 0.03, "RobotoCondensed"];

}, 0, [
    _startTime, _duration, _colour, _pathColour,
    _detonationPositionATL, _targetPositionATL, _intermediatePositionATL,
    _damage, _pathType
]] call CBA_fnc_addPerFrameHandler;
