#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Checks if unit can static line jump from plane

    Parameter(s):
        0: Vehicle <OBJECT>
        1: Unit <OBJECT>

    Return Value:
        Boolean
*/
params ["_vehicle", "_unit"];

(_vehicle getCargoIndex _unit) >= 0 &&
{(getPosATL _vehicle)#2 > STATIC_LINE_MINIMUM_ALTITUDE} &&
{(backpack _unit) == "ACE_NonSteerableParachute"}
