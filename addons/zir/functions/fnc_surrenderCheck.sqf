#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Checks if remaining units in a group should surrende
        Uses an MPKilled EH that will check after a unit dies if
        theres 2 unit or less
    Parameter(s):
        0: Unit <OBJECT>
    Return Value:
        Nothing
*/
params ["_unit"];

_unit addMPEventHandler ["MPKilled", {
    params ["_unit", "_killer", "_instigator", "_useEffects"];

    if (!local _unit) exitWith {};

    private _group = group _unit;
    if (_group getVariable [QGVAR(groupSurrendered), false]) exitWith {};

    private _unitsLeft = units _group;
    // exits if group still has no units in it
    if (count _unitsLeft < 1) exitWith {};

    private _pgBaseClass = QGVAR(Soldier_Base_Puritan_Guard);
    if (typeOf _unit == _pgBaseClass) exitWith {};
    if (!isPlayer _killer) exitWith {};

    private _pgIndex = _unitsLeft findIf {_x isKindOf _pgBaseClass};
    // purtian guard still alive so now surrender allowed
    if (_pgIndex > -1) exitWith {};

    // surrender
    if (count _unitsLeft <= 3) then { // needs to be 3 because the killed unit is still in group this soon
        // set a var so if surrendered units are killed, doesn't run again
        _group setVariable [QGVAR(groupSurrendered), true, true];
        {
            // roll the dice
            private _rng = random 10;
            if (_rng < 7) then {
                [_x, true] call ACE_captives_fnc_setSurrendered;
            };
        } forEach _unitsLeft;
    };
}];
