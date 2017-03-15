/*
    Author:
        Tim Beswick

    Description:
        Adds event handlers for all players

    Parameter(s):
        None

    Return Value:
        Nothing
*/
#include "script_component.hpp"

if (isServer) then {
    addMissionEventHandler ["EntityRespawned", {INFO_1("%1 Mission Respawned",(_this select 0))}];
    addMissionEventHandler ["EntityKilled", {INFO_1("%1 Mission Killed",(_this select 0))}];
    addMissionEventHandler ["HandleDisconnect", {INFO_1("%1 Mission Disconnected",(_this select 0))}];
    addMissionEventHandler ["PlayerConnected", {INFO_1("%1 Mission Player Connected",(_this select 2))}];
    addMissionEventHandler ["PlayerDisconnected", {INFO_1("%1 Mission Player Disconnected",(_this select 2))}];
};

if (!hasInterface) exitWith {};

player addEventHandler ["Respawn", {INFO_1("%1 Respawned",(_this select 0))}];
player addEventHandler ["Killed", {INFO_1("%1 was Killed",(_this select 0))}];
player addMPEventHandler ["MPKilled", {INFO_1("%1 was MPKilled",(_this select 0))}];
