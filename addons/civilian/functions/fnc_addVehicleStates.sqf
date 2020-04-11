#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Adds statemachine states for vehicle

    Parameters:
        None

    Return value:
        Nothing
*/
// Add state: OnState, OnEnter, OnLeave, Name

// State - enter
[GVAR(vehicle_statemachine), {
    // On state -
}, {
    // On Entered - disable AI behaviour
    params ["_vehicle"];

    private _driver = driver _vehicle;
    _driver disableAI "FSM";
    _vehicle forceSpeed 8;

    private _jipId = [QGVAR(addVehicleInteractions), [_vehicle]] call CBA_fnc_globalEventJIP;
    [_jipId, _vehicle] call CBA_fnc_removeGlobalEventJIP;
    _vehicle setVariable [QGVAR(vehicle_interaction_jipId), _jipId];
    TRACE_2("Entered statemachine",_vehicle,_driver);
}, {
    // On Leaving - Remove waypoints
    params ["_vehicle"];

    private _driver = driver _vehicle;
    private _group = group _driver;
    {deleteWaypoint [_group, 1]} forEach (waypoints _group);
    TRACE_2("Exited enter",_vehicle,_driver);
}, QGVAR(vehicle_state_enter)] call CBA_statemachine_fnc_addState;

// State - exit
[GVAR(vehicle_statemachine), {
    // On state -
}, {
    // On Entered - reset variables and states, remove vehicle from statemachine, give move command (let ambient driving module handle afterwards)
    params ["_vehicle"];

    private _driver = driver _vehicle;
    _driver enableAI "FSM";
    _driver enableAI "MOVE";
    _driver enableAI "PATH";
    _driver doMove ([_vehicle, 500, getDir _vehicle, 60] call CBA_fnc_randPos); // (let ambient driving module handle afterwards)
    _vehicle forceSpeed -1;

    _driver setVariable [QGVAR(vehicle_commandedToStop), false, true];
    _driver setVariable [QGVAR(vehicle_vehicle), objNull, true];
    _vehicle setVariable [QGVAR(vehicle_ignoreCommands), false, true];
    _vehicle setVariable [QGVAR(vehicle_lastTime), 0, true];
    _vehicle setVariable [QGVAR(vehicle_boredom), (_vehicle getVariable [QGVAR(vehicle_boredom), 0]) / 4, true];
    _vehicle setVariable [QGVAR(vehicle_annoyed), (_vehicle getVariable [QGVAR(vehicle_annoyed), 0]) / 4, true];
    _vehicle setVariable [QGVAR(vehicle_forceMoveUpdate), false, true];
    _vehicle setVariable [QGVAR(vehicle_moveCommander), objNull, true];
    _vehicle setVariable [QGVAR(vehicle_movePosition), [], true];
    _vehicle setVariable [QGVAR(vehicle_followCommander), objNull, true];
    _vehicle setVariable [QGVAR(vehicle_driver), objNull, true];

    private _jipId = _vehicle getVariable [QGVAR(vehicle_interaction_jipId), ""];
    [_jipId] call CBA_fnc_removeGlobalEventJIP;
    [QGVAR(removeVehicleInteractions), [_vehicle]] call CBA_fnc_globalEvent;

    GVAR(vehicle_statemachine_vehicles) deleteAt (GVAR(vehicle_statemachine_vehicles) find _vehicle);
    TRACE_2("Exited statemachine",_vehicle,_driver);
}, {
    // On Leaving -
}, QGVAR(vehicle_state_exit)] call CBA_statemachine_fnc_addState;

// State - stopping
[GVAR(vehicle_statemachine), {
    // On state - re-issue stop command at a certain interval
    params ["_vehicle"];

    private _lastTime = _vehicle getVariable [QGVAR(vehicle_lastTime), 0];
    if (CBA_missionTime < (_lastTime + VEHICLE_STOP_INTERVAL)) exitWith {};
    _vehicle setVariable [QGVAR(vehicle_lastTime), CBA_missionTime];

    private _driver = driver _vehicle;
    doStop _driver;
    TRACE_2("Stopping",_vehicle,_driver);
}, {
    // On Entered - stop
    params ["_vehicle"];

    private _driver = driver _vehicle;
    doStop _driver;
    TRACE_2("Enter stopping",_vehicle,_driver);
}, {
    // On Leaving -
    params ["_vehicle"];

    private _driver = driver _vehicle;
    TRACE_2("Exit stopping",_vehicle,_driver);
}, QGVAR(vehicle_state_stopping)] call CBA_statemachine_fnc_addState;

// State - stopped
[GVAR(vehicle_statemachine), {
    // On state - randomly increase boredom value
    params ["_vehicle"];

    private _lastTime = _vehicle getVariable [QGVAR(vehicle_lastTime), 0];
    if (CBA_missionTime < (_lastTime + VEHICLE_STOP_INTERVAL)) exitWith {};
    _vehicle setVariable [QGVAR(vehicle_lastTime), CBA_missionTime];

    private _boredom = _vehicle getVariable [QGVAR(vehicle_boredom), 0];
    private _random = random 100;
    if (_random < VEHICLE_STOP_BOREDOM_INCREMENT_CHANCE) then {
        private _increment = [1, 0.5] select (_vehicle getVariable [QGVAR(vehicle_ignoreCommands), false]);
        _vehicle setVariable [QGVAR(vehicle_boredom), _boredom + _increment, true];
        TRACE_3("Adding to boredom",_vehicle,_boredom,_vehicle getVariable [ARR_2(QGVAR(vehicle_boredom),0)]);
    };
}, {
    // On Entered - disable AI move
    params ["_vehicle"];

    private _driver = driver _vehicle;
    _driver disableAI "MOVE";
    _vehicle setVariable [QGVAR(vehicle_stopped), true, true];
    TRACE_2("Enter stopped",_vehicle,_driver);
}, {
    // On Leaving -
    params ["_vehicle"];

    private _driver = driver _vehicle;
    _vehicle setVariable [QGVAR(vehicle_stopped), false, true];
    TRACE_2("Exit stopped",_vehicle,_driver);
}, QGVAR(vehicle_state_stopped)] call CBA_statemachine_fnc_addState;

// State - move
[GVAR(vehicle_statemachine), {
    // On state - re-issue move command at a certain interval
    params ["_vehicle"];

    private _driver = driver _vehicle;
    private _lastTime = _vehicle getVariable [QGVAR(vehicle_lastTime), 0];
    private _forceMoveUpdate = _vehicle getVariable [QGVAR(vehicle_forceMoveUpdate), false];
    private _commandPosition = _vehicle getVariable [QGVAR(vehicle_movePosition), getPos (_vehicle getVariable [QGVAR(vehicle_moveCommander), _driver])];
    private _vehicleLength = _vehicle getVariable [QGVAR(vehicleLength), 4];

    if (_forceMoveUpdate || {CBA_missionTime > (_lastTime + VEHICLE_STOP_INTERVAL) && {(_vehicle distance _commandPosition) > _vehicleLength}}) then {
        _vehicle setVariable [QGVAR(vehicle_lastTime), CBA_missionTime];
        _vehicle setVariable [QGVAR(vehicle_forceMoveUpdate), false, true];
        _driver enableAI "MOVE";
        _driver doMove _commandPosition;
        TRACE_5("Moving",_vehicle,_driver,_commandPosition,_vehicle distance _commandPosition,_vehicleLength);
    };
}, {
    // On Entered -
    params ["_vehicle"];

    private _driver = driver _vehicle;
    TRACE_2("Enter move",_vehicle,_driver);
}, {
    // On Leaving - Reset move command values
    params ["_vehicle"];

    private _driver = driver _vehicle;
    _vehicle setVariable [QGVAR(vehicle_movePosition), [], true];
    _vehicle setVariable [QGVAR(vehicle_moveCommander), objNull, true];
    TRACE_2("Exit move",_vehicle,_driver);
}, QGVAR(vehicle_state_move)] call CBA_statemachine_fnc_addState;

// State - follow
[GVAR(vehicle_statemachine), {
    // On state - re-issue follow command at a certain interval to follow commander location
    params ["_vehicle"];

    private _driver = driver _vehicle;
    private _lastTime = _vehicle getVariable [QGVAR(vehicle_lastTime), 0];
    private _commandPosition = getPos (_vehicle getVariable [QGVAR(vehicle_followCommander), _driver]);
    private _direction = (getPos _vehicle) vectorFromTo _commandPosition;
    _commandPosition = _commandPosition vectorAdd (_direction vectorMultiply 3);
    private _vehicleLength = _vehicle getVariable [QGVAR(vehicleLength), 4];

    if (CBA_missionTime > (_lastTime + VEHICLE_STOP_INTERVAL)) then {
        _vehicle setVariable [QGVAR(vehicle_lastTime), CBA_missionTime];
        if ((_vehicle distance _commandPosition) > _vehicleLength) then {
            _driver enableAI "MOVE";
            _driver doMove _commandPosition;
            TRACE_5("Following",_vehicle,_driver,_commandPosition,_vehicle distance _commandPosition,_vehicleLength);
        } else {
            _driver disableAI "MOVE";
            doStop _driver;
            TRACE_5("Holding follow",_vehicle,_driver,_commandPosition,_vehicle distance _commandPosition,_vehicleLength);
        };
    };
}, {
    // On Entered -
    params ["_vehicle"];

    private _driver = driver _vehicle;
    TRACE_2("Enter follow",_vehicle,_driver);
}, {
    // On Leaving - Reset move command values
    params ["_vehicle"];

    private _driver = driver _vehicle;
    _vehicle setVariable [QGVAR(vehicle_followCommander), objNull, true];
    TRACE_2("Exit follow",_vehicle,_driver);
}, QGVAR(vehicle_state_follow)] call CBA_statemachine_fnc_addState;

// State - getOut
[GVAR(vehicle_statemachine), {
    // On state -
}, {
    // On Entered - get out of vehicle
    params ["_vehicle"];

    private _driver = driver _vehicle;
    _vehicle setVariable [QGVAR(vehicle_driver), _driver, true];
    _driver setVariable [QGVAR(vehicle_vehicle), _vehicle, true];
    moveOut _driver;
    unassignVehicle _driver;

    _driver setVariable [QGVAR(unit_commandedToStop), true, true];
    [QGVAR(startUnitStatemachine), [_driver], _driver] call CBA_fnc_targetEvent;
    TRACE_2("Enter get out",_vehicle,_driver);
}, {
    // On Leaving -
    params ["_vehicle"];

    private _driver = driver _vehicle;
    TRACE_2("Exit get out",_vehicle,_driver);
}, QGVAR(vehicle_state_getOut)] call CBA_statemachine_fnc_addState;

// State - getIn
[GVAR(vehicle_statemachine), {
    // On state -
}, {
    // On Entered - get into vehicle
    params ["_vehicle"];

    private _driver = _vehicle getVariable [QGVAR(vehicle_driver), objNull];
    if (isNull _driver) exitWith {};

    _driver enableAI "PATH";
    _driver enableAI "MOVE";
    _driver assignAsDriver _vehicle;
    [_driver, _vehicle, 0, "GETIN"] call CBA_fnc_addWaypoint;
    _driver forceWalk true;

    [QGVAR(stopUnitStatemachine), [_driver], _driver] call CBA_fnc_targetEvent;

    TRACE_2("Enter get in",_vehicle,_driver);
}, {
    // On Leaving -
    params ["_vehicle"];

    private _driver = driver _vehicle;
    _driver enableAI "PATH";
    _driver disableAI "MOVE";
    _driver forceWalk false;
    TRACE_2("Exit get in",_vehicle,_driver);
}, QGVAR(vehicle_state_getIn)] call CBA_statemachine_fnc_addState;