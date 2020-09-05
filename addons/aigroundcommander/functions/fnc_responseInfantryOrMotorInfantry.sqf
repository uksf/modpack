#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Create infantry groups or motor inf groups

    Parameters:
        None

    Return value:
        Nothing
*/

if (!isServer || {count GVAR(responseGroups) > GVAR(groupLimit)}) exitWith {};

private _chance = random 10;
// private _chance = 6; // for debug

if (_chance <= 5) then {
    [{
        params ["_args", "_idPFH"];
        _args params ["_groupCount", "_numberOfResponseGroupsToBeSpawned"];

        if (_groupCount == 0 || {count GVAR(responseGroups) > GVAR(groupLimit)}) exitWith {
            [_idPFH] call CBA_fnc_removePerFrameHandler;
        };

        [GVAR(infantrySpawns), true] call CBA_fnc_shuffle;
        private _index = GVAR(infantrySpawns) findIf {alive _x};
        if (_index == -1) exitWith {
            [_idPFH] call CBA_fnc_removePerFrameHandler;
        };

        private _spawnPosition = GVAR(infantrySpawns) select _index;
        private _stagingArea = [_spawnPosition] call FUNC(getStagingAreas);
        private _player = [_stagingArea] call FUNC(getPlayer);
        if (isNull _player) exitWith {
            [_idPFH] call CBA_fnc_removePerFrameHandler;
            [{call FUNC(responseInfantryOrMotorInfantry)}, [], 300] call CBA_fnc_waitAndExecute;
        };

        [_spawnPosition, {
            params ["", "", "", "", "_group"];

            GVAR(responseGroups) pushBack _group;
            call FUNC(addWaypoints);
        }, [_spawnPosition, _stagingArea, _player, _numberOfResponseGroupsToBeSpawned]] call FUNC(createGroupInfantry);

        _args set [0, _groupCount - 1];
    }, 30, [3, 3]] call CBA_fnc_addPerFrameHandler;
} else {
    [{
        params ["_args", "_idPFH"];
        _args params ["_groupCount", "_numberOfResponseGroupsToBeSpawned"];

        if (_groupCount == 0 || {count GVAR(responseGroups) > GVAR(groupLimit)}) exitWith {
            [_idPFH] call CBA_fnc_removePerFrameHandler;
        };

        [GVAR(carSpawns), true] call CBA_fnc_shuffle;
        private _index = GVAR(carSpawns) findIf {alive _x};
        if (_index == -1) exitWith {
            [_idPFH] call CBA_fnc_removePerFrameHandler;
        };

        private _spawnPosition = GVAR(carSpawns) select _index;
        private _stagingArea = [_spawnPosition] call FUNC(getStagingAreas);
        private _player = [_stagingArea] call FUNC(getPlayer);
        if (isNull _player) exitWith {
            [_idPFH] call CBA_fnc_removePerFrameHandler;
            [{call FUNC(responseInfantryOrMotorInfantry)}, [], 300] call CBA_fnc_waitAndExecute;
        };

        [_spawnPosition, {
            params ["", "", "", "", "_group"];

            GVAR(responseGroups) pushBack _group;
            call FUNC(addWaypointsTransport);
        }, [_spawnPosition, _stagingArea, _player, _numberOfResponseGroupsToBeSpawned]] call FUNC(createGroupCarTransport);

        _args set [0, _groupCount - 1];
    }, 15, [2, 2]] call CBA_fnc_addPerFrameHandler;
};
