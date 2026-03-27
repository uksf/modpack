#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Server-side ECM scan loop. Finds active ECM sources and jams nearby enemy drones.

    Parameters:
        None

    Return value:
        None
*/

if (!isServer) exitWith {};
if (GVAR(ecmDroneClasses) isEqualTo []) exitWith {};

{
    private _unit = _x;
    if (alive _unit && {_unit getVariable [QGVAR(ecmActive), false]}) then {
        [_unit] call FUNC(ecmUpdateBattery);

        if (_unit getVariable [QGVAR(ecmActive), false]) then {
            private _sourceData = [_unit] call FUNC(getECMSource);
            _sourceData params ["_mode", "_range", "_sourceObject"];

            if !(_mode isEqualTo "" || {isNull _sourceObject} || {_range <= 0}) then {
                private _sourceSide = [_sourceObject, true] call BIS_fnc_objectSide;
                private _drones = (_sourceObject nearEntities [["Air", "LandVehicle"], _range]) select {
                    [_x, GVAR(ecmDroneClasses)] call FUNC(matchesClassArray)
                };

                {
                    private _drone = _x;
                    if (
                        alive _drone
                        && {!(_drone getVariable [QGVAR(ecmJammed), false])}
                    ) then {
                        private _droneSide = [_drone, true] call BIS_fnc_objectSide;
                        if (_droneSide isNotEqualTo _sourceSide) then {
                            _drone setVariable [QGVAR(ecmJammed), true, true];
                            [QGVAR(applyDroneJamLocal), [_drone], _drone] call CBA_fnc_targetEvent;
                        };
                    };
                } forEach _drones;
            };
        };
    };
} forEach allPlayers;

{
    private _vehicle = _x;
    if (
        alive _vehicle
        && {_vehicle getVariable [QGVAR(ecmVehicleActive), false]}
    ) then {
        private _sourceSide = _vehicle getVariable [QGVAR(ecmVehicleSourceSide), sideUnknown];
        if (_sourceSide isEqualTo sideUnknown) then {
            _sourceSide = [_vehicle, true] call BIS_fnc_objectSide;
        };

        private _drones = (_vehicle nearEntities [["Air", "LandVehicle"], GVAR(ecmVehicleRange)]) select {
            [_x, GVAR(ecmDroneClasses)] call FUNC(matchesClassArray)
        };
        {
            private _drone = _x;
            if (
                alive _drone
                && {!(_drone getVariable [QGVAR(ecmJammed), false])}
            ) then {
                private _droneSide = [_drone, true] call BIS_fnc_objectSide;
                if (_droneSide isNotEqualTo _sourceSide) then {
                    _drone setVariable [QGVAR(ecmJammed), true, true];
                    [QGVAR(applyDroneJamLocal), [_drone], _drone] call CBA_fnc_targetEvent;
                };
            };
        } forEach _drones;
    };
} forEach vehicles;
