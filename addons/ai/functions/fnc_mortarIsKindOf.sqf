/*
    Author:
        Adam Bridgford

    Description:
        Checks what kind of unit caller is then adds appropiate delay

    Parameter(s):
        0: Unit <OBJECT>

    Return Value:
        Nothing
*/

#include "script_component.hpp"

params ["_unit"];
diag_log format ["Unit 2: %1", _unit];

if (_unit isKindOf "CUP_O_RU_RTO_Flora") then {
    [{_this call FUNC(mortarFire)}, [_unit], 90] call CBA_fnc_waitAndExecute;
    } else {
        [{_this call FUNC(mortarFire)}, [_unit], 150] call CBA_fnc_waitAndExecute;
    };
