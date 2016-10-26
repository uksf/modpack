/*
    Author:
    	Tim Beswick

    Description:
    	Run cleanup

    Parameters:
    	0: Killed object <OBJECT>

    Return value:
    	Nothing
*/
#include "script_component.hpp"

params ["_object"];

if (!(_object getVariable [QGVAR(excluded), false])) then {
    [{
        
    }, _object, GVAR(delay)] call CBA_fnc_waitAndExecute;
};