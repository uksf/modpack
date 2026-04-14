#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

GVAR(useRebros) = true;
GVAR(rebroStations) = [];
GVAR(rebroStationsFilterFrame) = -1;
GVAR(rebroDebugging) = false;
GVAR(debugReportingEnabled) = false;
GVAR(debugReportingNextUpdate) = createHashMap;
GVAR(debugConnectionData) = createHashMap;
GVAR(testRebroPfhHandle) = -1;
GVAR(testRebroMast) = objNull;
GVAR(testVehicle) = objNull;

[QGVAR(initialiseRebroStation), {call FUNC(initialiseRebroStation)}] call CBA_fnc_addEventHandler;
[QGVAR(deinitialiseRebroStation), {call FUNC(deinitialiseRebroStation)}] call CBA_fnc_addEventHandler;

["acre_signal_endTransmission", {
    if (!GVAR(debugReportingEnabled)) exitWith {};

    params ["", "_transmitterRadioId"];

    GVAR(debugReportingNextUpdate) deleteAt _transmitterRadioId;

    private _transmitterOwner = [_transmitterRadioId] call acre_sys_radio_fnc_getRadioObject;
    if (isNil "_transmitterOwner" || {isNull _transmitterOwner}) exitWith {};

    private _transmitterKey = if (isPlayer _transmitterOwner) then {
        getPlayerUID _transmitterOwner
    } else {
        netId _transmitterOwner
    };

    GVAR(debugConnectionData) deleteAt _transmitterKey;
    [QGVAR(debugPurgeTransmitter), [getPlayerUID player, _transmitterKey]] call CBA_fnc_serverEvent;
}] call CBA_fnc_addEventHandler;

if (isServer) then {
    [QGVAR(debugPurgeTransmitter), {
        params ["_receiverUid", "_transmitterKey"];

        private _sourceData = EGVAR(zeus,debugClientData) getOrDefault [QGVAR(signalData), createHashMap];
        private _entry = _sourceData getOrDefault [_receiverUid, []];
        if (_entry isEqualTo []) exitWith {};

        private _connectionData = _entry param [1, createHashMap];
        _connectionData deleteAt _transmitterKey;
    }] call CBA_fnc_addEventHandler;
};

private _action = [QGVAR(assembleRebroStation), "Assemble ReBro Station", "", {
    [_player, "Acts_carFixingWheel", 1] call ace_common_fnc_doAnimation;
    [10, [_target, _player], {
        params ["_args"];
        _args params ["_target", "_player"];

        [_player, "", 2] call ace_common_fnc_doAnimation;
        [_target] call FUNC(assembleRebroStation);
    }, {
        params ["_args"];
        _args params ["_target", "_player"];

        [_player, "", 2] call ace_common_fnc_doAnimation;
        hint "Failed to assemble Re-broadcasting Station";
    }, "Assembling Re-broadcasting Station"] call ace_common_fnc_progressBar;
}, {true}] call ace_interact_menu_fnc_createAction;
[QGVAR(rebroStationBox), 0, ["ACE_MainActions"], _action] call ace_interact_menu_fnc_addActionToClass;

_action = [QGVAR(disassembleRebroStation), "Disassemble ReBro Station", "", {
    [_player, "Acts_carFixingWheel", 1] call ace_common_fnc_doAnimation;
    [10, [_target, _player], {
        params ["_args"];
        _args params ["_target", "_player"];

        [_player, "", 2] call ace_common_fnc_doAnimation;
        [_target, _player] call FUNC(disassembleRebroStation);
    }, {
        params ["_args"];
        _args params ["_target", "_player"];

        [_player, "", 2] call ace_common_fnc_doAnimation;
        hint "Failed to disassemble Re-broadcasting Station";
    }, "Disassembling Re-broadcasting Station"] call ace_common_fnc_progressBar;
}, {true}] call ace_interact_menu_fnc_createAction;
[QGVAR(rebroStationEquipment), 0, ["ACE_MainActions"], _action] call ace_interact_menu_fnc_addActionToClass;

if (isServer) then {
    [QGVAR(rebroStations), {
        GVAR(rebroStations) select {alive _x && _x isKindOf QGVAR(rebroStationMast)} apply {[getPosATL _x, getDir _x]}
    }, {
        params ["_data"];

        {
            [objNull, _x] call FUNC(assembleRebroStation);
        } forEach _data;
    }] call EFUNC(persistence,registerSerializer);

    ["AllVehicles", "initPost", {call FUNC(initialiseVehicleRacks)}, true] call CBA_fnc_addClassEventHandler;
};

if (hasInterface) then {
    {[_x] call FUNC(addVehicleRebroActions)} forEach [
        QAIRGVAR(reaper,raf),
        QAIRGVAR(f35,base),
        QAIRGVAR(patches,dauphin)
    ];
};

ADDON = true;
