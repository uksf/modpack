#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

GVAR(addons) = ('true' configClasses (configFile >> "CfgPatches")) apply {configName _x};
activateAddons GVAR(addons);

GVAR(fpsState) = false;

if (hasInterface) then {
    GVAR(fpsArray) = [];

    [QGVAR(hint), {call FUNC(hint)}] call CBA_fnc_addEventHandler;
    [QGVAR(textTiles), {_this spawn BIS_fnc_textTiles}] call CBA_fnc_addEventHandler;

    ["CAManBase", "respawn", {
        call FUNC(addSelfActions);
    }, true, nil, true] call CBA_fnc_addClassEventHandler;
};

if (!isServer && !hasInterface) then {
    GVAR(fpsEventID) = [QGVAR(fpsGet), {call FUNC(fpsGet)}] call CBA_fnc_addEventHandler;
};

if (isServer) then {
    GVAR(markerID) = 100000;

    GVAR(fpsEventID) = [QGVAR(fpsGet), {call FUNC(fpsGet)}] call CBA_fnc_addEventHandler;

    [QGVAR(addObjectsToCurators), {call FUNC(addObjectsToCurators)}] call CBA_fnc_addEventHandler;
    [QGVAR(setSideRelation), {(_this#0) setFriend [(_this#1), (_this#2)]}] call CBA_fnc_addEventHandler;
    [QGVAR(waitAndDelete), {
        [{
            deleteVehicle _this;
            [QGVAR(deleteEmptyGroups), []] call CBA_fnc_globalEvent;
        }, _this#0, _this#1] call CBA_fnc_waitAndExecute
    }] call CBA_fnc_addEventHandler;
};
[QGVAR(log), {INFO(_this#0)}] call CBA_fnc_addEventHandler;
[QGVAR(deleteEmptyGroups), {{deleteGroup _x; true} count allGroups}] call CBA_fnc_addEventHandler;

#include "initSettings.sqf"

ADDON = true;
