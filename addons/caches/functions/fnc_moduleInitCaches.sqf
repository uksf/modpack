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
(_this#1) params ["_logic"];

if (!isServer) exitWith {};

private _area = _logic getVariable ["objectarea", []];
if (_area isEqualTo []) exitWith {};

private _numberOfCaches = _logic getVariable [QGVAR(cacheNumber), 0];
private _cacheTypes = parseSimpleArray (_logic getVariable [QGVAR(cachePoolString), "[]"]);
private _contentTypes = parseSimpleArray (_logic getVariable [QGVAR(cacheContentPoolString), "[]"]);

if (_cacheTypes isEqualTo [] || _contentTypes isEqualTo []) exitWith {};

for "_i" from 1 to _numberOfCaches do {

    // get a position
    _area deleteAt 4;
    private _areaArray = [getPos _logic] + _area;
    private _position = [_areaArray] call CBA_fnc_randPosArea;
    _position set [2, 0];

    private _nearestCover = (nearestTerrainObjects [_position, ["TREE", "SMALL TREE", "HOUSE"], 1]);
    if (_nearestCover isNotEqualTo []) then {
        _position = _nearestCover#0;
    };

    private _cache = createVehicle [selectRandom _cacheTypes, _position, [], 5, "NONE"];
    GVAR(caches) pushBack _cache;
    [_cache, _contentTypes] call FUNC(prepareCache);

    _cache addMPEventHandler ["MPKilled", {
        params ["_cache", "_killer", "_instigator"];

        GVAR(caches) deleteAt (GVAR(caches) find _cache);
        publicVariable QGVAR(caches);

        TRACE_3("",_cache,_killer,_instigator);
        if (side _killer != west && side _instigator != west) exitWith {};

        [QGVAR(cacheDestroyed), _cache] call CBA_fnc_serverEvent;
    }];
};

publicVariable QGVAR(caches);
