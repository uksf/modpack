#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Gets selectable players for global area

    Parameters:
        None

    Return value:
        Array of players and whether they are all valid
        [Players, All players are valid]
*/

// Player can't be in an air vehicle
// AND Player can't be in range of respawn positions
// AND Player can't be in excluded areas
// AND IF include areas exist THEN Player must be in an include area

private _allPlayers = call FUNC(getPlayers);
private _players = _allPlayers select {
    private _player = _x;

    !((vehicle _player) isKindOf "Air")
    && {[EGVAR(common,respawnPositions), {(getMarkerPos _x) distance2D _player <= GVAR(dynamicPatrolSafeZoneDistance)}] call EFUNC(common,arrayNone)}
    && {[GVAR(dynamicPatrolExcludeAreas), {[_player, _x#0, _x#1] call EFUNC(common,objectInArea)}] call EFUNC(common,arrayNone)}
    && {GVAR(dynamicPatrolIncludeAreas) isEqualTo [] || {[GVAR(dynamicPatrolIncludeAreas), {[_player, _x#0, _x#1] call EFUNC(common,objectInArea)}] call EFUNC(common,arrayAny)}}
};
TRACE_1("5) Dynamic spawn resolved players",_players);
if (_players isEqualTo []) exitWith {
    [[], true]
};

// Get only awake and conspicuous players
private _validPlayers = _players select {
    private _player = _x;

    [_player] call ace_common_fnc_isAwake && {!(QGVAR(conspicuous) in (([_player, "setCaptive"] call ace_common_fnc_statusEffect_get)#1))}
};

private _allPlayersAreValid = false;
if (_validPlayers isNotEqualTo []) then {
    // Prioritise selecting valid players if there are any
    TRACE_1("5) Dynamic spawn found valid players",_validPlayers);
    _players = _validPlayers;
    _allPlayersAreValid = true;
};

[_players, _allPlayersAreValid]
