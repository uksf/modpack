#include "script_component.hpp"
#define SERVER_DELAY 3
#define CLIENT_DELAY 1

if (!GVAR(enabled)) exitWith {
    INFO("Caching is disabled.");
};

INFO("Caching is enabled.");

if (isServer) then {
    // for caching
    [{
        private _groups = allGroups select {!(_x getVariable [QGVAR(excluded), false])};
        private _count = count _groups;
        private _perFrame = ceil (_count / (diag_fpsMin * SERVER_DELAY));
        [{
            params ["_args", "_idPFH"];
            _args params ["_groups", "_count", "_perFrame", "_index"];

            if (_index > _count || (count _groups <= 0)) exitWith {
                [_idPFH] call CBA_fnc_removePerFrameHandler;
            };

            [_groups select [_index, _perFrame]] call FUNC(cacheGroups);

            _args set [3, _index + _perFrame];
        }, 0, [_groups, _count, _perFrame, 0]] call cba_fnc_addPerFrameHandler;
    }, SERVER_DELAY, []] call cba_fnc_addPerFrameHandler;

    // for uncaching
    // TODO: think about performance for this
    [{
        private _groupIndex = GVAR(cachedGroupsPositions) findIf {([_x#1, GVAR(distance)] call EFUNC(common,anyNearPlayers))};
        if (_groupIndex == -1) exitWith {};

        // near groups uid
        private _uid = GVAR(cachedGroupsPositions)#_groupIndex#0;
        GVAR(cachedGroupsPositions) deleteAt _groupIndex;

        // hashmap lookup
        private _groupData = GVAR(cachedGroupsData) get _uid; // returns the data

        if (_groupData#4 == 0) exitWith { // SAVED_TYPE_INFANTRY
            [_uid, _groupData] call FUNC(recreateInfantryGroup);
        };

        if (_groupData#4 == 1) exitWith { // SAVED_TYPE_VEHICLE
            [_uid, _groupData] call FUNC(recreateVehicleGroup);
        };
    }, 0.1, []] call cba_fnc_addPerFrameHandler;
};
