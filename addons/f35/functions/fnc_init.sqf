/*
    Author:
        Tim Beswick, eRazeri, USAF Team

    Description:
        Inits F-35

    Parameters:
        0: Plane <OBJECT>

    Return value:
        Nothing
*/
#include "script_component.hpp"

params ["_plane"];

//TEMPORARY
if (local _plane) exitWith {
    private _position = getPosATL _plane;
    private _vectorDir = vectorDir _plane;
    private _vectorUp = vectorUp _plane;
    deleteVehicle _plane;

    _plane = "B_Plane_Fighter_01_F" createVehicle _position;
    _plane setVectorDir _vectorDir;
    _plane setVectorUp _vectorUp;
};

/*
GVAR(afterBurnerOn) = false;
GVAR(afterBurnerMultiplier) = 0.4;

if (local _plane) then {
    if ((driver _plane) isEqualTo player) then {
        [_plane] call FUNC(getIn);
    };
};*/
