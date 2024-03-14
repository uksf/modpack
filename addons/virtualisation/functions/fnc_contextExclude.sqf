#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Virtualisation exclude context action

    Parameter(s):
        0: Action Parameters

    Return Value:
        None
*/
params ["", ["_selectedObjects", []], ["_selectedGroups", []]];

if (_selectedObjects isNotEqualTo []) then {
    {
        _selectedGroups pushBackUnique (group _x);
    } forEach (_selectedObjects select {_x isKindOf "CAManBase" && alive _x && !isPlayer _x});
};

if (_selectedGroups isNotEqualTo []) exitWith {
    _selectedGroups = _selectedGroups select {({alive _x && !isPlayer _x} count (units _x)) > 0};

    private _anyIncluded = [_selectedGroups, {!(_x getVariable [QEGVAR(virtualisation,excluded), false])}] call EFUNC(common,arrayAny); // At least 1 included = true
    private _event = [QEGVAR(virtualisation,include), QEGVAR(virtualisation,exclude)] select _anyIncluded; // If any included, exclude
    {
        [_event, _x] call CBA_fnc_serverEvent;
    } forEach _selectedGroups;
};
