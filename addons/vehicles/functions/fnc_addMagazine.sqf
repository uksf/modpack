/*
    Author:
        Tim Beswick

    Description:
        Add magazine to turret

    Parameter(s):
        0: Vehicle <OBJECT>
        1: Turret <ARRAY>
        2: Magazine type <STRING>

    Return Value:
        None
*/
#include "script_component.hpp"

params ["_vehicle", "_turret", "_magazine"];
	
private _magazines = getMagazineCargo _vehicle;
private _quantities = (_magazines select 1);
clearMagazineCargoGlobal _vehicle;
	
private _i = 0;
{
	_quantity = _quantities select _i; 
	if (_x isEqualTo _magazine) then {
		_quantity = _quantity - 1;
		if (_quantity > 0) then {
			_vehicle addMagazineCargoGlobal [_x, _quantity];
		};
	} else {
		_vehicle addMagazineCargoGlobal [_x, _quantity];
	};
	_i = _i + 1;
    false	
} count (_magazines select 0);
	
_vehicle removeMagazineTurret [_magazine, _turret];
_vehicle addMagazineTurret [_magazine, _turret];
