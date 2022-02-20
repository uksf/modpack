#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Get buildings for the location

    Parameters:
        0: Placed objects <ARRAY>
        1: Location position <ARRAY>

    Return value:
        Array of buildings <ARRAY>
*/
params ["_placedObjects", "_position"];

if !(isServer) exitWith {};

private _buildings = nearestTerrainObjects [_position, ["BUILDING", "HOUSE", "CHURCH", "CHAPEL", "FUELSTATION", "HOSPITAL", "RUIN", "BUNKER"], 10, true];
private _placedBuildings = _placedObjects select {(_x distance _position) <= 10 && _x isKindOf "House"};
_buildings append _placedBuildings;

if (_buildings isEqualTo []) exitWith {
    []
};

_buildings = _buildings select {!isObjectHidden _x} apply {[_x distance _position, _x]};
_buildings sort true;
_buildings = _buildings apply {_x#1};

_buildings
