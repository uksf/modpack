#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Adds statemachine transitions for vehicle stop

    Parameters:
        None

    Return value:
        Nothing
*/
// Add transition: FromState, ToState, Condition, OnTransition, Name

// Transition - start -> stopping
[GVAR(stop_statemachine), QGVAR(stop_state_enter), QGVAR(stop_state_stopping), {true}, {}, QGVAR(stop_transition_enter_stopping)] call CBA_statemachine_fnc_addTransition;

// Transition - stopping -> exit (ignoring)
[GVAR(stop_statemachine), QGVAR(stop_state_stopping), QGVAR(stop_state_exit), {
    // Condition - driver is annoyed (threshold)
    params ["_vehicle"];

    private _annoyed = _vehicle getVariable [QGVAR(stop_statemachine_annoyed), 0];
    !alive _vehicle || {!alive _driver} || {_annoyed > STOP_STATEMACHINE_ANNOYED_THRESHOLD}
}, {
    // OnTransition - set driver as ignoring stop (annoyed)
    params ["_vehicle"];

    private _driver = driver _vehicle;
    _driver setVariable [QGVAR(ignoringStop), true, true];
    private _annoyed = _vehicle getVariable [QGVAR(stop_statemachine_annoyed), 0];
    TRACE_3("Exit triggered. Annoyed?",_vehicle,_annoyed,STOP_STATEMACHINE_ANNOYED_THRESHOLD);
}, QGVAR(stop_transition_stopping_stopped)] call CBA_statemachine_fnc_addTransition;

// Transition - stopping -> stopped
[GVAR(stop_statemachine), QGVAR(stop_state_stopping), QGVAR(stop_state_stopped), {
    // Condition - vehicle has stopped moving
    params ["_vehicle"];

    private _driver = driver _vehicle;

    !alive _vehicle || {!alive _driver} || {speed _vehicle < 1}
}, {
    // OnTransition -
}, QGVAR(stop_transition_stopping_stopped)] call CBA_statemachine_fnc_addTransition;

// Transition - stopping -> move
[GVAR(stop_statemachine), QGVAR(stop_state_stopping), QGVAR(stop_state_move), {
    // Condition - there is a move command position
    params ["_vehicle"];

    private _driver = driver _vehicle;
    private _commandPosition = _vehicle getVariable [QGVAR(stop_statemachine_movePosition), []];

    alive _vehicle && {alive _driver} && {!(_commandPosition isEqualTo [])}
}, {
    // OnTransition -
}, QGVAR(stop_transition_stopping_move)] call CBA_statemachine_fnc_addTransition;

// Transition - move -> stopping
[GVAR(stop_statemachine), QGVAR(stop_state_move), QGVAR(stop_state_stopping), {
    // Condition - vehicle has stopped moving, and is at move command position
    params ["_vehicle"];

    private _driver = driver _vehicle;
    private _commandPosition = _vehicle getVariable [QGVAR(stop_statemachine_movePosition), getPos (_vehicle getVariable [QGVAR(stop_statemachine_moveCommander), _driver])];
    private _vehicleLength = _vehicle getVariable [QGVAR(vehicleLength), 4];

    !alive _vehicle || {!alive _driver} || {(_vehicle distance _commandPosition) < _vehicleLength}
}, {
    // OnTransition -
}, QGVAR(stop_transition_move_stopping)] call CBA_statemachine_fnc_addTransition;

// Transition - stopped -> exit (boredom || annoyed || bypass)
[GVAR(stop_statemachine), QGVAR(stop_state_stopped), QGVAR(stop_state_exit), {
    // Condition - driver is bored (threshold) OR bypass has been issued
    params ["_vehicle"];

    private _driver = driver _vehicle;
    private _bypass = _vehicle getVariable [QGVAR(stop_statemachine_bypass), false];
    private _boredom = _vehicle getVariable [QGVAR(stop_statemachine_boredom), 0];
    private _annoyed = _vehicle getVariable [QGVAR(stop_statemachine_annoyed), 0];

    !alive _vehicle || {!alive _driver} || {_bypass} || {_boredom > STOP_STATEMACHINE_BOREDOM_THRESHOLD} || {_annoyed > STOP_STATEMACHINE_ANNOYED_THRESHOLD}
}, {
    // OnTransition -
    params ["_vehicle"];

    private _driver = driver _vehicle;
    private _boredom = _vehicle getVariable [QGVAR(stop_statemachine_boredom), 0];
    private _annoyed = _vehicle getVariable [QGVAR(stop_statemachine_annoyed), 0];

    if (_annoyed > STOP_STATEMACHINE_ANNOYED_THRESHOLD) exitWith {
        _driver setVariable [QGVAR(ignoringStop), true, true];
        [{_driver setVariable [QGVAR(ignoringStop), false, true]}, [_driver], 360] call CBA_fnc_waitAndExecute;
        [QGVAR(fireHorn), [_vehicle, _driver, 2], _vehicle] call CBA_fnc_targetEvent;
        TRACE_3("Exit triggered. Annoyed",_vehicle,_annoyed,STOP_STATEMACHINE_ANNOYED_THRESHOLD);
    };

    TRACE_3("Exit triggered. Bored",_vehicle,_boredom,STOP_STATEMACHINE_BOREDOM_THRESHOLD);
}, QGVAR(stop_transition_stopped_exit)] call CBA_statemachine_fnc_addTransition;
