#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Get rating for given area

    Parameters:
        0: Rating area <ARRAY>

    Return value:
        Array of area ratings <ARRAY>
        [Area, Logic, [Rating start, Rating current, Rating min, Rating max], [Percentage start, Percentage current]]
*/
params ["_ratingArea"];
_ratingArea params ["_logic", "_area", "_values"];

private _ratingStart = _values get QGVAR(ratingStart);
private _ratingCurrent = _values get QGVAR(ratingCurrent);
private _ratingMin = _values get QGVAR(ratingMin);
private _ratingMax = _values get QGVAR(ratingMax);

private _percentageStart = _ratingStart / (_ratingMax - _ratingMin) * 100;
private _percentageCurrent = _ratingCurrent / (_ratingMax - _ratingMin) * 100;

[_area, _logic, [_ratingStart, _ratingCurrent, _ratingMin, _ratingMax], [_percentageStart, _percentageCurrent]]
