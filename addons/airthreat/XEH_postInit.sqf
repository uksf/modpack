#include "script_component.hpp"

call FUNC(registerDebugProvider);

if !(isServer) exitWith {};

// Single commander loop — handles all scheduling and zone monitoring
[FUNC(commanderLoop), 10] call CBA_fnc_addPerFrameHandler;

DEBUG("Air threat commander loop started");
