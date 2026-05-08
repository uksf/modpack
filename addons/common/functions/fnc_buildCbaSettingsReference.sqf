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

// _settingData layout depends on _settingType — flatten into a HashMap so toJson emits an object.
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
        // CHECKBOX, COLOR — empty info.
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

    // priority returns "client" when the user can override; anything else means a higher
    // namespace (mission/server/userconfig/missionConfig) has forced the current value.
    private _priority = [_name] call cba_settings_fnc_priority;
    private _isForced = _priority isNotEqualTo "client";

    private _valueInfo = [_settingType, _settingData] call _valueInfoForType;

    private _obj = [
        format ['{"setting":%1',       [_name]            call uksf_common_fnc_toJson],
        format [',"displayName":%1',   [_disp]            call uksf_common_fnc_toJson],
        format [',"category":%1',      [_cat]             call uksf_common_fnc_toJson],
        format [',"subCategory":%1',   [_sub]             call uksf_common_fnc_toJson],
        format [',"tooltip":%1',       [_tip]             call uksf_common_fnc_toJson],
        format [',"settingType":%1',   [_settingType]     call uksf_common_fnc_toJson],
        format [',"valueInfo":%1',     [_valueInfo]       call uksf_common_fnc_toJson],
        format [',"defaultValue":%1',  [_defaultValue]    call uksf_common_fnc_toJson],
        format [',"isGlobal":%1',      [_isGlobal call _isGlobalString] call uksf_common_fnc_toJson],
        format [',"isForced":%1',      if (_isForced) then {"true"} else {"false"}],
        format [',"priority":%1}',     [_priority]        call uksf_common_fnc_toJson]
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
    '{"modpackVersion":"%1","gameVersion":"%2","exportedAt":"%3","settings":[%4]}',
    getText (configFile >> "CfgPatches" >> "uksf_main" >> "versionStr"),
    productVersion#2,
    _timestamp,
    _settingsJson
]
