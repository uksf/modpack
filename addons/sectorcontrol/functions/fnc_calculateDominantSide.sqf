#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Counts east and west men among the entities in the sector and stores the dominant side on the logic as a number: 0 east, 1 west, 2 no dominance.

    Parameters:
        0: The sector module logic <OBJECT>
        1: List of entities in the sector <ARRAY>
        2: Fraction by which one side must outnumber the other <NUMBER>

    Return value:
        Nothing

    Example:
        [_logic, _entities, _requiredDominance] call uksf_sectorcontrol_fnc_calculateDominantSide
*/

params ["_logic", "_entities", "_requiredDominance"];

if !(isServer) exitWith {};

private _men = _entities select {_x isKindOf "Man"} apply {[_x, side _x]};
private _opforMenCount = {_x#1 isEqualTo east} count _men;
private _bluforMenCount = {_x#1 isEqualTo west} count _men;

_logic setVariable [QGVAR(dominantSide), 2, true];
if (_opforMenCount + _bluforMenCount == 0) exitWith {};

private _currentOwner = _logic getVariable [QGVAR(currentOwner), 2];

private _requiredNumberToDominateOpfor = ceil((_opforMenCount) * (1 + _requiredDominance));
private _requiredNumberToDominateBlufor = ceil((_bluforMenCount) * (1 + _requiredDominance));

if !(_bluforMenCount >= _requiredNumberToDominateOpfor || _opforMenCount >= _requiredNumberToDominateBlufor) exitWith {};

if ((_bluforMenCount >= _requiredNumberToDominateOpfor) && (_currentOwner != 1)) exitWith {
    _logic setVariable [QGVAR(dominantSide), 1, true];
    [_logic, 1] call FUNC(showSectorAsContested);
};

if (_opforMenCount >= _requiredNumberToDominateBlufor && (_currentOwner != 0)) exitWith {
    _logic setVariable [QGVAR(dominantSide), 0, true];
    [_logic, 0] call FUNC(showSectorAsContested);
};

_logic setVariable [QGVAR(dominantSide), _currentOwner, true];
