#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Saves persistence data to the API via the extension.
        Encodes the data namespace directly as JSON and sends it in chunks.
        The C# API handles transformation to structured models for MongoDB.

    Parameter(s):
        None

    Return Value:
        None

    Example:
        call uksf_persistence_fnc_saveDataApi
*/

if (!GVAR(dataSaved)) exitWith {};

// Encode namespace directly — CBA_fnc_encodeJSON handles namespaces natively,
// encoding all variables as a JSON object with their SQF values as-is
private _json = [GVAR(dataNamespace)] call CBA_fnc_encodeJSON;
private _jsonLength = count _json;
INFO_1("API persistence save: %1 characters",_jsonLength);

// Chunk and send
// callExtension input limit is ~10KB. The chunk gets JSON-escaped (quotes doubled)
// then wrapped in an envelope by sendEvent, adding ~200 chars overhead.
// Use 4000 to leave room for worst-case escaping expansion.
private _chunkSize = 4000;
private _totalChunks = ceil (_jsonLength / _chunkSize);
if (_totalChunks < 1) then { _totalChunks = 1 };
private _saveId = format ["%1_%2", GVAR(key), call CBA_fnc_createUUID];

for "_i" from 0 to (_totalChunks - 1) do {
    private _start = _i * _chunkSize;
    private _chunk = _json select [_start, _chunkSize];

    ["persistence_save", createHashMapFromArray [
        ["id",    _saveId],
        ["key",   GVAR(key)],
        ["sessionId", EGVAR(api,sessionId)],
        ["index", _i],
        ["total", _totalChunks],
        ["data",  _chunk]
    ]] call EFUNC(api,sendEvent);
};

LOG_1("API persistence save: sent %1 chunks",_totalChunks);
