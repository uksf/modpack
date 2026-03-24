#include "script_component.hpp"

if !(isServer) exitWith {};

// Single commander loop — handles all scheduling and zone monitoring
[FUNC(commanderLoop), 10] call CBA_fnc_addPerFrameHandler;

INFO("Air threat commander loop started");
