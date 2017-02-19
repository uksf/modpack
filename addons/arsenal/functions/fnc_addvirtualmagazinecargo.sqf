/*
    Author: 
        Karel Moricky, edited by Tim Beswick for UKSF usage

    Description:
        Add virtual magazines to an object (e.g., ammo box).
        Virtual items can be selected in the Arsenal.

    Parameter(s):
        0: OBJECT - objct to which magazines will be added
        1: STRING or ARRAY of STRINGs - magazine class(es) to be added
        2 (Optional): BOOL - true to add magazines globally (default: false)
        3 (Optional): BOOL - true to add Arsenal action (default: true)

    Returns:
        ARRAY of ARRAYs - all virtual items within the object's space in format [<items>,<weapons>,<magazines>,<backpacks>]
*/
#include "script_component.hpp"

private ["_object","_classes","_isGlobal","_initAction"];
_object = _this param [0,missionnamespace,[missionnamespace,objnull]];
_classes = _this param [1,[],["",true,[]]];
_isGlobal = _this param [2,false,[false]];
_initAction = _this param [3,true,[true]];
[_object,_classes,_isGlobal,_initAction,1,2] call FUNC(addVirtualItemCargo);
