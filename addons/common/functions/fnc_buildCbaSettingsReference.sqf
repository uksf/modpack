#include "script_component.hpp"
/*
    Author: UKSF
    Description:
        Builds a JSON catalogue of every CBA setting registered in the running game.
        Single pass per setting: format JSON object, pair with sort key, sort, join.
        Sort: category → subCategory → settingName.

    Return Value:
        JSON string <STRING>

    Example:
        private _json = call uksf_common_fnc_buildCbaSettingsReference;
*/

private _localiseIfToken = { if (isLocalized _this) then { localize _this } else { _this } };

private _isGlobalString = {
    switch (_this) do {
        case 0: { "perClient" };
        case 1: { "globalForceable" };
        case 2: { "localLocked" };
        default { "unknown" };
    }
};

private _valueInfoForType = {
    params ["_type", "_data"];
    switch (_type) do {
        case "EDITBOX": {
            _data params [["_isPassword", false], ["_sanitizeFn", ""]];
            createHashMapFromArray [["isPassword", _isPassword], ["sanitizeFn", _sanitizeFn]]
        };
        case "LIST": {
            _data params [["_values", []], ["_labels", []], ["_tooltips", []]];
            createHashMapFromArray [["values", _values], ["labels", _labels], ["tooltips", _tooltips]]
        };
        case "SLIDER": {
            _data params [["_min", 0], ["_max", 1], ["_trailingDecimals", 0], ["_isPercentage", false]];
            createHashMapFromArray [["min", _min], ["max", _max], ["trailingDecimals", _trailingDecimals], ["isPercentage", _isPercentage]]
        };
        case "TIME": {
            _data params [["_min", 0], ["_max", 86400]];
            createHashMapFromArray [["min", _min], ["max", _max]]
        };
        default { createHashMap };
    }
};

private _items = cba_settings_allSettings apply {
    private _name = _x;
    (cba_settings_default getVariable _name) params [
        "_defaultValue", "_settingName", "_settingType", "_settingData",
        "_category", "_displayName", "_tooltip", "_isGlobal", "_script", "_subCategory"
    ];

    private _cat  = _category    call _localiseIfToken;
    private _sub  = _subCategory call _localiseIfToken;
    private _disp = _displayName call _localiseIfToken;
    private _tip  = _tooltip     call _localiseIfToken;

    private _priority = [_name] call cba_settings_fnc_priority;
    private _isForced = _priority isNotEqualTo "client";

    private _valueInfo = [_settingType, _settingData] call _valueInfoForType;

    private _obj = createHashMapFromArray [
        ["setting", _name],
        ["displayName", _disp],
        ["category", _cat],
        ["subCategory", _sub],
        ["tooltip", _tip],
        ["settingType", _settingType],
        ["valueInfo", _valueInfo],
        ["defaultValue", _defaultValue],
        ["isGlobal", _isGlobal call _isGlobalString],
        ["isForced", _isForced],
        ["priority", _priority]
    ];
    [[_cat, _sub, _name], _obj]
};

_items sort true;

systemTimeUTC params ["_year", "_month", "_day", "_hour", "_minute", "_second"];
private _timestamp = format ["%1-%2-%3T%4:%5:%6Z",
    _year,
    [_month,  2] call CBA_fnc_formatNumber,
    [_day,    2] call CBA_fnc_formatNumber,
    [_hour,   2] call CBA_fnc_formatNumber,
    [_minute, 2] call CBA_fnc_formatNumber,
    [_second, 2] call CBA_fnc_formatNumber
];

toJSON createHashMapFromArray [
    ["modpackVersion", getText (configFile >> "CfgPatches" >> "uksf_main" >> "versionStr")],
    ["gameVersion", str (productVersion#2)],
    ["exportedAt", _timestamp],
    ["settings", _items apply {_x select 1}]
]
