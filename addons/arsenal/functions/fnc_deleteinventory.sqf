/*
	Author: 
		Karel Moricky, edited by Tim Beswick for UKSF usage

	Description:
		Delete loadout saved using BIS_fnc_saveInventory

	Parameter(s):
		0: OBJECT - unit of which loadout will be saved
		1: ARRAY in format
			0: NAMESPACE or GROUP or OBJECT - target in which namespace the loadout is saved
			1: STRING - loadout name

	Returns:
		BOOL
*/
#include "script_component.hpp"

_center = _this param [0,player,[objnull]];
_path = _this param [1,[],[[]]];

[_center,_path,true] call FUNC(saveInventory);
true