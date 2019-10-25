#include "script_component.hpp"

if (hasInterface) then {
    ["ZEN_displayCuratorLoad", {call FUNC(curatorDisplayLoad)}] call CBA_fnc_addEventHandler;
    ["ZEN_displayCuratorUnload", {call FUNC(curatorDisplayUnload)}] call CBA_fnc_addEventHandler;
