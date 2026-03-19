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

    Example:
        call uksf_aiaircommander_fnc_moduleCommander
*/

if (!isServer) exitWith {};

GVAR(enabled) = true;
publicVariable QGVAR(enabled);

[{
    [{
        params ["_args", "_idPFH"];

        if (!alive atc) then {
            [_idPFH] call CBA_fnc_removePerFrameHandler;
        };

        [0] call FUNC(selectMission);
        call FUNC(checkAA);
    }, 1200] call CBA_fnc_addPerFrameHandler;
}, [], 60] call CBA_fnc_waitAndExecute;


