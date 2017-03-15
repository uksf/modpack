#include "script_component.hpp"

[QGVAR(databaseInitFinished), {_this call FUNC(addEvents)}] call CBA_fnc_addEventHandler;

//if (isDedicated) then {
if (isServer) then {
    if (isClass (configFile >> "CfgPatches" >> "extDB3")) then {
        if (GVAR(ID) != "DEFAULTWILLNOTLOAD") then {
            call FUNC(initPersistence);
        } else {
            ERROR("ID set to default. Will not run any persistence functionality.");
        };
    } else {
        ERROR("extDB3 not loaded. Will not run any persistence functionality.");
    };
};
