#include "script_component.hpp"

if (!GVAR(enableGestures)) exitWith {};

[QGVAR(addVehicleInteractions), {call FUNC(addVehicleInteractions)}] call CBA_fnc_addEventHandler;
[QGVAR(removeVehicleInteractions), {
    params ["_vehicle"];

    [_vehicle, 0, ["ACE_MainActions", QGVAR(ignoreCommands)]] call ace_interact_menu_fnc_removeActionFromObject;
    [_vehicle, 0, ["ACE_MainActions", QGVAR(followCommands)]] call ace_interact_menu_fnc_removeActionFromObject;
    [_vehicle, 0, ["ACE_MainActions", QGVAR(getOut)]] call ace_interact_menu_fnc_removeActionFromObject;
    [driver _vehicle, 0, ["ACE_MainActions", QGVAR(getIn)]] call ace_interact_menu_fnc_removeActionFromObject;
}] call CBA_fnc_addEventHandler;
[QGVAR(horn), {call FUNC(horn)}] call CBA_fnc_addEventHandler;

[QGVAR(startVehicleStatemachine), {call FUNC(startVehicleStatemachine)}] call CBA_fnc_addEventHandler;
[QGVAR(startUnitStatemachine), {call FUNC(startUnitStatemachine)}] call CBA_fnc_addEventHandler;

if (GVAR(allowDebug)) then {
    [QGVAR(debugBroadcast), {
        GVAR(debugBroadcastPFHId) = [{
            private _data = [];

            if !(isNull GVAR(vehicle_statemachine)) then {
                private _vehicles = GVAR(vehicle_statemachine_vehicles) apply {[_x, [_x, GVAR(vehicle_statemachine)] call CBA_statemachine_fnc_getCurrentState]};
                _data pushBack _vehicles;
            };

            if !(isNull GVAR(unit_statemachine)) then {
                private _units = GVAR(unit_statemachine_units) apply {[_x, [_x, GVAR(unit_statemachine)] call CBA_statemachine_fnc_getCurrentState]};
                _data pushBack _units;
            };

            if !(_data isEqualTo []) then {
                [QGVAR(debugReceive), _data] call CBA_fnc_globalEvent;
            };
        }] call CBA_fnc_addPerFrameHandler;
    }] call CBA_fnc_addEventHandler;

    [QGVAR(debugStopBroadcast), {[GVAR(debugBroadcastPFHId)] call CBA_fnc_removePerFrameHandler;}] call CBA_fnc_addEventHandler;
};

if (hasInterface) then {
    ["ace_common_playActionNow", {call FUNC(handleGesture)}] call CBA_fnc_addEventHandler;

    if (GVAR(allowDebug)) then {
        [QGVAR(debugReceive), {
            params ["_vehicles", "_units"];

            private _deleteVehicles = GVAR(debugVehicles) select {private _vehicle = _x#0; isNull _vehicle || {(_vehicles findIf {(_x#0) == _vehicle}) == -1}};
            {
                _x params ["_vehicle"];
                GVAR(debugVehicles) deleteAt (GVAR(debugVehicles) findIf {(_x#0) == _vehicle});
            } forEach _deleteVehicles;

            private _deleteUnits = GVAR(debugUnits) select {private _unit = _x#0; isNull _unit || {(_units findIf {(_x#0) == _unit}) == -1}};
            {
                _x params ["_unit"];
                GVAR(debugUnits) deleteAt (GVAR(debugUnits) findIf {(_x#0) == _unit});
            } forEach _deleteUnits;

            {
                private _vehicle = _x#0;
                private _index = GVAR(debugVehicles) findIf {(_x#0) ==_vehicle};
                if (_index != -1) then {
                    GVAR(debugVehicles) set [_index, _x];
                } else {
                    GVAR(debugVehicles) pushBack _x;
                };
            } forEach _vehicles;

            {
                private _unit = _x#0;
                private _index = GVAR(debugUnits) findIf {(_x#0) ==_unit};
                if (_index != -1) then {
                    GVAR(debugUnits) set [_index, _x];
                } else {
                    GVAR(debugUnits) pushBack _x;
                };
            } forEach _units;
        }] call CBA_fnc_addEventHandler;
    };
};
