#include "script_component.hpp"
#include "\a3\ui_f\hpp\defineResincl.inc"
/*
    Author:
        Tim Beswick

    Description:
        Selects the BLUFOR side (assumed default), then finds the player's
        slot in the lobby and assigns it automatically. Each frame until
        the slot is assigned, sends a Space keypress via the Rust extension
        (gated on Arma being the foreground window to avoid leaking input
        to other apps if the user has alt-tabbed).

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
        GVAR(sideSelected) = nil;
    };

    if (isNil QGVAR(sideSelected)) then {
        private _westButton = _display displayCtrl IDC_MPSETUP_WEST;
        if (!isNull _westButton && {ctrlEnabled _westButton}) then {
            ctrlActivate _westButton;
            GVAR(sideSelected) = true;
            TRACE_1("activated BLUFOR side button",_westButton);
        };
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

    if (_result isEqualTo "ok") then {
        TRACE_1("Space sent successfully, removing EH",GVAR(updateEHID));
        removeMissionEventHandler ["EachFrame", GVAR(updateEHID)];
        GVAR(updateEHID) = nil;
    };
};

_display setVariable [QFUNC(update), _fnc_update];
_display call _fnc_update;
