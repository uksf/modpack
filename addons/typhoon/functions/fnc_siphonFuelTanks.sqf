/***********************************************
Siphon tanks script by HCPOOKIE

Activated by user action.

 - Dynamically adds a percentage of fuel.
 - Animates cockpit status indicator

Accounts for Jets DLC dynamic loadout options
***********************************************/
/*
    Author:
        Tim Beswick

    Description:
        Toggles unit cache state

    Parameter(s):
        0: The module logic <OBJECT>
        1: Synchronized units <ARRAY>
        2: Activated <BOOL>

    Return Value:
        None
*/
#include "script_component.hpp"

private ["_v","_W","_C"];
_v = _this select 0;
_W = 0;
_C = 0;

// count fuel tanks on plane
{
    if ((_x select 0) isEqualTo "EF2K_fueltank") then {
        _W = _W + (_x select 1) param [0,0];
    };
} forEach magazinesAmmoFull _v;

{
    if ((_x select 0) isEqualTo "EF2K_CL_fueltank") then {
        _C = _C + (_x select 1) param [0,0];
    };
} forEach magazinesAmmoFull _v;

if ((_C < 1) && (_W < 1)) exitWith {_v vehicleChat "No fuel tanks found";};

// for each tank:
// - Adds percentage of fuel 
while {_W > 0} do {
	_v SetFuel ((Fuel _v) * 2); // 1.25
	_W = _W -1;
};

while {_C > 0} do {
	_v SetFuel ((Fuel _v) * 2.2); // 1.5
	_C = _C -1;
};

_v animate ['tank_switch',0.5];
_v animate ['tank_switch_ind',0];
_v vehicleChat format ["Fuel Tanks Siphoned. Remaining Fuel: %1",(Fuel _v)];
