#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Checks if player can swap with unconscious driver

    Parameter(s):
        0: Vehicle <OBJECT>
        1: Player <OBJECT>

    Return Value:
        None
*/
params ["_vehicle", "_player"];

private _driver = driver _vehicle;

!(isNull _driver)
&& {alive _driver}
&& {_player != _driver}
&& {_driver getVariable ["ACE_isUnconscious", false]}
&& {
    private _vehicleType = typeOf _vehicle;

    private _driverCompartment = GVAR(driverCompartmentHash) get _vehicleType;
    if (isNil "_driverCompartment") then {
        private _vehicleConfig = configOf _vehicle;
        _driverCompartment = (_vehicleConfig >> "driverCompartments") call BIS_fnc_getCfgData;
        if !(_driverCompartment isEqualType "") then {
            _driverCompartment = format ["Compartment%1", _driverCompartment];
        };

        GVAR(driverCompartmentHash) insert [[_vehicleType, _driverCompartment]];
    };

    private _fullCrew = fullCrew [_vehicle, "", true];
    (
        _fullCrew select (_fullCrew findIf {_x#0 == _player})
    ) params ["", "_role", "_cargoIndex", "_turretPath"];

    private _compartment = "";
    if (_role == "cargo") then {
        _compartment = GVAR(cargoCompartmentHash) get [_vehicleType, _cargoIndex];
        if (isNil "_compartment") then {
            private _vehicleConfig = configOf _vehicle;
            private _cargoCompartments = getArray (_vehicleConfig >> "cargoCompartments");
            private _cargoCompartmentsLast = count _cargoCompartments - 1;
            _compartment = _cargoCompartments select (_cargoIndex min _cargoCompartmentsLast);

            GVAR(cargoCompartmentHash) insert [[[_vehicleType, _cargoIndex], _compartment]];
        };
    } else {
        _compartment = GVAR(turretCompartmentHash) get [_vehicleType, _turretPath];
        if (isNil "_compartment") then {
            private _vehicleConfig = configOf _vehicle;
            private _turretConfig = [_vehicleConfig, _turretPath] call CBA_fnc_getTurret;
            _compartment = (_turretConfig >> "gunnerCompartments") call BIS_fnc_getCfgData;
            if !(_compartment isEqualType "") then {
                _compartment = format ["Compartment%1", _compartment]
            };

            GVAR(turretCompartmentHash) insert [[[_vehicleType, _turretPath], _compartment]];
        };
    };

    _compartment == _driverCompartment
}
