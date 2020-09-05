#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Creates light attack vehicles (cars) and infantry

    Parameters:
        None

    Return value:
        Nothing
*/

// light attack vehs
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
        [{call FUNC(responseCarAndInfantry)}, 300] call CBA_fnc_waitAndExecute;
    };

    [_spawnPosition, {
        params ["", "", "", "", "_group"];

        GVAR(responseGroups) pushBack _group;
        call FUNC(addWaypoints);
    }, [_spawnPosition, _stagingArea, _player, _numberOfResponseGroupsToBeSpawned]] call FUNC(createGroupCar);

    _args set [0, _groupCount - 1];
}, 5, [4, 4]] call CBA_fnc_addPerFrameHandler;

// infantry
[{
    params ["_args", "_idPFH"];
    _args params ["_groupCount", "_numberOfResponseGroupsToBeSpawned"];

    if (_groupCount == 0) exitWith {
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
        [{call FUNC(responseCarAndInfantry)}, 300] call CBA_fnc_waitAndExecute; // TODO: This will queue the function to run twice if the PFH above also fails to find a player
    };

    [_spawnPosition, {
        params ["", "", "", "", "_group"];

        GVAR(responseGroups) pushBack _group;
        call FUNC(addWaypoints);
    }, [_spawnPosition, _stagingArea, _player, _numberOfResponseGroupsToBeSpawned]] call FUNC(createGroupInfantry);

    _args set [0, _groupCount - 1];
}, 30, [3, 3]] call CBA_fnc_addPerFrameHandler;
