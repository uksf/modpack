#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Create infantry groups or motor inf groups

    Parameters:
        None.

    Return value:
        Nothing
*/

private _chance = random 10;
// private _chance = 6; // for debug

if (_chance <= 5) then {

    [{
        params ["_args","_idPFH"];
        _args params ["_groupCount","_numberOfResponseGroupsToBeSpawned"];

        if (_groupCount == 0) exitWith {
            [_idPFH] call CBA_fnc_removePerFrameHandler;
        };

        private _spawnLocation = GVAR(infantrySpawns) findIf {alive _x};

        if (_spawnLocation == -1) exitWith {
            [_idPFH] call CBA_fnc_removePerFrameHandler;
        };

        private _spawnPosition = (GVAR(infantrySpawns) select _spawnLocation);
        [GVAR(infantrySpawns), true] call cba_fnc_shuffle;

        private _stagingArea = [_spawnPosition] call FUNC(getStagingAreas);
        private _player = [_stagingArea] call FUNC(getPlayers);

        if (isNull _player) exitWith {
            [_idPFH] call CBA_fnc_removePerFrameHandler;
            [{
                call FUNC(responseInfantryOrMotorInfantry);
            },300] call cba_fnc_waitAndExecute;
        };

        private _group = [_spawnPosition] call FUNC(createGroupInfantry);
        GVAR(responseGroups) pushBack _group;
        [_group,_spawnPosition,_stagingArea,_player,_numberOfResponseGroupsToBeSpawned] call FUNC(addWaypoints);
        _groupCount = _groupCount - 1;

        _args set [0, _groupCount];
    },30,[3,3]] call CBA_fnc_addPerFrameHandler;
} else {
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
        [GVAR(carSpawns), true] call cba_fnc_shuffle;

        private _stagingArea = [_spawnPosition] call FUNC(getStagingAreas);
        private _player = [_stagingArea] call FUNC(getPlayers);

        if (isNull _player) exitWith {
            [_idPFH] call CBA_fnc_removePerFrameHandler;
            [{
                call FUNC(responseInfantryOrMotorInfantry);
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
};
