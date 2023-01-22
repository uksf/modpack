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

#define AI_FEATURES ["AIMINGERROR", "ANIM", "AUTOCOMBAT", "AUTOTARGET", "CHECKVISIBLE", "COVER", "FSM", "LIGHTS", "MINEDETECTION", "MOVE", "NVG", "PATH", "RADIOPROTOCOL", "SUPPRESSION", "TARGET", "TEAMSWITCH", "WEAPONAIM"]

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
    // diag_log format ["### Caching Unit %1 ###: %2", _x ,_unitLoadout];

    _unitDetailsInner pushBack (getPosATL _unit);

    _unitDetailsInner pushBack (getDir _unit);

    _unitDetailsInner pushBack (_unit skill "general");

    _unitDetailsInner pushBack (behaviour _unit);

    _unitDetailsInner pushBack (AI_FEATURES select {!(_unit checkAIFeature _x)}); // e.g. ["PATH", "FSM"]

    _unitDetails pushBack _unitDetailsInner;

} forEach units _group;

_unitDetails
