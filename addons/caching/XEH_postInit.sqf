#include "script_component.hpp"
#define SERVER_DELAY 3
#define CLIENT_DELAY 1

if (!GVAR(enabled)) exitWith {
    INFO("Caching is disabled.");
};

INFO("Caching is enabled.");

// for initial caching
if (isServer) then {
    [{
        private _includedGroups = allGroups select {!(_x getVariable [QGVAR(excluded), false])}; // not working currently, caches all
        private _includedGroupsBeyondDistance = _includedGroups select {!([leader _x, GVAR(distance)] call EFUNC(common,anyNearPlayers))};
        private _count = count _includedGroupsBeyondDistance;
        private _perFrame = ceil (_count / (diag_fpsMin * SERVER_DELAY));
        [{
            params ["_args", "_idPFH"];
            _args params ["_includedGroupsBeyondDistance", "_count", "_perFrame", "_index"];

            if (_index > _count || (count _includedGroupsBeyondDistance <= 0)) exitWith {
                [_idPFH] call CBA_fnc_removePerFrameHandler;
            };

            [_includedGroupsBeyondDistance select [_index, _perFrame]] call FUNC(cacheGroups);

            _args set [3, _index + _perFrame];
        }, 0, [_includedGroupsBeyondDistance, _count, _perFrame, 0]] call cba_fnc_addPerFrameHandler;
    }, SERVER_DELAY, []] call cba_fnc_addPerFrameHandler;
};

// for uncaching
if (isServer) then {
    [{
        private _count = count GVAR(cachedGroupsPositions);;
        private _perFrame = ceil (_count / (diag_fpsMin * SERVER_DELAY));

        [{
            params ["_args", "_idPFH"];
            _args params ["_count", "_perFrame", "_index"];

            if (_index > _count) exitWith {
                [_idPFH] call CBA_fnc_removePerFrameHandler;
            };

            // TODO: Need to check a position against each player (ALL_PLAYERS)
            private _groupIndex = GVAR(cachedGroupsPositions) findIf {
                private _groupPos = _x#1;
                {
                    private _player = _x;
                    (getPos _player distance2d _groupPos) < GVAR(distance);
                } forEach ALL_PLAYERS;
            };
            if (_groupIndex == -1) exitWith {};

            // near groups uid
            private _uid = GVAR(cachedGroupsPositions)#_groupIndex#0;
            GVAR(cachedGroupsPositions) deleteAt _groupIndex;
            // systemChat format ["uid: %1", _uid];

            // hashmap lookup
            private _groupData = GVAR(cachedGroupsData) get _uid; // returns the data

            [QGVAR(uncache), [_groups select [_index, _perFrame]]] call CBA_fnc_localEvent;

            _args set [3, _index + _perFrame];
        }, 0, [_count, _perFrame, 0]] call cba_fnc_addPerFrameHandler;
    }, SERVER_DELAY, []] call cba_fnc_addPerFrameHandler;
};

