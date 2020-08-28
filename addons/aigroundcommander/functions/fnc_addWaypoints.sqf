#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Adds waypoints to AI groups

    Parameters:
        0: _group <GROUP>
        1: _spawnPosition <OBJECT>
        2: _stagingArea <OBJECT>
        3: _player <OBJECT>

    Return value:
        Nothing
*/
#define TIMEOUT 420

params ["_group","_spawnPosition","_stagingArea","_player","_numberOfResponseGroupsToBeSpawned"];

[{
    // If you utilise the callback pattern for all group spawning, you don't need this WUAE which checks this every frame.
    alive leader (_this select 0)
},{
    params ["_group","_spawnPosition","_stagingArea","_player","_numberOfResponseGroupsToBeSpawned"];
    _group setVariable [QGVAR(spawnPosition),_spawnPosition,true]; // used in selectStayBehindForce

    // default move to staging area for all groups
    [_group,_stagingArea,50,"MOVE","AWARE","YELLOW","NORMAL","WEDGE","uksf_aigroundCommander_readyAtStagingArea = uksf_aigroundCommander_readyAtStagingArea + 1;", [0,0,0], 50] call cba_fnc_addWaypoint;
    // (leader _group) doMove (getPos _stagingArea);

    // for helis
    if (vehicle (leader _group) isKindOf "helicopter") exitWith {
        [_group,_player,100,"SAD","COMBAT","AWARE","YELLOW","NORMAL",""] call cba_fnc_addWaypoint;
        [_group,_player,300,"SAD","COMBAT","AWARE","YELLOW","NORMAL","(vehicle this) flyInHeight 100;"] call cba_fnc_addWaypoint;
        [_group,_spawnPosition,50,"MOVE","AWARE","YELLOW","FULL","FILE","(vehicle this) land 'LAND';"] call cba_fnc_addWaypoint;
        [_group,_spawnPosition,1,"MOVE","AWARE","YELLOW","FULL","FILE","[this] call uksf_groundCommander_fnc_handleDelete;"] call cba_fnc_addWaypoint;
    };

    // diag_log format ["AI CMDR: NumOfGroups: %1, 75: %2, readyAtStagingArea: %3",_numberOfResponseGroupsToBeSpawned,floor (_numberOfResponseGroupsToBeSpawned * 0.75),GVAR(readyAtStagingArea)];
    // Actually going to recommend using a PFH for this as you can control the check interval. WUAE is every frame, which is excessive for this application. Fewer codeblocks to manage too.
    [{
        params ["_args", "_idPFH"];
        _args params ["_group", "_player", "_numberOfResponseGroupsToBeSpawned", "_75Percent", "_timeout"];

        if (GVAR(readyAtStagingArea) >= _75Percent || _timeout > time) exitWith {
            [_idPFH] call CBA_fnc_removePerFrameHandler;

            [_group, _player, 200, "SAD", "AWARE", "YELLOW", "NORMAL", "FILE", "[(group this)] call uksf_aigroundCommander_fnc_selectStayBehindForce;"] call cba_fnc_addWaypoint;
        };
    }, 10, [_group,_player,_numberOfResponseGroupsToBeSpawned, floor (_numberOfResponseGroupsToBeSpawned * 0.75), time + TIMEOUT]] call CBA_fnc_addPerFrameHandler;
},[_group,_spawnPosition,_stagingArea,_player,_numberOfResponseGroupsToBeSpawned]] call cba_fnc_waitUntilAndExecute;
