/*
	Author:
		Tim Beswick

	Description:
		Initialises respawn EH for player

	Parameter(s):
		0: Unit <OBJECT>

	Return Value:
		None
*/
#include "script_component.hpp"

params ["_unit"];

if (local _unit) then {
	_action = [QGVAR(zeusMainAction), QUOTE(Zeus), ZEUS_ICON, {}, {true}, {call FUNC(getChildren)}] call ace_interact_menu_fnc_createAction;
	_path = [_unit, 1, ["ACE_SelfActions"], _action] call ace_interact_menu_fnc_addActionToObject;
};