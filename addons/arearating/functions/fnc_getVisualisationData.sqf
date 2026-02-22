#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Returns area rating visualisation data for Zeus.

    Parameter(s):
        None

    Return Value:
        Array of rating area data
*/

private _areas = GVAR(ratingAreas) apply {
    _x params ["_id", "_name", "_logic", "_area", "_values"];

    private _position = getPosATL _logic;
    private _current = _values getOrDefault [QGVAR(ratingCurrent), 50];
    private _minimum = _values getOrDefault [QGVAR(ratingMin), 0];
    private _maximum = _values getOrDefault [QGVAR(ratingMax), 100];
    private _start = _values getOrDefault [QGVAR(ratingStart), 50];
    private _range = _maximum - _minimum;
    private _percentage = if (_range > 0) then {round ((_current / _range) * 100)} else {0};
    private _startPercentage = if (_range > 0) then {round ((_start / _range) * 100)} else {0};

    [_position, _area, _name, _percentage, _startPercentage]
};

[_areas]
