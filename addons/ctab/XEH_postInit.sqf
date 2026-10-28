#include "script_component.hpp"

if (!hasInterface) exitWith {};

[QGVAR(modeChanged), FUNC(onModeChanged)] call CBA_fnc_addEventHandler;
