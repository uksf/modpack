/*
	Author:
		Tim Beswick

	Description:
		Opens zeus login menu

	Parameter(s):
		None

	Return Value:
		None
*/
#include "script_component.hpp"

if(name player != GETMVAR(GVAR(curatorName),"")) then {
	GVAR(screenState) = 0;
} else {
	if(GVAR(screenState) == 0) then {
		GVAR(screenState) = 1;
	};
};
INFO_1("Screen state: %1", GVAR(screenState));

switch (GVAR(screenState)) do {
	case 0: {
		if(dialog) then {
			closeDialog 0;
		};
		INFO("Opening login menu");
		createDialog GVAR(login);
	};
	case 1: {
		INFO("Opening main menu");
		createDialog GVAR(menu);
	};
};
GVAR(screenState) = 0;