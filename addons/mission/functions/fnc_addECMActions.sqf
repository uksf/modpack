#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Adds ACE self-actions for ECM.

    Parameters:
        None

    Return value:
        None
*/

if (!hasInterface) exitWith {};

private _action = [QGVAR(ecmTurnOn), "Turn On ECM", "", {
    [_player] call FUNC(ecmRequestActivate);
}, {
    if (!GVAR(ecmEnabled) || {_player getVariable [QGVAR(ecmActive), false]}) exitWith {false};

    private _source = [_player] call FUNC(getECMSource);
    _source params ["_mode"];
    if (_mode isEqualTo "vehicle") exitWith {true};
    if (_mode isNotEqualTo "backpack") exitWith {false};

    (_player getVariable [QGVAR(ecmBatteryRemaining), 0]) > 0
    || {[_player, QGVAR(ecmBattery)] call ace_common_fnc_hasItem}
}] call ace_interact_menu_fnc_createAction;
["CAManBase", 1, ["ACE_SelfActions"], _action, true] call ace_interact_menu_fnc_addActionToClass;

_action = [QGVAR(ecmTurnOff), "Turn Off ECM", "", {
    [_player] call FUNC(ecmRequestDeactivate);
}, {
    if (!GVAR(ecmEnabled)) exitWith {false};
    if (_player getVariable [QGVAR(ecmActive), false]) exitWith {true};

    private _source = [_player] call FUNC(getECMSource);
    if ((_source#0) isNotEqualTo "vehicle") exitWith {false};

    (_source#2) getVariable [QGVAR(ecmVehicleActive), false]
}] call ace_interact_menu_fnc_createAction;
["CAManBase", 1, ["ACE_SelfActions"], _action, true] call ace_interact_menu_fnc_addActionToClass;

_action = [QGVAR(ecmCheckBattery), "Check ECM Battery", "", {
    [_player] call FUNC(ecmCheckBattery);
}, {
    GVAR(ecmEnabled)
    && {[backpack _player, GVAR(ecmBackpackClasses)] call FUNC(matchesClassArray)}
}] call ace_interact_menu_fnc_createAction;
["CAManBase", 1, ["ACE_SelfActions"], _action, true] call ace_interact_menu_fnc_addActionToClass;

private _inventoryEHIDs = player getVariable [QGVAR(ecmInventoryEHIDs), []];
if (_inventoryEHIDs isNotEqualTo []) then {
    player removeEventHandler ["InventoryOpened", _inventoryEHIDs#0];
    player removeEventHandler ["InventoryClosed", _inventoryEHIDs#1];
};

private _ehOpened = player addEventHandler ["InventoryOpened", {
    // Force ACE condition refresh after loadout changes.
    false
}];

private _ehClosed = player addEventHandler ["InventoryClosed", {
    // Force ACE condition refresh after loadout changes.
}];

player setVariable [QGVAR(ecmInventoryEHIDs), [_ehOpened, _ehClosed]];
