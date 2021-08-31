#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Fires events for global rating passing thresholds.

    Parameters:
        0: Array of areas affecting rating change <ARRAY> (Optional)

    Return value:
        None
*/
params [["_areas", []]];

if !(isServer) exitWith {};

private _globalRating = call FUNC(getGlobalRating);
_globalRating params ["_ratings", "_percentages"];
_ratings params ["_globalStart", "_globalCurrent", "_globalMin", "_globalMax"];
_percentages params ["_percentageStart", "_percentageCurrent"];

TRACE_7("",GVAR(previousGlobalPercentage),_globalStart,_globalCurrent,_globalMin,_globalMax,_percentageStart,_percentageCurrent);

if (_percentageCurrent == GVAR(previousGlobalPercentage)) exitWith {};

if (GVAR(previousGlobalPercentage) == 0 && _areas isEqualTo []) exitWith {
    GVAR(previousGlobalPercentage) = _percentageCurrent;
};

{
   private _newValue = _x;

   if (_percentageCurrent == _newValue) then {
        [QGVAR(percentageSetTo), [GVAR(previousGlobalPercentage), _percentageCurrent, _areas]] call CBA_fnc_serverEvent;
        continue;
   };
} forEach [0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100];

if (_percentageCurrent > GVAR(previousGlobalPercentage)) then {
    [QGVAR(percentageIncreased), [GVAR(previousGlobalPercentage), _percentageCurrent, _areas]] call CBA_fnc_serverEvent;
};

if (_percentageCurrent < GVAR(previousGlobalPercentage)) then {
    [QGVAR(percentageDecreased), [GVAR(previousGlobalPercentage), _percentageCurrent, _areas]] call CBA_fnc_serverEvent;
};

GVAR(previousGlobalPercentage) = _percentageCurrent;
