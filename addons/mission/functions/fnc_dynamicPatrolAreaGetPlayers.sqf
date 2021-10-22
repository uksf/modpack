#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Gets selectable players for given area

    Parameters:
        0: Values <ARRAY>
        1: Logic <OBJECT>
        2: Area <ARRAY>

    Return value:
        Array of players and whether they are all valid
        [Players, All players are valid]
*/
params ["", "_logic", "_area"];

// Player can't be in an air vehicle
// AND Player can't be in excluded areas
// AND Player must be in area

private _allPlayers = call CBA_fnc_players;
private _players = _allPlayers select {
    private _player = _x;

    !((vehicle _player) isKindOf "Air")
    && {[_player, _logic, _area] call EFUNC(common,objectInArea)}
    && {[GVAR(dynamicPatrolExcludeAreas), {[_player, _x#0, _x#1] call EFUNC(common,objectInArea)}] call EFUNC(common,arrayNone)}
};
TRACE_1("5) Dynamic spawn resolved players",_players);
if (_players isEqualTo []) exitWith {
    INFO("5) Dynamic spawn failed players check");
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
