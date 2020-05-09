#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Starts statemachine for civilian units

    Parameters:
        0: Unit <OBJECT>

    Return value:
        Nothing
*/
params ["_unit"];

if !(local _unit) exitWith {};

GVAR(unit_statemachine_units) pushBack _unit;

if !(isNull GVAR(unit_statemachine)) exitWith {
    private _id = GVAR(unit_statemachine) getVariable "cba_statemachine_ID";
    private _currentState = _unit getVariable ("cba_statemachine_state" + str _id);

    [_unit, GVAR(unit_statemachine), _currentState, QGVAR(unit_state_enter)] call CBA_statemachine_fnc_manualTransition;
};

GVAR(unit_statemachine) = [{GVAR(unit_statemachine_units)}, true] call CBA_statemachine_fnc_create;

call FUNC(addUnitStates);
call FUNC(addUnitTransitions);
call FUNC(addUnitEventTransitions);

// Temporary patch to transfer non-local units to their client. Should be fixed on ambient civ spawning side
[{
    private _nonLocal = (GVAR(unit_statemachine_units) select {!(local _x)});
    {
        private _jipId = _x getVariable [QGVAR(unit_interaction_jipId), ""];
        [_jipId] call CBA_fnc_removeGlobalEventJIP;
        [QGVAR(removeUnitInteractions), [_x]] call CBA_fnc_globalEvent;

        GVAR(unit_statemachine_units) deleteAt (GVAR(unit_statemachine_units) find _x);
        [QGVAR(startUnitStatemachine), [_x], _x] call CBA_fnc_targetEvent;
    } forEach _nonLocal;
}, 5] call CBA_fnc_addPerFrameHandler;
