#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Adds statemachine transitions for unit

    Parameters:
        None

    Return value:
        Nothing
*/
// Add transition: FromState, ToState, Condition, OnTransition, Name

// Unit alive or null exit conditions first (transitions execute in added order)
private _fnc_isUnitNullOrDead = {
    params ["_unit"];

    isNull _unit || {!alive _unit}
};

[GVAR(unit_statemachine), QGVAR(unit_state_enter), QGVAR(unit_state_exit), _fnc_isUnitNullOrDead, {}, QGVAR(unit_transition_enter_exit_null)] call CBA_statemachine_fnc_addTransition;
[GVAR(unit_statemachine), QGVAR(unit_state_stopped), QGVAR(unit_state_exit), _fnc_isUnitNullOrDead, {}, QGVAR(unit_transition_stopped_exit_null)] call CBA_statemachine_fnc_addTransition;
[GVAR(unit_statemachine), QGVAR(unit_state_move), QGVAR(unit_state_exit), _fnc_isUnitNullOrDead, {}, QGVAR(unit_transition_move_exit_null)] call CBA_statemachine_fnc_addTransition;
[GVAR(unit_statemachine), QGVAR(unit_state_follow), QGVAR(unit_state_exit), _fnc_isUnitNullOrDead, {}, QGVAR(unit_transition_follow_exit_null)] call CBA_statemachine_fnc_addTransition;

// --------------------------------------------------------------------------------------------------------------

// Transition - enter -> stopped
[GVAR(unit_statemachine), QGVAR(unit_state_enter), QGVAR(unit_state_stopped), {
    // Condition - unit has stopped
    params ["_unit"];

    (speed _unit) < 0.1
}, {}, QGVAR(unit_transition_enter_stopped)] call CBA_statemachine_fnc_addTransition;

// Transition - stopped -> exit (ignoring)
[GVAR(unit_statemachine), QGVAR(unit_state_stopped), QGVAR(unit_state_exit), {
    // Condition - unit is annoyed (threshold)
    params ["_unit"];

    private _annoyed = _unit getVariable [QGVAR(annoyed), 0];
    _annoyed > STOP_ANNOYED_THRESHOLD
}, {
    // OnTransition - set unit as ignoring stop (annoyed)
    params ["_unit"];

    _unit setVariable [QGVAR(unit_ignoringStop), true, true];
    private _annoyed = _unit getVariable [QGVAR(annoyed), 0];
    TRACE_3("Exit triggered. Annoyed?",_unit,_annoyed,STOP_ANNOYED_THRESHOLD);
}, QGVAR(unit_transition_stopped_stopped)] call CBA_statemachine_fnc_addTransition;

// Transition - stopped -> move
[GVAR(unit_statemachine), QGVAR(unit_state_stopped), QGVAR(unit_state_move), {
    // Condition - there is a move command position
    params ["_unit"];

    private _commandPosition = _unit getVariable [QGVAR(unit_movePosition), []];

    _commandPosition isNotEqualTo []
}, {
    // OnTransition -
}, QGVAR(unit_transition_stopped_move)] call CBA_statemachine_fnc_addTransition;

// Transition - move -> stopped
[GVAR(unit_statemachine), QGVAR(unit_state_move), QGVAR(unit_state_stopped), {
    // Condition - unit has stopped moving, and is at move command position
    params ["_unit"];

    private _commandPosition = _unit getVariable [QGVAR(unit_movePosition), getPos (_unit getVariable [QGVAR(unit_moveCommander), _unit])];

    (_unit distance _commandPosition) <= 2
}, {
    // OnTransition -
}, QGVAR(unit_transition_move_stopped)] call CBA_statemachine_fnc_addTransition;

// Transition - stopped -> exit (boredom || annoyed)
[GVAR(unit_statemachine), QGVAR(unit_state_stopped), QGVAR(unit_state_exit), {
    // Condition - unit is bored (threshold) OR annoyed (threshold)
    params ["_unit"];

    private _boredom = _unit getVariable [QGVAR(boredom), 0];
    private _annoyed = _unit getVariable [QGVAR(annoyed), 0];

    _boredom > STOP_BOREDOM_THRESHOLD || {_annoyed > STOP_ANNOYED_THRESHOLD}
}, {
    // OnTransition -
    params ["_unit"];

    private _boredom = _unit getVariable [QGVAR(boredom), 0];
    private _annoyed = _unit getVariable [QGVAR(annoyed), 0];

    if (_annoyed > STOP_ANNOYED_THRESHOLD) exitWith {
        _unit setVariable [QGVAR(unit_ignoringStop), true, true];
        [{_this setVariable [QGVAR(unit_ignoringStop), false, true]}, _unit, 360] call CBA_fnc_waitAndExecute;
        TRACE_3("Exit triggered. Annoyed",_unit,_annoyed,STOP_ANNOYED_THRESHOLD);
    };

    TRACE_3("Exit triggered. Bored",_unit,_boredom,STOP_BOREDOM_THRESHOLD);
}, QGVAR(unit_transition_stopped_exit)] call CBA_statemachine_fnc_addTransition;
