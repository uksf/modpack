#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

#include "initSettings.sqf"

if (isServer) then {
    GVAR(curatorObjects) = [];
    GVAR(curatorPlayers) = [];
    [QGVAR(setCuratorsLocked), {call FUNC(setCuratorsLocked)}] call CBA_fnc_addEventHandler;
    [QGVAR(curatorAssign), {call FUNC(curatorAssign)}] call CBA_fnc_addEventHandler;
    [QGVAR(curatorUnassign), {call FUNC(curatorUnassign)}] call CBA_fnc_addEventHandler;

    addMissionEventHandler ["HandleDisconnect", {[QGVAR(curatorUnassign), [getAssignedCuratorLogic (_this#0)]] call CBA_fnc_serverEvent;}];

    ["CBA_settingsInitialized", {
        if (!isMultiplayer) then {
            GVAR(curatorsMax) = 1;
        };

        TRACE_1("",GVAR(curatorsMax));
        ["ModuleCurator_F", "init", {
            params ["_curator"];

            TRACE_1("Mission curator init",_curator);
            if ((count GVAR(curatorObjects)) >= GVAR(curatorsMax)) exitWith {
                INFO_1("Max curators reached. Deleting %1",_curator);
                deleteVehicle _curator;
            };

            call FUNC(curatorInit);
        }, false, [], true] call CBA_fnc_addClassEventHandler;
    }] call CBA_fnc_addEventHandler;
};

if (hasInterface) then {
    ["CAManBase", "respawn", {
        params ["_unit"];

        private _index = (GVAR(curatorPlayers) find (name _unit));
        if (_index != -1) then {
            GVAR(curatorUnassignedEHID) = [QGVAR(curatorUnassigned), {
                [QGVAR(curatorAssign), _this] call CBA_fnc_serverEvent;
                [QGVAR(curatorUnassigned), GVAR(curatorUnassignedEHID)] call CBA_fnc_removeEventHandler;
            }] call CBA_fnc_addEventHandler;
            [QGVAR(curatorUnassign), [GVAR(curatorObjects)#_index, _unit]] call CBA_fnc_serverEvent;
        } else {
            if (WHITELISTED) then {
                // call FUNC(curatorLogin);
            };
        };
    }, true, [], true] call CBA_fnc_addClassEventHandler;

    call FUNC(addCuratorActions);
};

ADDON = true;
