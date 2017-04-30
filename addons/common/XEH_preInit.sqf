#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

//Activate all addons
if (!isMultiplayer) then {
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
};


//FPS Debug
GVAR(fpsState) = false;

ADDON = true;
