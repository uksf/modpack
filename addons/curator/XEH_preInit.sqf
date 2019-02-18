#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

#include "initSettings.sqf"

if (isServer) then {
    GVAR(curatorGroup) = createGroup sideLogic;
    GVAR(curatorObjects) = [];
    GVAR(curatorPlayers) = [];
    [QGVAR(setCuratorsLocked), {call FUNC(setCuratorsLocked)}] call CBA_fnc_addEventHandler;
    [QGVAR(curatorAssign), {call FUNC(curatorAssign)}] call CBA_fnc_addEventHandler;
    [QGVAR(curatorUnassign), {call FUNC(curatorUnassign)}] call CBA_fnc_addEventHandler;

    addMissionEventHandler ["HandleDisconnect", {[QGVAR(curatorUnassign), [getAssignedCuratorLogic (_this select 0)]] call CBA_fnc_serverEvent;}];
    if (!isMultiplayer) then {
        GVAR(curatorsMax) = 1;
        publicVariable QGVAR(curatorsMax);
    };
    for "_i" from 1 to GVAR(curatorsMax) do {
        call FUNC(curatorCreate);
    };
};

if (hasInterface) then {
    ["CAManBase", "respawn", {
        params ["_unit"];

        [_unit] call FUNC(addCuratorActions);

        private _index = (GVAR(curatorPlayers) find (name _unit));
        if (_index > -1) then {
            [QGVAR(curatorUnassign), [GVAR(curatorObjects) select _index]] call CBA_fnc_serverEvent;
            [QGVAR(curatorAssign), [_unit]] call CBA_fnc_serverEvent;
        } else {
            if (WHITELISTED) then {
                // call FUNC(curatorLogin);
            };
        };
    }, true, [], true] call CBA_fnc_addClassEventHandler;

    ["CBA_loadingScreenDone", {
        [{
            !(isNull (findDisplay 46))
        }, {
            [] spawn {
                if (isMultiplayer) then {
                    startLoadingScreen ["Loading"];
                    private _step = (1 / GVAR(curatorsMax));
                    for "_index" from 1 to GVAR(curatorsMax) do {
                        progressLoadingScreen (_step * _index);
                        uiSleep 1;
                    };
                    endLoadingScreen;
                };
            };
            if (!isMultiplayer) then {
                call FUNC(curatorLogin);
            };
        }] call CBA_fnc_waitUntilAndExecute;
    }] call CBA_fnc_addEventHandler;
};

ADDON = true;
