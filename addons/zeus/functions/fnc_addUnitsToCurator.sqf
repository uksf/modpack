#include "script_component.hpp"
/*
    Author:
        Kex, Tim Beswick

    Description:
        Adds (or removes) a set of objects to all of the curator modules that are active.

    Parameter(s):
        0: Objects <ARRAY>
        1: Add or remove <BOOL>

    Return Value:
        None
*/

params [["_unitsToModify", [], [[]]], ["_addToCurator", true, [true]]];

if (isNil "Ares_addUnitsToCuratorFunction") then {
    Ares_addUnitsToCuratorFunction = {
        if (_this select 1) then {
            {
                [_x, (_this select 0)] spawn {
                    (_this select 0) addCuratorEditableObjects [(_this select 1), true];
                    (_this select 0) removeCuratorEditableObjects [allCurators, true];
                };
                false
            } count allCurators;
        } else {
            {_x removeCuratorEditableObjects [(_this select 0), true]; false} count allCurators;
        };
    };
    publicVariable "Ares_addUnitsToCuratorFunction";
};

[[_unitsToModify, _addToCurator], "Ares_addUnitsToCuratorFunction", false] call BIS_fnc_MP;
true
