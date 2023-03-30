#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

GVAR(killswitched) = false;

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

if (isServer) then {
    GVAR(virtualisedGroups) = createHashMap;
    GVAR(virtualisedGroupsPositionMap) = [];

    [QGVAR(recreateAll), {
        // This is an admin function only to be used when killswitch is on
        if (!GVAR(killswitched)) exitWith {};

        INFO("Recreating all virtualised groups");

        [{
            params ["", "_idPFH"];

            // This is an admin function only to be used when killswitch is on
            if (!GVAR(killswitched)) exitWith {
                [_idPFH] call CBA_fnc_removePerFrameHandler;
            };

            if (count GVAR(virtualisedGroupsPositionMap) == 0) exitWith {
                [_idPFH] call CBA_fnc_removePerFrameHandler;
                GVAR(virtualisedGroups) = createHashMap;
                GVAR(virtualisedGroupsPositionMap) = [];
            };

            private _id = GVAR(virtualisedGroupsPositionMap)#0#0;
            GVAR(virtualisedGroupsPositionMap) deleteAt 0;

            private _groupData = GVAR(virtualisedGroups) deleteAt _id;
            [QGVAR(recreateGroup), [_groupData]] call EFUNC(common,headlessEvent);
        }, 0.2, []] call CBA_fnc_addPerFrameHandler;
    }]] call CBA_fnc_addEventHandler;

    [QGVAR(deleteGroup), {deleteGroup _x}] call CBA_fnc_addEventHandler;

    {
        [_x, "initPost", {(group (_this#0)) setVariable [QQGVAR(excluded), true, true]}, true] call CBA_fnc_addClassEventHandler;
    } forEach ["B_UAV_AI", "O_UAV_AI", "I_UAV_AI"];
};

#include "initSettings.sqf"

ADDON = true;
