#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

#include "initSettings.sqf"

if (isServer) then {
    GVAR(prefabAreaModules) = [];
    GVAR(locationModules) = [];

    GVAR(prefabs) = createHashMap;
    GVAR(locations) = createHashMap;
    GVAR(destroyed) = createHashMap;

    [QEGVAR(persistence,loadingFinished), {call FUNC(initLocations)}] call CBA_fnc_addEventHandler;

    [QGVAR(persistenceData), FUNC(serialize), FUNC(deserialize)] call EFUNC(persistence,registerSerializer);
};

ADDON = true;
