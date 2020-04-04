#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Handles gesture played by ace, to trigger different functionality for civilians

    Parameters:
        0: Unit <OBJECT>
        1: Gesture name <STRING>

    Return value:
        Nothing
*/
params ["_unit", "_gesture"];

_gesture = toLower _gesture;
TRACE_2("Gesture event",_unit,_gesture);

if (CBA_missionTime < (GVAR(lastGesture) + GESTURE_COOLDOWN)) exitWith {DEBUG("Gesture called within cooldown, exiting")};
GVAR(lastGesture) = CBA_missionTime;

if ("ace_gestures_warning" in _gesture) exitWith {
    call FUNC(vehicleSlow);
    // call FUNC(unitAway); // send units away from commanding player
};

if ("ace_gestures_hold" in _gesture) exitWith {
    call FUNC(vehicleStop);
    call FUNC(unitStop);
};

if ("ace_gestures_point" in _gesture) exitWith {
    call FUNC(vehicleMove);
    call FUNC(unitMove);
};

if ("ace_gestures_forward" in _gesture) exitWith {
    call FUNC(vehicleGo);
    call FUNC(unitGo);
};

if ("follow" in _gesture) exitWith {
    call FUNC(vehicleFollow);
    call FUNC(unitFollow);
};

