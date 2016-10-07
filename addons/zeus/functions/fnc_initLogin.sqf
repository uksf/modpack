/*
	Author:
		Tim Beswick

	Description:
		Initialises login menu

	Parameter(s):
		None

	Return Value:
		None
*/
#include "script_component.hpp"

_name = GETMVAR(GVAR(curatorName),"");
if(_name == "") then {
	_name = "Not Assigned";
};
ctrlSetText [1020, format ["%1", _name]];