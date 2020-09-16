#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        adds waypoints to AI groups to move to staging areas then to nearest type

    Parameters:
        0: Staging area module (staging area position) <POSITION>

    Return value:
        Player position <ARRAY>
*/
params ["_stagingArea"];

if (GVAR(killerPlayers) isEqualTo []) exitWith {
    []
};

private _players = (GVAR(killerPlayers) apply {_x#0}) select {(_stagingArea distance2D _x) < 2000};
if (_players isEqualTo []) exitWith {
    []
};

_players = _players apply {[_stagingArea distance2D _x, _x]};
if (_players isEqualTo []) exitWith {
    []
};

_players sort true;
_players apply {getPos _x#1}
