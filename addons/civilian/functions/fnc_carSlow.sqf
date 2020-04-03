#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Searches for civilian vehicles in front of unit, and tells ones in range to slow down

    Parameters:
        0: Unit <OBJECT>

    Return value:
        Nothing
*/
params ["_unit"];

if (time < (GVAR(lastGesture) + GESTURE_COOLDOWN)) exitWith {DEBUG("Slow called within cooldown, exiting")};
GVAR(lastGesture) = time;

private _vehicles = _unit nearEntities [["Car", "Motorcycle", "Tank"], GESTURE_SEARCH_DISTANCE];
if (_vehicles isEqualTo []) exitWith {
    DEBUG("No entities found, reducing cooldown timeout");
    GVAR(lastGesture) = time - (GESTURE_COOLDOWN / 2);
};

_vehicles = _vehicles apply {[_x distance _unit, _x]};
_vehicles sort true;

TRACE_1("Near vehicles",_vehicles);
_vehicles = _vehicles select {
    private _vehicle = _x#1;
    private _driver = driver _vehicle;

    TRACE_5("Valid?",_vehicle,_driver,side _driver,_driver getVariable [ARR_2(QGVAR(commandedToStop),false)],_driver getVariable [ARR_2(QGVAR(ignoringStop),false)]);
    TRACE_3("LOS?",acos ((vectorDirVisual _unit) vectorCos ((eyePos _unit) vectorFromTo (eyePos _driver))),acos ((eyeDirection _driver) vectorCos ((eyePos _driver) vectorFromTo (eyePos _unit))),lineIntersects [ARR_4(eyePos _driver,eyePos _unit,_unit,_vehicle)]);

    !(isNull _driver) &&
    {!(isPlayer _driver)} &&
    {(speed _vehicle) > 20} &&
    {side _driver == civilian} &&
    {!(_driver getVariable [QGVAR(commandedToStop), false])} &&
    {!(_driver getVariable [QGVAR(ignoringStop), false])} &&
    {(acos ((vectorDirVisual _unit) vectorCos ((eyePos _unit) vectorFromTo (eyePos _driver)))) < VISION_WIDE_ARC} &&
    {(acos ((eyeDirection _driver) vectorCos ((eyePos _driver) vectorFromTo (eyePos _unit)))) < VISION_WIDE_ARC} &&
    {!(lineIntersects [eyePos _driver, eyePos _unit, _unit, _vehicle])}
};
TRACE_1("Valid vehicles?",_vehicles);

{
    private _vehicle = _x#1;
    private _driver = driver _vehicle;

    if (random 100 < STOP_IGNORE_CHANCE) exitWith {
        _driver setVariable [QGVAR(ignoringStop), true, true];
        [QGVAR(fireHorn), [_vehicle, _driver, 2], _vehicle] call CBA_fnc_targetEvent;
        [{_driver setVariable [QGVAR(ignoringStop), false, true]}, [_driver], 60] call CBA_fnc_waitAndExecute;
        TRACE_2("Slow ignored",_vehicle,_driver);
    };

    // Fake some mental delay before slowing vehicle
    [{
        _this forceSpeed 2.5;
        // Reset speed after some time
        [{ _this forceSpeed -1;}, _this, random 20 + random 10] call CBA_fnc_waitAndExecute;
    }, _vehicle, random 0.5 + (linearConversion [30, 100, _unit distance _vehicle, 0.5, 1, true])] call CBA_fnc_waitAndExecute;
} forEach _vehicles;

// Vehicle valid if:
// Driver is not a player
// Vehicle is driving fast (speed > 20kmh)
// Driver side is civilian
// Driver has not been commanded to stop
// Driver is not ignoring stop
// Unit hand is inside driver sight arc
// Driver is inside unit sight arc
// Unit is visible to driver
