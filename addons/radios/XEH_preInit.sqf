#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

GVAR(useRebros) = true;
GVAR(rebroStations) = [];
GVAR(rebroDebugging) = false;

[QGVAR(initialiseRebroStation), {call FUNC(initialiseRebroStation)}] call CBA_fnc_addEventHandler;
[QGVAR(deinitialiseRebroStation), {call FUNC(deinitialiseRebroStation)}] call CBA_fnc_addEventHandler;

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
