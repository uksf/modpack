#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Captures every connected player's state, so a player who disconnects
        after the save still has current data in it

    Parameter(s):
        None

    Return Value:
        None

    Example:
        call uksf_persistence_fnc_snapshotPlayers
*/

private _startedAt = diag_tickTime;
private _players = call CBA_fnc_players;
{
    [_x, getPlayerUID _x] call FUNC(storePlayerData);
} forEach _players;
INFO_2("Snapshot of %1 players took %2 ms",count _players,round ((diag_tickTime - _startedAt) * 1000));
