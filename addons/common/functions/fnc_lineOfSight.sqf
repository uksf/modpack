/*
    Author:
        Nicholas Clark & Tim Beswick

    Description:
        Check if in position in line of sight

    Parameters:
        0: Unit to check <OBJECT>
        1: Unit to check line of sight for <OBJECT>

    Return value:
        Boolean
*/
#include "script_component.hpp"

params ["_target", "_source"];

[getPosASL _source, getDir _source, 70, position _target] call BIS_fnc_inAngleSector && 
[_source, "VIEW"] checkVisibility [eyePos _source, eyePos _target] > 0
