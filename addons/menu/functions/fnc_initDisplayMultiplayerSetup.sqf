#include "script_component.hpp"
#include "\a3\ui_f\hpp\defineResincl.inc"
/*
    Author:
        Tim Beswick

    Description:
        Attempts to find and select player name

    Parameter(s):
        0: Display <DISPLAY>

    Return Value:
        Nothing
*/
params ["_display"];

private _fnc_update = {
    params [["_display", findDisplay IDD_MP_SETUP, [displayNull]]];

    if (isNil QGVAR(updateEHID)) then {
        GVAR(updateEHID) = addMissionEventHandler ["EachFrame", _display getVariable QFUNC(update)];
    };

    if (isNull _display) exitWith {
        removeMissionEventHandler ["EachFrame", GVAR(updateEHID)];
    };

    private _roles = _display displayCtrl IDC_MPSETUP_ROLES;
    private _playerName = toLower profileName;

    for "_i" from 0 to lbSize _roles do {
        private _text = toLower (_roles lbText _i);
        private _value = _roles lbValue _i;
        private _data = _roles lbData _i;

        if (_playerName in _text) exitWith {
            _roles lbSetCurSel _i;

            removeMissionEventHandler ["EachFrame", GVAR(updateEHID)];
        };
    };
};

_display setVariable [QFUNC(update), _fnc_update];
_display call _fnc_update;

