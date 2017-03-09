/*
    Author:
        esteldunedain from ACE https://github.com/acemod/ACE3, edited by Tim Beswick

    Description:
        Load a setting from config if it was not previosuly forced. Force if neccesary.

    Parameter(s):
        None

    Return Value:
        Nothing
*/
#include "script_component.hpp"

params ["_optionEntry"];

private _fnc_getValueWithType = {
    params ["_optionEntry", "_typeName"];

    private _valueConfig = (_optionEntry >> "value");
    private _value = if (isNumber (_optionEntry >> "value")) then {getNumber (_optionEntry >> "value")} else {0};
    TRACE_3("_fnc_getValueWithType:", configName _optionEntry, _typeName, _value);
    if (_typeName isEqualTo "BOOL") exitWith {
        _value > 0
    };
    if (_typeName isEqualTo "STRING") exitWith {
        getText (_optionEntry >> "value")
    };
    if (_typeName isEqualTo "ARRAY") exitWith {
        getArray (_optionEntry >> "value")
    };
    if (_typeName isEqualTo "COLOR") exitWith {
        getArray (_optionEntry >> "value")
    };
    _value
};

private _name = configName _optionEntry;

if (isNil _name) then {
    private _typeName = getText (_optionEntry >> "typeName");
    if (_typeName isEqualTo "") then {
        _typeName = "SCALAR";
    };
    private _value = [_optionEntry, _typeName] call _fnc_getValueWithType;
    missionNamespace setVariable [_name, _value];
    private _settingData = [_name, _typeName, (getNumber (_optionEntry >> "isClientSettable")) > 0, getText (_optionEntry >> "displayName"), getText (_optionEntry >> "description"), [], getNumber (_optionEntry >> "force") > 0, _value, getText (_optionEntry >> "category")];
    GVAR(settings) pushBack _settingData;
} else {
    private _settingData = [_name] call FUNC(getSettingData);
    if (_settingData select 6) exitWith {};
    private _value = [_optionEntry, _settingData select 1] call _fnc_getValueWithType;
    missionNamespace setVariable [_name, _value];
    if (getNumber (_optionEntry >> "force") > 0) then {
        _settingData set [6, true];
    };
};
