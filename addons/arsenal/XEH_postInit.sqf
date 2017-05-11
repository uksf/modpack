#include "script_component.hpp"

GVAR(loadoutConfigs) = ("true" configClasses (configFile >> QGVAR(loadouts)));
if (isClass (missionConfigFile >> QGVAR(loadouts))) then {
    private _missionLoadouts = ("true" configClasses (missionConfigFile >> QGVAR(loadouts)));
    GVAR(loadoutConfigs) = GVAR(loadoutConfigs) select {private _config = configName _x; ({(configName _x) isEqualTo _config} count _missionLoadouts) isEqualTo 0};
    GVAR(loadoutConfigs) append _missionLoadouts;
};
uiNamespace setVariable [QGVAR(loadoutConfigs), GVAR(loadoutConfigs)];
