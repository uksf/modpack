#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Creates motor inf and heli pair

    Parameters:
        None

    Return value:
        Nothing
*/

// motor inf
[{
    params ["_args", "_idPFH"];
    _args params ["_groupCount", "_numberOfResponseGroupsToBeSpawned"];

    if (_groupCount == 0) exitWith {
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
        [{call FUNC(responseMotorInfantryAndHeliPair)}, 300] call CBA_fnc_waitAndExecute;
    };

    [_spawnPosition, {
        params ["", "", "", "", "_group"];

        GVAR(responseGroups) pushBack _group;
        call FUNC(addWaypointsTpt);
    }, [_spawnPosition, _stagingArea, _player, _numberOfResponseGroupsToBeSpawned]] call FUNC(createGroupCarTpt);

    _args set [0, _groupCount - 1];
}, 15, [2, 2]] call CBA_fnc_addPerFrameHandler;

// heli pair
[{
    params ["_args", "_idPFH"];
    _args params ["_groupCount"];

    if (_groupCount == 0) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
    };

    [EGVAR(airCommander,heliSpawns), true] call CBA_fnc_shuffle;
    private _index = EGVAR(airCommander,heliSpawns) findIf {alive _x};
    if (_index == -1) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
    };

    private _spawnPosition = EGVAR(airCommander,heliSpawns) select _index;
    private _stagingArea = [_spawnPosition] call FUNC(getStagingAreas);
    private _player = [_stagingArea] call FUNC(getPlayer);
    if (isNull _player) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
        [{call FUNC(responseMotorInfantryAndHeliPair)}, 300] call CBA_fnc_waitAndExecute; // TODO: This will queue the function to run twice if the PFH above also fails to find a player
    };

    [_spawnPosition, {
        params ["", "", "", "", "_group"];

        GVAR(responseGroups) pushBack _group;
        call FUNC(addWaypoints);
    }, [_spawnPosition, _stagingArea, _player, 0]] call FUNC(createGroupAttackHeli);

    _args set [0, _groupCount - 1];
}, 30, [2]] call CBA_fnc_addPerFrameHandler;

