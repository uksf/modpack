#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Initialises data for dynamic patrol area

    Parameters:
        0: The module logic <OBJECT>
        1: Area array <ARRAY>

    Return value:
        Data array
*/

params ["_logic", "_area"];

if !(isServer) exitWith {
    INFO("3) Area data init failed server check");
};

private _values = [];

{
    private _property = _x;
    private _propertyConfig = GVAR(dynamicPatrolAreaAttributeConfig) >> _property;
    private _default = [_propertyConfig] call EFUNC(common,getConfigEntry);
    private _value = _logic getVariable [_property, _default];
    TRACE_3("3) Area data init resolved variable",_property,_value,_default);

    private _min = [_propertyConfig >> "min"] call EFUNC(common,getConfigEntry);
    if (!(_min isEqualType "") || {_min != ""}) then {
        _value = _value max _min;
    };
    TRACE_4("3) Area data init resolved variable after min",_property,_value,_default,_min);

    private _max = [_propertyConfig >> "max"] call EFUNC(common,getConfigEntry);
    if (!(_max isEqualType "") || {_max != ""}) then {
        _value = _value min _max;
    };
    TRACE_5("3) Area data init resolved variable after max",_property,_value,_default,_min,_max);

    private _compileString = [_propertyConfig >> "compileString"] call EFUNC(common,getConfigEntry);
    if (!(_compileString isEqualType "") || {_compileString != "" && {_compileString == 1}}) then {
        _value = [_value] call EFUNC(common,convertToArray);
    };

    TRACE_6("3) Area data init resolved variable final",_property,_value,_default,_min,_max,_compileString);

    _values pushBack _value;
} forEach [
    QGVAR(cooldown),
    QGVAR(distance),
    QGVAR(groupLimit),
    QGVAR(minUnits),
    QGVAR(maxUnits),
    QGVAR(minGroups),
    QGVAR(maxGroups),
    QGVAR(vehicleProbability),
    QGVAR(vehicleDistanceCoef),
    QGVAR(waypointDistance),
    QGVAR(vehicleWaypointDistance),
    QGVAR(unitPoolString),
    QGVAR(vehiclePoolString),
    QGVAR(combatMode),
    QGVAR(patrolSpeed),
    QGVAR(side),
    QGVAR(startDelay),
    QGVAR(condition)
];

TRACE_3("3) Area data init resolved variables",_logic,_area,_values);

// Set pools to global if no value given for zone
if ((_values#DYNAMIC_PATROL_INDEX_UNIT_POOL) isEqualTo []) then {
    _values set [DYNAMIC_PATROL_INDEX_UNIT_POOL, GVAR(dynamicPatrolUnitPool)];
};
TRACE_1("3) Area data init resolved unit pool",_values#DYNAMIC_PATROL_INDEX_UNIT_POOL);

if ((_values#DYNAMIC_PATROL_INDEX_VEHICLE_POOL) isEqualTo []) then {
    _values set [DYNAMIC_PATROL_INDEX_VEHICLE_POOL, GVAR(dynamicPatrolVehiclePool)];
};
TRACE_1("3) Area data init resolved vehicle pool",_values#DYNAMIC_PATROL_INDEX_VEHICLE_POOL);

// Resolve values from DYNAMIC_PATROL_INDEX for combatMode, patrolSpeed, and side
_values set [DYNAMIC_PATROL_INDEX_COMBAT_MODE, ['SAFE', 'AWARE', 'COMBAT']#(_values#DYNAMIC_PATROL_INDEX_COMBAT_MODE)];
_values set [DYNAMIC_PATROL_INDEX_PATROL_SPEED, ['LIMITED', 'NORMAL', 'FULL']#(_values#DYNAMIC_PATROL_INDEX_PATROL_SPEED)];
_values set [DYNAMIC_PATROL_INDEX_SIDE, [EAST, INDEPENDENT, WEST]#(_values#DYNAMIC_PATROL_INDEX_SIDE)];
TRACE_3("3) Area data init resolved combat mode, patro speed, side",_values#DYNAMIC_PATROL_INDEX_COMBAT_MODE,_values#DYNAMIC_PATROL_INDEX_PATROL_SPEED,_values#DYNAMIC_PATROL_INDEX_SIDE);

// Test condition and store as code in values
private _condition = compile (_values#DYNAMIC_PATROL_INDEX_CONDITION);
private _result = [_values, _logic, _area, []] call _condition;
if !(_result isEqualType false) then {
    ERROR("Invalid condition for dynamic patrol area module");
    _condition = {true};
};
_values set [DYNAMIC_PATROL_INDEX_CONDITION, _condition];
TRACE_1("3) Area data init resolved condition",_values#DYNAMIC_PATROL_INDEX_CONDITION);

[_values, _logic, _area]
