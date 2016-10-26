/*
    Author:
    	Tim Beswick

    Description:
    	Caches unit

    Parameters:
    	0: Unit to be cached <OBJECT>

    Return value:
    	Nothing
*/
#include "script_component.hpp"

params ["_unit"];

if (!isPlayer _unit && !(_unit isEqualTo leader _unit) && simulationEnabled _unit && {!("driver" in assignedVehicleRole _unit)} && alive _unit) then {
	_unit enableSimulationGlobal false;
	_unit hideObjectGlobal true;
	[_unit] call FUNC(addEventhandler);
	if (vehicle _unit isEqualTo _unit && {vehicle (leader _unit) isEqualTo (leader _unit)}) then {
		_unit setVariable [QGVAR(cachedPosition), ((leader _unit) worldToModelVisual (getPosATL _unit)), true];
		_unit attachTo [leader _unit, [0,-0.5,0]];
	};
};
