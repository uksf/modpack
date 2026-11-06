#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Lists the friendly groups in the Friendly app, nearest first.
        Lists the groups cTab shows as group markers on BFT, from cTab's own list.

    Parameter(s):
        None

    Return Value:
        Nothing

    Example:
        call uksf_ctab_fnc_friendlyRefresh
*/
if (isNull APP_CTRL(friendlyList)) exitWith {};

private _groups = (missionNamespace getVariable ["cTabBFTgroups", []]) apply {group (_x select 0)};
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
