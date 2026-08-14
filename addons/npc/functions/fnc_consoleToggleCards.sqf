#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Toggles the passive NPC debug cards for the local authorised player.
*/
params [["_state", !GVAR(consoleCardsEnabled), [false]]];

if !(ADMIN_OR_WHITELISTED) exitWith {};
GVAR(consoleCardsEnabled) = _state;

if (!_state) exitWith {
    if (GVAR(consoleCardsPFH) >= 0) then {[GVAR(consoleCardsPFH)] call CBA_fnc_removePerFrameHandler};
    GVAR(consoleCardsPFH) = -1;
    (QGVAR(consoleCards) call BIS_fnc_rscLayer) cutText ["", "PLAIN"];
};

(QGVAR(consoleCards) call BIS_fnc_rscLayer) cutRsc [QGVAR(consoleCards), "PLAIN", 0, false];
if (GVAR(consoleCardsPFH) >= 0) exitWith {};
GVAR(consoleCardsPFH) = [{
    private _display = uiNamespace getVariable [QGVAR(consoleCards), displayNull];
    if (isNull _display) exitWith {};
    private _position = getPosATL (call CBA_fnc_currentUnit);
    (_display displayCtrl IDC_CONSOLE_CARDS) ctrlSetStructuredText parseText ([_position] call FUNC(consoleCardText));
}, 0.2] call CBA_fnc_addPerFrameHandler;
