#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Adds statemachine event transitions for vehicle stop

    Parameters:
        None

    Return value:
        Nothing
*/
// Add event transition: FromState, ToState, Events, Condition, OnTransition, Name

// Event Transition - stopping -> move (moveCommand)
[GVAR(stop_statemachine), QGVAR(stop_state_stopping), QGVAR(stop_state_move), [QGVAR(moveCommand)], {true}, {
    // OnTransition - add some to annoyed value
    params ["_vehicle"];

    private _driver = driver _vehicle;
    private _annoyed = _vehicle getVariable [QGVAR(stop_statemachine_annoyed), 0];
    _vehicle setVariable [QGVAR(stop_statemachine_annoyed), _annoyed + random 5, true];
    TRACE_3("Adding to annoyed",_vehicle,_annoyed,_vehicle getVariable [ARR_2(QGVAR(stop_statemachine_annoyed),0)]);
}, QGVAR(stop_event_transition_stopping_move)] call CBA_statemachine_fnc_addEventTransition;

// Event Transition - stopped -> move (moveCommand)
[GVAR(stop_statemachine), QGVAR(stop_state_stopped), QGVAR(stop_state_move), [QGVAR(moveCommand)], {true}, {
    // OnTransition - add some to annoyed value
    params ["_vehicle"];

    private _driver = driver _vehicle;
    private _annoyed = _vehicle getVariable [QGVAR(stop_statemachine_annoyed), 0];
    _vehicle setVariable [QGVAR(stop_statemachine_annoyed), _annoyed + random 10, true];
    TRACE_3("Adding to annoyed",_vehicle,_annoyed,_vehicle getVariable [ARR_2(QGVAR(stop_statemachine_annoyed),0)]);
}, QGVAR(stop_event_transition_stopped_move)] call CBA_statemachine_fnc_addEventTransition;

// Event Transition - move -> stopping (stopCommand)
[GVAR(stop_statemachine), QGVAR(stop_state_move), QGVAR(stop_state_stopping), [QGVAR(stopCommand)], {true}, {
    // OnTransition - add some to annoyed value
    params ["_vehicle"];

    private _driver = driver _vehicle;
    private _annoyed = _vehicle getVariable [QGVAR(stop_statemachine_annoyed), 0];
    _vehicle setVariable [QGVAR(stop_statemachine_annoyed), _annoyed + random 20, true];
    _vehicle setVariable [QGVAR(stop_statemachine_movePosition), [], true];
    _vehicle setVariable [QGVAR(stop_statemachine_moveCommander), objNull, true];
    TRACE_3("Adding to annoyed",_vehicle,_annoyed,_vehicle getVariable [ARR_2(QGVAR(stop_statemachine_annoyed),0)]);
}, QGVAR(stop_event_transition_move_stopping)] call CBA_statemachine_fnc_addEventTransition;

// Event Transition - stopped -> exit (goCommand)
[GVAR(stop_statemachine), QGVAR(stop_state_stopped), QGVAR(stop_state_exit), [QGVAR(goCommand)], {true}, {}, QGVAR(stop_event_transition_stopped_exit)] call CBA_statemachine_fnc_addEventTransition;

// Event Transition - stopped -> getout (getoutCommand)
[GVAR(stop_statemachine), QGVAR(stop_state_stopped), QGVAR(stop_state_getout), [QGVAR(getOutCommand)], {true}, {}, QGVAR(stop_event_transition_stopped_getout)] call CBA_statemachine_fnc_addEventTransition;

// Event Transition - getout -> stopped (goCommand)
[GVAR(stop_statemachine), QGVAR(stop_state_getout), QGVAR(stop_state_stopped), [QGVAR(goCommand)], {true}, {}, QGVAR(stop_event_transition_getout_stopped)] call CBA_statemachine_fnc_addEventTransition;

// Event Transition - move -> exit (goCommand)
[GVAR(stop_statemachine), QGVAR(stop_state_move), QGVAR(stop_state_exit), [QGVAR(goCommand)], {true}, {}, QGVAR(stop_event_transition_stopped_getout)] call CBA_statemachine_fnc_addEventTransition;
