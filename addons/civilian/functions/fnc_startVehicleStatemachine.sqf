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

    Example:
        [_vehicle] call uksf_civilian_fnc_startVehicleStatemachine
*/
params ["_vehicle"];

if !(local _vehicle) exitWith {};

if (_vehicle in GVAR(vehicle_statemachine_vehicles)) exitWith {};
GVAR(vehicle_statemachine_vehicles) pushBack _vehicle;

_vehicle removeEventHandler ["Local", _vehicle getVariable [QGVAR(vehicle_localHandler), -1]];
private _localHandler = _vehicle addEventHandler ["Local", {
    params ["_object", "_isLocal"];
    if (_isLocal) exitWith {};
    _object removeEventHandler ["Local", _thisEventHandler];
    private _index = GVAR(vehicle_statemachine_vehicles) find _object;
    if (_index < 0) exitWith {};
    GVAR(vehicle_statemachine_vehicles) deleteAt _index;
    private _jipId = _object getVariable [QGVAR(vehicle_interaction_jipId), ""];
    if (_jipId isNotEqualTo "") then {[_jipId] call CBA_fnc_removeGlobalEventJIP};
    [QGVAR(removeVehicleInteractions), [_object]] call CBA_fnc_globalEvent;
    [QGVAR(startVehicleStatemachine), [_object], _object] call CBA_fnc_targetEvent;
}];
_vehicle setVariable [QGVAR(vehicle_localHandler), _localHandler];

if !(isNull GVAR(vehicle_statemachine)) exitWith {
    [_vehicle, GVAR(vehicle_statemachine), QGVAR(vehicle_state_enter), QGVAR(vehicle_state_enter)] call CBA_statemachine_fnc_manualTransition;
};

GVAR(vehicle_statemachine) = [{GVAR(vehicle_statemachine_vehicles) = GVAR(vehicle_statemachine_vehicles) select {!isNull _x}; GVAR(vehicle_statemachine_vehicles)}, true] call CBA_statemachine_fnc_create;

call FUNC(addVehicleStates);
call FUNC(addVehicleDriverStates);
call FUNC(addVehicleTransitions);
call FUNC(addVehicleEventTransitions);
