/*
    Author: 
        Karel Moricky, edited by Tim Beswick for UKSF usage

    Description:
        Get virtual backpacks to an object (e.g., ammo box).
        Virtual items can be selected in the Arsenal.

    Parameter(s):
        0: OBJECT

    Returns:
        ARRAY of ARRAYs - all virtual items within the object's space in format [<items>,<weapons>,<magazines>,<backpacks>]
*/
#include "script_component.hpp"

private ["_object"];
_object = _this param [0,missionnamespace,[missionnamespace,objnull]];
[_object,[],false,false,0,3] call FUNC(addVirtualItemCargo);
