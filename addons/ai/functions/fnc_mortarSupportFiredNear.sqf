/*
    Author:
        Adam Bridgford

    Description:
        FiredNear EH fnc. Sets a cooldown so requests are made every 15secs.
        Then does a check if mortar unit and RTO are alive.

    Parameter(s):
        0: Unit <OBJECT>

    Return Value:
        Nothing
*/

hint "firedNear fnc fired";
if (!(_unit getVariable [QGVAR(unitCooldown), false])) then {
        _unit setVariable [QGVAR(unitCooldown), true];
        [{(_this select 0) setVariable [QGVAR(unitCooldown), false];}, [_unit], 15] call CBA_fnc_waitAndExecute;

        if (alive mortar1) then {
            if (alive RTO) then {
                call fnc_mortarIsKindOf;
        };
    } else {
        exitWith {};
    };
};

