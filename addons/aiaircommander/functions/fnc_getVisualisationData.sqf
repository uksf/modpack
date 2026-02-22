#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Returns AI air commander visualisation data for Zeus.

    Parameter(s):
        None

    Return Value:
        Array of visualisation data
*/

private _aaSites = GVAR(aaSites) apply {
    private _position = getPosATL _x;
    private _vehicle = _x getVariable [QGVAR(aaVehicle), objNull];
    private _occupied = alive _vehicle;
    [_position, _occupied, netId _vehicle]
};

private _airspaceCentres = GVAR(airspaceCentre) apply {getPosATL _x};
private _enemyAirfields = GVAR(enemyAirfields) apply {getPosATL _x};

private _spawnPoints = [];
{_spawnPoints pushBack [getPosATL _x, "aa"]} forEach GVAR(aaSpawns);
{_spawnPoints pushBack [getPosATL _x, "heli"]} forEach GVAR(heliSpawns);
{_spawnPoints pushBack [getPosATL _x, "plane"]} forEach GVAR(planeSpawns);

[
    _aaSites,
    _airspaceCentres,
    _enemyAirfields,
    _spawnPoints
]
