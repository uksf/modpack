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

    Example:
        call uksf_civilian_fnc_addVehicleStates
*/

[GVAR(vehicle_statemachine), {
}, {
    params ["_vehicle"];

    private _driver = driver _vehicle;
    _vehicle forceSpeed 8;

    private _jipId = [QGVAR(addVehicleInteractions), [_vehicle]] call CBA_fnc_globalEventJIP;
    [_jipId, _vehicle] call CBA_fnc_removeGlobalEventJIP;
    _vehicle setVariable [QGVAR(vehicle_interaction_jipId), _jipId];
    TRACE_2("Entered statemachine",_vehicle,_driver);
}, {
    params ["_vehicle"];

    private _driver = driver _vehicle;
    private _group = group _driver;
    {deleteWaypoint [_group, 1]} forEach (waypoints _group);
    TRACE_2("Exited enter",_vehicle,_driver);
}, QGVAR(vehicle_state_enter)] call CBA_statemachine_fnc_addState;

[GVAR(vehicle_statemachine), {
}, {
    params ["_vehicle"];

    private _driver = driver _vehicle;
    if !(isNull _driver) then {
        _driver enableAI "FSM";
        _driver enableAI "MOVE";
        _driver doFollow _driver;
        [group _driver, [_vehicle, 500, getDir _vehicle, 60] call CBA_fnc_randPos] call CBA_fnc_addWaypoint;
        _driver setVariable [QGVAR(vehicle_commandedToStop), false, true];
        _driver setVariable [QGVAR(vehicle_vehicle), objNull, true];
    };

    if !(isNull _vehicle) then {
        _vehicle forceSpeed -1;
        _vehicle setVariable [QGVAR(vehicle_ignoreCommands), false, true];
        _vehicle setVariable [QGVAR(vehicle_lastTime), 0, true];
        _vehicle setVariable [QGVAR(boredom), (_vehicle getVariable [QGVAR(boredom), 0]) / 4, true];
        _vehicle setVariable [QGVAR(annoyed), (_vehicle getVariable [QGVAR(annoyed), 0]) / 4, true];
        _vehicle setVariable [QGVAR(vehicle_forceMoveUpdate), false, true];
        _vehicle setVariable [QGVAR(vehicle_moveCommander), objNull, true];
        _vehicle setVariable [QGVAR(vehicle_movePosition), [], true];
        _vehicle setVariable [QGVAR(vehicle_followCommander), objNull, true];
        _vehicle setVariable [QGVAR(vehicle_followCachedPosition), [], true];
        _vehicle setVariable [QGVAR(vehicle_driver), objNull, true];

        private _jipId = _vehicle getVariable [QGVAR(vehicle_interaction_jipId), ""];
        if (_jipId isNotEqualTo "") then {[_jipId] call CBA_fnc_removeGlobalEventJIP};
        [QGVAR(removeVehicleInteractions), [_vehicle]] call CBA_fnc_globalEvent;
    };

    GVAR(vehicle_statemachine_vehicles) deleteAt (GVAR(vehicle_statemachine_vehicles) find _vehicle);
    TRACE_2("Exited statemachine",_vehicle,_driver);
}, {
}, QGVAR(vehicle_state_exit)] call CBA_statemachine_fnc_addState;

[GVAR(vehicle_statemachine), {
    params ["_vehicle"];

    private _lastTime = _vehicle getVariable [QGVAR(vehicle_lastTime), 0];
    if (CBA_missionTime < (_lastTime + VEHICLE_STOP_INTERVAL)) exitWith {};
    _vehicle setVariable [QGVAR(vehicle_lastTime), CBA_missionTime];

    private _driver = driver _vehicle;
    doStop _driver;
    TRACE_2("Stopping",_vehicle,_driver);
}, {
    params ["_vehicle"];

    private _driver = driver _vehicle;
    doStop _driver;
    TRACE_2("Enter stopping",_vehicle,_driver);
}, {
    params ["_vehicle"];

    private _driver = driver _vehicle;
    TRACE_2("Exit stopping",_vehicle,_driver);
}, QGVAR(vehicle_state_stopping)] call CBA_statemachine_fnc_addState;

[GVAR(vehicle_statemachine), {
    params ["_vehicle"];

    private _lastTime = _vehicle getVariable [QGVAR(vehicle_lastTime), 0];
    if (CBA_missionTime < (_lastTime + VEHICLE_STOP_INTERVAL)) exitWith {};
    _vehicle setVariable [QGVAR(vehicle_lastTime), CBA_missionTime];

    private _boredom = _vehicle getVariable [QGVAR(boredom), 0];
    private _random = random 100;
    if (_random < VEHICLE_STOP_BOREDOM_INCREMENT_CHANCE) then {
        private _increment = [1, 0.5] select (_vehicle getVariable [QGVAR(vehicle_ignoreCommands), false]);
        _vehicle setVariable [QGVAR(boredom), _boredom + _increment, true];
        TRACE_3("Adding to boredom",_vehicle,_boredom,_vehicle getVariable [ARR_2(QGVAR(boredom),0)]);
    };
}, {
    params ["_vehicle"];

    private _driver = driver _vehicle;
    _driver disableAI "FSM";
    _driver disableAI "MOVE";
    _vehicle setVariable [QGVAR(vehicle_stopped), true, true];
    TRACE_2("Enter stopped",_vehicle,_driver);
}, {
    params ["_vehicle"];

    private _driver = driver _vehicle;
    _driver enableAI "FSM";
    _vehicle setVariable [QGVAR(vehicle_stopped), false, true];
    TRACE_2("Exit stopped",_vehicle,_driver);
}, QGVAR(vehicle_state_stopped)] call CBA_statemachine_fnc_addState;

[GVAR(vehicle_statemachine), {
    params ["_vehicle"];

    private _driver = driver _vehicle;
    private _lastTime = _vehicle getVariable [QGVAR(vehicle_lastTime), 0];
    private _forceMoveUpdate = _vehicle getVariable [QGVAR(vehicle_forceMoveUpdate), false];
    if (_forceMoveUpdate || {CBA_missionTime > (_lastTime + VEHICLE_STOP_INTERVAL)}) then {
        _vehicle setVariable [QGVAR(vehicle_lastTime), CBA_missionTime];
        _vehicle setVariable [QGVAR(vehicle_forceMoveUpdate), false, true];

        private _commandPosition = _vehicle getVariable [QGVAR(vehicle_movePosition), getPos (_vehicle getVariable [QGVAR(vehicle_moveCommander), _driver])];
        private _vehicleLength = _vehicle getVariable [QGVAR(vehicleLength), 5];
        private _vehicleFrontPosition = _vehicle modelToWorld [0, _vehicleLength / 2, 0];
        _vehicleFrontPosition set [2, 0];

        if ((_vehicleFrontPosition distance2D _commandPosition) > 5) then {
            private _moveOrdered = _driver getVariable [QGVAR(vehicle_moveOrdered), false];
            if !(_moveOrdered) then {
                _driver setVariable [QGVAR(vehicle_moveOrdered), true, true];
                _driver enableAI "MOVE";
                _driver doMove _commandPosition;
                TRACE_6("Moving",_vehicle,_driver,_commandPosition,_vehicleFrontPosition,_vehicleFrontPosition distance2D _commandPosition,_vehicleLength);
            };
        };
    };
}, {
    params ["_vehicle"];

    private _driver = driver _vehicle;
    _driver disableAI "FSM";
    _driver setBehaviour "CARELESS";
    _driver setVariable [QGVAR(vehicle_moveOrdered), false, true];
    TRACE_2("Enter move",_vehicle,_driver);
}, {
    params ["_vehicle"];

    private _driver = driver _vehicle;
    _driver disableAI "MOVE";
    _driver enableAI "FSM";
    _driver setBehaviour "SAFE";
    _driver setVariable [QGVAR(vehicle_moveOrdered), false, true];
    _vehicle setVariable [QGVAR(vehicle_movePosition), [], true];
    _vehicle setVariable [QGVAR(vehicle_moveCommander), objNull, true];
    TRACE_2("Exit move",_vehicle,_driver);
}, QGVAR(vehicle_state_move)] call CBA_statemachine_fnc_addState;

[GVAR(vehicle_statemachine), {
    params ["_vehicle"];

    private _driver = driver _vehicle;
    private _lastTime = _vehicle getVariable [QGVAR(vehicle_lastTime), 0];
    if (CBA_missionTime > (_lastTime + VEHICLE_STOP_INTERVAL)) then {
        _vehicle setVariable [QGVAR(vehicle_lastTime), CBA_missionTime];

        private _commandPosition = getPos (_vehicle getVariable [QGVAR(vehicle_followCommander), _driver]);
        private _direction = (getPos _vehicle) vectorFromTo _commandPosition;
        _commandPosition = _commandPosition vectorAdd (_direction vectorMultiply -3);
        _commandPosition set [2, 0];
        private _vehicleLength = _vehicle getVariable [QGVAR(vehicleLength), 5];
        private _vehicleFrontPosition = _vehicle modelToWorld [0, _vehicleLength / 2, 0];
        _vehicleFrontPosition set [2, 0];

        if ((_vehicleFrontPosition distance2D _commandPosition) > 5) then {
            _driver enableAI "MOVE";
            private _cachedPosition = _vehicle getVariable [QGVAR(vehicle_followCachedPosition), []];
            if (_cachedPosition isEqualTo [] || {(_cachedPosition distance2D _commandPosition) > 3}) then {
                _vehicle setVariable [QGVAR(vehicle_followCachedPosition), _commandPosition, true];
                _driver doMove _commandPosition;
                TRACE_6("Following",_vehicle,_driver,_commandPosition,_vehicleFrontPosition,_vehicleFrontPosition distance2D _commandPosition,_vehicleLength);
            } else {
                TRACE_5("Following (cached)",_vehicle,_driver,_commandPosition,_cachedPosition,_cachedPosition distance2D _commandPosition);
            };
        } else {
            _driver disableAI "MOVE";
            doStop _driver;
            TRACE_6("Holding follow",_vehicle,_driver,_commandPosition,_vehicleFrontPosition,_vehicleFrontPosition distance2D _commandPosition,_vehicleLength);
        };
    };
}, {
    params ["_vehicle"];

    private _driver = driver _vehicle;
    _driver disableAI "FSM";
    _driver setBehaviour "CARELESS";
    _vehicle forceSpeed 3;
    TRACE_2("Enter follow",_vehicle,_driver);
}, {
    params ["_vehicle"];

    private _driver = driver _vehicle;
    _driver disableAI "MOVE";
    _driver enableAI "FSM";
    _driver setBehaviour "SAFE";
    _vehicle setVariable [QGVAR(vehicle_followCommander), objNull, true];
    _vehicle setVariable [QGVAR(vehicle_followCachedPosition), [], true];
    _vehicle forceSpeed 8;
    TRACE_2("Exit follow",_vehicle,_driver);
}, QGVAR(vehicle_state_follow)] call CBA_statemachine_fnc_addState;
