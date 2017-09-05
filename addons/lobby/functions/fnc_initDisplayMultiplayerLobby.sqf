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

    private _unitNames = configFile >> "CfgUnitNames";
    private _playerList = _display displayCtrl IDC_MPSETUP_ROLES;
    for "-" from 1 to lbSize _playerList do {
        private _text = _playerList lbText 0;
        private _value = _playerList lbValue 0;
        private _unitName = false;
        _playerList lbDelete 0;
        if (isArray (_unitNames >> _text) || {isArray (_unitNames >> (_playerList lbText 0))}) then {
            _unitName = true;
        };
        if (_value == -1) then {
            if (_unitName) then {
                _text = (getArray (_unitNames >> (_playerList lbText 0))) select 0;
            } else {
                private _callsign = (_playerList lbText 0) splitString SEPARATORS param [1, ""];

                if (_callsign != "") then {
                    _text = _callsign;
                };
            };
        } else {
            if (_unitName) then {
                _text = (getArray (_unitNames >> _text)) select 1;
            } else {
                _text = _text splitString SEPARATORS select 0;
            };
        };
        _playerList lbSetValue [_playerList lbAdd _text, _value];
    };
};

_display setVariable [QFUNC(update), _fnc_update];
_display call _fnc_update;
_display displayAddEventHandler ["MouseMoving", _fnc_update];
_display displayAddEventHandler ["MouseHolding", _fnc_update];
