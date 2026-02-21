#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Receives rebro signal report from a client and stores for visualisation providers.

    Parameter(s):
        0: Player <OBJECT>
        1: Position <ARRAY>
        2: Signal log <HASHMAP> - rebro connections
        3: Network log <HASHMAP> - full mesh data

    Return Value:
        None
*/
if (!isServer) exitWith {};

params ["_player", "_position", "_signalLog", "_networkLog"];

GVAR(visualiseRebroReports) set [getPlayerUID _player, [_player, _position, name _player, _signalLog, _networkLog, CBA_missionTime]];

// Clean stale reports (older than 10s)
private _staleKeys = [];
{
    private _report = GVAR(visualiseRebroReports) get _x;
    if (CBA_missionTime - (_report#5) > 10) then {
        _staleKeys pushBack _x;
    };
} forEach keys GVAR(visualiseRebroReports);
{GVAR(visualiseRebroReports) deleteAt _x} forEach _staleKeys;
