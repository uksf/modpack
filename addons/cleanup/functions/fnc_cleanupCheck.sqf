/*
    Author:
    	Tim Beswick

    Description:
    	Run cleanup every 1/4 of delay time

    Parameters:
    	None

    Return value:
    	Nothing
*/
#include "script_component.hpp"

if (GVAR(enabled)) then {
    [{
        _killed = missionNamespace getVariable [QGVAR(killed), []];
        missionNamespace setVariable [QGVAR(killed), [], true];
        {
            _x params ["_object", "_time"];
            if (!(_object getVariable [QGVAR(excluded), false]) && ((_time + GVAR(delay) - 10) < time)) then {
                deleteVehicle _object;
            };
            false
        } count _killed;
    }, GVAR(delay) / 4, []] call CBA_fnc_addPerFrameHandler;
};
