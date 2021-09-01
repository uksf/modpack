#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Initialises data for rating area

    Parameters:
        0: The module logic <OBJECT>
        1: Area array <ARRAY>

    Return value:
        Data array
*/
params ["_persistenceId", "_logic", "_area"];

if !(isServer) exitWith {};

private _values = createHashMap;

{
    private _property = _x;
    private _propertyConfig = GVAR(ratingAreaAttributeConfig) >> _property;
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
    TRACE_5("Area data init resolved variable after max",_property,_value,_default,_min,_max);

    private _compileString = [_propertyConfig >> "compileString"] call EFUNC(common,getConfigEntry);
    if (!(_compileString isEqualType "") || {_compileString != "" && {_compileString == 1}}) then {
        if (_value isEqualType "") then {
            if (_value != "") then {
                _value = call compile _value;
            } else {
                _value = [];
            };
        };
    };

    TRACE_6("Area data init resolved variable final",_property,_value,_default,_min,_max,_compileString);

    _values set [_property, _value];
} forEach [
    QGVAR(ratingStart),
    QGVAR(ratingMin),
    QGVAR(ratingMax),
    QGVAR(ied_planter),
    QGVAR(ied_destroyed),
    QGVAR(caches_destroyed),
    QGVAR(safehouse_destroyed),
    QGVAR(civ_hit),
    QGVAR(civ_killed)
];

private _ratingStart = _values get QGVAR(ratingStart);
private _ratingMin = _values get QGVAR(ratingMin);
private _ratingMax = _values get QGVAR(ratingMax);

if (_ratingStart < _ratingMin) then {
    _ratingStart = _ratingMin;
};

if (_ratingStart > _ratingMax) then {
    _ratingStart = _ratingMax;
};

_values set [QGVAR(ratingStart), _ratingStart];
_values set [QGVAR(ratingCurrent), _ratingStart];

[_persistenceId, _logic, _area, _values]
