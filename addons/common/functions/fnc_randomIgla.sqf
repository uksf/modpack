/*
	Author:
		Tim Beswick

	Description:
		1 in 200 chance of giving RPG unit an IGLA

	Parameter(s):
		0: Unit <OBJECT>

	Return Value:
		Nothing
*/
#include "script_component.hpp"

params ["_unit"];

if ((isServer && !hasInterface) || !isMultiplayer) then {
	if ((random 200) == 1) then {
		if (_unit isKindOf "Laraka_RPG" || _unit isKindOf "Azaadi_RPG") then {
			_unit removeWeapon "rhs_weap_rpg7";
			removeBackpack _unit;

			_unit addWeapon "rhs_weap_igla";
			_unit addBackpack "Laraka_B_AA";
		};
	};
};
