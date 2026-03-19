#include "script_component.hpp"

#include "XEH_PREP.hpp"

GVAR(statusPerFrameHandler) = -1;
GVAR(processId) = -1;

if (!isDedicated) exitWith {};

call FUNC(start);
