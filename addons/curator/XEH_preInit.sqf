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

if (hasInterface) then {
    [QEGVAR(lobby,respawned), {
        [{
            !(isNull (findDisplay 46))
        },{
            [] spawn {
                if (isMultiplayer) then {
                    while {isNull (uiNamespace getVariable "RscDisplayLoading")} do {
                        startLoadingScreen ["Loading"];
                        uiSleep 0.1;
                    };
                    private _step = (1 / GVAR(curatorsMax));
                    for "_index" from 1 to GVAR(curatorsMax) do {
                        progressLoadingScreen (_step * _index);
                        uiSleep 1;
                    };
                    endLoadingScreen;
                };
            };
        }] call CBA_fnc_waitUntilAndExecute;
        call FUNC(addCuratorActions);
        if (!isMultiplayer || {isMultiplayer && WHITELISTED}) then {
            call FUNC(curatorLogin);
        };
        ["CAManBase", "respawn", {
            params ["_unit"];
            private _index = (GVAR(curatorPlayers) find (name _unit));
            if (_index > -1) then {
                [QGVAR(curatorUnassign), [GVAR(curatorObjects) select _index]] call CBA_fnc_serverEvent;
                [QGVAR(curatorAssign), [_unit]] call CBA_fnc_serverEvent;
            } else {
                if (WHITELISTED) then {
                    call FUNC(curatorLogin);
                };
            };
        }, true, [], true] call CBA_fnc_addClassEventHandler;
    }] call CBA_fnc_addEventHandler;
};

ADDON = true;
