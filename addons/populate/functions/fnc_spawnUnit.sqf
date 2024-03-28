#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Spawns a unit at the passed position

    Parameters:
        0: _spawnPos <POSITION>
        1: _module <OBJECT>
        2: _group <GROUP>

    Return value:
        Nothing
*/

params ["_spawnPos", "_module", "_group"];

// select random unit to spawn and spawn it at the pos
private _unitPool = _module getVariable [QGVAR(unitPoolString), []];
private _unitType = selectRandom _unitPool;

private _unit = _group createUnit [_unitType, _spawnPos, [], 0, "NONE"];
_unit disableAI "PATH";

// TODO: exclude virtualization until the group is spawned, then set to true


