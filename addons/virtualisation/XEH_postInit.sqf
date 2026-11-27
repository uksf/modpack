#include "script_component.hpp"
#define DELAY 3
#define SIM_DELAY 1

if (!GVAR(enabled)) exitWith {
    INFO("Virtualisation is disabled.");
};

if (EGVAR(caching,enabled)) exitWith {
    INFO("Caching is enabled, virtualisation has been disabled.");
};

INFO("Virtualisation is enabled.");

call FUNC(registerDebugProviders);

if (isServer) then {
    [{
        if (GVAR(killswitched) || isGamePaused) exitWith {};

        private _groups = allGroups select {!(_x getVariable [QGVAR(excluded), false])};
        private _count = count _groups;
        private _perFrame = ceil (_count / (diag_fpsMin * DELAY));
        [{
            params ["_args", "_idPFH"];
            _args params ["_groups", "_count", "_perFrame", "_index"];

            if (isGamePaused) exitWith {};

            if (_index > _count || (count _groups <= 0)) exitWith {
                [_idPFH] call CBA_fnc_removePerFrameHandler;
            };

            [_groups select [_index, _perFrame]] call FUNC(virtualiseGroups);

            _args set [3, _index + _perFrame];
        }, 0, [_groups, _count, _perFrame, 0]] call CBA_fnc_addPerFrameHandler;
    }, DELAY, []] call CBA_fnc_addPerFrameHandler;

    [{
        if (GVAR(killswitched) || isGamePaused) exitWith {};
        call FUNC(simulateGroups);
    }, SIM_DELAY, []] call CBA_fnc_addPerFrameHandler;

    [{
        if (GVAR(killswitched) || isGamePaused) exitWith {};

        private _bufferedDistance = GVAR(distance) - 200;

        private _players = ALL_PLAYERS select {!((objectParent _x) isKindOf "Air")};
        private _positions = GVAR(groupPositionMap) apply {_x#1};
        private _groupIndex = -1;
        {
            private _player = _x;
            private _indices = _positions inAreaArrayIndexes [getPosATL _player, _bufferedDistance, _bufferedDistance, 0, false];
            {
                if ((_groupIndex < 0 || {_x < _groupIndex}) && {_player distance (_positions#_x) <= _bufferedDistance}) then {
                    _groupIndex = _x;
                };
            } forEach _indices;
        } forEach _players;

        if (_groupIndex == -1) exitWith {};

        [_groupIndex] call FUNC(devirtualiseGroup);
    }, DELAY, []] call CBA_fnc_addPerFrameHandler;
};

if (hasInterface) then {
    call FUNC(addAdminActions);
};
