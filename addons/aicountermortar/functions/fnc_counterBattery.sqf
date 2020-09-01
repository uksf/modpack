#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        sets up and executes counter battery fire

    Parameters:
        None
        
    Return value:
        Nothing
*/

if (!isServer) exitWith {};

params ["_bluforMortarPos","_counterBatteryUnit"];

[_counterBatteryUnit,_counterBatteryUnit,_bluforMortarPos] call EFUNC(mission,fireMission);

[{
    GVAR(counterInProgress) = 0;
},[],1200] call cba_fnc_waitAndExecute;