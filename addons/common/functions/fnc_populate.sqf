/*
	Author:
		Tim Beswick

	Description:
		Populates given vehicle with given unit array.
		If turret array is given, units will be removed from the given turret indices

	Parameter(s):
		0: Vehicle <OBJECT>
		1: Units <ARRAY>
		1: Turrets <ARRAY> (Optional)
		1: Side <SCALAR> (Optional)

	Return Value:
		Nothing
*/
#include "script_component.hpp"

params [["_vehicle", objNull], ["_units", []], ["_turrets", []], ["_side", 0]];

if (isServer) then {
	[{
		params ["_vehicle", "_units", "_turrets", "_side"];
		if (!isNull (driver _vehicle)) then {
			_side = switch (_side) do {
				case 0: {east};
				case 1: {west};
				case 2: {resistance};
				case 3: {civilian};
				default {sideUnknown};
			};
			_men = [[0,0,0], _side, _units] call BIS_fnc_spawnGroup;
			[units _men] call Ares_fnc_AddUnitsToCurator;

			[{
				params ["_vehicle", "_men", "_turrets"];
				{
					_x moveincargo _vehicle;
				} forEach (units _men);

				if (count _turrets > 0) then {
					[{
						params ["_vehicle", "_turrets"];
						{
							[_vehicle turretUnit [_x]] join grpNull;
							deleteVehicle (_vehicle turretUnit [_x]);
						} forEach _turrets;
					}, [_vehicle, _turrets], 2] call CBA_fnc_waitAndExecute;
				};
			}, [_vehicle, _men, _turrets], 2] call CBA_fnc_waitAndExecute;
		};
	}, [_vehicle, _units, _turrets, _side], 2] call CBA_fnc_waitAndExecute;
};