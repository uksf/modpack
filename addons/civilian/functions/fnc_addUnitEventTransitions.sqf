#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Adds statemachine event transitions for unit

    Parameters:
        None

    Return value:
        Nothing
*/
#define RANDOM_ANNOYED_STOPPED_TO_MOVE random 10
#define RANDOM_ANNOYED_MOVE_TO_STOPPED random 20

// Add event transition: FromState, ToState, Events, Condition, OnTransition, Name

// Event Transition - stopped -> move (moveCommand)
[GVAR(unit_statemachine), QGVAR(unit_state_stopped), QGVAR(unit_state_move), [QGVAR(moveCommand)], {true}, {
    // OnTransition - add some to annoyed value
    params ["_unit"];

    private _annoyed = _unit getVariable [QGVAR(annoyed), 0];
    _unit setVariable [QGVAR(annoyed), _annoyed + RANDOM_ANNOYED_STOPPED_TO_MOVE, true];
    TRACE_3("Adding to annoyed",_unit,_annoyed,_unit getVariable [ARR_2(QGVAR(annoyed),0)]);
}, QGVAR(unit_event_transition_stopped_move)] call CBA_statemachine_fnc_addEventTransition;

// Event Transition - stopped -> follow (followCommand)
[GVAR(unit_statemachine), QGVAR(unit_state_stopped), QGVAR(unit_state_follow), [QGVAR(followCommand)], {true}, {}, QGVAR(unit_event_transition_stopped_follow)] call CBA_statemachine_fnc_addEventTransition;

// Event Transition - stopped -> exit (goCommand)
[GVAR(unit_statemachine), QGVAR(unit_state_stopped), QGVAR(unit_state_exit), [QGVAR(goCommand)], {true}, {}, QGVAR(unit_event_transition_stopped_exit)] call CBA_statemachine_fnc_addEventTransition;

// Event Transition - move -> exit (goCommand)
[GVAR(unit_statemachine), QGVAR(unit_state_move), QGVAR(unit_state_exit), [QGVAR(goCommand)], {true}, {}, QGVAR(unit_event_transition_move_exit)] call CBA_statemachine_fnc_addEventTransition;

// Event Transition - move -> stopped (stopCommand)
[GVAR(unit_statemachine), QGVAR(unit_state_move), QGVAR(unit_state_stopped), [QGVAR(stopCommand)], {true}, {
    // OnTransition - add some to annoyed value
    params ["_unit"];

    private _annoyed = _unit getVariable [QGVAR(annoyed), 0];
    _unit setVariable [QGVAR(annoyed), _annoyed + RANDOM_ANNOYED_MOVE_TO_STOPPED, true];
    TRACE_3("Adding to annoyed",_unit,_annoyed,_unit getVariable [ARR_2(QGVAR(annoyed),0)]);
}, QGVAR(unit_event_transition_move_stopped)] call CBA_statemachine_fnc_addEventTransition;

// Event Transition - move -> follow (followCommand)
[GVAR(unit_statemachine), QGVAR(unit_state_move), QGVAR(unit_state_follow), [QGVAR(followCommand)], {true}, {}, QGVAR(unit_event_transition_move_follow)] call CBA_statemachine_fnc_addEventTransition;

// Event Transition - follow -> move (moveCommand)
[GVAR(unit_statemachine), QGVAR(unit_state_follow), QGVAR(unit_state_move), [QGVAR(moveCommand)], {true}, {}, QGVAR(unit_event_transition_follow_move)] call CBA_statemachine_fnc_addEventTransition;

// Event Transition - follow -> stopped (stopCommand)
[GVAR(unit_statemachine), QGVAR(unit_state_follow), QGVAR(unit_state_stopped), [QGVAR(stopCommand)], {true}, {}, QGVAR(unit_event_transition_follow_stopped)] call CBA_statemachine_fnc_addEventTransition;
