/*
    Author:
        Tim Beswick

    Description:
        Check if in position in line of sight

    Parameters:
        0: Unit to check <OBJECT>
        1: Unit to check line of sight for <OBJECT>
        2: Check if distance is within zoom range <BOOL>

    Return value:
        Boolean
*/
#include "script_component.hpp"

params ["_target", "_source", ["_zoomCheck", false]];

private _pos = worldToScreen (getPos _target);
private _los = ((count _pos) > 0) && {(abs (_pos select 0)) < 1.5} && {(abs (_pos select 1)) < 1.5} && {[_source, "VIEW", (vehicle _source)] checkVisibility [eyePos _source, eyePos _target] > 0};
private _zoom = true;
if (_zoomCheck) then {
    private _distanceMultiplier = if ((vehicle _target) isKindOf "CAManBase") then {
        (DISTANCE_MULTIPLIER + (DISTANCE_MULTIPLIER * (currentVisionMode _source)))
    } else {
        (DISTANCE_MULTIPLIER + (2 * DISTANCE_MULTIPLIER * (currentVisionMode _source))) * VEHICLE_MULTIPLIER
    };
    private _distance = (getObjectViewDistance select 0) min (DISTANCE_MIN + (_distanceMultiplier * ((call CBA_fnc_getFov) select 1)));
    _zoom = ((_target distance _source) < _distance);
};

_los && _zoom
