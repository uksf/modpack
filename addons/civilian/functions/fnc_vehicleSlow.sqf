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

private _vehicles = _unit nearEntities [["Car", "Motorcycle", "Tank"], GESTURE_VEHICLE_SEARCH_DISTANCE];
if (_vehicles isEqualTo []) exitWith {
    DEBUG("No entities found, reducing cooldown timeout");
    GVAR(lastGesture) = CBA_missionTime - (GESTURE_COOLDOWN / 2);
};

_vehicles = _vehicles apply {[_x distance _unit, _x]};
_vehicles sort true;

TRACE_1("Near vehicles",_vehicles);
_vehicles = _vehicles select {
    private _vehicle = _x#1;
    private _driver = driver _vehicle;

    TRACE_5("Valid?",_vehicle,_driver,side _driver,_driver getVariable [ARR_2(QGVAR(vehicle_commandedToStop),false)],_driver getVariable [ARR_2(QGVAR(vehicle_ignoringStop),false)]);
    TRACE_3("LOS?",acos ((vectorDirVisual _unit) vectorCos ((eyePos _unit) vectorFromTo (eyePos _driver))),acos ((eyeDirection _driver) vectorCos ((eyePos _driver) vectorFromTo (eyePos _unit))),lineIntersects [ARR_4(eyePos _driver,eyePos _unit,_unit,_vehicle)]);

    !(isNull _driver) &&
    {!(isPlayer _driver)} &&
    {(speed _vehicle) > 20} &&
    {side _driver == civilian} &&
    {!(_driver getVariable [QGVAR(vehicle_commandedToStop), false])} &&
    {!(_driver getVariable [QGVAR(vehicle_ignoringStop), false])} &&
    {(acos ((vectorDirVisual _unit) vectorCos ((eyePos _unit) vectorFromTo (eyePos _driver)))) < VEHICLE_VISION_ARC_WIDE} &&
    {(acos ((eyeDirection _driver) vectorCos ((eyePos _driver) vectorFromTo (eyePos _unit)))) < VEHICLE_VISION_ARC_WIDE} &&
    {!(lineIntersects [eyePos _driver, eyePos _unit, _unit, _vehicle])}
};
TRACE_1("Valid vehicles?",_vehicles);

{
    private _vehicle = _x#1;
    private _driver = driver _vehicle;

    if (random 100 < STOP_IGNORE_CHANCE) exitWith {
        _driver setVariable [QGVAR(vehicle_ignoringStop), true, true];
        [QGVAR(horn), [_vehicle, _driver, 2], _vehicle] call CBA_fnc_targetEvent;
        [{_this setVariable [QGVAR(vehicle_ignoringStop), false, true]}, _driver, 60] call CBA_fnc_waitAndExecute;
        TRACE_2("Slow ignored",_vehicle,_driver);
    };

    // Fake some mental delay before slowing vehicle
    [{
        _this forceSpeed 2.5;
        // Reset speed after some time
        [{ _this forceSpeed -1;}, _this, random 20 + random 10] call CBA_fnc_waitAndExecute;
    }, _vehicle, random 0.5 + (linearConversion [30, GESTURE_VEHICLE_SEARCH_DISTANCE, _unit distance _vehicle, 0.5, 1, true])] call CBA_fnc_waitAndExecute;
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
