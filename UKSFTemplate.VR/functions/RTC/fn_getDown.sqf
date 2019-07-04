#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        AI lie down if speed greater than 1kmh

    Parameters:
        0: UNIT <OBJECT>
        
    Return value:
        Nothing
*/

params ["_unit","_causedBy","_damage","_shooter"];

private _group = group _unit;

if (speed _unit < 1) exitWith {};
if ((group _unit) getVariable [QGVAR(down), false]) exitWith {hint "already down"};

if (alive _unit) then {
	
	{_x setUnitPos "DOWN"} forEach units _group; 
	_group setSpeedMode "FULL";
	_group setCombatMode "RED";
	(group _unit) setVariable [QGVAR(down), true, true];
	
};

[{
	params ["_shooter","_group"];
	
	{_x setUnitPos "MIDDLE"} forEach units _group; 
	{["ace_zeus_suppressiveFire", [_x, (getPosASL _shooter), ""], _x] call CBA_fnc_targetEvent;} foreach units _group;
	(group _unit) setVariable [QGVAR(down), false, true];
	_group setCombatMode "YELLOW";
	
},[_shooter,_group], 30] call CBA_fnc_waitAndExecute;
