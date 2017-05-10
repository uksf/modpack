
/*
    Author:
        Adam Bridgford, Tim Beswick

    Description:
        Checks if unit is alive.
        
    Parameter(s):
        0: Unit hit <OBJECT>
        1: Object causing the damage <OBJECT>
        2: Damage dealt <SCALAR>
        3: Unit causing the damage <SCALAR>
        
    Return Value:
        Nothing
*/

#include "script_component.hpp"


params ["_unit", "", "", "_instigator"];

if (!alive _unit ||
   {!((side _unit) isEqualTo east)}
) exitwith {};
hint "3";

params ["_unit","_instigator"];

    if (alive _unit) then {
        hint "unit alive";
        _this call FUNC(rf_returnFire);
    };
