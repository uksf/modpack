#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

#include "initSettings.inc.sqf"

if (isServer) then {
    GVAR(curatorObjects) = [];
    GVAR(curatorPlayers) = [];
    GVAR(reservationSerial) = 0;
    addMissionEventHandler ["HandleDisconnect", {[objNull, objNull, _this#0, true] call FUNC(curatorUnassign)}];
    addMissionEventHandler ["EntityRespawned", {
        params ["_unit", "_oldUnit"];
        if (!isPlayer _unit) exitWith {};
        private _index = GVAR(curatorPlayers) find (name _unit);
        if (_index == -1) exitWith {};
        private _curator = GVAR(curatorObjects) param [_index, objNull];
        if (isNull _curator) exitWith {};
        private _holder = getAssignedCuratorUnit _curator;
        if (!isNull _holder && {_holder != _oldUnit} && {_holder != _unit}) exitWith {};
        [_curator] call FUNC(curatorUnassign);
        [_unit] call FUNC(curatorAssign);
    }];

    ["CBA_settingsInitialized", {
        if (!isMultiplayer) then {
            GVAR(curatorsMax) = 1;
        };

        TRACE_1("",GVAR(curatorsMax));
        ["ModuleCurator_F", "init", {
            params ["_curator"];

            call FUNC(pruneCurators);

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
    GVAR(curatorUnassignedEHID) = -1;
    call FUNC(addCuratorActions);

    call FUNC(buildMissingVehiclesCache);

    ["zen_editor_treesLoaded", {
        params ["_display"];
        [_display] call FUNC(injectMissingVehicles);
    }] call CBA_fnc_addEventHandler;

    ["CAManBase", "respawn", {
        params ["_unit"];

        [QEGVAR(common,addObjectsToCurators), [[_unit]]] call CBA_fnc_serverEvent;

        if (WHITELISTED && {!((name _unit) in GVAR(curatorPlayers))}) then {
            call FUNC(curatorLogin);
        };
    }, true, [], true] call CBA_fnc_addClassEventHandler;
};

ADDON = true;
