#include "script_component.hpp"


["CBA_BuildingPos", "initPost", {
	params ["_pos"];

	GVAR(aiBuildingPositions) pushBack (getPosATL _pos);
}, true] call CBA_fnc_addClassEventHandler;

