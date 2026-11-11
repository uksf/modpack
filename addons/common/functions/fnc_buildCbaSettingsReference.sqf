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

    private _obj = [
        format ['{"setting":%1',       toJSON (_name)],
        format [',"displayName":%1',   toJSON (_disp)],
        format [',"category":%1',      toJSON (_cat)],
        format [',"subCategory":%1',   toJSON (_sub)],
        format [',"tooltip":%1',       toJSON (_tip)],
        format [',"settingType":%1',   toJSON (_settingType)],
        format [',"valueInfo":%1',     toJSON (_valueInfo)],
        format [',"defaultValue":%1',  toJSON (_defaultValue)],
        format [',"isGlobal":%1',      toJSON (_isGlobal call _isGlobalString)],
        format [',"isForced":%1',      if (_isForced) then {"true"} else {"false"}],
        format [',"priority":%1}',     toJSON (_priority)]
    ] joinString "";
    [[_cat, _sub, _name], _obj]
};

_items sort true;

private _settingsJson = (_items apply { _x select 1 }) joinString ",";

systemTimeUTC params ["_year", "_month", "_day", "_hour", "_minute", "_second"];
private _timestamp = format ["%1-%2-%3T%4:%5:%6Z",
    _year,
    [_month,  2] call CBA_fnc_formatNumber,
    [_day,    2] call CBA_fnc_formatNumber,
    [_hour,   2] call CBA_fnc_formatNumber,
    [_minute, 2] call CBA_fnc_formatNumber,
    [_second, 2] call CBA_fnc_formatNumber
];

format [
    '{"modpackVersion":%1,"gameVersion":%2,"exportedAt":%3,"settings":[%4]}',
    toJSON getText (configFile >> "CfgPatches" >> "uksf_main" >> "versionStr"),
    toJSON str (productVersion#2),
    toJSON _timestamp,
    _settingsJson
]
