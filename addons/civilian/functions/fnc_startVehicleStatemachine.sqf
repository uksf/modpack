#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Starts statemachine for civilian vehicle stop

    Parameters:
        0: Vehicle <OBJECT>

    Return value:
        Nothing
*/
params ["_vehicle"];

if !(local _vehicle) exitWith {};

GVAR(vehicle_statemachine_vehicles) pushBack _vehicle;

if !(isNull GVAR(vehicle_statemachine)) exitWith {
    [_vehicle, GVAR(vehicle_statemachine), QGVAR(vehicle_state_enter), QGVAR(vehicle_state_enter)] call CBA_statemachine_fnc_manualTransition;
};

GVAR(vehicle_statemachine) = [{GVAR(vehicle_statemachine_vehicles)}, true] call CBA_statemachine_fnc_create;

call FUNC(addVehicleStates);
call FUNC(addVehicleTransitions);
call FUNC(addVehicleEventTransitions);

// Temporary patch to transfer non-local units to their client. Should be fixed on ambient vehicle spawning side
[{
    private _nonLocal = (GVAR(vehicle_statemachine_vehicles) select {!(local _x)});
    {
        private _jipId = _x getVariable [QGVAR(vehicle_interaction_jipId), ""];
        [_jipId] call CBA_fnc_removeGlobalEventJIP;
        [QGVAR(removeVehicleInteractions), [_x]] call CBA_fnc_globalEvent;
        
        GVAR(vehicle_statemachine_vehicles) deleteAt (GVAR(vehicle_statemachine_vehicles) find _x);
        [QGVAR(startVehicleStatemachine), [_x], _x] call CBA_fnc_targetEvent;
    } forEach _nonLocal;
}, 5] call CBA_fnc_addPerFrameHandler;
