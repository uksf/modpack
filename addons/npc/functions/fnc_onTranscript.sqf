#include "script_component.hpp"
/*
    Author:
        Beswick.T

    Description:
        Handle one transcript callback from the extension. Parses the
        SQF-notation payload "[uttId, ""text""]", tags it with the local player
        and current time, and raises uksf_npc_transcript for downstream
        consumers (sub-plan #5).

    Parameter(s):
        0: Callback data string <STRING>

    Return Value:
        None

    Example:
        "[7,""hello there""]" call uksf_npc_fnc_onTranscript
*/

private _data = _this;

private _parsed = parseSimpleArray _data;
if (_parsed isEqualTo []) exitWith {
    TRACE_1("stt transcript parse failed",_data);
};

_parsed params [["_uttId", -1, [0]], ["_text", "", [""]]];
if (_text isEqualTo "") exitWith {};

[QGVAR(transcript), [player, _text, _uttId, serverTime]] call CBA_fnc_localEvent;
