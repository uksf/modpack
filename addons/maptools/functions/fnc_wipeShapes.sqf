#include "script_component.hpp"
/*
    Author:
        Beswick.T

    Description:
        Deletes every shape marker emitted this session by this player.

    Parameter(s):
        None

    Return Value:
        None

    Example:
        call uksf_maptools_fnc_wipeShapes
*/
{ deleteMarker _x } forEach GVAR(playerShapes);
GVAR(playerShapes) = [];
