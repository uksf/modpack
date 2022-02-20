#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Deserialize rating area values from serialized data

    Parameter(s):
        0: Serialized data <ARRAY>

    Return Value:
        None
*/
params [["_data", []]];

if !(isServer) exitWith {};

{
    _x params ["_id", "_displayName", "_logic", "_area", "_values"];

    private _dataIndex = _data findIf {_x#0 == _id};
    if (_dataIndex == -1) exitWith {};

    private _areaData = _data#_dataIndex;
    _areaData params ["", "_areaDataValues"];

    private _ratingCurrent = _areaDataValues get QGVAR(ratingCurrent);
    private _ratingMin = _values get QGVAR(ratingMin);
    private _ratingMax = _values get QGVAR(ratingMax);

    _ratingCurrent = (_ratingCurrent max _ratingMin) min _ratingMax;

    _values set [QGVAR(ratingCurrent), _ratingCurrent];
} forEach GVAR(ratingAreas);
