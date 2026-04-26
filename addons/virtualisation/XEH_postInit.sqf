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

call FUNC(registerDebugProviders);

if (isServer) then {
    // Virtualisation
    [{
        // Killswitch
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

    // Recreation
    [{
        // Killswitch
        if (GVAR(killswitched) || isGamePaused) exitWith {};

        call FUNC(simulateGroups);

        // To avoid flicker, we'll recreate groups 200m closer, but virtualise 200m further away (400m buffer zone)
        private _bufferedDistance = GVAR(distance) - 200;

        private _groupIndex = GVAR(groupPositionMap) findIf {
            private _groupPosition = _x#1;

            [ALL_PLAYERS, {
                _x distance _groupPosition <= _bufferedDistance
                && {!((objectParent _x) isKindOf "Air")}
            }] call EFUNC(common,arrayAny)
        };

        if (_groupIndex == -1) exitWith {};

        private _id = (GVAR(groupPositionMap) deleteAt _groupIndex)#0;
        TRACE_1("requesting recreate group",_id);

        private _simulatedIndex = GVAR(simulatedGroupIds) findIf {_x == _id};
        if (_simulatedIndex >= 0) then { GVAR(simulatedGroupIds) deleteAt _simulatedIndex };

        private _entry = GVAR(groupDataMap) deleteAt _id;
        _entry params ["_side", "_vehicles", "_infantry", "_waypoints", "_combatMode", "_formationDirection",
                       "_simState", "", "", "", "_originalLeaderPos"];

        private _simPosition = _simState#1;
        private _rebaseDelta = [_simPosition#0 - _originalLeaderPos#0, _simPosition#1 - _originalLeaderPos#1, 0];

        private _payload = [_side, _vehicles, _infantry, _waypoints, _combatMode, _formationDirection, _rebaseDelta];
        [QGVAR(recreateGroup), [_payload]] call EFUNC(common,headlessEvent);
    }, DELAY, []] call CBA_fnc_addPerFrameHandler;
};

if (hasInterface) then {
    call FUNC(addAdminActions);
};
