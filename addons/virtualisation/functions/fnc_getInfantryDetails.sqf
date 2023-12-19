#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
       Gets unit details for each unit in the group and returns an array

    Parameters:
        0: Group <GROUP>
        1: Vehicles <ARRAY>

    Return value:
        Array of unit details <ARRAY>
        [[_type, _position, _direction, _skill, _behaviour, _disabledFeatures, _stance], [...]]
*/
params ["_group", ["_vehicles", []]];

// Only get units that are not already accounted for in vehicle details
private _units = (units _group) select {
    private _unit = _x;

    alive _unit
    && [_vehicles, {vehicle _unit == _x}] call EFUNC(common,arrayNone)
};

_units apply {
    private _unit = _x;

    private _type = typeOf _unit;
    private _position = getPosASL _unit;
    private _direction = getDir _unit;
    private _stance = unitPos _unit;
    private _skill = _unit skill "general";
    private _behaviour = behaviour _unit;
    private _disabledFeatures = AI_FEATURES select {!(_unit checkAIFeature _x)}; // e.g. ["PATH", "FSM"]

    [_type, _position, _direction, _stance, _skill, _behaviour, _disabledFeatures]
}
