#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Create light attack vehicles

    Parameters:
        0: Spawn position module <OBJECT>
        1: Callback once spawning complete <CODE> (Optional)
        2: Callback arguments <ARRAY> (Optional)

    Return value:
        Nothing
*/
params ["_spawnPosition", ["_callback", {}, [{}]], ["_callbackArgs", [], [[]]]];

if !(alive _spawnPosition) exitWith {};

private _nearRoads = _spawnPosition nearRoads 100;
private _roadSpawn = selectRandom _nearRoads;
_spawnPosition = [getPos _roadSpawn, _spawnPosition getPos [20, random 360]] select (isNull _nearRoads);

[_spawnPosition, 1, 0, EAST, EGVAR(gear,gearSoldier), EGVAR(gear,gearCar), {
    params ["_vehicle", "_turrets"];

    (_vehicle emptyPositions "driver") + count _turrets + (_vehicle emptyPositions "cargo")
}, {
    params ["_callback", "_callbackArgs", "_group"];

    _callbackArgs pushBack _group;
    _callbackArgs call _callback;
}, [_callback, _callbackArgs]] call EFUNC(common,spawnGroup);
