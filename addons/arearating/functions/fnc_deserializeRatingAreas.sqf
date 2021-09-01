#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Deserialize rating area values from persistence data

    Parameter(s):
        0: Persistence data <ARRAY>

    Return Value:
        None
*/
params [["_data", []]];

if !(isServer) exitWith {};

{
    _x params ["_persistenceId", "_logic", "_area", "_values"];

    private _persistentDataIndex = _data findIf {_x#0 == _persistenceId};
    if (_persistentDataIndex == -1) exitWith {};

    private _persistentData = _data#_persistentDataIndex;
    _persistentData params ["", "_persistentValues"];

    private _ratingCurrent = _persistentValues get QGVAR(ratingCurrent);
    private _ratingMin = _values get QGVAR(ratingMin);
    private _ratingMax = _values get QGVAR(ratingMax);

    if (_ratingCurrent < _ratingMin) then {
        _ratingCurrent = _ratingMin;
    };

    if (_ratingCurrent > _ratingMax) then {
        _ratingCurrent = _ratingMax;
    };

    _values set [QGVAR(ratingCurrent), _ratingCurrent];
} forEach GVAR(ratingAreas);
