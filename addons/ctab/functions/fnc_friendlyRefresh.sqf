#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Lists the friendly groups in the Friendly app, nearest first.
        A group is listed when it is on one of the player's cTab sides and one of its living members carries a cTab tablet or Android, the same rule cTab uses for its group markers.

    Parameter(s):
        None

    Return Value:
        Nothing

    Example:
        call uksf_ctab_fnc_friendlyRefresh
*/
if (isNull APP_CTRL(friendlyList)) exitWith {};

private _sides = call cTab_fnc_getPlayerSides;
private _groups = allGroups select {
    side _x in _sides && {units _x findIf {alive _x && {[_x, ctab_core_leaderDevices] call cTab_fnc_checkGear}} != -1}
};
_groups = [_groups, [], {cTab_player distance2D leader _x}] call BIS_fnc_sortBy;
GVAR(friendlyGroups) = _groups;

lbClear APP_CTRL(friendlyList);
{
    private _index = APP_CTRL(friendlyList) lbAdd format ["%1 (%2)", groupId _x, (cTab_player distance2D leader _x) call FUNC(formatDistance)];
    APP_CTRL(friendlyList) lbSetValue [_index, _forEachIndex];
} forEach _groups;

if (_groups isEqualTo []) exitWith {
    [APP_CTRL(friendlyInfo), ["No friendly groups with a cTab device."]] call FUNC(setInfo);
};
APP_CTRL(friendlyList) lbSetCurSel 0;
