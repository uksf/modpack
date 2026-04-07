#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Append a single tick value to a flat sampled-series array using
        gap-compaction. Positive values are stored as-is. Zero values
        extend the trailing negative gap counter (or open a new one).

        A series like 12, 8, 0, 0, 0, 5, 0, 0, 7, 0 becomes
        [12, 8, -3, 5, -2, 7, -1].

    Parameter(s):
        0: Series array <ARRAY> - mutated in place
        1: Tick value <NUMBER> - non-negative

    Return Value:
        None

    Example:
        [_series, 12] call uksf_common_fnc_sampledSeriesAppend
*/
params [["_series", [], [[]]], ["_value", 0, [0]]];

if (_value > 0) exitWith {
    _series pushBack _value;
};

private _lastIndex = (count _series) - 1;
if (_lastIndex >= 0 && {_series#_lastIndex < 0}) then {
    _series set [_lastIndex, _series#_lastIndex - 1];
} else {
    _series pushBack -1;
};
