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

    Example:
        [_unit] call uksf_zir_fnc_surrenderCheck
*/
params ["_unit"];

if (!isServer) exitWith {};

_unit addMPEventHandler ["MPKilled", {
    if (!isServer) exitWith {};
    params ["_unit", "_killer", "_instigator", "_useEffects"];

    private _group = group _unit;
    if (_group getVariable [QGVAR(groupSurrendered), false]) exitWith {};

    private _unitsLeft = units _group;
    if (count _unitsLeft < 1) exitWith {};

    private _pgBaseClass = QGVAR(Soldier_Base_Puritan_Guard);
    if (typeOf _unit == _pgBaseClass) exitWith {};
    if (!isPlayer _killer) exitWith {};

    private _pgIndex = _unitsLeft findIf {_x isKindOf _pgBaseClass};
    if (_pgIndex > -1) exitWith {};

    if (count _unitsLeft <= 3) then {
        _group setVariable [QGVAR(groupSurrendered), true, true];
        {
            private _rng = random 10;
            if (_rng < 7) then {
                [QGVAR(setSurrendered), [_x, true], _x] call CBA_fnc_targetEvent;
            };
        } forEach _unitsLeft;
    };
}];
