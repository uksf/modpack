#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Shows the newest cTab messages in the Messages app, oldest first, and marks the shown received messages as read.
        Runs when the app opens and on each cTab messagesUpdated event.

    Parameter(s):
        None

    Return Value:
        Nothing

    Example:
        call uksf_ctab_fnc_messagesRefresh
*/
if (isNull APP_CTRL(messagesHistory)) exitWith {};

private _variable = format ["cTab_messages_%1", call cTab_fnc_getPlayerEncryptionKey];
private _messages = cTab_player getVariable [_variable, []];
private _first = 0 max (count _messages - MESSAGES_SHOWN);

private _lines = [];
for "_i" from _first to (count _messages - 1) do {
    (_messages select _i) params ["_title", "_body", "_state"];
    private _colour = ["#99CCFF", "#FFFFFF"] select (_state != 2);
    private _prefix = ["", "To "] select (_state == 2);
    _lines pushBack format ["<t color='%1' size='0.8'>%2%3</t>", _colour, _prefix, [_title] call FUNC(escapeText)];
    _lines pushBack (([[_body] call FUNC(escapeText), endl, "<br/>"] call CBA_fnc_replace));
    if (_state == 0) then {
        (_messages select _i) set [2, 1];
    };
};
cTab_player setVariable [_variable, _messages];

if (_lines isEqualTo []) then {
    _lines = ["No messages."];
};
[APP_CTRL(messagesHistory), _lines] call FUNC(setInfo);
