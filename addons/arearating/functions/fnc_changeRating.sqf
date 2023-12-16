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

if (GVAR(ratingAreas) isEqualTo []) exitWith {};

if !(isServer) exitWith {
    [QGVAR(changeRating), _this] call CBA_fnc_serverEvent;
};

TRACE_2("",_ratingAreas,_ratingChange);
private _validRatingAreas = [];
{
    private _ratingArea = _x;
    if (_ratingArea isEqualType [] && {count _ratingArea == 5}) then {
        _validRatingAreas pushBack _ratingArea;
        continue;
    };

    if (_ratingArea isEqualType "") then {
        private _ratingAreaIndex = GVAR(ratingAreas) findIf {_x#0 == _ratingArea || _x#1 == _ratingArea};
        if (_ratingAreaIndex != -1) then {
            _ratingArea = GVAR(ratingAreas)#_ratingAreaIndex;
            _validRatingAreas pushBack _ratingArea;
        };
    };
} forEach _ratingAreas;

TRACE_2("",_validRatingAreas);

{
    _x params ["", "", "", "", "_values"];

    private _ratingCurrent = _values get QGVAR(ratingCurrent);
    private _ratingMin = _values get QGVAR(ratingMin);
    private _ratingMax = _values get QGVAR(ratingMax);

    _ratingCurrent = _ratingCurrent + _ratingChange;
    _ratingCurrent = (_ratingCurrent max _ratingMin) min _ratingMax;

    _values set [QGVAR(ratingCurrent), _ratingCurrent];
} forEach _validRatingAreas;

call FUNC(broadcastRatingAreas);
[_validRatingAreas] call FUNC(recalculateGlobalRatingEvents);
