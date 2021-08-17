#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Creates specified number of caches

    Parameters:
        0: The module object <OBJECT>

    Return value:
        Nothing
*/

(_this select 1) params ["_module"];

if (!isServer) exitWith {};

private _numberOfCaches = _module getVariable [QGVAR(cacheNumber), 0];
private _cacheTypes = parseSimpleArray (_module getVariable [QGVAR(cachePoolString), []]);
private _contentTypes = parseSimpleArray (_module getVariable [QGVAR(cacheContentPoolString), []]);
private _area = _module getVariable ["objectarea", []];

for "_i" from 1 to _numberOfCaches do {

    // get a position
    _area deleteAt 4;
    private _areaArray = [(getPos _module)] + _area;
    private _position = [_areaArray] call CBA_fnc_randPosArea;
    private _nearestCover = (nearestTerrainObjects [_position, ["TREE", "SMALL TREE", "HOUSE"], 1]);

    // set nearestCover to the random pos if its empty
    if (_nearestCover isEqualTo []) then {
        _nearestCover = _position;
    } else {
        _nearestCover = _nearestCover select 0;
    };

    private _cache = createVehicle [selectRandom _cacheTypes, _nearestCover, [], 5, "NONE"];
    GVAR(caches) pushBack _cache;
    [_cache,_contentTypes] call FUNC(prepareCache);

    _cache addMPEventHandler ["MPKilled", {
        params ["_unit"];
        GVAR(caches) deleteAt (GVAR(caches) find _unit);
        publicVariable QGVAR(caches);
    }];
};

publicVariable QGVAR(caches);

