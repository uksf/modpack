#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        for transport
        adds waypoints to AI groups to move to staging areas then dismount

    Parameters:
        0: _group <GROUP>
        1: _spawnPosition <POSITION>
        
    Return value:
        Nothing
*/

params ["_group","_spawnPosition","_stagingArea","_player","_numberOfResponseGroupsToBeSpawned"];

[{alive leader (_this select 0)},{

    params ["_group","_spawnPosition","_stagingArea","_player","_numberOfResponseGroupsToBeSpawned"];

    _group setVariable [QGVAR(spawnPosition),_spawnPosition,true]; // needed as I can't pass spawn point into the wp as a param
    _group setVariable [QGVAR(SAPos),_stagingArea,true]; // needed as I can't pass spawn point into the wp as a param

    [_group,_stagingArea,50,"MOVE","AWARE","YELLOW","NORMAL","FILE","uksf_aigroundCommander_readyAtStagingArea = uksf_aigroundCommander_readyAtStagingArea + 1;"] call cba_fnc_addWaypoint;

    [{
        params ["_group","_player","_numberOfResponseGroupsToBeSpawned"];
        (GVAR(readyAtStagingArea) >= floor(_numberOfResponseGroupsToBeSpawned * 0.75))}, {

        params ["_group","_player","_numberOfResponseGroupsToBeSpawned"];

        [_group,_player,300,"GETOUT","AWARE","YELLOW","NORMAL","FILE","[this] call uksf_aigroundCommander_fnc_unloadTransport;"] call cba_fnc_addWaypoint;
        GVAR(readyAtStagingAreaTimeout) = 0;
    },[_group,_player,_numberOfResponseGroupsToBeSpawned],420,{
        [_group,_player,300,"GETOUT","AWARE","YELLOW","NORMAL","FILE","[this] call uksf_aigroundCommander_fnc_unloadTransport;"] call cba_fnc_addWaypoint;
        GVAR(readyAtStagingAreaTimeout) = 0;
    }] call cba_fnc_waitUntilAndExecute;
},[_group,_spawnPosition,_stagingArea,_player,_numberOfResponseGroupsToBeSpawned]] call cba_fnc_waitUntilAndExecute;