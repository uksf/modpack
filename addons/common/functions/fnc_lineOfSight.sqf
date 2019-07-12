/*
    Author:
        Tim Beswick

    Description:
        Check if in object is in line of sight and on screen.
        If zoomCheck is true, the objects distance will be compared to the zoom level of the player, allowing for high power optics.
        If groupCheck is true, other members of the group will be checked for onscreen & LOS if the leader is not onscreen & in LOS

    Parameters:
        0: Unit to check <OBJECT>
        1: Unit to check line of sight for <OBJECT>
        2: Check if distance is within zoom range <BOOL>
        3: Check other members of group if leader is on screen <BOOL>

    Return value:
        Boolean
*/
#include "script_component.hpp"

params [["_target", objNull, [objNull]], ["_source", objNull, [objNull]], ["_zoomCheck", false], ["_groupCheck", false]];

private _pos = worldToScreen (getPos _target);
private _los = ((count _pos) > 0 &&
                {_pos#0 > GVAR(bufferedSafeX) && _pos#0 < GVAR(bufferedSafeW) && _pos#1 > GVAR(bufferedSafeY) && _pos#1 < GVAR(bufferedSafeH) &&
                {([_source, "VIEW", (vehicle _source)] checkVisibility [eyePos _source, eyePos _target]) > 0}});

if (!_los && {_groupCheck}) then {
    _los = (({
        private _pos = worldToScreen (getPos _x);
        if ((count _pos) > 0 &&
            {_pos#0 > GVAR(bufferedSafeX) && _pos#0 < GVAR(bufferedSafeW) && _pos#1 > GVAR(bufferedSafeY) && _pos#1 < GVAR(bufferedSafeH) &&
            {([_source, "VIEW", (vehicle _source)] checkVisibility [eyePos _source, eyePos _x]) > 0}}
        ) exitWith {
            _target = _x;
            1
        };
    } count ((units (group _target)) - [_target])) > 0);
};

if (_los && {_zoomCheck}) then {
    private _distanceMultiplier = (400 + (4 * 200 * (((currentVisionMode _source) - 1) max 0)));
    if (!((vehicle _target) isKindOf "CAManBase")) then {
        _distanceMultiplier = _distanceMultiplier * VEHICLE_MULTIPLIER;
    };
    private _distance = (getObjectViewDistance#0) min (DISTANCE_MIN + (_distanceMultiplier * ((call CBA_fnc_getFov)#1)));
    _los = ((_target distance _source) < _distance);
};

_los
