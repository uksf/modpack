#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Adds statemachine states for a vehicle driver leaving and re-entering

    Parameters:
        None

    Return value:
        Nothing

    Example:
        call uksf_civilian_fnc_addVehicleDriverStates
*/

[GVAR(vehicle_statemachine), {
}, {
    params ["_vehicle"];

    private _driver = driver _vehicle;
    _vehicle setVariable [QGVAR(vehicle_driver), _driver, true];
    _driver setVariable [QGVAR(vehicle_vehicle), _vehicle, true];
    _driver leaveVehicle _vehicle;

    _driver setVariable [QGVAR(unit_commandedToStop), true, true];
    [{[QGVAR(startUnitStatemachine), [_this], _this] call CBA_fnc_targetEvent;}, _driver] call CBA_fnc_execNextFrame;
    [{_this enableAI "FSM"}, _driver, 2] call CBA_fnc_waitAndExecute;
    TRACE_2("Enter get out",_vehicle,_driver);
}, {
    params ["_vehicle"];

    private _driver = driver _vehicle;
    TRACE_2("Exit get out",_vehicle,_driver);
}, QGVAR(vehicle_state_getOut)] call CBA_statemachine_fnc_addState;

[GVAR(vehicle_statemachine), {
    params ["_vehicle"];

    private _driver = _vehicle getVariable [QGVAR(vehicle_driver), objNull];
    if (isNull _driver || {!isNull objectParent _driver} || {(_driver distance _vehicle) > GET_IN_ACTION_DISTANCE}) exitWith {};
    if (CBA_missionTime < ((_vehicle getVariable [QGVAR(vehicle_getInTime), 0]) + GET_IN_ACTION_DELAY)) exitWith {};

    _vehicle setVariable [QGVAR(vehicle_getInTime), CBA_missionTime];
    _driver action ["getInDriver", _vehicle];
}, {
    params ["_vehicle"];

    private _driver = _vehicle getVariable [QGVAR(vehicle_driver), objNull];
    if (isNull _driver) exitWith {};

    _vehicle setVariable [QGVAR(vehicle_getInTime), CBA_missionTime];
    [QGVAR(stopUnitStatemachine), [_driver], _driver] call CBA_fnc_targetEvent;

    [{
        params ["_vehicle", "_driver"];

        _driver disableAI "FSM";
        _driver enableAI "MOVE";
        (group _driver) addVehicle _vehicle;
        _driver assignAsDriver _vehicle;
        [_driver] orderGetIn true;
        [_driver, _vehicle, 0, "GETIN", "CARELESS", "BLUE", "LIMITED"] call CBA_fnc_addWaypoint;
        _driver forceWalk true;
    }, [_vehicle, _driver]] call CBA_fnc_execNextFrame;

    TRACE_2("Enter get in",_vehicle,_driver);
}, {
    params ["_vehicle"];

    private _driver = driver _vehicle;
    _driver setBehaviour "SAFE";
    _driver enableAI "FSM";
    _driver disableAI "MOVE";
    _driver forceWalk false;
    TRACE_2("Exit get in",_vehicle,_driver);
}, QGVAR(vehicle_state_getIn)] call CBA_statemachine_fnc_addState;
