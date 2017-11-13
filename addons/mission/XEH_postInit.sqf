#include "script_component.hpp"

call FUNC(getConfigGroups);

["CAManBase", "MPHit", {_this call FUNC(support)}, true, [], true] call CBA_fnc_addClassEventHandler;
