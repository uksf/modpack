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

if (_unit isKindOf ["CUP_O_RU_JTAC_EMR","CUP_O_RU_JTAC_Flora"]) then {
    hint "Is kind of fired true";
       [{call fnc_mortarFire},[], 90] call CBA_fnc_waitAndExecute;
    } else {
        hint "Is kind of fired false";
        [{call fnc_mortarFire},[], 120] call CBA_fnc_waitAndExecute;
    };
