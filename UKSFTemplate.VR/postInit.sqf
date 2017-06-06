/*
    Author:
    	Tim Beswick

    Description:
    	Adds mission stuff

    Parameters:
    	None
        
    Return value:
    	Nothing
*/

if ((!isServer && !hasInterface) || !isMultiplayer || is3DENMultiplayer) then {
    ["uksf_spawn_spawnGroup", {_this call uksf_spawn_fnc_spawnGroup}] call CBA_fnc_addEventHandler;
};

call uksf_spawn_fnc_getGroups;

if (isServer) then {
    #include "spawning.hpp"
};
