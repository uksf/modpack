/*
    Author:
        Tim Beswick

    Description:
        Called on mission display load. Creates unit from slot info.

    Parameter(s):
        None

    Return Value:
        Nothing
*/
#include "script_component.hpp"

if (!isMultiplayer) exitWith {
    [QGVAR(respawned), [player]] call CBA_fnc_localEvent;
};

private _unitNameConfigs = configFile >> "CfgUnitNames";
private _unit = objNull;
if (isArray (_unitNameConfigs >> (roleDescription player))) then {
    private _unitConfig = (getArray (_unitNameConfigs >> (roleDescription player)));
    private _groupName = _unitConfig select 0;
    private _group = (GVAR(unitGroups) select {(groupId _x) isEqualTo _groupName}) select 0;
    if (isNil "_group") then {
        _group = createGroup west;
        _group setGroupIdGlobal [_groupName];
        GVAR(unitGroups) pushBack _group;
        publicVariable QGVAR(unitGroups);
    };
    private _class = _unitConfig select 2;
    _unit = _group createUnit [_class, [-1000, -1000, 0], [], 10, "NONE"];
};

if (getMissionConfigValue ["respawn", "NONE"] != "NONE") then {
    [{deleteVehicle _this}, player, 5] call CBA_fnc_waitAndExecute;
    startLoadingScreen ["Loading"];
    if (!(isNull _unit)) then {
        selectPlayer _unit;
    };
    GVAR(firstRespawn) = true;
    forceRespawn player;

    [] spawn {
        uiSleep 1;
        progressLoadingScreen 1;
        uiSleep 1;
        endLoadingScreen;
    };
} else {
    [QGVAR(respawned), [player]] call CBA_fnc_localEvent;
};
