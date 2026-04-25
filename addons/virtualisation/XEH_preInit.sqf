#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

GVAR(killswitched) = false;
GVAR(groupDataMap) = createHashMap;
GVAR(groupPositionMap) = [];
GVAR(simulatedGroupIds) = [];
GVAR(simChunkCursor) = -1;

[QGVAR(include), {_this setVariable [QGVAR(excluded), false, true]}] call CBA_fnc_addEventHandler;
[QGVAR(exclude), {_this setVariable [QGVAR(excluded), true, true]}] call CBA_fnc_addEventHandler;
[QGVAR(deleteGroup), {deleteGroup _this}] call CBA_fnc_addEventHandler;
[QGVAR(recreateGroup), {call FUNC(recreateGroup)}] call CBA_fnc_addEventHandler;

if (isServer) then {
    [QGVAR(devirtualiseNearby), {call FUNC(devirtualiseNearby)}] call CBA_fnc_addEventHandler;
    [QGVAR(recreateAll), {call FUNC(recreateAll)}] call CBA_fnc_addEventHandler;

    {
        [_x, "initPost", {(group (_this#0)) setVariable [QGVAR(excluded), true, true]}, true] call CBA_fnc_addClassEventHandler;
    } forEach ["B_UAV_AI", "O_UAV_AI", "I_UAV_AI"];
};

if (hasInterface) then {
    call FUNC(addContextActions);
};

#include "initSettings.inc.sqf"

ADDON = true;
