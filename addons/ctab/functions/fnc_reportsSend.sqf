#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Sends the report in the Reports app to the selected recipients as a cTab message.
        The message lists each filled field. Each filled grid field adds a cTab marker at that grid.

    Parameter(s):
        None

    Return Value:
        Nothing

    Example:
        call uksf_ctab_fnc_reportsSend
*/
GVAR(reportType) params ["_title", "_fields"];

private _recipients = [APP_CTRL(reportRecipients)] call ctab_messaging_fnc_getSelectedRecipients;
if (_recipients isEqualTo []) exitWith {
    [APP_CTRL(reportStatus), ["Select at least one recipient."]] call FUNC(setInfo);
};

private _lines = [_title];
private _attachments = [];
{
    _x params ["_label", "_default"];
    private _value = ctrlText ((APP_CTRL(reportRows) select _forEachIndex) select 1);
    if (_value == "") then {continue};

    _lines pushBack format ["%1: %2", _label, _value];
    if (_default == "grid") then {
        private _parsed = [_value] call ctab_messaging_fnc_parseGridPosition;
        if (count _parsed == 2) then {
            _parsed params ["_position", "_precision"];
            private _centre = [(_position select 0) + (_precision select 0) / 2, (_position select 1) + (_precision select 1) / 2];
            _attachments pushBack [0, _label, _centre];
        };
    };
} forEach _fields;

[[_title, _lines joinString endl, 0, _attachments], _recipients] call ctab_messaging_fnc_sendMessage;
APP_CTRL(reportRecipients) lbSetCurSel -1;
[APP_CTRL(reportStatus), [format ["%1 sent to %2.", _title, count _recipients]]] call FUNC(setInfo);
