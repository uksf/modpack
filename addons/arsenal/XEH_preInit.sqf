#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

private _loadoutConfigs = uiNamespace getVariable [QGVAR(configLoadouts), []];
if (isClass (missionConfigFile >> QGVAR(loadouts))) then {
    private _missionLoadouts = ("true" configClasses (missionConfigFile >> QGVAR(loadouts)));
    _loadoutConfigs = _loadoutConfigs select {private _config = configName _x; ({(configName _x) isEqualTo _config} count _missionLoadouts) isEqualTo 0};
    _loadoutConfigs append _missionLoadouts;
};
private _defaultLoadouts = _loadoutConfigs apply {[getText (_x >> "name"), call compile (getText (_x >> "loadout"))]};
uiNamespace setVariable [QGVAR(defaultLoadouts), _defaultLoadouts];

GVAR(useMainOpGear) = false;
GVAR(cachedMainOpGear) = [];
GVAR(cachedFullGear) = [];

["ace_arsenal_displayOpened", {
    params ["_display"];

    private _buttonMainOpGear = _display displayCtrl IDC_buttonMainOpGear;
    if (isMultiplayer) exitWith {
        _buttonMainOpGear ctrlEnable false;
        _buttonMainOpGear ctrlShow false;
    };

    _buttonMainOpGear ctrlSetText (["Turn On Main Op Gear", "Turn Off Main Op Gear"] select GVAR(useMainOpGear));

    if (is3DEN) then {
        GVAR(useMainOpGear) = true;
        [_display] call FUNC(switchMainOpGear);
    } else {
        GVAR(useMainOpGear) = !GVAR(useMainOpGear); // switchMainOpGear toggles state, so flip beforehand
        [{
            [_this] call FUNC(switchMainOpGear);
        }, _display] call CBA_fnc_execNextFrame;
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
