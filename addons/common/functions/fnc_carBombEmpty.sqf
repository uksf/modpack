/*
	Author:
		Tim Beswick

	Description:
		Empty car bomb

	Parameter(s):
		0: Vehicle <OBJECT>
		1: Target side <SIDE>

	Return Value:
		Nothing
*/
#include "script_component.hpp"

params ["_car", "_side"];

if (isServer) then {
	private _distance = 25 + ((random 10) - 5);
	[{
		params ["_args", "_idPFH"];
		_args params ["_car", "_side", "_distance"];

		if ((driver _car) != objNull) then {
			_car deleteVehicleCrew (driver _car);
		};
		_nearUnits = _car nearEntities [["CAManBase", "Car", "Motorcycle", "Tank"], _distance];
		_nearUnits = _nearUnits - [_car];
		{
			if (side _x == _side || side _x == civilian || !alive _x) then {
				_nearUnits = _nearUnits - [_x];
			};
		} forEach _nearUnits;

		if (count _nearUnits != 0) exitWith {	
			[_idPFH] call CBA_fnc_removePerFrameHandler;
			[_car, QEGVAR(common,alarm)] call CBA_fnc_globalSay3d;	
			[{
				params ["_car"];
				_pos = getPos _car;
				"R_TBG32V_F" createVehicle [_pos select 0, _pos select 1, (_pos select 2) + 0.1];
				_car setDamage 1;
			}, [_car], 3] call CBA_fnc_waitAndExecute;
		};	
	}, 5, [_car, _side, _distance]] call CBA_fnc_addPerFrameHandler;
};