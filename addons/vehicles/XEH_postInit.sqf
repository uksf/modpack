#include "script_component.hpp"

call FUNC(addSwapDriverActions);

[QGVAR(swapDriver), {call FUNC(swapDriverLocal)}] call CBA_fnc_addEventHandler;
