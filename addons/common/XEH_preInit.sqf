#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

//Activate all addons
[] spawn {
    GVAR(addons) = [];
    private _cfgPatches = configFile >> "CfgPatches";
    for "_i" from 0 to (count _cfgPatches - 1) do {
        private _class = _cfgPatches select _i;
        if (isClass _class) then {
            GVAR(addons) pushBack (configName _class);
        };
    };
    activateAddons GVAR(addons);
};

//FPS Debug
GVAR(fpsState) = false;

ADDON = true;
