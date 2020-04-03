#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Searches for civilian vehicles in front of unit, and stops closest one if found

    Parameters:
        0: Unit <OBJECT>

    Return value:
        Nothing
*/
params ["_unit"];

if (time < (GVAR(lastGesture) + GESTURE_COOLDOWN)) exitWith {DEBUG("Stop called within cooldown, exiting")};
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
    TRACE_3("LOS?",acos ((vectorDirVisual _unit) vectorCos ((eyePos _unit) vectorFromTo (eyePos _driver))),acos ((eyeDirection _driver) vectorCos ((eyePos _driver) vectorFromTo (eyePos _unit))),lineIntersects [ARR_4(eyePos _driver,eyePos _unit,_unit,_vehicle)]);

    !(isNull _driver) &&
    {!(isPlayer _driver)} &&
    {side _driver == civilian} &&
    {!(_driver getVariable [QGVAR(ignoringStop), false])} &&
    {(acos ((vectorDirVisual _unit) vectorCos ((eyePos _unit) vectorFromTo (eyePos _driver)))) < VISION_ARC} &&
    {(acos ((eyeDirection _driver) vectorCos ((eyePos _driver) vectorFromTo (eyePos _unit)))) < VISION_ARC} &&
    {!(lineIntersects [eyePos _driver, eyePos _unit, _unit, _vehicle])}
};
TRACE_1("Valid vehicle?",_index);

if (_index != -1) then {
    private _vehicle = _entities#_index#1;
    private _driver = driver _vehicle;
    TRACE_2("Selected vehicle",_vehicle,_driver);

    private _stopCommanded = _driver getVariable [QGVAR(commandedToStop), false];
    if (_stopCommanded) exitWith {
        TRACE_2("Vehicle already commanded to stop (forcing)",_vehicle,_driver);
        [{[QGVAR(stopCommand), _this, _this#0] call CBA_fnc_targetEvent}, [_vehicle], random 0.2 + (linearConversion [1, 50, _unit distance _vehicle, 0.2, 0.8, true])] call CBA_fnc_waitAndExecute;
    };

    if (random 100 < STOP_IGNORE_CHANCE) exitWith {
        _driver setVariable [QGVAR(ignoringStop), true, true];
        [QGVAR(fireHorn), [_vehicle, _driver, 2], _vehicle] call CBA_fnc_targetEvent;
        [{_driver setVariable [QGVAR(ignoringStop), false, true]}, [_driver], 60] call CBA_fnc_waitAndExecute;
        TRACE_2("Stop ignored",_vehicle,_driver);
    };

    GVAR(debug_vehicleSphere) = "Sign_Sphere100cm_F" createVehicle [0,0,0];
    GVAR(debug_vehicleSphere) setObjectTextureGlobal [0, "#(rgb,8,8,3)color(1,1,0,1)"];
    GVAR(debug_vehicleSphere) attachTo [_vehicle, [0,0,2]];

    private _boundingBox = 0 boundingBoxReal _vehicle;
    private _length = (abs (((_boundingBox#1)#1) - ((_boundingBox#0)#1))) * 1.5;
    _driver setVariable [QGVAR(commandedToStop), true, true];
    _vehicle setVariable [QGVAR(vehicleLength), _length, true];

    // If unit is within a small arc to the front of driver, set position in front of unit as move command poisition (should make driver pull up to unit)
    if ((acos ((eyeDirection _driver) vectorCos ((eyePos _driver) vectorFromTo (eyePos _unit)))) < (VISION_ARC / 2)) then {
        private _commandPosition = (positionCameraToWorld [0,0,0]) vectorAdd ((vectorDirVisual _unit) vectorMultiply 7);
        _commandPosition = _commandPosition vectorAdd ((vectorDirVisual _vehicle) vectorMultiply 4);
        _commandPosition set [2, 0];
        _vehicle setVariable [QGVAR(stop_statemachine_movePosition), _commandPosition, true];
        _vehicle setVariable [QGVAR(stop_statemachine_moveCommander), _unit, true];
        _vehicle setVariable [QGVAR(stop_statemachine_forceMoveUpdate), true, true];
        TRACE_1("Stop command given move position",_commandPosition);
    };

    // Fake some mental delay before starting stop statemachine based on distance
    [{[QGVAR(startStopStatemachine), _this, _this#0] call CBA_fnc_targetEvent}, [_vehicle], random 0.5 + (linearConversion [30, 100, _unit distance _vehicle, 0.5, 1, true])] call CBA_fnc_waitAndExecute;
};

// Vehicle valid if:
// Driver is not a player
// Vehicle is driving (speed > 1kmh)
// Driver side is civilian
// Driver is not ignoring stop
// Unit hand is inside driver sight arc
// Driver is inside unit sight arc
// Unit is visible to driver
