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

TRACE_1("Gesture event",_gesture);
if ("ace_gestures_warning" in _gesture) exitWith {call FUNC(carSlow)};
if ("ace_gestures_hold" in _gesture) exitWith {call FUNC(carStop)};
if ("ace_gestures_point" in _gesture) exitWith {call FUNC(carMove)};
if ("ace_gestures_forward" in _gesture) exitWith {call FUNC(carGo)};
if ("follow" in _gesture) exitWith {call FUNC(carGetOut)};

