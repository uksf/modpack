#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Sends the text in the Messages app to the selected recipients as a cTab message, then clears the text.

    Parameter(s):
        None

    Return Value:
        Nothing

    Example:
        call uksf_ctab_fnc_messagesSend
*/
private _text = ctrlText APP_CTRL(messagesText);
private _recipients = [APP_CTRL(messagesRecipients)] call ctab_messaging_fnc_getSelectedRecipients;
if (_text == "" || {_recipients isEqualTo []}) exitWith {
    ["MSG", "Write a message and select at least one recipient.", 3] call cTab_fnc_addNotification;
};

[_text, _recipients] call ctab_core_fnc_sendMessage;
APP_CTRL(messagesText) ctrlSetText "";
