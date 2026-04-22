#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Removes and returns a spatial chunk of positions near a seed.

    Parameters:
        0: Mutable position list [[positionATL, direction, ...], ...] <ARRAY>

    Return Value:
        Chunk array [[positionATL, direction, ...], ...] <ARRAY>

    Example:
        [_positions] call uksf_autoplace_fnc_takeChunk
*/
#define MAX_CHUNK_RADIUS 150

params ["_positions"];

if (_positions isEqualTo []) exitWith {[]};

private _seed = _positions deleteAt 0;
private _seedPosition = _seed#0;

private _nearby = [];
for "_index" from ((count _positions) - 1) to 0 step -1 do {
    private _positionData = _positions#_index;
    private _distance = (_positionData#0) distance2D _seedPosition;
    if (_distance <= MAX_CHUNK_RADIUS) then {
        _nearby pushBack [_index, _positionData, _distance];
    };
};

_nearby = [_nearby, [], {_x#2}, "ASCEND"] call BIS_fnc_sortBy;

private _takeCount = ((count _nearby) min (MAX_GROUP_SIZE - 1)) max 0;
private _selected = _nearby select [0, _takeCount];
private _selectedIndices = _selected apply {_x#0};
private _selectedPositions = _selected apply {_x#1};

if (_selectedIndices isNotEqualTo []) then {
    _selectedIndices = [_selectedIndices, [], {_x}, "DESCEND"] call BIS_fnc_sortBy;
    {
        _positions deleteAt _x;
    } forEach _selectedIndices;
};

private _chunk = [_seed];
_chunk append _selectedPositions;

if ((count _chunk) > 1) then {
    private _sumX = 0;
    private _sumY = 0;
    {
        _sumX = _sumX + ((_x#0)#0);
        _sumY = _sumY + ((_x#0)#1);
    } forEach _chunk;

    private _centroid = [_sumX / (count _chunk), _sumY / (count _chunk), 0];
    private _nearestIndex = 0;
    private _nearestDistance = 1e9;

    for "_idx" from 0 to ((count _chunk) - 1) do {
        private _distance = ((_chunk#_idx)#0) distance2D _centroid;
        if (_distance < _nearestDistance) then {
            _nearestDistance = _distance;
            _nearestIndex = _idx;
        };
    };

    if (_nearestIndex > 0) then {
        private _leaderPosition = _chunk deleteAt _nearestIndex;
        _chunk insert [0, [_leaderPosition]];
    };
};

_chunk
