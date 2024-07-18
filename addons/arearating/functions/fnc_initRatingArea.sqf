#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Initialises data for rating area

    Parameters:
        0: Area id <STRING>
        1: Area display name <STRING>
        2: Area logic <OBJECT>
        3: Area shape <ARRAY>

    Return value:
        Data array
*/
params ["_id", "_displayName", "_logic", "_area"];

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
        _value = [_value] call EFUNC(common,convertToArray);
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

_ratingStart = (_ratingStart max _ratingMin) min _ratingMax;

_values set [QGVAR(ratingStart), _ratingStart];
_values set [QGVAR(ratingCurrent), _ratingStart];

[_id, _displayName, _logic, _area, _values]
