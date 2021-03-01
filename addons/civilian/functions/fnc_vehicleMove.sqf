#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Searches for civilian vehicles in front of unit, and commands them to move to pointed at location

    Parameters:
        0: Unit <OBJECT>

    Return value:
        Nothing
*/
params ["_unit"];

private _entities = _unit nearEntities [["Car", "Motorcycle", "Tank"], GESTURE_VEHICLE_SEARCH_DISTANCE];
if (_entities isEqualTo []) exitWith {
    DEBUG("No entities found, reducing cooldown timeout");
    GVAR(lastGesture) = CBA_missionTime - (GESTURE_COOLDOWN / 2);
};

_entities = _entities apply {[_x distance _unit, _x]};
_entities sort true;

TRACE_1("Near entities",_entities);
private _index = _entities findIf {
    private _vehicle = _x#1;
    private _driver = driver _vehicle;

    TRACE_6("Valid?",_vehicle,_driver,side _driver,_driver getVariable [ARR_2(QGVAR(vehicle_ignoreCommands),false)],_driver getVariable [ARR_2(QGVAR(vehicle_commandedToStop),false)],_driver getVariable [ARR_2(QGVAR(vehicle_ignoringStop),false)]);
    TRACE_2("LOS?",acos ((eyeDirection _driver) vectorCos ((eyePos _driver) vectorFromTo (eyePos _unit))),lineIntersects [ARR_4(eyePos _driver,eyePos _unit,_unit,_vehicle)]);

    !(isNull _driver) &&
    {!(isPlayer _driver)} &&
    {side _driver == civilian} &&
    {!(_vehicle getVariable [QGVAR(vehicle_ignoreCommands), false])} &&
    {_driver getVariable [QGVAR(vehicle_commandedToStop), false]} &&
    {!(_driver getVariable [QGVAR(vehicle_ignoringStop), false])} &&
    {(acos ((eyeDirection _driver) vectorCos ((eyePos _driver) vectorFromTo (eyePos _unit)))) < VISION_ARC} &&
    {!(lineIntersects [eyePos _driver, eyePos _unit, _unit, _vehicle])}
};
TRACE_1("Valid vehicle?",_index);

if (_index != -1) then {
    private _vehicle = _entities#_index#1;
    private _driver = driver _vehicle;
    TRACE_1("Selected vehicle",_vehicle);

    private _origin = AGLtoASL positionCameraToWorld [0,0,0];
    private _commandPosition = AGLtoASL positionCameraToWorld [0,0,30];
    private _intersections = lineIntersectsSurfaces [_origin, _commandPosition, _unit, _vehicle, true, 1];
    if (_intersections isNotEqualTo []) then {
        _commandPosition = ASLToAGL (_intersections#0#0);
    };

    private _direction = (getPos _vehicle) vectorFromTo _commandPosition;
    _commandPosition = _commandPosition vectorAdd (_direction vectorMultiply 4);
    _commandPosition set [2, 0];
    TRACE_1("Move command position",_commandPosition);

    // Fake some mental delay before executing move event
    [{
        params ["_vehicle", "_commandPosition", "_unit"];

        _vehicle setVariable [QGVAR(vehicle_movePosition), _commandPosition, true];
        _vehicle setVariable [QGVAR(vehicle_moveCommander), _unit, true];
        _vehicle setVariable [QGVAR(vehicle_forceMoveUpdate), true, true];
        [QGVAR(moveCommand), [_vehicle], _vehicle] call CBA_fnc_targetEvent;
    }, [_vehicle, _commandPosition, _unit], random 0.5 + (linearConversion [10, GESTURE_VEHICLE_SEARCH_DISTANCE / 2, _unit distance _vehicle, 0.5, 1, true])] call CBA_fnc_waitAndExecute;
};

// Vehicle valid if:
// Driver is not a player
// Driver side is civilian
// Vehicle is not set to ignore orders
// Driver has been told to stop
// Driver is not ignoring stop
// Unit hand is inside driver sight arc
// Unit is visible to driver
