/*
    Author:
        Tim Beswick

    Description:
        Toggles the side rleation between Indep and Blufor

    Parameter(s):
        0: The module logic <OBJECT>
        1: Synchronized units <ARRAY>
        2: Activated <BOOL>

    Return Value:
        None
*/
#include "script_component.hpp"

params ["_logic", "_units", "_activated"];

if !(_activated && local _logic) exitWith {};

private _sides = getArray (configFile >> "CfgVehicles" >> typeOf _logic >> QGVAR(sides));
_sides params ["_side1", "_side2"];
_side1 = call compile _side1;
_side2 = call compile _side2;

private _message = "%1 is now FRIENDLY to %2";
private _value = if ((_side1 getFriend _side2) < 0.6) then {
    1 // Is enemy, set friend
} else {
    _message = "%1 is now HOSTILE to %2";
    0 // Is friend, set enemy
};
[QEGVAR(common,setSideRelation), [_side1, _side2, _value]] call CBA_fnc_serverEvent;
[QEGVAR(common,setSideRelation), [_side2, _side1, _value]] call CBA_fnc_serverEvent;
[format [_message, _side1, _side2]] call ace_common_fnc_displayTextStructured;

deleteVehicle _logic;
