
/*
    Author:
        Adam Bridgford, Tim Beswick

    Description:
        Finds empty statics / vehicle nearby
        
    Parameter(s):
        0: Unit hit <OBJECT>
        1: Object causing the damage <OBJECT>
        2: Damage dealt <SCALAR>
        3: Unit causing the damage <SCALAR>
        
    Return Value:
        Nothing
*/

#include "script_component.hpp"
diag_log "

params ["_unit", "", "", ""];

if (
    !(alive _unit)
) exitWith {};

[{
    params ["_unit"];

    if (alive _unit) then {
        _emptyVic = (getPosATL _unit) nearEntities ["Car",30];
        diag_log _emptyVic;
        _crew = fullCrew [_vehicle, "gunner"];
        diag_log _crew;

    };
}];
    


