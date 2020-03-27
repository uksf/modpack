#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Creates a respawn marker

    Parameters:
        None

    Return value:
        None
*/
params ["_logic", "", "_activated"];

if (_activated) then {
    private _position = position _logic;
    private _marker = createMarker ["respawn_west_" + str _logic, _position];
    private _name = _logic getvariable ["Name", "UKSF"];
    _marker setMarkerType "flag_UK";
    _marker setMarkerText _name;
    GVAR(respawnPositions) pushBack _marker;
};
