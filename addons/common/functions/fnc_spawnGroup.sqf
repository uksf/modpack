#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Spawns group based on mode with given unit and vehicle pools. Creates units over time to avoid performance degradation
        Group is disabled from caching

    Parameters:
        0: Position where group will spawn <ARRAY>
        1: Type of group (0 = infantry, 1 = vehicle) <NUMBER>
        2: Number of units in group (only applies for infantry spawn) <NUMBER>
        3: Side of group <SIDE>
        4: Unit classname pool <ARRAY>
        5: Vehicle classname pool <ARRAY>
        6: Code to resolve vehicle crew count (Args passed: [_vehicle, _turrets]) <CODE> (Optional)
        7: Callback once spawning complete (Args passed: [callback args, _group, (_vehicle)]) <CODE> (Optional)
        8: Callback arguments <ARRAY> (Optional)

    Return value:
        Nothing
*/
UKSF_DEPRECATED(QFUNC(spawnGroup),"5.21.0","uksf_common_fnc_spawnGroupInfantry OR uksf_common_fnc_spawnGroupVehicle");

params [["_position", [], [[]]], ["_type", 0, [0]], ["_count", 1, [0]], ["_side", EAST, [sideUnknown]], ["_unitPool", []], ["_vehiclePool", []], ["_countCode", {-1}, [{}]], ["_callback", {}, [{}]], ["_callbackArgs", [], [[]]]];

if (_type == 0) exitWith {
    [_position, _count, _side, _unitPool, _callback, _callbackArgs] call FUNC(spawnGroupInfantry);
};

[_position, _side, _unitPool, _vehiclePool, _countCode, _callback, _callbackArgs] call FUNC(spawnGroupVehicle);
