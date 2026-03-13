#include "script_component.hpp"
/*
    Author:
        Beswick.T

    Description:
        Debug visualisation for a single target's overpressure result.
        Draws path lines and floating damage text. Uses game time for
        duration so slow-motion time acceleration works correctly.
        Supports two calling conventions:
            Path trace mode: [target, detonationASL, targetASL, intermediateASL, damage, pathType]
            Wave mode: [target, targetASL, hitPointASL, damage, pathType, pathHistory]

    Parameter(s):
        0: Target object <OBJECT>
        1: Detonation position ASL or target position ASL <ARRAY>
        2: Target position ASL or hit point ASL <ARRAY>
        3: Intermediate point ASL or damage <ARRAY|NUMBER>
        4: Damage or path type string <NUMBER|STRING>
        5: Path type string or path history <STRING|ARRAY>
        6: Path history (Optional, wave mode only) <ARRAY>

    Return Value:
        None

    Example:
        [_target, _detonationPositionASL, _targetPositionASL, _intermediatePointASL, _damage, _pathType] call uksf_blastoverpressure_fnc_debugDraw
*/

private _isWaveMode = (count _this > 5) && {(_this#5) isEqualType []};

private ["_target", "_targetPositionASL", "_damage", "_pathType", "_pathSegmentsATL", "_detonationPositionATL", "_targetPositionATL", "_intermediatePositionATL"];

if (_isWaveMode) then {
    // Wave mode: [target, targetASL, hitPointASL, damage, pathType, pathHistory]
    params ["_targetObj", "_targetPosASL", "_hitPointASL", "_dmg", "_type", "_pathHistory"];
    _target = _targetObj;
    _targetPositionASL = _targetPosASL;
    _damage = _dmg;
    _pathType = _type;

    // Convert path history to ATL segments
    _pathSegmentsATL = _pathHistory apply { [ASLToATL (_x#0), _x#1] };
    // Add the final segment to the hit point
    _pathSegmentsATL pushBack [ASLToATL _hitPointASL, (count _pathHistory - 1) max 0];

    _targetPositionATL = ASLToATL _targetPosASL;
} else {
    // Path trace mode: [target, detonationASL, targetASL, intermediateASL, damage, pathType]
    params ["_targetObj", "_detonationPositionASL", "_targetPosASL", "_intermediatePointASL", "_dmg", "_type"];
    _target = _targetObj;
    _targetPositionASL = _targetPosASL;
    _damage = _dmg;
    _pathType = _type;

    _detonationPositionATL = ASLToATL _detonationPositionASL;
    _targetPositionATL = ASLToATL _targetPosASL;
    _intermediatePositionATL = ASLToATL _intermediatePointASL;
    _pathSegmentsATL = [];
};

private _startTime = CBA_missionTime;
private _duration = 5;

// Colour based on damage: bright red for high damage, orange for low
private _normalisedDamage = (_damage / 25) min 1;
private _colour = [1, 0.3 * (1 - _normalisedDamage), 0, 1];

// Path colour: orange for overhead, cyan for bounce
private _pathColour = if (_pathType isEqualTo "overhead") then {
    [1, 0.6, 0, 1]
} else {
    [0, 0.8, 1, 1]
};

[{
    params ["_args", "_perFrameHandlerID"];
    _args params [
        "_startTime", "_duration", "_colour", "_pathColour",
        "_targetPositionATL", "_damage", "_pathType",
        "_pathSegmentsATL", "_detonationPositionATL", "_intermediatePositionATL"
    ];

    if (CBA_missionTime > _startTime + _duration) exitWith {
        [_perFrameHandlerID] call CBA_fnc_removePerFrameHandler;
    };

    if (_pathSegmentsATL isNotEqualTo []) then {
        // Wave mode: draw full bounce path
        for "_j" from 1 to (count _pathSegmentsATL - 1) do {
            private _previous = _pathSegmentsATL select (_j - 1);
            private _current = _pathSegmentsATL select _j;
            _previous params ["_previousPositionATL", "_previousBounceCount"];
            _current params ["_currentPositionATL", ""];

            private _segmentColour = switch (_previousBounceCount) do {
                case 0: { _pathColour };
                case 1: { [1, 0.5, 0, 1] };
                case 2: { [1, 0, 0, 1] };
                default { [1, 0, 1, 1] };
            };

            drawLine3D [_previousPositionATL vectorAdd [0, 0, 0.1], _currentPositionATL vectorAdd [0, 0, 0.1], _segmentColour];
        };
    } else {
        // Path trace mode: draw detonation -> intermediate -> target
        drawLine3D [_detonationPositionATL vectorAdd [0, 0, 0.1], _intermediatePositionATL vectorAdd [0, 0, 0.1], _pathColour];
        drawLine3D [_intermediatePositionATL vectorAdd [0, 0, 0.1], _targetPositionATL vectorAdd [0, 0, 0.1], _pathColour];

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
    };

    // Floating text at target
    private _textPosition = _targetPositionATL vectorAdd [0, 0, 2];
    private _damageText = format ["%1 | %2", _damage toFixed 1, _pathType];
    drawIcon3D ["\a3\ui_f\data\IGUI\Cfg\Actions\clear_empty_ca.paa", _colour, _textPosition, 0.5, 0.5, 0, _damageText, 2, 0.03, "RobotoCondensed"];

}, 0, [
    _startTime, _duration, _colour, _pathColour,
    _targetPositionATL, _damage, _pathType,
    _pathSegmentsATL,
    _detonationPositionATL, _intermediatePositionATL
]] call CBA_fnc_addPerFrameHandler;
