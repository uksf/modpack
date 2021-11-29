#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Manually adjust rating for the given array of areas or IDs or display names.
        Use negative values for negative changes.

    Parameters:
        0: Areas or IDs or display names <ARRAY>
        1: Rating change <SCALAR>

    Return value:
        Nothing
*/
params [["_ratingAreas", [], [[]]], ["_ratingChange", 0, [0]]];

if !(isServer) exitWith {};
if (uksf_arearating_ratingAreas isEqualTo []) exitWith {};

private _validRatingAreas = [];
{
    private _ratingArea = _x;
    if (_ratingArea isEqualType [] && {count _ratingArea == 5}) then {
        _validRatingAreas pushBack _ratingArea;
        continue;
    };

    if (_ratingArea isEqualType "") then {
        private _ratingAreaIndex = uksf_arearating_ratingAreas findIf {_x#0 == _ratingArea || _x#1 == _ratingArea};
        if (_ratingAreaIndex != -1) then {
            _ratingArea = uksf_arearating_ratingAreas#_ratingAreaIndex;
            _validRatingAreas pushBack _ratingArea;
        };
    };
} forEach _ratingAreas;

{
    _x params ["", "", "", "", "_values"];

    private _ratingCurrent = _values get "uksf_arearating_ratingCurrent";
    private _ratingMin = _values get "uksf_arearating_ratingMin";
    private _ratingMax = _values get "uksf_arearating_ratingMax";

    _ratingCurrent = _ratingCurrent + _ratingChange;
    _ratingCurrent = (_ratingCurrent max _ratingMin) min _ratingMax;

    _values set ["uksf_arearating_ratingCurrent", _ratingCurrent];
} forEach _validRatingAreas;

[_validRatingAreas] call uksf_arearating_fnc_recalculateGlobalRatingEvents;
