#include "script_component.hpp"
/*
    Author:
        Bridg, Tim Beswick

    Description:
        Gets vehicle details

    Parameters:
        0: Vehicles <ARRAY>

    Return value:
        Array of vehicle details <ARRAY>
        [[_type, _position, _direction, _engineState, _fuel, _crew], [...]]
*/
params ["_vehicles"];

_vehicles apply {
    private _vehicle = _x;

    private _type = typeOf _vehicle;
    private _position = getPosASL _vehicle;
    private _direction = getDir _vehicle;
    private _engineState = isEngineOn _vehicle;
    private _fuel = fuel _vehicle;
    private _crew = (fullCrew _vehicle) apply {
        _x params ["_unit", "_role", "_cargoIndex", "_turretPath"];

        [typeOf _unit, _role, _cargoIndex, _turretPath]
    };

    [_type, _position, _direction, _engineState, _fuel, _crew]
}
