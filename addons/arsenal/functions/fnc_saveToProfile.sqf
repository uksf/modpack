/*
	Author:
		Tim Beswick

	Description:
		Saves given data to profileNamespace and returns save data.

	Parameter(s):
		0: Data to save <ARRAY>

	Return Value:
		Saved data <ARRAY>
*/
#include "script_component.hpp"

params ["_data"];

profilenamespace setvariable ["bis_fnc_saveInventory_data", _data];
profilenamespace setvariable ["bis_fnc_saveInventory_profile", true];
if !(isnil {profilenamespace getvariable "bis_fnc_saveInventory_profile"}) then {saveprofilenamespace};

profilenamespace getvariable ["bis_fnc_saveInventory_data", []]
