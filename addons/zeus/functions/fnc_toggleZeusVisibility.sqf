////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	AUTHOR: by 
//	DATE: 1/4/17
//	VERSION: 2.0
//  DESCRIPTION: Function for module "hide zeus"
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
    Author:
        Anton Struyk, Kex, Tim Beswick

    Description:
        Toggles visibility of curator

    Parameter(s):
        None

    Return Value:
        None
*/
#include "script_component.hpp"
#include "\achilles\modules_f_ares\module_header.hpp"

private _text = "Zeus is now hidden";
if (!(isObjectHidden player)) then  {
	[player, true] remoteExec ["hideObjectGlobal",2];
	player allowDamage false;
	player setCaptive true;
} else {
	if (isObjectHidden player) then {
		[player, false] remoteExec ["hideObjectGlobal",2];
		player allowDamage true;
		player setCaptive false;
		_text = "Zeus is now visible";
	};
};

[_text] call Ares_fnc_ShowZeusMessage;

#include "\achilles\modules_f_ares\module_footer.hpp"
