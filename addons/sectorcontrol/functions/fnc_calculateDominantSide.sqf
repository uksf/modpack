#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Sorts the array of entities in area and works out who is more dominant - daddy.

    Parameters:
        0: list of entities in the radius <ARRAY>
        1: percentage for dominance <FLOAT>

    Return value:
        Nothing
*/

params ["_logic", "_entities", "_requiredDominance"];

if !(isServer) exitWith {};

// get all the men
private _men = _entities select {_x isKindOf "Man"} apply {[_x, side _x]}; // [object, side]

// work out their side
// private _menBluFor = _men select {_x#1 isEqualTo WEST};

private _opforMenCount = {_x#1 isEqualTo EAST} count _men;
private _bluforMenCount = {_x#1 isEqualTo WEST} count _men;

// get sector owner
private _currentOwner = _logic getVariable [QGVAR(currentOwner), 2]; // 2 = No one

// workout required dominance, quick maffs
private _requiredNumberToDominateOpfor = ceil((_opforMenCount) * (1 + _requiredDominance)); // e.g. 12×1.25=15
private _requiredNumberToDominateBlufor = ceil((_bluforMenCount) * (1 + _requiredDominance));
private _currentNumberBlufor = _bluforMenCount;
private _currentNumberOpfor = _opforMenCount;

// no dominance, do nothing
if !(_currentNumberBlufor >= _requiredNumberToDominateOpfor || _currentNumberOpfor >= _requiredNumberToDominateBlufor) exitWith {};

// allow capture if the dominant side is different from the current owner
if ((_currentNumberBlufor >= _requiredNumberToDominateOpfor) && (_currentOwner != 1)) exitWith {
    _logic setVariable [QGVAR(dominantSide), 1, true];
    [_logic, 1] call FUNC(showSectorAsContested);
};

if (_currentNumberOpfor >= _requiredNumberToDominateBlufor && (_currentOwner != 0)) exitWith {
    _logic setVariable [QGVAR(dominantSide), 0, true];
    [_logic, 0] call FUNC(showSectorAsContested);
};

_logic setVariable [QGVAR(dominantSide), _currentOwner, true];
