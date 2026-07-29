#include "..\script_component.hpp"

params ["_value"];

if (isNil "uksf_dev_runId") exitWith {
    diag_log text "uksf_dev_postResult: no runId set";
    false
};

private _payload = str _value;
diag_log text format ["uksf_dev_postResult [%1]: %2", uksf_dev_runId, _payload];

private _openResult = ("uksf" callExtension ["devRunOpen", [uksf_dev_runId]]) select 0;
if (_openResult find "error:" == 0) exitWith {
    diag_log text format ["uksf_dev_postResult: open failed - %1", _openResult];
    false
};

private _len = count _payload;
private _offset = 0;
private _chunkSize = 1048576;
while {_offset < _len} do {
    private _take = (_len - _offset) min _chunkSize;
    private _chunkPart = _payload select [_offset, _take];
    private _writeResult = ("uksf" callExtension ["devRunChunk", [uksf_dev_runId, _chunkPart]]) select 0;
    if (_writeResult find "error:" == 0) exitWith {
        diag_log text format ["uksf_dev_postResult: chunk failed - %1", _writeResult];
    };
    _offset = _offset + _take;
};

("uksf" callExtension ["devRunFinish", [uksf_dev_runId]]) select 0;
uksf_dev_resultPosted = true;
true
