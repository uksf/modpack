#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Init for air commander:
            - Inits PFH for missions

    Parameters:
        None.

    Return value:
        Nothing
*/

if (!isServer) exitWith {};

// mission PFH
[{
    params ["_args","_idPFH"];
    if (!alive atc) then {
        [_idPFH] call cba_fnc_removePerFrameHandler;
    };
    call FUNC(selectMission);
    call FUNC(checkAA);
},1200]call cba_fnc_addPerFrameHandler;
