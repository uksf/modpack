#include "script_component.hpp"
/*
    Author:
        Denis Usenko, Pennyworth, Tim Beswick

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
        [configFile] call uksf_common_fnc_configExportExtension;
*/
#define arg(x)          (_this select (x))
#define argIf(x)        if(count _this > (x))
#define argIfType(x,t)  if(argIf(x)then{typeName arg(x) == (t)}else{false})
#define argSafe(x)      argIf(x)then{arg(x)}
#define argOr(x,v)      (argSafe(x)else{v})
#define push(a,v)       (a)pushBack(v)

"ConfigDumpFileIO" callExtension format ["open:AllInOne%1.cpp", productVersion#2];

private _escapeString = {
    private _source = toArray _this;
    private _start = _source find 34;
    if(_start != -1) then {
        private _target = +_source;
        _target resize _start;
        for "_i" from _start to count _source - 1 do {
            private _charCode = _source select _i;
            push(_target,_charCode);
            if(_charCode isEqualTo 34) then {
                push(_target,_charCode);
            };
        };
        str toString _target;
    } else {
        str _this;
    };
};

private _collectInheritedProperties = {
    private _config = _this;
    private _propertyNameList = [];
    private _propertyNameLCList = [];
    while {
        private _className = configName _config;
        for "_i" from 0 to count _config - 1 do {
            private _propertyName = _config select _i;
            private _propertyNameLC = toLower configName _propertyName;
            if!(_propertyNameLC in _propertyNameLCList) then {
                push(_propertyNameList,_propertyName);
                push(_propertyNameLCList,_propertyNameLC);
            };
        };
        _className != "";
    } do {
        _config = inheritsFrom _config;
    };
    _propertyNameList;
};

private _dumpConfigTree = {
    private _includeInheritedProperties = argOr(1,false);
    private _specifyParentClass = argOr(2,!_includeInheritedProperties);

    private _result = [];
    private _indents = [""];
    private _depth = 0;

    private _pushLine = {
        if(_depth >= count _indents) then {
            _indents set [_depth, (_indents select _depth-1) + toString[9]];
        };
        _myString = (_indents select _depth) + (_this);
        "ConfigDumpFileIO" callExtension ("write:" +  _myString);
    };

    private _traverse = {
        private _confName = configName _this;
        if( isText _this ) exitWith {
            _confName + " = " + (getText _this call _escapeString) + ";" call _pushLine;
        };
        if( isNumber _this ) exitWith {
            _confName + " = " + str getNumber _this + ";" call _pushLine;
        };
        if( isArray _this ) exitWith {
            _confName + "[] = " + (getArray _this call _traverseArray) + ";" call _pushLine;
        };
        if( isClass _this ) exitWith {
            "class " + _confName + (
                configName inheritsFrom _this call {
                    if( _this isEqualTo "" || !_specifyParentClass ) then { "" } else { ": " + _this }
                }
            ) + "{" call _pushLine;
            if( _includeInheritedProperties ) then {
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

    private _traverseArray = {
        if(_this isEqualType []) exitWith {
            private _array = [];
            for "_i" from 0 to count _this - 1 do {
                push(_array,_this select _i call _traverseArray);
            };
            "{" + (_array joinString ", ") + "}";
        };
        if(_this isEqualType "") exitWith {
            _this call _escapeString;
        };
        str _this;
    };

    arg(0) call _traverse;

    "ConfigDumpFileIO" callExtension "close:yes";
    true
};

private _startTime = diag_tickTime;
private _finished = _this call _dumpConfigTree;
private _endTime = diag_tickTime;
hint format ["Ready\nNow get config from the ConfigDumpFileIO directory\ntime: %1", _endTime - _startTime];
