#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

GVAR(ratingAreasEnabled) = false;
GVAR(ratingAreas) = [];

GVAR(debugMode) = false;
GVAR(debugMarkers) = [];
GVAR(debugPFHID) = -1;

if (isServer) then {
    GVAR(ratingAreaModules) = [];
    GVAR(hitUnitCache) = [];
    GVAR(previousGlobalPercentage) = 0;
    GVAR(ratingBroadcastPFHID) = -1;
    GVAR(ratingBroadcastTime) = -1;

    [QGVAR(persistenceData), FUNC(serializeRatingAreas), FUNC(deserializeRatingAreas)] call EFUNC(persistence,registerSerializer);

    GVAR(ratingAreaAttributeConfig) = EGVAR(common,configVehicles) >> QGVAR(moduleRatingArea) >> "Attributes";

    [QGVAR(changeRating), {call FUNC(changeRating)}] call CBA_fnc_addEventHandler;
    [QEGVAR(ied,planterKilled), {[QGVAR(ied_planter), _this] call FUNC(handleRatingChanged)}] call CBA_fnc_addEventHandler;
    [QEGVAR(ied,iedDestroyed), {[QGVAR(ied_destroyed), _this] call FUNC(handleRatingChanged)}] call CBA_fnc_addEventHandler;
    [QEGVAR(caches,cacheDestroyed), {[QGVAR(caches_destroyed), _this] call FUNC(handleRatingChanged)}] call CBA_fnc_addEventHandler;
    [QEGVAR(safehouses,destroyed), {[QGVAR(safehouse_destroyed), _this] call FUNC(handleRatingChanged)}] call CBA_fnc_addEventHandler;

    ["CAManBase", "init", {
        params ["_unit"];

        if (side _unit != civilian) exitWith {};

        _this#0 addMPEventHandler ["MPHit", {
            params ["_unit", "", "", "_instigator"];

            if !(isServer) exitWith {};
            if (isPlayer _unit || side _instigator != west) exitWith {};

            if (_unit in GVAR(hitUnitCache)) exitWith {};
            GVAR(hitUnitCache) pushBack _unit;
            [{GVAR(hitUnitCache) deleteAt (GVAR(hitUnitCache) find _this)}, _unit, 3] call CBA_fnc_waitAndExecute;

            [QGVAR(civ_hit), _unit] call FUNC(handleRatingChanged);
        }];

        _this#0 addMPEventHandler ["MPKilled", {
            params ["_unit", "_killer", "_instigator"];

            if !(isServer) exitWith {};
            if (side _killer != west && side _instigator != west) exitWith {};

            [QGVAR(civ_killed), _unit] call FUNC(handleRatingChanged);
        }];
    }] call CBA_fnc_addClassEventHandler;
};

ADDON = true;
