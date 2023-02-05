#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
       Gets vehicle details

    Parameters:
        0: group <OBJECT>

    Return value:
        _unitDetails
*/
params ["_group"];

// get group composition
private _unitDetails = [];

{
    private _unit = _x;
    private _unitDetailsInner = [];
    // push back unit types
    _unitDetailsInner pushBack (typeOf _x);

    // get unit loadouts
    // private _unitLoadout = getUnitLoadout _x;
    // _unitDetails pushBack _unitLoadout;

    _unitDetailsInner pushBack (getPosATL _unit);

    _unitDetailsInner pushBack (getDir _unit);

    _unitDetailsInner pushBack (_unit skill "general");

    _unitDetailsInner pushBack (behaviour _unit);

    _unitDetailsInner pushBack (AI_FEATURES select {!(_unit checkAIFeature _x)}); // e.g. ["PATH", "FSM"]

    // stores vehicle details if present, has to be run per unit
    if !(isNull assignedVehicle _x) then {
        _unitDetailsInner pushBack (typeOf assignedVehicle _x);
        _unitDetailsInner pushBack (assignedVehicleRole _x);
        _unitDetailsInner pushBack (getPosATL vehicle _x);
        _unitDetailsInner pushBack (isEngineOn vehicle _x);
        _unitDetailsInner pushBack (getDir vehicle _x);
    };

    _unitDetails pushBack _unitDetailsInner;

} forEach units _group;

_unitDetails
