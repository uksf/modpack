/*
    Author:
        Adam Bridgford

    Description:
        FiredNear EH fnc. Sets a cooldown so requests are made every 15secs.
        Then does a check if mortar unit and RTO are alive.
        Requires a mortar called mortar1 and an RTO called RTO

    Parameter(s):
        0: Unit <OBJECT> (fired at)

    Return Value:
        Nothing
*/

#include "script_component.hpp"

params ["_unit"];

if (!((side _unit) isEqualTo east)) exitWith {};

if (!(_unit getVariable [QGVAR(unitCooldown), false])) then {
        _unit setVariable [QGVAR(unitCooldown), true];
        [{(_this select 0) setVariable [QGVAR(unitCooldown), false];}, [_unit], 15] call CBA_fnc_waitAndExecute;

        if (!alive mortar1) exitWith {};
            if (alive RTO) then {
                [_unit] call FUNC(mortarIsKindOf);
        };
    };
