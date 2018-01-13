#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

// Activate all addons
[] spawn {
    GVAR(addons) = [];
    private _activated = activatedAddons;
    private _cfgPatches = configFile >> "CfgPatches";
    for "_i" from 0 to (count _cfgPatches - 1) do {
        private _class = _cfgPatches select _i;
        if (isClass _class && {!(_class in _activated)}) then {
            GVAR(addons) pushBack (configName _class);
        };
    };
    activateAddons GVAR(addons);
};

// FPS Debug
GVAR(fpsState) = false;

// Setup events
if (hasInterface) then {
    GVAR(fpsArray) = [];

    [QGVAR(hint), {_this call FUNC(hint)}] call CBA_fnc_addEventHandler;
    [QGVAR(startLoadingScreen), {startLoadingScreen _this}] call CBA_fnc_addEventHandler;
    [QGVAR(progressLoadingScreen), {progressLoadingScreen _this}] call CBA_fnc_addEventHandler;
    [QGVAR(endLoadingScreen), {endLoadingScreen}] call CBA_fnc_addEventHandler;
};
if (!isServer && !hasInterface) then {
    GVAR(fpsEventID) = [QGVAR(fpsGet), {_this call FUNC(fpsGet)}] call CBA_fnc_addEventHandler;
};
if (isServer) then {
    GVAR(fpsEventID) = [QGVAR(fpsGet), {_this call FUNC(fpsGet)}] call CBA_fnc_addEventHandler;

    [QGVAR(addObjectsToCurators), {_this call FUNC(addObjectsToCurators)}] call CBA_fnc_addEventHandler;
    [QGVAR(setSideRelation), {(_this select 0) setFriend [(_this select 1), (_this select 2)]}] call CBA_fnc_addEventHandler;
    [QGVAR(waitAndDelete), {[{deleteVehicle _this}, _this select 0, _this select 1] call CBA_fnc_waitAndExecute}] call CBA_fnc_addEventHandler;
};
[QGVAR(log), {INFO(_this select 0)}] call CBA_fnc_addEventHandler;

#include "initSettings.sqf"

ADDON = true;
