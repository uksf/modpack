/*
	Author:
		Tim Beswick

	Description:
		Adds eyewear to genfor

	Parameter(s):
		0: Unit <OBJECT>

	Return Value:
		Nothing
*/
#include "script_component.hpp"

params ["_unit"];

if (isServer) then {
	if (_unit isKindOf "GENFOR_P") exitWith {};
	if (_unit isKindOf "GENFOR_FP") exitWith {};

	removeGoggles _unit;

	_sunglasses = [
		"G_Lowprofile",
		"G_Tactical_Clear",
		"G_Aviator",
		"G_Shades_Black",
		"G_Shades_Blue",
		"G_Shades_Green",
		"G_Shades_Red",
		"G_Sport_Blackred",
		"G_Sport_BlackWhite",
		"G_Sport_Blackyellow",
		"G_Sport_Checkered",
		"G_Sport_Greenblack",
		"G_Sport_Red",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		""
	];
	_count = count _sunglasses;
	_unit addGoggles (selectRandom _sunglasses);

	if (_unit isKindOf "GENFOR_O") then {
		removeGoggles _unit;
		_unit addGoggles "G_Aviator";
	};
};