/*
    Author:
        Tim Beswick

    Description:
        Handles client connect on server

    Parameter(s):
        PlayerConnected params

    Return Value:
        None
*/
#include "script_component.hpp"

params ["_id", "_uid", "_name", "_jip", "_owner"];

TRACE_5("PlayerConnected",_id,_uid,_name,_jip,_owner);

[QGVAR(initClient), nil, _owner] call CBA_fnc_ownerEvent;
