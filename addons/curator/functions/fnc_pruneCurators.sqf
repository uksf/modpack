#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Removes deleted curators from the curator slots on the server
        Drops each deleted curator together with its player name, so curatorObjects and curatorPlayers stay aligned by index

    Parameter(s):
        None

    Return Value:
        None

    Example:
        call uksf_curator_fnc_pruneCurators
*/

private _liveIndexes = [];
{
    if (!isNull _x) then {
        _liveIndexes pushBack _forEachIndex;
    };
} forEach GVAR(curatorObjects);

GVAR(curatorPlayers) = _liveIndexes apply {GVAR(curatorPlayers) param [_x, ""]};
GVAR(curatorObjects) = _liveIndexes apply {GVAR(curatorObjects) select _x};
publicVariable QGVAR(curatorObjects);
publicVariable QGVAR(curatorPlayers);
