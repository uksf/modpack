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
// 1 MB amortises callExtension overhead while keeping each SQF buffer concat O(buffer)
// rather than O(180 MB). At 16 KB the per-flush extension crossings dominated; at 1 MB
// they're ~64x fewer and the buffer copy stays cheap.
#define FLUSH_THRESHOLD 1048576

params [["_root", configNull, [configNull]], ["_includeInherited", false, [false]]];

if (isNull _root) exitWith {
    private _message = "configExport: invalid config";
    diag_log text _message;
    hint _message;
    ""
};

private _gameVersion = productVersion#2;
// "version" is a number (5.23) from VERSION_CONFIG macro — getText returns ""; use "versionStr" for the full "5.23.8" string
private _modpackVersion = getText (configFile >> "CfgPatches" >> "uksf_main" >> "versionStr");
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
// Array buffer + joinString on flush keeps total work O(N). String concat in a tight loop
// (_buffer = _buffer + _line) is O(buffer-size) per append; at MB-scale buffers that
// dominates and tanks throughput. pushBack is amortised O(1), joinString is O(N) once.
private _bufferLines = [];
private _bufferSize = 0;
private _lineCount = 0;

private _flush = {
    if (_bufferLines isEqualTo []) exitWith {};
    private _payload = _bufferLines joinString "";
    private _result = ("uksf" callExtension ["configExportWrite", [_payload]]) select 0;
    if (_result find "error:" == 0) then {
        diag_log text format ["configExport: write failed - %1", _result];
    };
    _bufferLines = [];
    _bufferSize = 0;
};

// Cached indent strings keyed by depth — built lazily, indexed in O(1) per line.
// _currentIndent is updated whenever _depth changes so the per-line hot path doesn't even
// need an `_indents select _depth` lookup.
private _newLine = toString [10];
private _indents = [""];
private _currentIndent = "";
private _appendLine = {
    // Inlined in the hot leaf-write path inside _traverse; this fallback handles class
    // headers/footers and the cold inherited-properties branch.
    _bufferLines pushBack (_currentIndent + _text + _newLine);
    _bufferSize = _bufferSize + count _text;
    _lineCount = _lineCount + 1;
    if (_bufferSize >= FLUSH_THRESHOLD) then { call _flush };
};

private _escapeString = {
    // Fast path: most config text values contain no embedded quotes, so a single string
    // scan beats unconditionally calling toArray. Saves an allocation per text leaf.
    if (_this find """" == -1) exitWith { str _this };
    private _result = [];
    {
        _result pushBack _x;
        if (_x == 34) then { _result pushBack 34 };
    } forEach toArray _this;
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
private _text = "";
private _tab = toString [9];
// _traverse handles ONLY class nodes. Leaf properties (text/number/array) are dispatched
// inline in the iteration loop — eliminates a recursive function call per leaf (and the
// 4-way isXxx dispatch chain on every entry). _appendLine is also inlined in the hot loop.
// Profiling showed 99.6% of runtime was SQF interpreter overhead; the ~3.7M function calls
// from the per-leaf `call _traverse` + `call _appendLine` dominated.
private _traverse = {
    private _name = configName _this;
    private _isRoot = _name == "";
    if (!_isRoot) then {
        private _parent = configName inheritsFrom _this;
        _text = if (_includeInherited || _parent == "") then {
            "class " + _name + " {"
        } else {
            "class " + _name + ": " + _parent + " {"
        };
        call _appendLine;
        _depth = _depth + 1;
        if (_depth >= count _indents) then {
            _indents set [_depth, _currentIndent + _tab];
        };
        _currentIndent = _indents select _depth;
    };

    if (_includeInherited) then {
        // Cold path — kept readable, uses _appendLine function call.
        {
            private _entry = _x;
            if (isClass _entry) then {
                _entry call _traverse;
            } else {
                private _entryName = configName _entry;
                if (isText _entry) then {
                    _text = _entryName + " = " + (getText _entry call _escapeString) + ";";
                    call _appendLine;
                };
                if (isNumber _entry) then {
                    _text = _entryName + " = " + str (getNumber _entry) + ";";
                    call _appendLine;
                };
                if (isArray _entry) then {
                    _text = _entryName + "[] = " + (getArray _entry call _formatArray) + ";";
                    call _appendLine;
                };
            };
        } forEach (_this call _collectInheritedProperties);
    } else {
        // HOT PATH: leaf-write inlined to avoid both `call _traverse` and `call _appendLine`
        // per property. ~3.7M iterations dominate total runtime.
        for "_i" from 0 to count _this - 1 do {
            private _entry = _this select _i;
            if (isClass _entry) then {
                _entry call _traverse;
            } else {
                private _entryName = configName _entry;
                private _line = "";
                // Order matters — most config properties are numbers (caliber, weight,
                // damage, hit values etc), then strings (model paths, display names),
                // then arrays. Front-loading the most common type cuts ~2 isXxx checks
                // per leaf at scale.
                if (isNumber _entry) then {
                    _line = _entryName + " = " + str (getNumber _entry) + ";";
                } else {
                    if (isText _entry) then {
                        _line = _entryName + " = " + (getText _entry call _escapeString) + ";";
                    } else {
                        if (isArray _entry) then {
                            _line = _entryName + "[] = " + (getArray _entry call _formatArray) + ";";
                        };
                    };
                };
                _bufferLines pushBack (_currentIndent + _line + _newLine);
                _bufferSize = _bufferSize + count _line;
                _lineCount = _lineCount + 1;
                if (_bufferSize >= FLUSH_THRESHOLD) then { call _flush };
            };
        };
    };

    if (!_isRoot) then {
        _depth = _depth - 1;
        _currentIndent = _indents select _depth;
        _text = "};";
        call _appendLine;
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
