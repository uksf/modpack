#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        adds EH to CAManBase units

    Parameters:
        None
        
    Return value:
        Nothing
*/

["CAManBase", "init", {_this#0 addMPEventHandler ["MPHit", {call FUNC(getDown)}]}, true, [], true] call CBA_fnc_addClassEventHandler;
