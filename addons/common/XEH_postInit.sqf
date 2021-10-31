#include "script_component.hpp"
#include "initKeybinds.sqf"

// Set server object
if (isServer) then {
    GVAR(server) = player;
    publicVariable QGVAR(server);

    // Delete empty groups every 5 minutes
    [{
        [QGVAR(deleteEmptyGroups), []] call CBA_fnc_globalEvent;
    }, 300, []] call cba_fnc_addPerFrameHandler;
};

// Set headless client array to player if singleplayer
if (isMultiplayer && !is3DENMultiplayer) then {
    acex_headless_headlessClients = entities "HeadlessClient_F";
} else {
    acex_headless_headlessClients = [player];
};

if (hasInterface) then {
    call FUNC(addSelfActions);

    ["visibleMap", {
        params ["", "_mapOn"];
        [_mapOn] call FUNC(mapPosition);
    }] call CBA_fnc_addPlayerEventHandler;

    private _buffer = safeZoneW / 10;
    GVAR(bufferedSafeX) = safeZoneX - _buffer;
    GVAR(bufferedSafeW) = safeZoneX + safeZoneW + _buffer;
    GVAR(bufferedSafeY) = safeZoneY - _buffer;
    GVAR(bufferedSafeH) = safeZoneY + safeZoneH + _buffer;
};

GVAR(missionObjects) = (allMissionObjects "All") - (allMissionObjects "Logic");
GVAR(missionObjectsMinusUnits) = GVAR(missionObjects) - allUnits;

if (isServer) then {
    if (GVAR(mainOp)) then {
        ["ace_medical_treatment_locationPAK", 2, 0, "server", false] call CBA_settings_fnc_set;
        ["ace_medical_spontaneousWakeUpEpinephrineBoost", 4, 0, "server", false] call CBA_settings_fnc_set;
        ["uksf_curator_curatorsLocked", true, 0, "server", false] call CBA_settings_fnc_set;
    } else {
        ["ace_medical_treatment_locationPAK", 0, 0, "server", false] call CBA_settings_fnc_set;
        ["ace_medical_spontaneousWakeUpEpinephrineBoost", 5, 0, "server", false] call CBA_settings_fnc_set;
        ["uksf_curator_curatorsLocked", false, 0, "server", false] call CBA_settings_fnc_set;
    };
};
