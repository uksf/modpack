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

            private _assignRoleControl = _display displayCtrl IDC_MPSETUP_ASSIGNROLE;
            TRACE_3("AssignRole ctrl",_assignRoleControl,ctrlType _assignRoleControl,ctrlEnabled _assignRoleControl);

            [{
                params ["_display", "_assignRoleControl"];

                TRACE_1("attempting ctrlActivate true",_assignRoleControl);
                _assignRoleControl ctrlActivate true;

                [{
                    params ["_display"];
                    private _roles = _display displayCtrl IDC_MPSETUP_ROLES;
                    private _currentSelection = lbCurSel _roles;
                    TRACE_1("post-activate lbCurSel",_currentSelection);
                }, [_display], 0] call CBA_fnc_waitAndExecute;
            }, [_display, _assignRoleControl], 0] call CBA_fnc_waitAndExecute;

            removeMissionEventHandler ["EachFrame", GVAR(updateEHID)];
        };
    };
};

_display setVariable [QFUNC(update), _fnc_update];
_display call _fnc_update;
