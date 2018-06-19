/*
    Author:
        Tim Beswick

    Description:
        Handles client disconnect on server

    Parameter(s):
        PlayerDisconnected params

    Return Value:
        None
*/
#include "script_component.hpp"

params ["_id", "_uid", "_name", "_jip", "_owner"];

TRACE_5("PlayerDisconnected",_id,_uid,_name,_jip,_owner);
