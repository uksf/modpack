#include "script_component.hpp"
#include "\a3\ui_f\hpp\defineResincl.inc"
/*
    Author:
        Tim Beswick

    Description:
        Attempts to find and select player's slot. Each frame:
        - If the continue button is enabled, assignment is done — stop.
        - Otherwise find the player's role, re-select it, and ask the
          extension to press Space. Extension skips if Arma is not the
          foreground window, so retries succeed once the user tabs back.

    Parameter(s):
        0: Display <DISPLAY>

    Return Value:
        Nothing

    Example:
        [_display] call uksf_menu_fnc_initDisplayMultiplayerSetup
*/
params ["_display"];
TRACE_1("initDisplayMultiplayerSetup called",_display);

private _fnc_update = {
    params [["_display", findDisplay IDD_MP_SETUP, [displayNull]]];

    if (isNil QGVAR(updateEHID)) then {
        GVAR(updateEHID) = addMissionEventHandler ["EachFrame", _display getVariable QFUNC(update)];
        TRACE_1("registered EachFrame EH",GVAR(updateEHID));
    };

    if (isNull _display) exitWith {
        TRACE_1("display null, removing EH",GVAR(updateEHID));
        removeMissionEventHandler ["EachFrame", GVAR(updateEHID)];
        GVAR(updateEHID) = nil;
    };

    private _continueButton = _display displayCtrl IDC_OK;
    if (ctrlEnabled _continueButton) exitWith {
        TRACE_1("slot assigned (continue enabled), removing EH",GVAR(updateEHID));
        removeMissionEventHandler ["EachFrame", GVAR(updateEHID)];
        GVAR(updateEHID) = nil;
    };

    private _roles = _display displayCtrl IDC_MPSETUP_ROLES;
    private _playerName = toLower profileName;
    private _count = lbSize _roles;

    private _foundIndex = -1;
    for "_i" from 0 to (_count - 1) do {
        private _text = toLower (_roles lbText _i);
        if (_playerName in _text) exitWith {
            _foundIndex = _i;
        };
    };

    if (_foundIndex < 0) exitWith {
        TRACE_2("player not found yet",_playerName,_count);
    };

    private _scrollFixIndex = (_foundIndex + 6) min (_count - 1);
    _roles lbSetCurSel _scrollFixIndex;
    _roles lbSetCurSel _foundIndex;
    ctrlSetFocus _roles;

    private _result = "uksf" callExtension "pressSpace";
    TRACE_2("pressSpace attempt",_foundIndex,_result);
};

_display setVariable [QFUNC(update), _fnc_update];
_display call _fnc_update;
