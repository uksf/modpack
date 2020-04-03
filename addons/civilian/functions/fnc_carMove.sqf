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

if (time < (GVAR(lastGesture) + GESTURE_COOLDOWN)) exitWith {DEBUG("Move called within cooldown, exiting")};
GVAR(lastGesture) = time;

private _entities = _unit nearEntities [["Car", "Motorcycle", "Tank"], GESTURE_SEARCH_DISTANCE];
if (_entities isEqualTo []) exitWith {
    DEBUG("No entities found, reducing cooldown timeout");
    GVAR(lastGesture) = time - (GESTURE_COOLDOWN / 2);
};

_entities = _entities apply {[_x distance _unit, _x]};
_entities sort true;

TRACE_1("Near entities",_entities);
private _index = _entities findIf {
    private _vehicle = _x#1;
    private _driver = driver _vehicle;

    TRACE_5("Valid?",_vehicle,_driver,side _driver,_driver getVariable [ARR_2(QGVAR(commandedToStop),false)],_driver getVariable [ARR_2(QGVAR(ignoringStop),false)]);
    TRACE_2("LOS?",acos ((eyeDirection _driver) vectorCos ((eyePos _driver) vectorFromTo (eyePos _unit))),lineIntersects [ARR_4(eyePos _driver,eyePos _unit,_unit,_vehicle)]);

    !(isNull _driver) &&
    {!(isPlayer _driver)} &&
    {side _driver == civilian} &&
    {_driver getVariable [QGVAR(commandedToStop), false]} &&
    {!(_driver getVariable [QGVAR(ignoringStop), false])} &&
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
    if !(_intersections isEqualTo []) then {
        _commandPosition = ASLToAGL (_intersections#0#0);
    };

    private _direction = vectorDirVisual _vehicle;
    private _theta = acos ((vectorDirVisual _vehicle) vectorCos (vectorDirVisual _unit));
    if (_theta > 90) then {
        _direction = _direction vectorMultiply -1;
    };

    _commandPosition = _commandPosition vectorAdd (_direction vectorMultiply 4);
    _commandPosition set [2, 0];
    TRACE_1("Move command position",_commandPosition);

    _vehicle setVariable [QGVAR(stop_statemachine_movePosition), _commandPosition, true];
    _vehicle setVariable [QGVAR(stop_statemachine_moveCommander), _unit, true];
    _vehicle setVariable [QGVAR(stop_statemachine_forceMoveUpdate), true, true];

    // Fake some mental delay before executing move event
    [{[QGVAR(moveCommand), _this, _this#0] call CBA_fnc_targetEvent}, [_vehicle], random 0.5 + (linearConversion [10, 50, _unit distance _vehicle, 0.5, 1, true])] call CBA_fnc_waitAndExecute;
};

// Vehicle valid if:
// Driver is not a player
// Driver side is civilian
// Driver has been told to stop
// Driver is not ignoring stop
// Unit hand is inside driver sight arc
// Unit is visible to driver
