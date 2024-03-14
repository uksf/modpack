#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

GVAR(killswitched) = false;
GVAR(groupDataMap) = createHashMap;
GVAR(groupPositionMap) = [];
GVAR(curatorViewMapID) = 999;
GVAR(curatorViewPFHID) = -1;
GVAR(showVirtualised) = false;

[QGVAR(deleteGroup), {deleteGroup _this}] call CBA_fnc_addEventHandler;
[QGVAR(recreateGroup), {call FUNC(recreateGroup)}] call CBA_fnc_addEventHandler;

if (isServer) then {
    GVAR(dataStreamClientObjects) = [];

    [QGVAR(include), {_this setVariable [QGVAR(excluded), false, true]}] call CBA_fnc_addEventHandler;
    [QGVAR(exclude), {_this setVariable [QGVAR(excluded), true, true]}] call CBA_fnc_addEventHandler;
    [QGVAR(devirtualizeNearby), {call FUNC(devirtualizeNearby)}] call CBA_fnc_addEventHandler;
    [QGVAR(recreateAll), {call FUNC(recreateAll)}] call CBA_fnc_addEventHandler;
    [QGVAR(toggleDataStreamForClient), {call FUNC(toggleDataStreamForClient)}] call CBA_fnc_addEventHandler;

    {
        [_x, "initPost", {(group (_this#0)) setVariable [QGVAR(excluded), true, true]}, true] call CBA_fnc_addClassEventHandler;
    } forEach ["B_UAV_AI", "O_UAV_AI", "I_UAV_AI"];
};

if (hasInterface) then {
    call FUNC(addContextActions);

    ["zen_curatorDisplayLoaded", {call FUNC(curatorDisplayLoad)}] call CBA_fnc_addEventHandler;
    ["zen_curatorDisplayUnloaded", {call FUNC(curatorDisplayUnload)}] call CBA_fnc_addEventHandler;

    [QGVAR(streamData), {
        params ["_groupPositionMap", "_groupDataMap"];

        GVAR(groupPositionMap) = _groupPositionMap;
        GVAR(groupDataMap) = _groupDataMap;
    }] call CBA_fnc_addEventHandler;
};

#include "initSettings.sqf"

ADDON = true;
