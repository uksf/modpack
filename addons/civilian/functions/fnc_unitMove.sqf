#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Searches for civilian units in front of unit, and commands them to move to pointed at location

    Parameters:
        0: Unit <OBJECT>

    Return value:
        Nothing
*/
params ["_unit"];

private _entities = _unit nearEntities [["CAManBase"], GESTURE_UNIT_SEARCH_DISTANCE];
if (_entities isEqualTo []) exitWith {
    DEBUG("No entities found, reducing cooldown timeout");
    GVAR(lastGesture) = CBA_missionTime - (GESTURE_COOLDOWN / 2);
};

_entities = _entities apply {[_x distance _unit, _x]};
_entities sort true;

TRACE_1("Near entities",_entities);
private _index = _entities findIf {
    private _civilian = _x#1;

    TRACE_6("Valid?",_civilian,vehicle _civilian,side _civilian,_civilian getVariable [ARR_2(QGVAR(unit_ignoreCommands),false)],_civilian getVariable [ARR_2(QGVAR(unit_stopped),false)],_civilian getVariable [ARR_2(QGVAR(unit_ignoringStop),false)]);
    TRACE_2("LOS?",acos ((eyeDirection _civilian) vectorCos ((eyePos _civilian) vectorFromTo (eyePos _unit))),lineIntersects [ARR_4(eyePos _civilian,eyePos _unit,_unit,_civilian)]);

    !(isNull _civilian) &&
    {!(isPlayer _civilian)} &&
    {(vehicle _civilian) == _civilian} &&
    {side _civilian == civilian} &&
    {!(_civilian getVariable [QGVAR(unit_ignoreCommands), false])} &&
    {_civilian getVariable [QGVAR(unit_commandedToStop), false]} &&
    {!(_civilian getVariable [QGVAR(unit_ignoringStop), false])} &&
    {(acos ((eyeDirection _civilian) vectorCos ((eyePos _civilian) vectorFromTo (eyePos _unit)))) < VISION_ARC} &&
    {!(lineIntersects [eyePos _civilian, eyePos _unit, _unit, _civilian])}
};
TRACE_1("Valid civilian?",_index);

if (_index != -1) then {
    private _civilian = _entities#_index#1;
    TRACE_1("Selected civilian",_civilian);

    private _origin = AGLtoASL positionCameraToWorld [0,0,0];
    private _commandPosition = AGLtoASL positionCameraToWorld [0,0,30];
    private _intersections = lineIntersectsSurfaces [_origin, _commandPosition, _unit, _civilian, true, 1];
    if !(_intersections isEqualTo []) then {
        _commandPosition = ASLToAGL (_intersections#0#0);
    };

    // private _direction = (getPos _civilian) vectorFromTo _commandPosition;
    // _commandPosition = _commandPosition vectorAdd (_direction vectorMultiply 2);
    _commandPosition set [2, 0];
    TRACE_1("Move command position",_commandPosition);

    _civilian setVariable [QGVAR(unit_movePosition), _commandPosition, true];
    _civilian setVariable [QGVAR(unit_moveCommander), _unit, true];
    _civilian setVariable [QGVAR(unit_forceMoveUpdate), true, true];

    // Fake some mental delay before executing move event
    [{[QGVAR(moveCommand), _this, _this#0] call CBA_fnc_targetEvent}, [_civilian], random 0.5 + (linearConversion [2, GESTURE_UNIT_SEARCH_DISTANCE / 2, _unit distance _civilian, 0.1, 0.5, true])] call CBA_fnc_waitAndExecute;
};

// Civilian valid if:
// Civilian is not a player
// Civilian is not in a vehicle
// Civilian side is civilian
// Civilian is not set to ignore orders
// Civilian has been told to stop
// Civilian is not ignoring stop
// Unit hand is inside Civilian sight arc
// Unit is visible to Civilian
