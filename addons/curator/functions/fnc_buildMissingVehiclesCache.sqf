#include "script_component.hpp"
/*
    Author:
        Beswick.T

    Description:
        Builds a cache of scope=2 vehicle classes from specific 3CB addons
        that are known to be dropped by the engine's curator tree builder.
        Called once at mission start.

    Parameter(s):
        None

    Return Value:
        None

    Example:
        call uksf_curator_fnc_buildMissingVehiclesCache
*/

private _cfgVehicles = configFile >> "CfgVehicles";
private _cfgFactions = configFile >> "CfgFactionClasses";

// Only target 3CB addons with vehicles affected by the engine bug
private _targetAddons = [
    "uksf_vehicles",
    "uksf_weapons",
    "UK3CB_BAF_Vehicles_Husky",
    "UK3CB_BAF_Vehicles_Coyote_Jackal",
    "UK3CB_BAF_Vehicles_LandRover",
    "UK3CB_BAF_Vehicles_Warrior_a3",
    "UK3CB_BAF_Vehicles_Bulldog",
    "UK3CB_BAF_Vehicles_Panther",
    "UK3CB_BAF_Weapons_Static"
];

// HashMap of className -> [side, factionDisplayName, categoryDisplayName, displayName, icon]
GVAR(missingVehiclesCache) = createHashMap;

{
    private _patchConfig = configFile >> "CfgPatches" >> _x;
    if (!isClass _patchConfig) then { continue };

    {
        private _className = _x;
        private _classConfig = _cfgVehicles >> _className;
        if (!isClass _classConfig) then { continue };

        private _scope = getNumber (_classConfig >> "scope");
        private _scopeCurator = getNumber (_classConfig >> "scopeCurator");
        if (_scope < 2 || {_scopeCurator < 2}) then { continue };

        private _side = getNumber (_classConfig >> "side");
        private _factionClass = getText (_classConfig >> "faction");
        private _displayName = getText (_classConfig >> "displayName");

        private _factionName = getText (_cfgFactions >> _factionClass >> "displayName");
        if (_factionName == "") then { _factionName = _factionClass };

        private _editorSubcat = getText (_classConfig >> "editorSubcategory");
        private _categoryName = if (_editorSubcat != "") then {
            private _subcatConfig = configFile >> "CfgEditorSubcategories" >> _editorSubcat;
            if (isClass _subcatConfig) then {
                getText (_subcatConfig >> "displayName")
            } else {
                getText (_classConfig >> "vehicleClass")
            };
        } else {
            getText (_classConfig >> "vehicleClass")
        };
        if (_categoryName == "") then { _categoryName = "Other" };

        private _icon = getText (_classConfig >> "icon");
        if (_icon != "" && {(_icon find "\") == -1}) then { _icon = "" };

        GVAR(missingVehiclesCache) set [_className, [_side, _factionName, _categoryName, _displayName, _icon]];
    } forEach getArray (_patchConfig >> "units");
} forEach _targetAddons;

INFO_1("Cached %1 target curator vehicle classes",count GVAR(missingVehiclesCache));
