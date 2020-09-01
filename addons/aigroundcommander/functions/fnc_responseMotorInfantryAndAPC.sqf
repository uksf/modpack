#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Creates APC and Motor inf

    Parameters:
        None.

    Return value:
        Nothing
*/



// APC
[{
    params ["_args","_idPFH"];
    _args params ["_groupCount","_numberOfResponseGroupsToBeSpawned"];

    if (_groupCount == 0) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
    };

    private _spawnLocation = GVAR(apcSpawns) findIf {alive _x};

    if (_spawnLocation == -1) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
    };

    private _spawnPosition = (GVAR(apcSpawns) select _spawnLocation);
    [GVAR(apcSpawns), true] call CBA_fnc_shuffle;

    private _stagingArea = [_spawnPosition] call FUNC(getStagingAreas);
    private _player = [_stagingArea] call FUNC(getPlayers);

    if (isNull _player) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
        [{
            call FUNC(responseMotorInfantryAndAPC);
        },300] call CBA_fnc_waitAndExecute;
    };

    private _group = [_spawnPosition, {
        // callback (_group is appended to the args array in createGroupAPC)
        params ["_spawnPosition", "_stagingArea", "_player", "_numberOfResponseGroupsToBeSpawned", "_group"];

        GVAR(responseGroups) pushBack _group;
        [_group, _spawnPosition, _stagingArea, _player, _numberOfResponseGroupsToBeSpawned] call FUNC(addWaypoints);
    }, [_spawnPosition, _stagingArea, _player, _numberOfResponseGroupsToBeSpawned]] call FUNC(createGroupAPC);

    _groupCount = _groupCount - 1;

    _args set [0, _groupCount];
},15,[3,3]] call CBA_fnc_addPerFrameHandler;

// motor inf
[{
    params ["_args","_idPFH"];
    _args params ["_groupCount","_numberOfResponseGroupsToBeSpawned"];

    if (_groupCount == 0) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
    };

    private _spawnLocation = GVAR(carSpawns) findIf {alive _x};

    if (_spawnLocation == -1) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
    };

    private _spawnPosition = (GVAR(carSpawns) select _spawnLocation);
    [GVAR(carSpawns), true] call CBA_fnc_shuffle;

    private _stagingArea = [_spawnPosition] call FUNC(getStagingAreas);
    private _player = [_stagingArea] call FUNC(getPlayers);

    if (isNull _player) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
        [{
            call FUNC(responseMotorInfantryAndAPC);
        },300] call CBA_fnc_waitAndExecute;
    };

    private _group = [_spawnPosition, {
            params ["_spawnPosition", "_stagingArea", "_player", "_numberOfResponseGroupsToBeSpawned"];

            GVAR(responseGroups) pushBack _group;
            [_group, _spawnPosition, _stagingArea, _player, _numberOfResponseGroupsToBeSpawned] call FUNC(addWaypointsTpt);
    }, [_spawnPosition, _stagingArea, _player, _numberOfResponseGroupsToBeSpawned]] call FUNC(createGroupCarTpt);
    _groupCount = _groupCount - 1;

    _args set [0, _groupCount];
},15,[2,2]] call CBA_fnc_addPerFrameHandler;
