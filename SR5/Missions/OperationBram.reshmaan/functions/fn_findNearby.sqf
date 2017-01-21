params ["_unit", "", "", "_shooter"];

if (isPlayer _unit) exitWith {};

_side = side _unit;
_nearestUnits = (getPos _unit) nearEntities [["Man"], 500];

if (_side countSide _nearestUnits > 0) then {
	{
		if ((side _x == _side) && (group _x != group _unit) && !(behaviour leader (group _x) isEqualTo "COMBAT") && (_x == leader group _x) 
			&& !(_x getVariable ["noRadio", false]) && !((group _x) getVariable ["Tasked", false])) then {			
			(group _x) setVariable ["Tasked", true, true];
			[group _x, getpos _shooter, 50, true] call CBA_fnc_taskAttack;
			[group _x, 1] setWaypointStatements ["true", "[this] call UKSF_Mission_fnc_reTasking"];
		};
		false
	} count _nearestUnits;
};
