#include "script_component.hpp"

/*
    Author:
        Codex

    Description:
        Computes patrol anchor 2/3 of the way to target with 250-500m lateral offset.
*/

params [
    ["_spawnPosition", [], [[]]],
    ["_targetPosition", [], [[]]]
];

if !(_spawnPosition isEqualType [] && {_targetPosition isEqualType []} && {count _spawnPosition >= 2} && {count _targetPosition >= 2}) exitWith {[]};

private _dir = _spawnPosition getDir _targetPosition;
private _distance = (_spawnPosition distance2D _targetPosition) max 10;
private _basePosition = _spawnPosition getPos [_distance * 0.66, _dir];

private _offsetDistance = 250 + random 250;
private _offsetDirection = _dir + (selectRandom [-90, 90]) + (random 20 - 10);
private _anchor = _basePosition getPos [_offsetDistance, _offsetDirection];

if (surfaceIsWater _anchor) then {
    _anchor = _basePosition getPos [_offsetDistance, _offsetDirection + 180];
};
if (surfaceIsWater _anchor) then {
    _anchor = _basePosition;
};

_anchor set [2, 0];
_anchor
