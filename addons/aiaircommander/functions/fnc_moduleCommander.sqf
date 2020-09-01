#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Init pfh for air commander

    Parameters:
        None

    Return value:
        Nothing
*/

if (!isServer) exitWith {};

[{
    params ["_args", "_idPFH"];

    if (!alive atc) then {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
    };

    call FUNC(selectMission);
    call FUNC(checkAA);
},1200]call CBA_fnc_addPerFrameHandler;
