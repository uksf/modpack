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

    Example:
        [_unit] call uksf_civilian_fnc_startUnitStatemachine
*/
params ["_unit"];

if !(local _unit) exitWith {};

if (_unit in GVAR(unit_statemachine_units)) exitWith {};
GVAR(unit_statemachine_units) pushBack _unit;

private _localHandler = _unit addEventHandler ["Local", {
    params ["_object", "_isLocal"];
    if (_isLocal) exitWith {};
    _object removeEventHandler ["Local", _thisEventHandler];
    private _index = GVAR(unit_statemachine_units) find _object;
    if (_index < 0) exitWith {};
    GVAR(unit_statemachine_units) deleteAt _index;
    private _jipId = _object getVariable [QGVAR(unit_interaction_jipId), ""];
    if (_jipId isNotEqualTo "") then {[_jipId] call CBA_fnc_removeGlobalEventJIP};
    [QGVAR(removeUnitInteractions), [_object]] call CBA_fnc_globalEvent;
    [QGVAR(startUnitStatemachine), [_object], _object] call CBA_fnc_targetEvent;
}];
_unit setVariable [QGVAR(unit_localHandler), _localHandler];

if !(isNull GVAR(unit_statemachine)) exitWith {
    private _id = GVAR(unit_statemachine) getVariable "cba_statemachine_ID";
    private _currentState = _unit getVariable ("cba_statemachine_state" + str _id);

    [_unit, GVAR(unit_statemachine), _currentState, QGVAR(unit_state_enter)] call CBA_statemachine_fnc_manualTransition;
};

GVAR(unit_statemachine) = [{GVAR(unit_statemachine_units)}, true] call CBA_statemachine_fnc_create;

call FUNC(addUnitStates);
call FUNC(addUnitTransitions);
call FUNC(addUnitEventTransitions);

[{
    private _nonLocal = (GVAR(unit_statemachine_units) select {!(local _x)});
    {
        _x removeEventHandler ["Local", _x getVariable [QGVAR(unit_localHandler), -1]];
        private _jipId = _x getVariable [QGVAR(unit_interaction_jipId), ""];
        if (_jipId isNotEqualTo "") then {[_jipId] call CBA_fnc_removeGlobalEventJIP};
        [QGVAR(removeUnitInteractions), [_x]] call CBA_fnc_globalEvent;

        GVAR(unit_statemachine_units) deleteAt (GVAR(unit_statemachine_units) find _x);
        [QGVAR(startUnitStatemachine), [_x], _x] call CBA_fnc_targetEvent;
    } forEach _nonLocal;
}, 5] call CBA_fnc_addPerFrameHandler;
