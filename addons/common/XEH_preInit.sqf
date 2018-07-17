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

GVAR(fpsState) = false;

if (hasInterface) then {
    GVAR(fpsArray) = [];

    [QGVAR(hint), {_this call FUNC(hint)}] call CBA_fnc_addEventHandler;
    [QGVAR(textTiles), {_this spawn BIS_fnc_textTiles}] call CBA_fnc_addEventHandler;

    ["CAManBase", "respawn", {
        call FUNC(fpsAction);
    }, true, nil, true] call CBA_fnc_addClassEventHandler;
};

if (!isServer && !hasInterface) then {
    GVAR(fpsEventID) = [QGVAR(fpsGet), {_this call FUNC(fpsGet)}] call CBA_fnc_addEventHandler;
};

if (isServer) then {
    GVAR(markerID) = 100000;

    GVAR(fpsEventID) = [QGVAR(fpsGet), {_this call FUNC(fpsGet)}] call CBA_fnc_addEventHandler;

    [QGVAR(addObjectsToCurators), {_this call FUNC(addObjectsToCurators)}] call CBA_fnc_addEventHandler;
    [QGVAR(setSideRelation), {(_this select 0) setFriend [(_this select 1), (_this select 2)]}] call CBA_fnc_addEventHandler;
    [QGVAR(waitAndDelete), {
        [{
            deleteVehicle _this;
            [QGVAR(deleteEmptyGroups), []] call CBA_fnc_globalEvent;
        }, _this select 0, _this select 1] call CBA_fnc_waitAndExecute
    }] call CBA_fnc_addEventHandler;
};
[QGVAR(log), {INFO(_this select 0)}] call CBA_fnc_addEventHandler;
[QGVAR(deleteEmptyGroups), {{deleteGroup _x; true} count allGroups}] call CBA_fnc_addEventHandler;

#include "initSettings.sqf"

ADDON = true;
