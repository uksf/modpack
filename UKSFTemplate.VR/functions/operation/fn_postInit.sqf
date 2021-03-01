#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Runs at mission PostInit, AFTER all mission objects are loaded.
        Use this to perform operations at mission start, for example:
            - Modifying mission objects
            - Adding ACE interactions
            - Starting any long running per frame handlers

    Parameters:
        Nothing

    Return value:
        Nothing
*/

[{
    params ["_args", "_idPFH"];
    _args params ["_text"];

    [_idPFH] call CBA_fnc_removePerFrameHandler;
}, 0, ["parameter1"]] call CBA_fnc_addPerFrameHandler;
