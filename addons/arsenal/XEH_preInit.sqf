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
        if (isMultiplayer) then {
            {
                private _display = findDisplay 1127001;
                private _buttonMainOpGear = _display displayCtrl 1003;
                _buttonMainOpGear ctrlEnable false;
                _buttonMainOpGear ctrlShow false;
            } call CBA_fnc_execNextFrame;
        };
    };
}] call CBA_fnc_addEventHandler;

[QGVAR(addArsenalAction), {
    params ["_object"];
    private _id = _object addAction ["Arsenal", {[_this select 3, ace_player] call ace_arsenal_fnc_openBox;}, _object, 10, true, true, "", "true", 5];
    _object setVariable [QGVAR(arsenalActionId), _id];
}] call CBA_fnc_addEventHandler;

[QGVAR(removeArsenalAction), {
    params ["_object"];
    private _id = _object getVariable [QGVAR(arsenalActionId), -1];
    if (_id != -1) then {
        _object removeAction _id;
    };
}] call CBA_fnc_addEventHandler;

ADDON = true;
