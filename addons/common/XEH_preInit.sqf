#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

//Activate all addons
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

//FPS Debug
GVAR(fpsState) = false;

//Setup events
if (hasInterface) then {
    GVAR(fpsArray) = [];
    call FUNC(fpsAction);

    [QGVAR(hint), {_this call FUNC(hint)}] call CBA_fnc_addEventHandler;
};
if (!isServer && !hasInterface) then {
    GVAR(fpsEventID) = [QGVAR(fpsGet), {_this call FUNC(fpsGet)}] call CBA_fnc_addEventHandler;
};
if (isServer) then {
    GVAR(server) = player;
    publicVariable QGVAR(server);
    GVAR(fpsEventID) = [QGVAR(fpsGet), {_this call FUNC(fpsGet)}] call CBA_fnc_addEventHandler;

    [QGVAR(addObjectsToCurators), {_this call FUNC(addObjectsToCurators)}] call CBA_fnc_addEventHandler;
};
[QGVAR(log), {INFO(_this select 0)}] call CBA_fnc_addEventHandler;

ADDON = true;
