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

if (!isMultiplayer) exitWith {};

private _unitNameConfigs = configFile >> "CfgUnitNames";
if (isArray (_unitNameConfigs >> (roleDescription player))) then {
    private _unitConfig = (getArray (_unitNameConfigs >> (roleDescription player)));
    private _groupName = _unitConfig select 0;
    private _group = (GVAR(unitGroups) select {(groupId _x) isEqualTo _groupName}) select 0;
    if (isNil "_group") then {
        _group = createGroup west;
    };
    private _class = _unitConfig select 2;
    private _unit = _group createUnit [_class, [-1000, -1000, 0], [], 0, "NONE"];
    private _oldUnit = player;
    startLoadingScreen ["Loading"];
    selectPlayer _unit;
    forceRespawn player;
    deleteVehicle _oldUnit;
    [] spawn {
        uiSleep 1;
        progressLoadingScreen 1;
        uiSleep 1;
        endLoadingScreen;
    };
};
