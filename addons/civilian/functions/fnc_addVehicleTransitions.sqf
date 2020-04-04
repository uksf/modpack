#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Adds statemachine transitions for vehicle

    Parameters:
        None

    Return value:
        Nothing
*/
// Add transition: FromState, ToState, Condition, OnTransition, Name

// Transition - enter -> stopping
[GVAR(vehicle_statemachine), QGVAR(vehicle_state_enter), QGVAR(vehicle_state_stopping), {
    // Condition - vehicle has slowed down
    params ["_vehicle"];

    (speed _vehicle) < 30
}, {}, QGVAR(vehicle_transition_enter_stopping)] call CBA_statemachine_fnc_addTransition;

// Transition - stopping -> exit (ignoring)
[GVAR(vehicle_statemachine), QGVAR(vehicle_state_stopping), QGVAR(vehicle_state_exit), {
    // Condition - driver is annoyed (threshold)
    params ["_vehicle"];

    private _annoyed = _vehicle getVariable [QGVAR(vehicle_statemachine_annoyed), 0];
    !alive _vehicle || {!alive _driver} || {_annoyed > VEHICLE_STOP_ANNOYED_THRESHOLD}
}, {
    // OnTransition - set driver as ignoring stop (annoyed)
    params ["_vehicle"];

    private _driver = driver _vehicle;
    _driver setVariable [QGVAR(ignoringStop), true, true];
    private _annoyed = _vehicle getVariable [QGVAR(vehicle_statemachine_annoyed), 0];
    TRACE_3("Exit triggered. Annoyed?",_vehicle,_annoyed,VEHICLE_STOP_ANNOYED_THRESHOLD);
}, QGVAR(vehicle_transition_stopping_stopped)] call CBA_statemachine_fnc_addTransition;

// Transition - stopping -> stopped
[GVAR(vehicle_statemachine), QGVAR(vehicle_state_stopping), QGVAR(vehicle_state_stopped), {
    // Condition - vehicle has stopped moving
    params ["_vehicle"];

    private _driver = driver _vehicle;

    !alive _vehicle || {!alive _driver} || {speed _vehicle < 0.1}
}, {
    // OnTransition -
}, QGVAR(vehicle_transition_stopping_stopped)] call CBA_statemachine_fnc_addTransition;

// Transition - stopping -> move
[GVAR(vehicle_statemachine), QGVAR(vehicle_state_stopping), QGVAR(vehicle_state_move), {
    // Condition - there is a move command position
    params ["_vehicle"];

    private _driver = driver _vehicle;
    private _commandPosition = _vehicle getVariable [QGVAR(vehicle_statemachine_movePosition), []];

    alive _vehicle && {alive _driver} && {!(_commandPosition isEqualTo [])}
}, {
    // OnTransition -
}, QGVAR(vehicle_transition_stopping_move)] call CBA_statemachine_fnc_addTransition;

// Transition - move -> stopping
[GVAR(vehicle_statemachine), QGVAR(vehicle_state_move), QGVAR(vehicle_state_stopping), {
    // Condition - vehicle has stopped moving, and is at move command position
    params ["_vehicle"];

    private _driver = driver _vehicle;
    private _commandPosition = _vehicle getVariable [QGVAR(vehicle_statemachine_movePosition), getPos (_vehicle getVariable [QGVAR(vehicle_statemachine_moveCommander), _driver])];
    private _vehicleLength = _vehicle getVariable [QGVAR(vehicleLength), 4];

    !alive _vehicle || {!alive _driver} || {(_vehicle distance _commandPosition) < _vehicleLength}
}, {
    // OnTransition -
}, QGVAR(vehicle_transition_move_stopping)] call CBA_statemachine_fnc_addTransition;

// Transition - stopped -> exit (boredom || annoyed || bypass)
[GVAR(vehicle_statemachine), QGVAR(vehicle_state_stopped), QGVAR(vehicle_state_exit), {
    // Condition - driver is bored (threshold) OR bypass has been issued
    params ["_vehicle"];

    private _driver = driver _vehicle;
    private _bypass = _vehicle getVariable [QGVAR(vehicle_statemachine_bypass), false];
    private _boredom = _vehicle getVariable [QGVAR(vehicle_statemachine_boredom), 0];
    private _annoyed = _vehicle getVariable [QGVAR(vehicle_statemachine_annoyed), 0];

    !alive _vehicle || {!alive _driver} || {_bypass} || {_boredom > VEHICLE_STOP_BOREDOM_THRESHOLD} || {_annoyed > VEHICLE_STOP_ANNOYED_THRESHOLD}
}, {
    // OnTransition -
    params ["_vehicle"];

    private _driver = driver _vehicle;
    private _boredom = _vehicle getVariable [QGVAR(vehicle_statemachine_boredom), 0];
    private _annoyed = _vehicle getVariable [QGVAR(vehicle_statemachine_annoyed), 0];

    if (_annoyed > VEHICLE_STOP_ANNOYED_THRESHOLD) exitWith {
        _driver setVariable [QGVAR(ignoringStop), true, true];
        [{_driver setVariable [QGVAR(ignoringStop), false, true]}, [_driver], 360] call CBA_fnc_waitAndExecute;
        [QGVAR(horn), [_vehicle, _driver, 2], _vehicle] call CBA_fnc_targetEvent;
        TRACE_3("Exit triggered. Annoyed",_vehicle,_annoyed,VEHICLE_STOP_ANNOYED_THRESHOLD);
    };

    TRACE_3("Exit triggered. Bored",_vehicle,_boredom,VEHICLE_STOP_BOREDOM_THRESHOLD);
}, QGVAR(vehicle_transition_stopped_exit)] call CBA_statemachine_fnc_addTransition;

// Transition - getOut -> stopped
[GVAR(vehicle_statemachine), QGVAR(vehicle_state_getIn), QGVAR(vehicle_state_stopped), {
    // Condition - driver is in vehicle
    params ["_vehicle"];

    private _driver = _vehicle getVariable [QGVAR(vehicle_statemachine_driver), objNull];
    !alive _vehicle || {!alive _driver} || {_driver == (driver _vehicle)}
}, {
    // OnTransition - unset stored driver
    params ["_vehicle"];

    _vehicle setVariable [QGVAR(vehicle_statemachine_driver), objNull, true];
}, QGVAR(vehicle_transition_getIn_stopped)] call CBA_statemachine_fnc_addTransition;
