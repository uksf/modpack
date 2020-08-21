#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Creates light attack vehicles (cars) and infantry

    Parameters:
        None.
        
    Return value:
        Nothing
*/

// light attack vehs
[{
    params ["_args","_idPFH"];
    _args params ["_groupCount","_numberOfResponseGroupsToBeSpawned"];

    if (_groupCount == 0) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
    };   

    private _spawnLocation = GVAR(carLocations) findIf {alive _x};

    if (_spawnLocation == -1) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
    };

    private _spawnPosition = (GVAR(carLocations) select _spawnLocation);
    [GVAR(carLocations), true] call cba_fnc_shuffle;

    private _stagingArea = [_spawnPosition] call FUNC(getStagingAreas);
    private _player = [_stagingArea] call FUNC(getPlayers);

    if (isNull _player) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
        [{
            call FUNC(responseCarAndInfantry);
        },300] call cba_fnc_waitAndExecute;
    };    

    private _group = [_spawnPosition, {
        params ["_spawnPosition", "_stagingArea", "_player", "_numberOfResponseGroupsToBeSpawned", "_group"];

        GVAR(responseGroups) pushBack _group;
        [_group, _spawnPosition, _stagingArea, _player, _numberOfResponseGroupsToBeSpawned] call FUNC(addWaypoints);
    }, [_spawnPosition, _stagingArea, _player, _numberOfResponseGroupsToBeSpawned]] call FUNC(createGroupCar);

    _groupCount = _groupCount - 1;

    _args set [0, _groupCount];
},5,[4,4]] call CBA_fnc_addPerFrameHandler;

// infantry
[{
    params ["_args","_idPFH"];
    _args params ["_groupCount","_numberOfResponseGroupsToBeSpawned"];

    if (_groupCount == 0) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
    };   

    private _spawnLocation = GVAR(infantryLocations) findIf {alive _x};

    if (_spawnLocation == -1) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
    };

    private _spawnPosition = (GVAR(infantryLocations) select _spawnLocation);
    [GVAR(infantryLocations), true] call cba_fnc_shuffle;

    private _stagingArea = [_spawnPosition] call FUNC(getStagingAreas);
    private _player = [_stagingArea] call FUNC(getPlayers);

    if (isNull _player) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
        [{
            call FUNC(responseCarAndInfantry);
        },300] call cba_fnc_waitAndExecute;
    };    

    private _group = [_spawnPosition] call FUNC(createGroupInfantry);
    GVAR(responseGroups) pushBack _group;
    [_group, _spawnPosition, _stagingArea, _player, _numberOfResponseGroupsToBeSpawned] call FUNC(addWaypoints);
    _groupCount = _groupCount - 1;

    _args set [0, _groupCount];
},30,[3,3]] call CBA_fnc_addPerFrameHandler;
