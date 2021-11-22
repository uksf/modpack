#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Handle rating change for event.
        Finds area by object or position and changes rating based on module settings.

    Parameters:
        0: Event type <STRING>
        1: Event object or position <OBJECT/ARRAY>

    Return value:
        Nothing
*/
params ["_type", ["_data", objNull, [objNull, []]]];

if !(isServer) exitWith {};
if (GVAR(ratingAreas) isEqualTo []) exitWith {};

TRACE_2("",_type,_data);
if (_type == "") exitWith {};
if (_data isEqualType objNull && {isNull _data}) exitWith {};
if (_data isEqualType [] && {_data isEqualTo []}) exitWith {};

private _position = _data;
if (_position isEqualType objNull) then {
    _position = getPosASL _data;
};

TRACE_3("",_type,_data,_position);

private _areas = GVAR(ratingAreas) select {[_position, _x#2, _x#3] call EFUNC(common,objectInArea)};
TRACE_1("",_areas);

{
    _x params ["", "", "", "", "_values"];

    private _ratingCurrent = _values get QGVAR(ratingCurrent);
    private _ratingMin = _values get QGVAR(ratingMin);
    private _ratingMax = _values get QGVAR(ratingMax);
    private _ratingChange = _values get _type;

    _ratingCurrent = _ratingCurrent + _ratingChange;
    _ratingCurrent = (_ratingCurrent max _ratingMin) min _ratingMax;

    _values set [QGVAR(ratingCurrent), _ratingCurrent];
} forEach _areas;

[_areas] call FUNC(recalculateGlobalRatingEvents);
