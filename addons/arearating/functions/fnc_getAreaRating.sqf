#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Get rating for given area

    Parameters:
        0: Rating area array or persistence ID <ARRAY/STRING>

    Return value:
        Array of area ratings <ARRAY>
        [Persistence ID, Area, Logic, [Rating start, Rating current, Rating min, Rating max], [Percentage start, Percentage current]]
*/
params [["_ratingArea", [], [[], ""]]];

if (_ratingArea isEqualType "") then {
    private _ratingAreaIndex = GVAR(ratingAreas) findIf {_x#0 == _ratingArea};
    if (_ratingAreaIndex == -1) exitWith {};

    _ratingArea = GVAR(ratingAreas)#_ratingAreaIndex;
};

_ratingArea params ["_persistenceId", "_logic", "_area", "_values"];

private _ratingStart = _values get QGVAR(ratingStart);
private _ratingCurrent = _values get QGVAR(ratingCurrent);
private _ratingMin = _values get QGVAR(ratingMin);
private _ratingMax = _values get QGVAR(ratingMax);

private _percentageStart = _ratingStart / (_ratingMax - _ratingMin) * 100;
private _percentageCurrent = _ratingCurrent / (_ratingMax - _ratingMin) * 100;

[_persistenceId, _area, _logic, [_ratingStart, _ratingCurrent, _ratingMin, _ratingMax], [_percentageStart, _percentageCurrent]]
