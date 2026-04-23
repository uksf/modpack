#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Load selected objects into a picked cargo holder via ACE cargo.
        Uses ACE zeus destination picker (red line) for target selection.

    Parameter(s):
        0: Action Parameters

    Return Value:
        None

    Example:
        [_selectedObjects, _selectedGroups] call uksf_zeus_fnc_contextLoadIntoCargo
*/
params ["", "_selectedObjects"];

private _cargoItems = _selectedObjects select {alive _x && {!isPlayer _x}};
if (_cargoItems isEqualTo []) exitWith {};

GVAR(loadIntoCargoItems) = _cargoItems;

[
    _cargoItems # 0,
    {
        params ["_successful", "", "_mousePosASL"];

        private _cargoItems = GVAR(loadIntoCargoItems);
        GVAR(loadIntoCargoItems) = nil;

        if (!_successful) exitWith {};
        if (isNil "_cargoItems" || {_cargoItems isEqualTo []}) exitWith {};

        private _holder = (nearestObjects [ASLToAGL _mousePosASL, ace_cargo_cargoHolderTypes, 15, false]) param [0, objNull];
        if (isNull _holder) exitWith {
            ["STR_ACE_Zeus_NothingSelected"] call ace_zeus_fnc_showMessage;
        };
        if (!alive _holder) exitWith {
            ["STR_ACE_Zeus_OnlyAlive"] call ace_zeus_fnc_showMessage;
        };

        private _holderName = [_holder] call ace_common_fnc_getName;
        private _loadedCount = 0;
        private _failedNames = [];

        {
            if ([_x, _holder, true] call ace_cargo_fnc_loadItem) then {
                _loadedCount = _loadedCount + 1;
            } else {
                _failedNames pushBack ([_x] call ace_common_fnc_getName);
            };
        } forEach _cargoItems;

        if (_loadedCount > 0) then {
            ["Loaded %1 object(s) into %2", _loadedCount, _holderName] call ace_zeus_fnc_showMessage;
        };
        if (_failedNames isNotEqualTo []) then {
            ["Failed to load: %1", _failedNames joinString ", "] call ace_zeus_fnc_showMessage;
        };
    },
    "Load Into Cargo",
    "\a3\ui_f\data\IGUI\Cfg\Actions\loadVehicle_ca.paa"
] call ace_zeus_fnc_getModuleDestination;
