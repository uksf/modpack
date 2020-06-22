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
        Nothing
*/
params ["_logic", "_area"];

if !(isServer) exitWith {};

private _values = [];

{
    private _property = _x;
    private _propertyConfig = GVAR(dynamicPatrolAreaAttributeConfig) >> _property;
    private _default = [_propertyConfig] call EFUNC(common,getConfigEntry);
    private _value = _logic getVariable [_property, _default];

    private _min = [_propertyConfig >> "min"] call EFUNC(common,getConfigEntry);
    if (!(_min isEqualType "") || {_min != ""}) then {
        _value = _value max _min;
    };

    private _max = [_propertyConfig >> "max"] call EFUNC(common,getConfigEntry);
    if (!(_max isEqualType "") || {_max != ""}) then {
        _value = _value min _max;
    };

    private _compileString = [_propertyConfig >> "compileString"] call EFUNC(common,getConfigEntry);
    if (!(_compileString isEqualType "") || {_compileString != "" && {_compileString == 1}}) then {
        if (_value != "") then {
            _value = call compile _value;
        };

        if ((_value isEqualType "" && {_value == ""})) then {
            _value = [];
        };
    };

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
    QGVAR(side)
];

// Set pools to global if no value given for zone
if ((_values#11) isEqualTo []) then {
    _values set [11, GVAR(dynamicPatrolUnitPool)];
};
if ((_values#12) isEqualTo []) then {
    _values set [12, GVAR(dynamicPatrolVehiclePool)];
};

// Resolve values from index for combatMode, patrolSpeed, and side
_values set [13, ['SAFE', 'AWARE', 'COMBAT']#(_values#13)];
_values set [14, ['LIMITED', 'NORMAL', 'FULL']#(_values#14)];
_values set [15, [EAST, INDEPENDENT, WEST]#(_values#15)];


[_values, _logic, _area]
