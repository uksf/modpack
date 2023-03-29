#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

GVAR(virtualisedGroups) = createHashMap;
GVAR(virtualisedGroupsPositionMap) = [];

GVAR(killswitched) = false;

[QGVAR(deleteGroup), {deleteGroup _x}] call CBA_fnc_addEventHandler;
[QGVAR(recreateGroup), {
    params ["_groupData"];
    _groupData params ["_type"];

    switch (_type) do {
        case SAVED_TYPE_INFANTRY: {
            [_groupData] call FUNC(recreateInfantryGroup);
        };
        case SAVED_TYPE_VEHICLE: {
            [_groupData] call FUNC(recreateVehicleGroup);
        };
        default {
            ERROR_1("'%1' is not a valid virtualised group type",_type);
        };
    };
}] call CBA_fnc_addEventHandler;

{
    [_x, "initPost", {(group (_this#0)) setVariable [QQGVAR(excluded), true, true]}, true] call CBA_fnc_addClassEventHandler;
} forEach ["B_UAV_AI", "O_UAV_AI", "I_UAV_AI"];

#include "initSettings.sqf"

ADDON = true;
