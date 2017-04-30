#include "script_component.hpp"

//Setup eventhandlers
if (isServer) then {
    [QGVAR(curatorAssign), {_this call FUNC(curatorAssign)}] call CBA_fnc_addEventHandler;
    [QGVAR(curatorCreate), {_this call FUNC(curatorCreate)}] call CBA_fnc_addEventHandler;
    [QGVAR(curatorUnassign), {_this call FUNC(curatorUnassign)}] call CBA_fnc_addEventHandler;
};
if (hasInterface) then {
    [QGVAR(curatorLogout), {_this call FUNC(curatorLogout)}] call CBA_fnc_addEventHandler;
};

//Start curator access
if (isServer) then {
    addMissionEventHandler ["HandleDisconnect", {[QGVAR(curatorUnassign), [getAssignedCuratorLogic (_this select 0)]] call CBA_fnc_serverEvent;}];
    if (isMultiplayer) then {
        for "_i" from 1 to GVAR(curatorsMax) do {
            call FUNC(curatorCreate);
        };
    };
};
if (!isMultiplayer) then {
    call FUNC(curatorCreate);
    call FUNC(curatorLogin);
};
if (hasInterface) then {
    call FUNC(addCuratorActions);
};
