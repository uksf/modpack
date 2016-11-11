/*
    Author:
    	Tim Beswick

    Description:
    	Uncaches unit

    Parameters:
    	0: Unit to be uncached <OBJECT>

    Return value:
    	Nothing
*/
#include "script_component.hpp"

params ["_unit", "_pos"];

if (!isPlayer _unit && !(_unit isEqualTo leader _unit) && {!("driver" in assignedVehicleRole _unit)} && alive _unit) then {
	_unit enableSimulationGlobal true;
	_unit hideObjectGlobal false;
	if (vehicle _unit isEqualTo _unit) then {
		detach _unit;
		_position = ((leader _unit) modelToWorldVisual (_unit getVariable [QGVAR(cachedPosition), [random 10,random 10,0]]));
		if (count (lineIntersectsObjs [ATLToASL _position vectorAdd [0,0,1.8], [ATLToASL _position select 0, ATLToASL _position select 1, 0], objNull, objNull, false, 32]) == 0) then {
			_position set [2, 0];
		};
		_unit setPosATL _position;
	};
};