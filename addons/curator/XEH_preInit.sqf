#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

// Curator access
GVAR(curatorGroup) = createGroup sideLogic;
GVAR(curatorObjects) = [];
GVAR(curatorPlayers) = [];

// Setup eventhandlers
if (isServer) then {
    [QGVAR(curatorAssign), { _this call FUNC(curatorAssign) }] call CBA_fnc_addEventHandler;
    [QGVAR(curatorUnassign), { _this call FUNC(curatorUnassign) }] call CBA_fnc_addEventHandler;

    // Start curator access
    addMissionEventHandler ["HandleDisconnect", { [QGVAR(curatorUnassign), [getAssignedCuratorLogic (_this select 0)]] call CBA_fnc_serverEvent; }];
    if (!isMultiplayer) then {
        GVAR(curatorsMax) = 1;
        publicVariable QGVAR(curatorsMax);
    };
    for "_i" from 1 to GVAR(curatorsMax) do {
        call FUNC(curatorCreate);
    };
};

ADDON = true;
