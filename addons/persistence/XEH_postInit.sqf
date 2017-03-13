#include "script_component.hpp"

//if (isDedicated) then {
if (isServer) then {
    if (isClass (configFile >> "CfgPatches" >> "extDB3") && {GVAR(ID) != "DEFAULTWILLNOTLOAD"}) then {
        call FUNC(initPersistence);
    } else {
        ERROR("extDB3 not loaded or ID set to default. Will not run any persistence functionality.");
    };
};
