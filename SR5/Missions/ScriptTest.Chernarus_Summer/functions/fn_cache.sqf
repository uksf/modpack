/*
    Author:
    	Nicholas Clark & Tim Beswick

    Description:
    	Caches unit

    Parameters:
    	0: Unit to be cached <OBJECT>

    Return value:
    	Nothing

    Called from:
    	Caching PFH;
*/
params ["_unit"];

if (!isPlayer _unit && {!("driver" in assignedVehicleRole _unit)}) then {
	_unit enableSimulationGlobal false;
	_unit hideObjectGlobal true;
	[_unit] call UKSF_Mission_fnc_addEventhandler;
	if (vehicle _unit isEqualTo _unit && {vehicle (leader _unit) isEqualTo (leader _unit)}) then {
		_unit attachTo [leader _unit];
	};
};
