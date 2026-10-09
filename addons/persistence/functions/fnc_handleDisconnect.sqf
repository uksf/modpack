#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Handles client disconnect on server

    Parameter(s):
        0: Unit <OBJECT>
        1: Id <NUMBER>
        2: UID <STRING>
        3: Name <STRING>

    Return Value:
        None

    Example:
        [_unit, _id, _uid, _name] call uksf_persistence_fnc_handleDisconnect
*/
params ["_unit", "_id", "_uid", "_name"];

TRACE_4("HandleDisconnect",_unit,_id,_uid,_name);

[GVAR(hashHasRedeployed), _uid, false] call CBA_fnc_hashSet;
[GVAR(hashFirstRespawn), _uid, true] call CBA_fnc_hashSet;
[GVAR(hashBodies), _uid, _unit] call CBA_fnc_hashSet;

[_unit, _uid] call FUNC(storePlayerData);

if (GVAR(shutdownInProgress)) then {
    GVAR(shutdownDisconnectedCount) = GVAR(shutdownDisconnectedCount) + 1;
    DEBUG_2("Shutdown disconnect saved: %1 (%2 of expected)",_name,GVAR(shutdownDisconnectedCount));
};
