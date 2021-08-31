#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

GVAR(ratingAreasEnabled) = false;
GVAR(ratingAreaModules) = [];
GVAR(ratingAreas) = [];
GVAR(hitUnitCache) = [];
GVAR(previousGlobalPercentage) = 0;

GVAR(debugMode) = false;
GVAR(debugMarkers) = [];
GVAR(debugPFHID) = -1;

GVAR(ratingAreaAttributeConfig) = EGVAR(common,configVehicles) >> QGVAR(moduleRatingArea) >> "Attributes";

[QEGVAR(ied,planterKilled), {[QGVAR(ied_planter), _this] call FUNC(ratingChanged)}] call CBA_fnc_addEventHandler;
[QEGVAR(caches,cacheDestroyed), {[QGVAR(caches_destroyed), _this] call FUNC(ratingChanged)}] call CBA_fnc_addEventHandler;
[QEGVAR(safehouses,safehouseDestroyed), {[QGVAR(safehouse_destroyed), _this] call FUNC(ratingChanged)}] call CBA_fnc_addEventHandler;

[QEGVAR(ied,iedDestroyed), {[QGVAR(ied_destroyed), _this] call FUNC(ratingChanged)}] call CBA_fnc_addEventHandler;

["CAManBase", "init", {
    params ["_unit"];

    if (side _unit != civilian) exitWith {};

    _this#0 addMPEventHandler ["MPHit", {
        params ["_unit", "", "", "_instigator"];

        if (side _instigator != west) exitWith {};

        if (_unit in GVAR(hitUnitCache)) exitWith {};
        GVAR(hitUnitCache) pushBack _unit;
        [{GVAR(hitUnitCache) deleteAt (GVAR(hitUnitCache) find _this)}, _unit, 3] call CBA_fnc_waitAndExecute;

        [QGVAR(civ_hit), _unit] call FUNC(ratingChanged);
    }];

    _this#0 addMPEventHandler ["MPKilled", {
        params ["_unit", "_killer", "_instigator"];

        if (side _killer != west && side _instigator != west) exitWith {};

        [QGVAR(civ_killed), _unit] call FUNC(ratingChanged);
    }];
}] call CBA_fnc_addClassEventHandler;

ADDON = true;
