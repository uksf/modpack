#include "script_component.hpp"
/*
    Author:
        Denis Usenko, Pennyworth, Tim Beswick

    Description:
        Dumps a config tree to a file via the uksf extension.
        Output is written to <arma_root>/uksf_config_export/.
        Filename: config_<gameVersion>_uksf-<modpackVersion>.cpp
        Passing configFile dumps the whole config (no synthetic wrapper class).
        ONLY WORKS ON SERVER CLIENT IN MULTIPLAYER

    Parameters:
        0: Config entry <CONFIG>
        1: Include inherited properties <BOOLEAN> (Optional, default false)

    Return Value:
        Output file path on success, empty string on failure <STRING>

    Example:
        [configFile >> "CfgVehicles" >> "UK3CB_BAF_Box_WpsSpecial"] call uksf_common_fnc_configExport;
        [configFile, true] call uksf_common_fnc_configExport;
*/
#define FLUSH_THRESHOLD 16384

params [["_root", configNull, [configNull]], ["_includeInherited", false, [false]]];

if (isNull _root) exitWith {
    private _message = "configExport: invalid config";
    diag_log text _message;
    hint _message;
    ""
};

private _gameVersion = productVersion#2;
private _modpackVersion = getText (configFile >> "CfgPatches" >> "uksf_main" >> "version");
private _modpackVersionSafe = [_modpackVersion, ".", "-"] call CBA_fnc_replace;
private _filename = format ["config_%1_uksf-%2.cpp", _gameVersion, _modpackVersionSafe];

private _openResult = ("uksf" callExtension ["configExportOpen", [_filename]]) select 0;
if (_openResult find "error:" == 0) exitWith {
    private _message = format ["configExport: open failed - %1", _openResult];
    diag_log text _message;
    hint _message;
    ""
};

private _outputPath = _openResult;
private _buffer = "";
private _lineCount = 0;

private _flush = {
    if (_buffer isEqualTo "") exitWith {};
    private _result = ("uksf" callExtension ["configExportWrite", [_buffer]]) select 0;
    if (_result find "error:" == 0) then {
        diag_log text format ["configExport: write failed - %1", _result];
    };
    _buffer = "";
};

private _indent = toString [9];
private _newLine = toString [10];
private _appendLine = {
    params ["_depth", "_text"];
    private _prefix = "";
    for "_i" from 1 to _depth do { _prefix = _prefix + _indent };
    _buffer = _buffer + _prefix + _text + _newLine;
    _lineCount = _lineCount + 1;
    if (count _buffer >= FLUSH_THRESHOLD) then { call _flush };
};

private _escapeString = {
    private _source = toArray _this;
    if !(34 in _source) exitWith { str _this };
    private _result = [];
    {
        _result pushBack _x;
        if (_x == 34) then { _result pushBack 34 };
    } forEach _source;
    str toString _result
};

private _collectInheritedProperties = {
    private _config = _this;
    private _propertyList = [];
    private _seenLowerCase = [];
    while {
        for "_i" from 0 to count _config - 1 do {
            private _property = _config select _i;
            private _nameLowerCase = toLower configName _property;
            if !(_nameLowerCase in _seenLowerCase) then {
                _propertyList pushBack _property;
                _seenLowerCase pushBack _nameLowerCase;
            };
        };
        configName _config != ""
    } do {
        _config = inheritsFrom _config;
    };
    _propertyList
};

private _formatArray = {
    if (_this isEqualType []) exitWith {
        private _items = [];
        { _items pushBack (_x call _formatArray) } forEach _this;
        "{" + (_items joinString ", ") + "}"
    };
    if (_this isEqualType "") exitWith { _this call _escapeString };
    str _this
};

private _depth = 0;
private _traverse = {
    private _name = configName _this;

    if (isText _this) exitWith {
        [_depth, format ["%1 = %2;", _name, getText _this call _escapeString]] call _appendLine;
    };
    if (isNumber _this) exitWith {
        [_depth, format ["%1 = %2;", _name, getNumber _this]] call _appendLine;
    };
    if (isArray _this) exitWith {
        [_depth, format ["%1[] = %2;", _name, getArray _this call _formatArray]] call _appendLine;
    };
    if (isClass _this) exitWith {
        private _isRoot = _name == "";
        if (!_isRoot) then {
            private _parent = configName inheritsFrom _this;
            private _header = if (_includeInherited || _parent == "") then {
                "class " + _name + " {"
            } else {
                "class " + _name + ": " + _parent + " {"
            };
            [_depth, _header] call _appendLine;
            _depth = _depth + 1;
        };

        private _children = if (_includeInherited) then {
            _this call _collectInheritedProperties
        } else {
            private _list = [];
            for "_i" from 0 to count _this - 1 do { _list pushBack (_this select _i) };
            _list
        };
        { _x call _traverse } forEach _children;

        if (!_isRoot) then {
            _depth = _depth - 1;
            [_depth, "};"] call _appendLine;
        };
    };
};

private _startTime = diag_tickTime;
_root call _traverse;
call _flush;

private _closeResult = ("uksf" callExtension ["configExportClose", []]) select 0;
private _closeFailed = _closeResult find "error:" == 0;
private _elapsed = diag_tickTime - _startTime;

private _summary = if (_closeFailed) then {
    format ["configExport: close failed after %1 lines in %2s - %3", _lineCount, _elapsed toFixed 2, _closeResult]
} else {
    format ["configExport: %1 lines in %2s -> %3", _lineCount, _elapsed toFixed 2, _outputPath]
};
diag_log text _summary;
hint _summary;

if (_closeFailed) then { "" } else { _outputPath }
