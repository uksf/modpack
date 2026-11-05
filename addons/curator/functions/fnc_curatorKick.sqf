#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Kicks player or all players

    Parameter(s):
        0: Kick all <BOOL>
        1: Player <STRING> (Optional)

    Return Value:
        None

    Example:
        [_kickAll, _player] call uksf_curator_fnc_curatorKick
*/
params ["_kickAll", ["_player", ""]];
[player, _kickAll, _player] remoteExecCall [QFUNC(requestKick), 2];
