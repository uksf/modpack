#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Shows one friendly group in the Friendly app: its grid, distance and bearing from the player, and each member with the vehicle or foot and the state.
        Centres the app map on the group leader.

    Parameter(s):
        0: Group <GROUP>

    Return Value:
        Nothing

    Example:
        [group player] call uksf_ctab_fnc_friendlyShow
*/
params ["_group"];

private _leader = leader _group;
private _lines = [
    format ["<t size='1.2'>%1</t>", [groupId _group] call FUNC(escapeText)],
    format ["Grid: %1", [getPosASL _leader] call ctab_core_fnc_gridPosition],
    format ["From you: %1, bearing %2", (cTab_player distance2D _leader) call FUNC(formatDistance), round (cTab_player getDir _leader)],
    ""
];

{
    private _state = switch (true) do {
        case (!alive _x): {"dead"};
        case (lifeState _x == "INCAPACITATED"): {"down"};
        case (damage _x > 0.1): {"injured"};
        default {"ok"};
    };
    private _transport = ["foot", getText (configOf objectParent _x >> "displayName")] select (!isNull objectParent _x);
    _lines pushBack format ["%1 - %2, %3", [name _x] call FUNC(escapeText), [_transport] call FUNC(escapeText), _state];
} forEach units _group;

[APP_CTRL(friendlyInfo), _lines] call FUNC(setInfo);

private _map = APP_CTRL(friendlyMap);
if (!isNull _map) then {
    _map ctrlMapAnimAdd [0.5, ctrlMapScale _map, getPosASL _leader];
    ctrlMapAnimCommit _map;
};
