/*
    Author:
        Tim Beswick

    Description:
        Shows loading screen and handles lobby respawn on first respawn

    Parameter(s):
        0: Display <DISPLAY>

    Return Value:
        Nothing
*/
#include "script_component.hpp"

if (GVAR(firstRespawn)) then {
    GVAR(firstRespawn) = false;
    private _unitNameConfigs = configFile >> "CfgUnitNames";
    private _unit = objNull;
    if (isArray (_unitNameConfigs >> (roleDescription player))) then {
        startLoadingScreen ["Loading"];
        private _unitConfig = (getArray (_unitNameConfigs >> (roleDescription player)));
        private _groupName = _unitConfig select 0;
        private _group = (GVAR(unitGroups) select {(groupId _x) isEqualTo _groupName}) select 0;
        if (isNil "_group") then {
            _group = createGroup west;
            _group setGroupIdGlobal [_groupName];
            GVAR(unitGroups) pushBack _group;
            publicVariable QGVAR(unitGroups);
        };
        progressLoadingScreen 0.5;
        private _class = _unitConfig select 2;
        _unit = _group createUnit [_class, [-1000, -1000, 0], [], 10, "NONE"];
        [QEGVAR(common,waitAndDelete), [player, 5]] call CBA_fnc_serverEvent;
        selectPlayer _unit;
        [] spawn {
            uiSleep 0.25;
            progressLoadingScreen 1;
            uiSleep 0.25;
            endLoadingScreen;
            forceRespawn player;
            [QGVAR(respawned), [player]] call CBA_fnc_localEvent;
        };
    } else {
        [QGVAR(respawned), [player]] call CBA_fnc_localEvent;
    };
};
