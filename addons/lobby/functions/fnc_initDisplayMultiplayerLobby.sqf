/*
    Author:
        Tim Beswick

    Description:
        Parses lobby slots

    Parameter(s):
        0: Display <DISPLAY>

    Return Value:
        Nothing
*/
#include "script_component.hpp"
#include "\u\uksf\addons\lobby\players.hpp"

#define SEPARATORS "@"

params ["_display"];

private _fnc_update = {
    params [["_display", findDisplay IDD_MP_SETUP, [displayNull]]];

    if (isNil QGVAR(update_EHID)) then {
        GVAR(update_EHID) = addMissionEventHandler ["EachFrame", _display getVariable QFUNC(update)];
    };

    if (isNull _display) exitWith {
        removeMissionEventHandler ["EachFrame", GVAR(update_EHID)];
    };

    private _playerList = _display displayCtrl IDC_MPSETUP_ROLES;
    for "-" from 1 to lbSize _playerList do {
        private _text = _playerList lbText 0;
        private _value = _playerList lbValue 0;
        _playerList lbDelete 0;
        if (_value == -1) then {
            private _callsign = (_playerList lbText 0) splitString SEPARATORS param [1, ""];

            if (_callsign != "") then {
                _text = _callsign;
            };
        } else {
            _text = _text splitString SEPARATORS select 0;
        };
        _playerList lbSetValue [_playerList lbAdd _text, _value];
    };
};

testplayers = [["Test Group", ["Test Unit 1", "Test Unit 2"]], ["Group", ["Unit 1", "Unit 2"]]];
private _fnc_updateTEST = {
    params [["_display", findDisplay IDD_MP_SETUP, [displayNull]]];

    if (isNil QGVAR(update_EHID)) then {
        GVAR(update_EHID) = addMissionEventHandler ["EachFrame", _display getVariable QFUNC(update)];
    };

    if (isNull _display) exitWith {
        removeMissionEventHandler ["EachFrame", GVAR(update_EHID)];
    };

    private _playerList = _display displayCtrl IDC_MPSETUP_ROLES;
    _playerList lbDelete 0;
    _playerList lbDelete 0;
    _playerList lbDelete 0;
    _playerList lbDelete 0;
    _playerList lbDelete 0;
    _playerList lbDelete 0;
    _playerList lbSetValue [_playerList lbAdd ((testplayers select 0) select 0), -1];
    _playerList lbSetValue [_playerList lbAdd (((testplayers select 0) select 1) select 0), 0];
    _playerList lbSetValue [_playerList lbAdd (((testplayers select 0) select 1) select 1), 1];
    _playerList lbSetValue [_playerList lbAdd ((testplayers select 1) select 0), -1];
    _playerList lbSetValue [_playerList lbAdd (((testplayers select 1) select 1) select 0), 0];
    _playerList lbSetValue [_playerList lbAdd (((testplayers select 1) select 1) select 1), 1];
};

_display setVariable [QFUNC(update), _fnc_updateTEST];
_display call _fnc_updateTEST;

_display displayAddEventHandler ["MouseMoving", _fnc_updateTEST];
_display displayAddEventHandler ["MouseHolding", _fnc_updateTEST];
