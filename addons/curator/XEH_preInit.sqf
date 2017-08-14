#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

// Curator access
GVAR(curatorGroup) = creategroup sideLogic;
GVAR(curatorObjects) = [];
GVAR(curatorPlayers) = [];

// Setup eventhandlers
if (isServer) then {
    [QGVAR(curatorAssign), {_this call FUNC(curatorAssign)}] call CBA_fnc_addEventHandler;
    [QGVAR(curatorCreate), {_this call FUNC(curatorCreate)}] call CBA_fnc_addEventHandler;
    [QGVAR(curatorUnassign), {_this call FUNC(curatorUnassign)}] call CBA_fnc_addEventHandler;
};
if (hasInterface) then {
    [QGVAR(curatorLogout), {_this call FUNC(curatorLogout)}] call CBA_fnc_addEventHandler;
};

// Start curator access
if (isServer) then {
    addMissionEventHandler ["HandleDisconnect", {[QGVAR(curatorUnassign), [getAssignedCuratorLogic (_this select 0)]] call CBA_fnc_serverEvent;}];
    [] spawn {
        if (!isMultiplayer) then {
            GVAR(curatorsMax) = 1;
        };
        for "_i" from 1 to GVAR(curatorsMax) do {
            call FUNC(curatorCreate);
        };
        missionNamespace setVariable [QGVAR(curatorsCreated), true, true];
    };
};

ADDON = true;
