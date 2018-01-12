#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

private _loadoutConfigs = ("true" configClasses (configFile >> QGVAR(loadouts)));
if (isClass (missionConfigFile >> QGVAR(loadouts))) then {
    private _missionLoadouts = ("true" configClasses (missionConfigFile >> QGVAR(loadouts)));
    _loadoutConfigs = _loadoutConfigs select {private _config = configName _x; ({(configName _x) isEqualTo _config} count _missionLoadouts) isEqualTo 0};
    _loadoutConfigs append _missionLoadouts;
};
private _defaultLoadouts = [];
{
    private _name = getText (_x >> "name");
    private _inventory = call compile (getText (_x >> "loadout"));
    _defaultLoadouts pushBack [_name, _inventory];
    true
} count _loadoutConfigs;
uiNamespace setVariable [QGVAR(defaultLoadouts), _defaultLoadouts];

ADDON = true;
