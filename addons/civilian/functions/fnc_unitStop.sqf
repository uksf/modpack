#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Searches for civilian units in front of unit, and stops closest ones if found (max 5)

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
    TRACE_3("LOS?",acos ((vectorDirVisual _unit) vectorCos ((eyePos _unit) vectorFromTo (eyePos _civilian))),acos ((eyeDirection _civilian) vectorCos ((eyePos _civilian) vectorFromTo (eyePos _unit))),lineIntersects [ARR_4(eyePos _civilian,eyePos _unit,_unit,_civilian)]);

    !(isNull _civilian) &&
    {!(isPlayer _civilian)} &&
    {isNull objectParent _civilian} &&
    {side _civilian == civilian} &&
    {!(_civilian getVariable [QGVAR(unit_ignoreCommands), false])} &&
    {!(_civilian getVariable [QGVAR(unit_stopped), false])} &&
    {!(_civilian getVariable [QGVAR(unit_ignoringStop), false])} &&
    {(acos ((vectorDirVisual _unit) vectorCos ((eyePos _unit) vectorFromTo (eyePos _civilian)))) < VISION_ARC} &&
    {(acos ((eyeDirection _civilian) vectorCos ((eyePos _civilian) vectorFromTo (eyePos _unit)))) < VISION_ARC} &&
    {!(lineIntersects [eyePos _civilian, eyePos _unit, _unit, _civilian])}
};
TRACE_1("Valid civilian?",_index);

if (_index != -1) then {
    private _civilian = _entities#_index#1;
    TRACE_1("Selected civilian",_civilian);

    _civilian setVariable [QGVAR(unit_stopCommander), _unit, true];

    private _stopCommanded = _civilian getVariable [QGVAR(unit_commandedToStop), false];
    if (_stopCommanded) exitWith {
        TRACE_1("Civilian already commanded to stop (forcing)",_civilian);
        [{[QGVAR(stopCommand), _this, _this#0] call CBA_fnc_targetEvent}, [_civilian], random 0.2 + (linearConversion [1, 50, _unit distance _civilian, 0.2, 0.8, true])] call CBA_fnc_waitAndExecute;
    };

    if (random 100 < UNIT_STOP_IGNORE_CHANCE) exitWith {
        _civilian setVariable [QGVAR(unit_ignoringStop), true, true];
        [{_this setVariable [QGVAR(unit_ignoringStop), false, true]}, _civilian, 60] call CBA_fnc_waitAndExecute;
        TRACE_1("Stop ignored",_civilian);
    };

    _civilian setVariable [QGVAR(unit_commandedToStop), true, true];

    // If unit is within a small arc to the front of civilian, set position in front of unit as move command poisition (should make civilian walk up to unit)
    private _commandPosition = [];
    private _commandUnit = objNull;
    private _forceMoveUpdate = false;
    if ((acos ((eyeDirection _civilian) vectorCos ((eyePos _civilian) vectorFromTo (eyePos _unit)))) < (VISION_ARC / 1.5) && {(random 100) < UNIT_STOP_WALK_TO_PLAYER_CHANCE}) then {
        _commandPosition = (positionCameraToWorld [0,0,0]) vectorAdd ((vectorDirVisual _unit) vectorMultiply 5);
        _commandPosition set [2, 0];
        _commandUnit = _unit;
        _forceMoveUpdate = true;
        TRACE_1("Stop command given move position",_commandPosition);
    };

    // Fake some mental delay before starting unit statemachine based on distance
    [{
        params ["_civilian", "_commandPosition", "_commandUnit", "_forceMoveUpdate"];

        _civilian setVariable [QGVAR(unit_movePosition), _commandPosition, true];
        _civilian setVariable [QGVAR(unit_moveCommander), _commandUnit, true];
        _civilian setVariable [QGVAR(unit_forceMoveUpdate), _forceMoveUpdate, true];
        [QGVAR(startUnitStatemachine), [_civilian], _civilian] call CBA_fnc_targetEvent;
    }, [_civilian, _commandPosition, _commandUnit, _forceMoveUpdate], random 0.5 + (linearConversion [10, GESTURE_UNIT_SEARCH_DISTANCE, _unit distance _civilian, 0.1, 0.5, true])] call CBA_fnc_waitAndExecute;
};

// Civilian valid if:
// Civilian is not a player
// Civilian is not in a vehicle
// Civilian side is civilian
// Civilian is not set to ignore orders
// Civilian has not stopped
// Civilian is not ignoring stop
// Unit hand is inside Civilian sight arc
// Civilian is inside unit sight arc
// Unit is visible to Civilian
