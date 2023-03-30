#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
       Gets unit details for each unit in the group and returns an array

    Parameters:
        0: group <OBJECT>

    Return value:
        _unitDetails
*/
params ["_group"];

// get group composition
private _unitDetails = [];
private _units = (units _group) select {alive _x};
{
    private _unit = _x;

    private _type = typeOf _unit;
    // private _unitLoadout = getUnitLoadout _x;
    // _unitDetails pushBack _unitLoadout;
    private _position = getPosATL _unit; // TODO: Check compatibility with spawning pos formats, units above water, etc
    private _direction = getDir _unit;
    private _skill = _unit skill "general";
    private _behaviour = behaviour _unit;
    private _disabledFeatures = AI_FEATURES select {!(_unit checkAIFeature _x)}; // e.g. ["PATH", "FSM"]
    private _stance = unitPos _unit;

    _unitDetails pushBack [_type, _position, _direction, _skill, _behaviour, _disabledFeatures, _stance];
} forEach _units;

_unitDetails
