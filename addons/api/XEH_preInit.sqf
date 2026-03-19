#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

ADDON = true;

if (isServer) then {
    call FUNC(initMission);
};
