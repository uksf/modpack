#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Get current rating for area for a given object or position

    Parameters:
        0: Object or position <OBJECT/ARRAY>

    Return value:
        Array of area ratings <ARRAY>
        [[ID, Display name, Logic, Area, [Rating start, Rating current, Rating min, Rating max], [Percentage start, Percentage current]], ...]
*/
params [["_position", objNull, [objNull, []]]];

if (_position isEqualType objNull) then {
    _position = getPosASL _position;
};

private _areas = GVAR(ratingAreas) select {[_position, _x#2, _x#3] call EFUNC(common,objectInArea)};
_areas apply {[_x] call FUNC(getAreaRating)};
