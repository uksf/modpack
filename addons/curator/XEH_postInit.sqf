#include "script_component.hpp"

// Start curator access
[] spawn {
    if (isServer) then {
        addMissionEventHandler ["HandleDisconnect", {[QGVAR(curatorUnassign), [getAssignedCuratorLogic (_this select 0)]] call CBA_fnc_serverEvent;}];
        if (!isMultiplayer) then {
            GVAR(curatorsMax) = 1;
        };
        [QEGVAR(common,startLoadingScreen), ["Loading..."]] call CBA_fnc_globalEvent;
        for "_i" from 1 to GVAR(curatorsMax) do {
            call FUNC(curatorCreate);
            [QEGVAR(common,progressLoadingScreen), (1 / GVAR(curatorsMax)) * _i] call CBA_fnc_globalEvent;
        };
        [QEGVAR(common,endLoadingScreen), []] call CBA_fnc_globalEvent;
    };

    if (!isMultiplayer || {(getPlayerUID player) in WHITELIST}) then {
        call FUNC(curatorLogin);
    };
    if (hasInterface) then {
        call FUNC(addCuratorActions);
        ["CAManBase", "respawn", {
            private _index = GVAR(curatorPlayers) find (name player);
            if (_index > -1) then {
                [QGVAR(curatorUnassign), [GVAR(curatorObjects) select _index]] call CBA_fnc_serverEvent;
                [QGVAR(curatorAssign), [player]] call CBA_fnc_serverEvent;
            };
        }, true, [], true] call CBA_fnc_addClassEventHandler;
    };
};
