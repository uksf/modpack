/*
    Author:
        Denis Usenko, Tim Beswick

    Description:
        Exports Specified config entry and copies to clipboard.
        ONLY WORKS ON SERVER CLIENT IN MULTIPLAYER

    Parameters:
        0: Config entry <CONFIG>
        1: IncludeInheritedPropertiesFlag <BOOLEAN>

    Return value:
        Exported config <STRING>

    Example:
        [configFile >> "CfgVehicles" >> "UK3CB_BAF_Box_WpsSpecial"] call uksf_common_fnc_configExportExtension;
*/
#include "script_component.hpp"

#define PUSH(a,v) (a) set [count(a),(v)]

private ["_joinString", "_escapeString", "_collectInheritedProperties", "_dumpConfigTree"];

_joinString = {
    params ["_list", "_char", "_size", "_subsize", "_oversize", "_j"];

    if (count _list < 1) exitwith {""};
    for "_a" from 1 to (ceil ((log (count _list)) / 0.3010299956639812)) do {
        _size = count _list / 2;
        _subsize = floor _size;
        _oversize = ceil _size;
        _j = 0;
        for "_i" from 0 to _subsize - 1 do {
            _list set [_i, (_list select _j) + _char + (_list select (_j+1))];
            _j = _j + 2;
        };
        if (_subsize != _oversize) then {
            _list set [_j/2, _list select _j];
        };
        _list resize _oversize;
    };
    _list select 0;
};

_escapeString = {
    private ["_source", "_target", "_start", "_charCode"];
    _source = toArray _this;
    _start = _source find 34;
    if (_start > 0) then {
        _target = +_source;
        _target resize _start;
        for "_i" from _start to count _source - 1 do {
            _charCode = _source select _i;
            PUSH(_target,_charCode);
            if (_charCode == 34) then {
                PUSH(_target,_charCode);
            };
        };
        str toString _target;
    } else {
        str _this;
    };
};

_collectInheritedProperties = {
    private ["_config", "_className", "_propertyNameList", "_propertyNameLCList", "_propertyName", "_propertyNameLC"];
    _config = _this;
    _propertyNameList = [];
    _propertyNameLCList = [];
    while {
        _className = configName _config;
        for "_i" from 0 to count _config - 1 do {
            _propertyName = _config select _i;
            _propertyNameLC = toLower configName _propertyName;
            if !(_propertyNameLC in _propertyNameLCList) then {
                PUSH(_propertyNameList,_propertyName);
                PUSH(_propertyNameLCList,_propertyNameLC);
            };
        };
        _className != "";
    } do {
        _config = inheritsFrom _config;
    };
    _propertyNameList;
};

_dumpConfigTree = {
    params ["_config", ["_includeInheritedProperties", false], "_specifyParentClass", "_result", "_indents", "_depth", "_pushLine", "_traverse", "_traverseArray"];
    _specifyParentClass = !_includeInheritedProperties;

    "mb_fileio" callExtension "open_w|config_dump.cpp";
    _result = [];
    _indents = [""];
    _depth = -1;
    _pushLine = {
        if (_depth < 0) then {
            "mb_fileio" callExtension format ["write|/* %1 %2.%3 */", ProductVersion select 0, ProductVersion select 2, ProductVersion select 3];
        } else {
            if (_depth >= count _indents) then {
                _indents set [_depth, (_indents select _depth-1) + "    "];
            };
            "mb_fileio" callExtension format ["write|%1%2", _indents select _depth, _this];
        };
    };

    _traverse = {
        private "_confName";
        _confName = configName _this;
        if (isText _this) exitwith {
            _confName + " = " + (getText _this call _escapeString) + ";" call _pushLine;
        };
        if (isNumber _this) exitwith {
            _confName + " = " + str getNumber _this + ";" call _pushLine;
        };
        if (isArray _this) exitwith {
            _confName + "[] = " + (getArray _this call _traverseArray) + ";" call _pushLine;
        };
        if (isClass _this) exitwith {
            "class " + _confName + (
                configName inheritsFrom _this call {
                    if (_this == "" || !_specifyParentClass) then { "" } else { " : " + _this }
                }
            ) + " {" call _pushLine;
            if (_includeInheritedProperties) then {
                _this = _this call _collectInheritedProperties;
            };
            _depth = _depth + 1;
            for "_i" from 0 to count _this - 1 do {
                _this select _i call _traverse
            };
            _depth = _depth - 1;
            "};" call _pushLine;
        };
    };

    _traverseArray = {
        if (typeName _this == "array") exitwith {
            private "_array";
            _array = [];
            for "_i" from 0 to count _this - 1 do {
                PUSH(_array,_this select _i call _traverseArray);
            };
            "{" + ([_array, ", "] call _joinString) + "}";
        };
        if (typeName _this == "string") exitwith {
            _this call _escapeString;
        };
        str _this;
    };

    _config call _traverse;

    "mb_fileio" callExtension "close";
};

private ["_res", "_startTime", "_endTime"];
_startTime = diag_tickTime;
_res = _this call _dumpConfigTree;
_endTime = diag_tickTime;
hint format ["Config Export Done. %1", _endTime - _startTime];
_res