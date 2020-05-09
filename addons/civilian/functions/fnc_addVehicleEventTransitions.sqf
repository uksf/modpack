#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Adds statemachine event transitions for vehicle

    Parameters:
        None

    Return value:
        Nothing
*/
#define RANDOM_ANNOYED_STOPPING_TO_MOVE random 5
#define RANDOM_ANNOYED_STOPPED_TO_MOVE random 10
#define RANDOM_ANNOYED_MOVE_TO_STOPPING random 20

// Add event transition: FromState, ToState, Events, Condition, OnTransition, Name

// Event Transition - stopping -> move (moveCommand)
[GVAR(vehicle_statemachine), QGVAR(vehicle_state_stopping), QGVAR(vehicle_state_move), [QGVAR(moveCommand)], {true}, {
    // OnTransition - add some to annoyed value
    params ["_vehicle"];

    private _driver = driver _vehicle;
    private _annoyed = _vehicle getVariable [QGVAR(annoyed), 0];
    _vehicle setVariable [QGVAR(annoyed), _annoyed + RANDOM_ANNOYED_STOPPING_TO_MOVE, true];
    TRACE_3("Adding to annoyed",_vehicle,_annoyed,_vehicle getVariable [ARR_2(QGVAR(annoyed),0)]);
}, QGVAR(vehicle_event_transition_stopping_move)] call CBA_statemachine_fnc_addEventTransition;

// Event Transition - stopped -> move (moveCommand)
[GVAR(vehicle_statemachine), QGVAR(vehicle_state_stopped), QGVAR(vehicle_state_move), [QGVAR(moveCommand)], {true}, {
    // OnTransition - add some to annoyed value
    params ["_vehicle"];

    private _driver = driver _vehicle;
    private _annoyed = _vehicle getVariable [QGVAR(annoyed), 0];
    _vehicle setVariable [QGVAR(annoyed), _annoyed + RANDOM_ANNOYED_STOPPED_TO_MOVE, true];
    TRACE_3("Adding to annoyed",_vehicle,_annoyed,_vehicle getVariable [ARR_2(QGVAR(annoyed),0)]);
}, QGVAR(vehicle_event_transition_stopped_move)] call CBA_statemachine_fnc_addEventTransition;

// Event Transition - stopped -> follow (followCommand)
[GVAR(vehicle_statemachine), QGVAR(vehicle_state_stopped), QGVAR(vehicle_state_follow), [QGVAR(followCommand)], {true}, {}, QGVAR(vehicle_event_transition_stopped_follow)] call CBA_statemachine_fnc_addEventTransition;

// Event Transition - stopped -> getOut (getOutCommand)
[GVAR(vehicle_statemachine), QGVAR(vehicle_state_stopped), QGVAR(vehicle_state_getOut), [QGVAR(getOutCommand)], {true}, {}, QGVAR(vehicle_event_transition_stopped_getOut)] call CBA_statemachine_fnc_addEventTransition;

// Event Transition - stopped -> exit (goCommand)
[GVAR(vehicle_statemachine), QGVAR(vehicle_state_stopped), QGVAR(vehicle_state_exit), [QGVAR(goCommand)], {true}, {}, QGVAR(vehicle_event_transition_stopped_exit)] call CBA_statemachine_fnc_addEventTransition;

// Event Transition - move -> exit (goCommand)
[GVAR(vehicle_statemachine), QGVAR(vehicle_state_move), QGVAR(vehicle_state_exit), [QGVAR(goCommand)], {true}, {}, QGVAR(vehicle_event_transition_move_exit)] call CBA_statemachine_fnc_addEventTransition;

// Event Transition - move -> stopping (stopCommand)
[GVAR(vehicle_statemachine), QGVAR(vehicle_state_move), QGVAR(vehicle_state_stopping), [QGVAR(stopCommand)], {true}, {
    // OnTransition - add some to annoyed value
    params ["_vehicle"];

    private _driver = driver _vehicle;
    private _annoyed = _vehicle getVariable [QGVAR(annoyed), 0];
    _vehicle setVariable [QGVAR(annoyed), _annoyed + RANDOM_ANNOYED_MOVE_TO_STOPPING, true];
    TRACE_3("Adding to annoyed",_vehicle,_annoyed,_vehicle getVariable [ARR_2(QGVAR(annoyed),0)]);
}, QGVAR(vehicle_event_transition_move_stopping)] call CBA_statemachine_fnc_addEventTransition;

// Event Transition - move -> follow (followCommand)
[GVAR(vehicle_statemachine), QGVAR(vehicle_state_move), QGVAR(vehicle_state_follow), [QGVAR(followCommand)], {true}, {}, QGVAR(vehicle_event_transition_move_follow)] call CBA_statemachine_fnc_addEventTransition;

// Event Transition - follow -> move (moveCommand)
[GVAR(vehicle_statemachine), QGVAR(vehicle_state_follow), QGVAR(vehicle_state_move), [QGVAR(moveCommand)], {true}, {}, QGVAR(vehicle_event_transition_follow_move)] call CBA_statemachine_fnc_addEventTransition;

// Event Transition - follow -> stopping (stopCommand)
[GVAR(vehicle_statemachine), QGVAR(vehicle_state_follow), QGVAR(vehicle_state_stopping), [QGVAR(stopCommand)], {true}, {}, QGVAR(vehicle_event_transition_follow_stopping)] call CBA_statemachine_fnc_addEventTransition;

// Event Transition - getOut -> getIn (getInCommand)
[GVAR(vehicle_statemachine), QGVAR(vehicle_state_getOut), QGVAR(vehicle_state_getIn), [QGVAR(getInCommand)], {true}, {}, QGVAR(vehicle_event_transition_getOut_getIn)] call CBA_statemachine_fnc_addEventTransition;

// Event Transition - getOut -> stopped (goCommand)
[GVAR(vehicle_statemachine), QGVAR(vehicle_state_getOut), QGVAR(vehicle_state_stopped), [QGVAR(goCommand)], {true}, {}, QGVAR(vehicle_event_transition_getOut_stopped)] call CBA_statemachine_fnc_addEventTransition;
