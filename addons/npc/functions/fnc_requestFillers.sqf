#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Client asks the server for cached filler clips after its own sinks exist.

    Parameter(s):
        None

    Return Value:
        None

    Example:
        call uksf_npc_fnc_requestFillers
*/
if (!hasInterface) exitWith {};
[QGVAR(requestFillers), [player]] call CBA_fnc_serverEvent;
