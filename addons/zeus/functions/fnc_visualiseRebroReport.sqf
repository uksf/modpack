#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Receives rebro signal report from a client and stores for visualisation providers.

    Parameter(s):
        0: Player <OBJECT>
        1: Position <ARRAY>
        2: Signal log <HASHMAP> - rebro station signal strengths
        3: Connection log <HASHMAP> - player-to-player connection data

    Return Value:
        None
*/
if (!isServer) exitWith {};

params ["_player", "_position", "_signalLog", "_connectionLog"];

GVAR(visualiseRebroReports) set [getPlayerUID _player, [_player, _position, name _player, _signalLog, _connectionLog, CBA_missionTime]];

// Clean stale reports (older than 10s)
private _staleKeys = [];
{
    private _report = GVAR(visualiseRebroReports) get _x;
    if (CBA_missionTime - (_report#5) > 10) then {
        _staleKeys pushBack _x;
    };
} forEach keys GVAR(visualiseRebroReports);
{GVAR(visualiseRebroReports) deleteAt _x} forEach _staleKeys;
