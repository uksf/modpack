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

    Example:
        [_display] call uksf_menu_fnc_initDisplayMultiplayerSetup
*/
params ["_display"];
TRACE_1("initDisplayMultiplayerSetup called",_display);

private _fnc_update = {
    params [["_display", findDisplay IDD_MP_SETUP, [displayNull]]];
    TRACE_1("_fnc_update tick",_display);

    if (isNil QGVAR(updateEHID)) then {
        GVAR(updateEHID) = addMissionEventHandler ["EachFrame", _display getVariable QFUNC(update)];
        TRACE_1("registered EachFrame EH",GVAR(updateEHID));
    };

    if (isNull _display) exitWith {
        TRACE_1("display null, removing EH",GVAR(updateEHID));
        removeMissionEventHandler ["EachFrame", GVAR(updateEHID)];
    };

    private _roles = _display displayCtrl IDC_MPSETUP_ROLES;
    private _playerName = toLower profileName;
    TRACE_3("searching roles",_playerName,_roles,lbSize _roles);

    private _count = lbSize _roles;
    for "_i" from 0 to _count do {
        private _text = toLower (_roles lbText _i);
        private _value = _roles lbValue _i;
        private _data = _roles lbData _i;

        if (_playerName in _text) exitWith {
            TRACE_3("found player",_playerName,_i,_count);

            private _scrollFixIndex = (_i + 6) min (_count - 1);
            _roles lbSetCurSel _scrollFixIndex;
            _roles lbSetCurSel _i;

            // Move mouse to selected row and click via extension SendInput
            private _listboxPosition = ctrlPosition _roles;
            _listboxPosition params ["_listboxX", "_listboxY", "_listboxW", "_listboxH"];
            private _clickX = _listboxX + (_listboxW * 0.5);
            private _clickY = _listboxY + (_listboxH * 0.5);
            TRACE_4("clicking at listbox centre",_clickX,_clickY,_listboxPosition,_i);

            setMousePosition [_clickX, _clickY];

            uiNamespace setVariable [QGVAR(assignRoleDisplay), _display];
            onEachFrame {
                private _display = uiNamespace getVariable QGVAR(assignRoleDisplay);
                private _result = "uksf" callExtension "click";
                TRACE_1("click result",_result);

                onEachFrame {
                    private _display = uiNamespace getVariable QGVAR(assignRoleDisplay);
                    private _roles = _display displayCtrl 109;
                    TRACE_1("post-click lbCurSel",lbCurSel _roles);
                    onEachFrame {};
                };
            };

            removeMissionEventHandler ["EachFrame", GVAR(updateEHID)];
        };
    };
};

_display setVariable [QFUNC(update), _fnc_update];
_display call _fnc_update;
