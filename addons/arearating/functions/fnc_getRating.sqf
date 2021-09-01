#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Get current rating for area for a given object or position

    Parameters:
        0: Event object or position <OBJECT/ARRAY>

    Return value:
        Array of area ratings <ARRAY>
        [[Persistence ID, Area, Logic, [Rating start, Rating current, Rating min, Rating max], [Percentage start, Percentage current]], ...]
*/
params [["_data", objNull, [objNull, []]]];

if !(isServer) exitWith {};

if (_type == "") exitWith {};
if (_data isEqualType objNull && {isNull _data}) exitWith {};
if (_data isEqualType []) exitWith {};

private _position = _data;
if (_position isEqualType objNull) then {
    _position = getPosASL _data;
};

private _areas = GVAR(ratingAreas) select {[_position, _x#1, _x#2] call EFUNC(common,objectInArea)};
_areas apply {[_x] call FUNC(getAreaRating)};
