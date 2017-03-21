#include "script_component.hpp"


//if (isDedicated) then {
if (isServer) then {
    if (GVAR(ID) != "DEFAULTWILLNOTLOAD") then {
        call FUNC(initPersistence);
    } else {
        ERROR("Found default ID. Will not run any persistence functionality.");
    };
};
