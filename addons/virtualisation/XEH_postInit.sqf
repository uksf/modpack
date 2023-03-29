#include "script_component.hpp"
#define DELAY 3

if (!GVAR(enabled)) exitWith {
    INFO("Virtualisation is disabled.");
};

// TODO: Remove after extensive testing
if (EGVAR(caching,enabled)) exitWith {
    INFO("Caching is enabled, virtualisation has been disabled.");
};

INFO("Virtualisation is enabled.");

if (hasInterface) then {
    call FUNC(addAdminActions);
};

if (isServer) then {
    // Virtualisation
    [{
        // Killswitch
        if (GVAR(killswitched)) exitWith {};

        private _groups = allGroups select {!(_x getVariable [QGVAR(excluded), false])};
        private _count = count _groups;
        private _perFrame = ceil (_count / (diag_fpsMin * SERVER_DELAY));
        [{
            params ["_args", "_idPFH"];
            _args params ["_groups", "_count", "_perFrame", "_index"];

            if (_index > _count || (count _groups <= 0)) exitWith {
                [_idPFH] call CBA_fnc_removePerFrameHandler;
            };

            [_groups select [_index, _perFrame]] call FUNC(virtualizeGroups);

            _args set [3, _index + _perFrame];
        }, 0, [_groups, _count, _perFrame, 0]] call CBA_fnc_addPerFrameHandler;
    }, DELAY, []] call CBA_fnc_addPerFrameHandler;

    // Recreation
    // TODO: think about performance for this
    [{
        // Killswitch
        if (GVAR(killswitched)) exitWith {};

        private _groupIndex = GVAR(virtualisedGroupsPositionMap) findIf {
            [ALL_PLAYERS, {
                _x distance _x#1 <= GVAR(distance)
                && {!((objectParent _x) isKindOf "Air")}
            }] call FUNC(arrayAny)
        };
        if (_groupIndex == -1) exitWith {};

        private _id = GVAR(virtualisedGroupsPositionMap)#_groupIndex#0;
        GVAR(virtualisedGroupsPositionMap) deleteAt _groupIndex;

        private _groupData = GVAR(virtualisedGroups) deleteAt _id;
        [QGVAR(recreateGroup), [_groupData]] call EFUNC(common,headlessEvent);
    }, DELAY, []] call CBA_fnc_addPerFrameHandler;
};
