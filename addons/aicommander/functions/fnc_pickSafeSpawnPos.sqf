#include "script_component.hpp"
/*
    Author:
        Codex

    Description:
        Pick one safe spawn position from objective cache, refreshing when empty.

    Parameters:
        0: Objective module <OBJECT>

    Return Value:
        Spawn position ATL <ARRAY>
*/

params [["_objective", objNull, [objNull]]];

if (isNull _objective) exitWith {[0, 0, 0]};

private _safePoints = _objective getVariable [QGVAR(safeSpawnPoints), []];
if (_safePoints isEqualTo []) then {
    _safePoints = [_objective] call FUNC(refreshObjectiveSafeSpawns);
};

if (_safePoints isEqualTo []) exitWith {
    private _fallback = getPosATL _objective;
    [_fallback#0, _fallback#1, 0]
};

private _pick = selectRandom _safePoints;
[_pick#0, _pick#1, 0]

