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

if (isMultiplayer && !isServer) exitWith {};

HCs = [];
{
    _id = owner _x;
    HCs = HCs + [_id];
} forEach (entities "HeadlessClient_F");

if (!isMultiplayer || is3DENMultiplayer) then {
    HCs = [player, player];
};

#include "spawning.hpp"