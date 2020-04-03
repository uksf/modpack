#include "script_component.hpp"

if (!GVAR(enableGestures)) exitWith {};

["ace_common_playActionNow", {call FUNC(handleGesture)}] call CBA_fnc_addEventHandler;

[QGVAR(startStopStatemachine), {call FUNC(startStopStatemachine)}] call CBA_fnc_addEventHandler;
