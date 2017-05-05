/*
    Author:
        Adam Bridgford, Tim Beswick

    Description:
        Requests artillery support on nearest enemy position.
        
        ///////////////////////////////////////////////////////////////////////////////////////////////
        Still relies on static RTO and mortar1 units and custom designation of ammo type.
        ///////////////////////////////////////////////////////////////////////////////////////////////

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

if (
    !(local _unit) ||
    {!((side _unit) isEqualTo east)} ||
    {!(alive RTO1)} ||
    {!(alive mortar1)} ||
    {mortar1 getVariable [QGVAR(cooldown), false]} ||
    {_unit getVariable [QGVAR(cooldown), false]} ||
    {(_unit distance2D _instigator) < 150}
) exitWith {};

[{
    params ["_unit", "_instigator"];

    if (alive _unit) then {
        _unit setVariable [QGVAR(cooldown), true];
        [{(_this select 0) setVariable [QGVAR(cooldown), false];}, [_unit], 120] call CBA_fnc_waitAndExecute;
        mortar1 setVariable [QGVAR(cooldown), true];
        [{(_this select 0) setVariable [QGVAR(cooldown), false];}, [mortar1], 300] call CBA_fnc_waitAndExecute;

        private _position = [getPosATL _instigator, 100] call CBA_fnc_randPos;
        [{
            mortar1 commandArtilleryFire [(_this select 0), "CUP_40Rnd_GRAD_HE", (floor random [1,2,4])];
        }, [_position], 120] call CBA_fnc_waitAndExecute;
    };
}, [_unit, _instigator], 2] call CBA_fnc_waitAndExecute;    
