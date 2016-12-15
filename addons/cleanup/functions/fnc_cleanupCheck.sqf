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
        private _newKilled = [];
        {
            _x params ["_object", "_time"];
            _multiplier = if (_object isKindOf "Man") then {
                1
            } else {
                2
            };
            if (!(_object getVariable [QGVAR(excluded), false])) then {
                if ((_time + (GVAR(delay) * _multiplier)) < time) then {
                    deleteVehicle _object;
                } else {
                    _newKilled pushBack _x;
                };                
            };
            false
        } count _killed;
        missionNamespace setVariable [QGVAR(killed), _newKilled, true];
    }, GVAR(delay) / 4, []] call CBA_fnc_addPerFrameHandler;
};
