/*
	Author:
		Tim Beswick

	Description:
		Checks if unit has no uniform

	Parameter(s):
		0: Unit <OBJECT>

	Return Value:
		None
*/
#include "script_component.hpp"

params ["_unit"];

[{
	params ["_args"];
	_args params ["_unit"];

	if (isPlayer _unit || isNull _unit || !alive _unit ||
		damage _unit > 0.1 || !local _unit) exitWith {};

	_currentUniform = uniform _unit;
	_currentWeapon = primaryWeapon _unit;
	_config = configFile >> "CfgVehicles" >> typeOf _unit;
	_uniform = getText (_config >> "uniformClass");
	_weapon = (getArray (_config >> "weapons")) select {_x != "Throw" && _x != "Put"};

	if ((_currentUniform == "" && _uniform != "") || (_currentWeapon == "" && count _weapon > 0)) then {
		_leader = leader _unit;
		_type = typeOf _unit;
		_pos = getPos _unit;
		_dir = direction _unit;
		_group = if (!isNull _leader && _leader != _unit) then {
			group _leader
		} else {
			_side = switch (getNumber (_config >> "side")) do {
				case 0: {east};
				case 1: {west};
				case 2: {resistance};
				case 3: {civilian};
				default {sideUnknown};
			};
			createGroup _side
		};
		_vehicle = if (vehicle _unit != _unit) then {
			vehicle _unit
		} else {
			_unit
		};

		deleteVehicle _unit;
		_unit = _type createUnit [[0,0,0], _group];
		if (_vehicle == _unit) then {
			_unit moveInAny _vehicle;
		} else {
			_unit setPos _pos;
			_unit setDir _dir;
		};
	};
}, [_unit], 30] call CBA_fnc_waitAndExecute;
