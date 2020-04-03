#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Adds statemachine states for vehicle stop

    Parameters:
        None

    Return value:
        Nothing
*/
// Add state: OnState, OnEnter, OnLeave, Name

// State - enter
[GVAR(stop_statemachine), {
    // On state -
}, {
    // On Entered - disable AI behaviour
    params ["_vehicle"];

    private _driver = driver _vehicle;
    private _group = group _driver;
    _driver disableAI "FSM";
    _group setSpeedMode "LIMITED";
    {deleteWaypoint [_group, 1]} forEach (waypoints _group);
    TRACE_2("Entered statemachine",_vehicle,_driver);
}, {
    // On Leaving -
}, QGVAR(stop_state_enter)] call CBA_statemachine_fnc_addState;

// State - exit
[GVAR(stop_statemachine), {
    // On state -
}, {
    // On Entered - reset variables and states, remove vehicle from statemachine, give move command (let ambient driving module handle afterwards)
    params ["_vehicle"];

    private _driver = driver _vehicle;
    private _group = group _driver;
    TRACE_2("Exited statemachine",_vehicle,_driver);
    _driver enableAI "FSM";
    _driver enableAI "MOVE";
    _driver enableAI "PATH";
    _driver doMove ([_vehicle, 500, getDir _vehicle, 60] call CBA_fnc_randPos); // (let ambient driving module handle afterwards)
    _group setSpeedMode "NORMAL";

    _driver setVariable [QGVAR(commandedToStop), false, true];
    _vehicle setVariable [QGVAR(stop_statemachine_bypass), false, true];
    _vehicle setVariable [QGVAR(stop_statemachine_lastTime), 0, true];
    _vehicle setVariable [QGVAR(stop_statemachine_boredom), (_vehicle getVariable [QGVAR(stop_statemachine_boredom), 0]) / 4, true];
    _vehicle setVariable [QGVAR(stop_statemachine_annoyed), (_vehicle getVariable [QGVAR(stop_statemachine_annoyed), 0]) / 4, true];

    deleteVehicle GVAR(debug_vehicleSphere);
    deleteVehicle GVAR(debug_vehicleMoveCommandSphere);

    GVAR(stop_statemachine_vehicles) deleteAt (GVAR(stop_statemachine_vehicles) find _vehicle);
}, {
    // On Leaving -
}, QGVAR(stop_state_exit)] call CBA_statemachine_fnc_addState;

// State - stopping
[GVAR(stop_statemachine), {
    // On state - re-issue stop command at a certain interval
    params ["_vehicle"];

    private _lastTime = _vehicle getVariable [QGVAR(stop_statemachine_lastTime), 0];
    if (time < (_lastTime + STOP_STATEMACHINE_INTERVAL)) exitWith {};
    _vehicle setVariable [QGVAR(stop_statemachine_lastTime), time];

    private _driver = driver _vehicle;
    doStop _driver;
    TRACE_2("Stopping",_vehicle,_driver);
}, {
    // On Entered - stop
    params ["_vehicle"];

    private _driver = driver _vehicle;
    doStop _driver;
    TRACE_2("Enter stopping",_vehicle,_driver);

    GVAR(debug_vehicleSphere) setObjectTextureGlobal [0, "#(rgb,8,8,3)color(1,1,0,1)"];
}, {
    // On Leaving -
    params ["_vehicle"];

    private _driver = driver _vehicle;
    TRACE_2("Exit stopping",_vehicle,_driver);
}, QGVAR(stop_state_stopping)] call CBA_statemachine_fnc_addState;

// State - stopped
[GVAR(stop_statemachine), {
    // On state - randomly increase boredom value
    params ["_vehicle"];

    private _lastTime = _vehicle getVariable [QGVAR(stop_statemachine_lastTime), 0];
    if (time < (_lastTime + STOP_STATEMACHINE_INTERVAL)) exitWith {};
    _vehicle setVariable [QGVAR(stop_statemachine_lastTime), time];

    private _boredom = _vehicle getVariable [QGVAR(stop_statemachine_boredom), 0];
    private _random = random 100;
    if (_random < STOP_STATEMACHINE_BOREDOM_INCREMENT_CHANCE) then {
        _vehicle setVariable [QGVAR(stop_statemachine_boredom), _boredom + 1, true];
        TRACE_3("Adding to boredom",_vehicle,_boredom,_vehicle getVariable [ARR_2(QGVAR(stop_statemachine_boredom),0)]);
    };
}, {
    // On Entered - disable AI move
    params ["_vehicle"];

    private _driver = driver _vehicle;
    _driver disableAI "MOVE";
    TRACE_2("Enter stopped",_vehicle,_driver);

    GVAR(debug_vehicleSphere) setObjectTextureGlobal [0, "#(rgb,8,8,3)color(0,1,0,1)"];
}, {
    // On Leaving -
    params ["_vehicle"];

    private _driver = driver _vehicle;
    TRACE_2("Exit stopped",_vehicle,_driver);
}, QGVAR(stop_state_stopped)] call CBA_statemachine_fnc_addState;

// State - move
[GVAR(stop_statemachine), {
    // On state - re-issue move command at a certain interval
    params ["_vehicle"];

    private _lastTime = _vehicle getVariable [QGVAR(stop_statemachine_lastTime), 0];
    private _forceMoveUpdate = _vehicle getVariable [QGVAR(stop_statemachine_forceMoveUpdate), false];
    private _commandPosition = _vehicle getVariable [QGVAR(stop_statemachine_movePosition), getPos (_vehicle getVariable [QGVAR(stop_statemachine_moveCommander), _driver])];
    private _vehicleLength = _vehicle getVariable [QGVAR(vehicleLength), 4];

    if (_forceMoveUpdate || {time > (_lastTime + STOP_STATEMACHINE_INTERVAL) && {(_vehicle distance _commandPosition) > _vehicleLength}}) then {
        _vehicle setVariable [QGVAR(stop_statemachine_lastTime), time];
        _vehicle setVariable [QGVAR(stop_statemachine_forceMoveUpdate), false, true];

        private _driver = driver _vehicle;
        private _group = group _driver;
        private _commandPosition = _vehicle getVariable [QGVAR(stop_statemachine_movePosition), getPos (_vehicle getVariable [QGVAR(stop_statemachine_moveCommander), _driver])];
        _driver doMove _commandPosition;
        _driver enableAI "MOVE";
        _group setSpeedMode "NORMAL";

        deleteVehicle GVAR(debug_vehicleMoveCommandSphere);
        GVAR(debug_vehicleMoveCommandSphere) = createVehicle ["Sign_Sphere25cm_F", _commandPosition, [], 0, "CAN_COLLIDE"];
        GVAR(debug_vehicleSphere) setObjectTextureGlobal [0, "#(rgb,8,8,3)color(0,0,1,1)"];
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
    _vehicle setVariable [QGVAR(stop_statemachine_movePosition), [], true];
    _vehicle setVariable [QGVAR(stop_statemachine_moveCommander), objNull, true];
    TRACE_2("Exit move",_vehicle,_driver);
}, QGVAR(stop_state_move)] call CBA_statemachine_fnc_addState;

// State - getout
[GVAR(stop_statemachine), {
    // On state - make unit look at getout commander, until they are facing them
    params ["_vehicle"];

    private _lastTime = _vehicle getVariable [QGVAR(stop_statemachine_lastTime), 0];
    if (time < (_lastTime + STOP_STATEMACHINE_INTERVAL)) exitWith {};
    _vehicle setVariable [QGVAR(stop_statemachine_lastTime), time];

    private _driver = _vehicle getVariable [QGVAR(stop_statemachine_driver), objNull];
    private _getoutCommander = _driver getVariable [QGVAR(stop_statemachine_getoutCommander), objNull];
    private _position = [getPos _getoutCommander, (getPos _vehicle) vectorAdd ((vectorDirVisual _vehicle) vectorMultiply 3)] select (isNull _getoutCommander);

    if ((acos ((vectorDirVisual _driver) vectorCos ((eyePos _driver) vectorFromTo _position))) < VISION_ARC / 3) exitWith {
        TRACE_2("Watching position",_vehicle,_position);
        _driver disableAI "MOVE";
        _driver enableAI "PATH";
    };

    _driver disableAI "PATH";
    _driver enableAI "MOVE";
    _driver doWatch _position;
    TRACE_2("Watch position",_vehicle,_position);
}, {
    // On Entered - get out of vehicle
    params ["_vehicle"];

    private _driver = driver _vehicle;
    _vehicle setVariable [QGVAR(stop_statemachine_driver), _driver, true];
    moveOut _driver;
    TRACE_2("Get out",_vehicle,_driver);
}, {
    // On Leaving - get into vehicle
    params ["_vehicle"];

    private _driver = _vehicle getVariable [QGVAR(stop_statemachine_driver), objNull];
    if (isNull _driver) exitWith {};

    _driver doWatch objNull;
    _driver moveInDriver _vehicle;
    _driver enableAI "PATH";
    _driver disableAI "MOVE";
    TRACE_2("Get in",_vehicle,_driver);
}, QGVAR(stop_state_getout)] call CBA_statemachine_fnc_addState;
