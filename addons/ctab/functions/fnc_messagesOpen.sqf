#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Builds the Messages app, a chat screen over cTab's own messages.
        The history shows the newest messages, sent and received. Sending uses cTab's message system, so the messages also appear in the cTab message screen.

    Parameter(s):
        0: cTab display <DISPLAY>
        1: App content group <CONTROL>

    Return Value:
        Nothing

    Example:
        [_display, _group] call uksf_ctab_fnc_messagesOpen
*/
params ["", "_group"];

[_group, "cTab_RscText", [0.02, 0.03, 0.58, 0.08], "Messages"] call FUNC(createCtrl);
uiNamespace setVariable [QGVAR(messagesHistory), [_group, [0.02, 0.12, 0.58, 0.72]] call FUNC(createInfo)];
uiNamespace setVariable [QGVAR(messagesText), [_group, "cTab_RscEdit", [0.02, 0.86, 0.44, 0.1]] call FUNC(createCtrl)];
[_group, [0.48, 0.86, 0.12, 0.1], "Send", {call FUNC(messagesSend)}] call FUNC(createButton);

[_group, "cTab_RscText", [0.63, 0.03, 0.35, 0.08], "Send to"] call FUNC(createCtrl);
private _recipients = [_group, QGVAR(listBoxMulti), [0.63, 0.12, 0.35, 0.84]] call FUNC(createCtrl);
[_recipients] call ctab_messaging_fnc_fillRecipientList;
uiNamespace setVariable [QGVAR(messagesRecipients), _recipients];

call FUNC(messagesRefresh);
