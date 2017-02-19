#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

GVAR(curatorObjects) = [objNull,objNull,objNull,objNull,objNull];

if (isServer) then {
    if (isNil {missionNamespace getVariable QGVAR(pingAdded)}) then {
        missionNamespace setVariable [QGVAR(pingAdded), false, true];
    };
    call FUNC(ping);    
    call FUNC(initCurators);
};

ADDON = true;
