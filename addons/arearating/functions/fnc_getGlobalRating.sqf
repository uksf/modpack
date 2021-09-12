#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Get current global rating

    Parameters:
        None

    Return value:
        Array of ratings and percentages <ARRAY>
        [[Global start, Global current, Global min, Global max], [Percentage start, Percentage current]]
*/

if !(isServer) exitWith {};

if (GVAR(ratingAreas) isEqualTo []) exitWith {
    [[0, 0, 0, 0], [0, 0]]
};

private _globalStart = 0;
private _globalCurrent = 0;
private _globalMin = 0;
private _globalMax = 0;

{
    _x params ["", "", "_logic", "_area", "_values"];

    private _ratingStart = _values get QGVAR(ratingStart);
    private _ratingCurrent = _values get QGVAR(ratingCurrent);
    private _ratingMin = _values get QGVAR(ratingMin);
    private _ratingMax = _values get QGVAR(ratingMax);

    _globalStart = _globalStart + _ratingStart;
    _globalCurrent = _globalCurrent + _ratingCurrent;
    _globalMin = _globalMin + _ratingMin;
    _globalMax = _globalMax + _ratingMax;
} forEach GVAR(ratingAreas);

private _percentageStart = _globalStart / (_globalMax - _globalMin) * 100;
private _percentageCurrent = _globalCurrent / (_globalMax - _globalMin) * 100;

[[_globalStart, _globalCurrent, _globalMin, _globalMax], [_percentageStart, _percentageCurrent]]
