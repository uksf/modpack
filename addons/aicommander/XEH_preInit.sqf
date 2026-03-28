#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

// Addon globals are initialized here and filled by runtime functions.
GVAR(commanders) = [];
GVAR(objectives) = [];
GVAR(enabled) = false;
GVAR(debugGridRadius) = 2500;
GVAR(overlayEnabled) = false;
GVAR(overlayEH) = -1;
GVAR(safeSpawnOverlayEnabled) = false;
GVAR(safeSpawnOverlayEH) = -1;
GVAR(airStrikeSpawns) = [];

if (isServer) then {
    [QGVAR(hitRawForward), {call FUNC(handleMissionHitRaw)}] call CBA_fnc_addEventHandler;
    [QGVAR(forceAirStrikeOnPlayer), {call FUNC(debugForceAirStrikeOnPlayer)}] call CBA_fnc_addEventHandler;
    [QGVAR(staffRequest), {call FUNC(submitStaffRequest)}] call CBA_fnc_addEventHandler;

    ["CAManBase", "init", {
        params ["_unit"];

        if (isNull _unit) exitWith {};
        _unit addMPEventHandler ["MPHit", {
            params ["_unit", "", "", "_shooter"];
            [_unit, _shooter] call FUNC(handleMissionHitRaw);
        }];
    }] call CBA_fnc_addClassEventHandler;
};

// Also consume mission-level hit events so contact reporting works regardless of unit locality (server/HC/client).
[QEGVAR(mission,hitRaw), {call FUNC(handleMissionHitRaw)}] call CBA_fnc_addEventHandler;

ADDON = true;

