/*
    Author:
    	Nicholas Clark & Tim Beswick

    Description:
    	Add eventhandler for cached group's leader

    Parameters:
    	0: Leader of cached group <OBJECT>

    Return value:
    	Nothing

    Called from:
    	cache;
*/
params ["_unit"];

if (_unit isEqualTo leader _unit && {!(_unit getVariable ["UKSF_Mission_leaderHasEH",false])}) exitWith {
	_unit setVariable ["UKSF_Mission_leaderHasEH",true];

	// if leader is killed, setup new leader
	_unit addEventHandler ["killed", {
		if (group (_this select 0) in UKSF_Mission_groups && {leader (_this select 0) isEqualTo (_this select 0)} && {count units group (_this select 0) >= 2}) then {
			[
				{!((leader (_this select 0)) isEqualTo (_this select 1))},
				{
					_newLeader = leader (_this select 0);
					[_newLeader] call FUNC(uncache;
					[_newLeader] call FUNC(addEventhandler;
				},
				[group (_this select 0),_this select 0]
			] call CBA_fnc_waitUntilAndExecute;
		};
	}];

	// if leader exits vehicle while group is cached, move group out of vehicle and move to leader
	if !((vehicle _unit) isEqualTo _unit) then {
		(vehicle _unit) addEventHandler ["GetOut", {
			if (group (_this select 2) in UKSF_Mission_groups) then {
				group (_this select 2) leaveVehicle (_this select 0);
			};
		}];
	};
};

if !(_unit getVariable ["UKSF_Mission_UnitHasEH",false]) exitWith {
	_unit setVariable ["UKSF_Mission_UnitHasEH",true];
	_unit addEventHandler ["killed", {
		[_this select 0] call FUNC(uncache;
	}];
};
