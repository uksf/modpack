#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Creats Tank and APC

    Parameters:
        None

    Return value:
        Nothing
*/

if (!isServer || {count GVAR(responseGroups) > GVAR(groupLimit)}) exitWith {};

// APC
[{
    params ["_args", "_idPFH"];
    _args params ["_groupCount", "_numberOfResponseGroupsToBeSpawned"];

    if (_groupCount == 0 || {count GVAR(responseGroups) > GVAR(groupLimit)}) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
    };

    [GVAR(apcSpawns), true] call CBA_fnc_shuffle;
    private _index = GVAR(apcSpawns) findIf {alive _x};
    if (_index == -1) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
    };

    private _spawnPosition = GVAR(apcSpawns) select _index;
    private _stagingArea = [_spawnPosition] call FUNC(getStagingAreas);
    private _player = [_stagingArea] call FUNC(getPlayer);
    if (isNull _player) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
        [{call FUNC(responseTankAndAPC)}, 300] call CBA_fnc_waitAndExecute;
    };

    [_spawnPosition, {
        params ["", "", "", "", "_group"];

        GVAR(responseGroups) pushBack _group;
        call FUNC(addWaypoints);
    }, [_spawnPosition, _stagingArea, _player, _numberOfResponseGroupsToBeSpawned]] call FUNC(createGroupAPC);

    _args set [0, _groupCount - 1];
}, 12, [2, 2]] call CBA_fnc_addPerFrameHandler;

// Tank
[{
    params ["_args", "_idPFH"];
    _args params ["_groupCount", "_numberOfResponseGroupsToBeSpawned"];

    if (_groupCount == 0 || {count GVAR(responseGroups) > GVAR(groupLimit)}) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
    };

    [GVAR(tankSpawns), true] call CBA_fnc_shuffle;
    private _index = GVAR(tankSpawns) findIf {alive _x};
    if (_index == -1) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
    };

    private _spawnPosition = GVAR(tankSpawns) select _index;
    private _stagingArea = [_spawnPosition] call FUNC(getStagingAreas);
    private _player = [_stagingArea] call FUNC(getPlayer);
    if (isNull _player) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
        [{call FUNC(responseTankAndAPC)}, 300] call CBA_fnc_waitAndExecute; // TODO: This will queue the function to run twice if the PFH above also fails to find a player
    };

    [_spawnPosition, {
        params ["", "", "", "", "_group"];

        GVAR(responseGroups) pushBack _group;
        call FUNC(addWaypoints);
    }, [_spawnPosition, _stagingArea, _player, _numberOfResponseGroupsToBeSpawned]] call FUNC(createGroupTank);

    _args set [0, _groupCount - 1];
}, 12, [2, 2]] call CBA_fnc_addPerFrameHandler;
