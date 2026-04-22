#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Can use load into cargo context action

    Parameter(s):
        0: Action Parameters

    Return Value:
        Boolean

    Example:
        [_selectedObjects, _selectedGroups] call uksf_zeus_fnc_contextCanLoadIntoCargo
*/
params ["", "_selectedObjects"];

if !(ace_cargo_enable) exitWith {false};

if (_selectedObjects isEqualTo []) exitWith {false};

_selectedObjects findIf {!alive _x || {isPlayer _x}} == -1
