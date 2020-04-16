#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Adds statemachine states for unit

    Parameters:
        None

    Return value:
        Nothing
*/
// Add state: OnState, OnEnter, OnLeave, Name

// State - enter
[GVAR(unit_statemachine), {
    // On state - re-issue stop command at a certain interval
    params ["_unit"];

    private _lastTime = _unit getVariable [QGVAR(unit_lastTime), 0];
    if (CBA_missionTime < (_lastTime + UNIT_STOP_INTERVAL)) exitWith {};
    _unit setVariable [QGVAR(unit_lastTime), CBA_missionTime];

    doStop _unit;
    TRACE_1("Re-issuing stop",_unit);
}, {
    // On Entered - disable AI behaviour
    params ["_unit"];

    _unit disableAI "FSM";
    _unit forceWalk true;
    doStop _unit;

    private _jipId = [QGVAR(addUnitInteractions), [_unit]] call CBA_fnc_globalEventJIP;
    [_jipId, _unit] call CBA_fnc_removeGlobalEventJIP;
    _unit setVariable [QGVAR(unit_interaction_jipId), _jipId];
    TRACE_1("Entered statemachine",_unit);
}, {
    // On Leaving - Remove waypoints
    params ["_unit"];

    private _group = group _unit;
    {deleteWaypoint [_group, 1]} forEach (waypoints _group);
    TRACE_1("Exited enter",_unit);
}, QGVAR(unit_state_enter)] call CBA_statemachine_fnc_addState;

// State - exit
[GVAR(unit_statemachine), {
    // On state -
}, {
    // On Entered - reset variables and states, remove unit from statemachine, give move command (let ambient module handle afterwards)
    params ["_unit"];

    _unit enableAI "FSM";
    _unit enableAI "MOVE";
    _unit enableAI "PATH";
    _unit doMove ([_unit, 50, getDir _unit, 60] call CBA_fnc_randPos); // (let ambient module handle afterwards)
    _unit forceWalk false;

    _unit setVariable [QGVAR(unit_commandedToStop), false, true];
    _unit setVariable [QGVAR(unit_ignoreCommands), false, true];
    _unit setVariable [QGVAR(unit_lastTime), 0, true];
    _unit setVariable [QGVAR(boredom), (_unit getVariable [QGVAR(boredom), 0]) / 4, true];
    _unit setVariable [QGVAR(annoyed), (_unit getVariable [QGVAR(annoyed), 0]) / 4, true];
    _unit setVariable [QGVAR(unit_forceMoveUpdate), false, true];
    _unit setVariable [QGVAR(unit_moveCommander), objNull, true];
    _unit setVariable [QGVAR(unit_movePosition), [], true];
    _unit setVariable [QGVAR(unit_followCommander), objNull, true];

    private _jipId = _unit getVariable [QGVAR(unit_interaction_jipId), ""];
    [_jipId] call CBA_fnc_removeGlobalEventJIP;
    [QGVAR(removeUnitInteractions), [_unit]] call CBA_fnc_globalEvent;

    GVAR(unit_statemachine_units) deleteAt (GVAR(unit_statemachine_units) find _unit);

    private _vehicle = _unit getVariable [QGVAR(vehicle_vehicle), objNull];
    if !(isNull _vehicle) then {
        [QGVAR(getInCommand), [_vehicle], _vehicle] call CBA_fnc_targetEvent;
    };
    TRACE_1("Exited statemachine",_unit);
}, {
    // On Leaving -
}, QGVAR(unit_state_exit)] call CBA_statemachine_fnc_addState;

// State - stopped
[GVAR(unit_statemachine), {
    // On state - randomly increase boredom value
    params ["_unit"];

    private _lastTime = _unit getVariable [QGVAR(unit_lastTime), 0];
    if (CBA_missionTime < (_lastTime + UNIT_STOP_INTERVAL)) exitWith {};
    _unit setVariable [QGVAR(unit_lastTime), CBA_missionTime];

    private _boredom = _unit getVariable [QGVAR(boredom), 0];
    private _random = random 100;
    if (_random < UNIT_STOP_BOREDOM_INCREMENT_CHANCE) then {
        private _increment = [1, 0.5] select (_unit getVariable [QGVAR(unit_ignoreCommands), false]);
        _unit setVariable [QGVAR(boredom), _boredom + _increment, true];
        TRACE_3("Adding to boredom",_unit,_boredom,_unit getVariable [ARR_2(QGVAR(boredom),0)]);
    };
}, {
    // On Entered - disable AI move
    params ["_unit"];

    _unit disableAI "MOVE";
    _unit setVariable [QGVAR(unit_stopped), true, true];
    TRACE_1("Enter stopped",_unit);
}, {
    // On Leaving -
    params ["_unit"];

    _unit setVariable [QGVAR(unit_stopped), false, true];
    TRACE_1("Exit stopped",_unit);
}, QGVAR(unit_state_stopped)] call CBA_statemachine_fnc_addState;

// State - move
[GVAR(unit_statemachine), {
    // On state - re-issue move command at a certain interval
    params ["_unit"];

    private _lastTime = _unit getVariable [QGVAR(unit_lastTime), 0];
    private _forceMoveUpdate = _unit getVariable [QGVAR(unit_forceMoveUpdate), false];
    private _commandPosition = _unit getVariable [QGVAR(unit_movePosition), getPos (_unit getVariable [QGVAR(unit_moveCommander), _unit])];

    if (_forceMoveUpdate || {CBA_missionTime > (_lastTime + UNIT_STOP_INTERVAL) && {(_unit distance _commandPosition) > 2}}) then {
        _unit setVariable [QGVAR(unit_lastTime), CBA_missionTime];
        _unit setVariable [QGVAR(unit_forceMoveUpdate), false, true];
        _unit enableAI "MOVE";
        _unit doMove _commandPosition;
        TRACE_3("Moving",_unit,_commandPosition,_unit distance _commandPosition);
    };
}, {
    // On Entered -
    params ["_unit"];

    _unit setBehaviour "CARELESS";
    TRACE_1("Enter move",_unit);
}, {
    // On Leaving - Reset move command values
    params ["_unit"];

    _unit setBehaviour "SAFE";
    _unit setVariable [QGVAR(unit_movePosition), [], true];
    _unit setVariable [QGVAR(unit_moveCommander), objNull, true];
    TRACE_1("Exit move",_unit);
}, QGVAR(unit_state_move)] call CBA_statemachine_fnc_addState;

// State - follow
[GVAR(unit_statemachine), {
    // On state - re-issue follow command at a certain interval to follow commander location
    params ["_unit"];

    private _lastTime = _unit getVariable [QGVAR(unit_lastTime), 0];
    private _commandPosition = getPos (_unit getVariable [QGVAR(unit_followCommander), _unit]);
    private _direction = (getPos _unit) vectorFromTo _commandPosition;
    _commandPosition = _commandPosition vectorAdd (_direction vectorMultiply -2);

    if (CBA_missionTime > (_lastTime + UNIT_STOP_INTERVAL)) then {
        _unit setVariable [QGVAR(unit_lastTime), CBA_missionTime];
        if ((_unit distance _commandPosition) > 2) then {
            _unit enableAI "MOVE";
            _unit doMove _commandPosition;
            TRACE_3("Following",_unit,_commandPosition,_unit distance _commandPosition);
        } else {
            _unit disableAI "MOVE";
            doStop _unit;
            TRACE_3("Holding follow",_unit,_commandPosition,_unit distance _commandPosition);
        };
    };
}, {
    // On Entered -
    params ["_unit"];

    _unit setBehaviour "CARELESS";
    TRACE_1("Enter follow",_unit);
}, {
    // On Leaving - Reset move command values
    params ["_unit"];

    _unit setBehaviour "SAFE";
    _unit setVariable [QGVAR(unit_followCommander), objNull, true];
    TRACE_1("Exit follow",_unit);
}, QGVAR(unit_state_follow)] call CBA_statemachine_fnc_addState;


// make unit look at getOut commander, until they are facing them
// params ["_unit"];

// private _lastTime = _unit getVariable [QGVAR(unit_lastTime), 0];
// if (CBA_missionTime < (_lastTime + UNIT_STOP_INTERVAL)) exitWith {};
// _unit setVariable [QGVAR(unit_lastTime), CBA_missionTime];

// private _driver = _unit getVariable [QGVAR(unit_driver), objNull];
// private _getOutCommander = _driver getVariable [QGVAR(unit_getOutCommander), objNull];
// private _position = [getPos _getOutCommander, (getPos _unit) vectorAdd ((vectorDirVisual _unit) vectorMultiply 3)] select (isNull _getOutCommander);

// if ((acos ((vectorDirVisual _driver) vectorCos ((eyePos _driver) vectorFromTo _position))) < unit_VISION_ARC / 3) exitWith {
//     TRACE_2("Watching position",_unit,_position);
//     _driver disableAI "MOVE";
//     _driver enableAI "PATH";
// };

// _driver disableAI "PATH";
// _driver enableAI "MOVE";
// _driver doWatch _position;
// TRACE_2("Watch position",_unit,_position);
