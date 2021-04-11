#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Creates the picket groups
        _picketLocations is the modules, not their positions

    Parameters:
        0: _picketLocations <ARRAY>

    Return value:
        Nothing
*/


if (!isServer) exitWith {};

params ["_picketLocations"];

{
    private _sideFromModule = _x getVariable [QGVAR(side), 0];
    if (_sideFromModule == 0) then {
        _x setVariable [QGVAR(side), EAST];
    } else {
        _x setVariable [QGVAR(side), INDEPENDENT];
    };

    private _side = _x getVariable [QGVAR(side), EAST];
    private _groupSize = _x getVariable [QGVAR(picketGroupSize), 0];
    private _picketUnitsRaw = _x getVariable [QGVAR(picketUnitPoolString), []];
    private _picketUnitsParsed = parseSimpleArray _picketUnitsRaw;
    private _behaviour = _x getVariable [QGVAR(behaviour), 0];

    [getPos _x, 0, _groupSize, _side, _picketUnitsParsed, [], {-1}, {call FUNC(picketBehaviour)}, [_behaviour]] call EFUNC(common,spawnGroup);
} forEach _picketLocations;
