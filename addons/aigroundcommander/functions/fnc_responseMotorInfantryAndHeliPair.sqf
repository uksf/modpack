#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Creates motor inf and heli pair

    Parameters:
        None.
        
    Return value:
        Nothing
*/


// motor inf
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
            call FUNC(responseMotorInfantryAndHeliPair);
        },300] call cba_fnc_waitAndExecute;
    };    

    private _group = [_spawnPosition, {
            params ["_spawnPosition", "_stagingArea", "_player", "_numberOfResponseGroupsToBeSpawned", "_group"];

            GVAR(responseGroups) pushBack _group;
            [_group, _spawnPosition, _stagingArea, _player, _numberOfResponseGroupsToBeSpawned] call FUNC(addWaypointsTpt);
        }, [_spawnPosition, _stagingArea, _player, _numberOfResponseGroupsToBeSpawned]] call FUNC(createGroupCarTpt);

    _groupCount = _groupCount - 1;

    _args set [0, _groupCount];
},15,[2,2]] call CBA_fnc_addPerFrameHandler;

// heli pair
[{
    params ["_args","_idPFH"];
    _args params ["_groupCount"];

    if (_groupCount == 0) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
    };   

    private _spawnLocation = EGVAR(airCommander,heliLocations) findIf {alive _x};

    if (_spawnLocation == -1) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
    };

    private _spawnPosition = (EGVAR(airCommander,heliLocations) select _spawnLocation);
    [EGVAR(airCommander,heliLocations), true] call cba_fnc_shuffle;

    private _stagingArea = [_spawnPosition] call FUNC(getStagingAreas);
    private _player = [_stagingArea] call FUNC(getPlayers);

    if (isNull _player) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
        [{
            call FUNC(responseMotorInfantryAndHeliPair);
        },300] call cba_fnc_waitAndExecute;
    };    

    private _group = [_spawnPosition] call EFUNC(airCommander,createGroupAttackHeli);
    GVAR(responseGroups) pushBack _group;
    [_group, _spawnPosition, _stagingArea, _player] call FUNC(addWaypoints);
    _groupCount = _groupCount - 1;

    _args set [0, _groupCount];
},30,[2]] call CBA_fnc_addPerFrameHandler;

