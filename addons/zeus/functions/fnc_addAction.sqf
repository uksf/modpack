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

_action = ["OpenZeusMenu", "Open Zeus Menu", "\A3\Ui_F_Curator\Data\Logos\arma3_zeus_icon_ca.paa", {call FUNC(openMenu)}, {true}] call ace_interact_menu_fnc_createAction;
_path = [_unit, 1, ["ACE_SelfActions"], _action] call ace_interact_menu_fnc_addActionToObject;

INFO_2("Respawned, action added: %1, at path %2", _action select 0, _path);