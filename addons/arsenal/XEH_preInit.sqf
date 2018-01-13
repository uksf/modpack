#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

private _loadoutConfigs = uiNamespace getVariable [QGVAR(configLoadouts), []];
if (isClass (missionConfigFile >> QGVAR(loadouts))) then {
    private _missionLoadouts = ("true" configClasses (missionConfigFile >> QGVAR(loadouts)));
    _loadoutConfigs = _loadoutConfigs select {private _config = configName _x; ({(configName _x) isEqualTo _config} count _missionLoadouts) isEqualTo 0};
    _loadoutConfigs append _missionLoadouts;
};
private _defaultLoadouts = [];
{
    private _name = getText (_x >> "name");
    private _inventory = call compile (getText (_x >> "loadout"));
    if (_name == "Empty") then {
        uiNamespace setVariable [QGVAR(emptyLoadout), _inventory];
    };
    _defaultLoadouts pushBack [_name, _inventory];
    true
} count _loadoutConfigs;
uiNamespace setVariable [QGVAR(defaultLoadouts), _defaultLoadouts];

["ace_arsenal_displayOpened", {
    if (is3DEN) then {
        [] spawn {
            disableSerialization;
            private _display = findDisplay 1127001;
            private _buttonMainOpGear = _display displayCtrl 1003;
            _buttonMainOpGear ctrlEnable false;
            _buttonMainOpGear ctrlShow false;
        };
    } else {
        {
            private _display = findDisplay 1127001;
            private _buttonMainOpGear = _display displayCtrl 1003;
            if (isMultiplayer) then {
                _buttonMainOpGear ctrlEnable false;
                _buttonMainOpGear ctrlShow false;
            };
        } call CBA_fnc_execNextFrame;
    };
}] call CBA_fnc_addEventHandler;

ADDON = true;
