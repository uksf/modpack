/*
    Author:
        Tim Beswick

    Description:
        Kicks player or all players

    Parameter(s):
        0: Kick all <BOOL>
        1: Player <OBJECT> (Optional)

    Return Value:
        None
*/
#include "script_component.hpp"

params ["_kickAll", ["_player", objnull]];

if (_kickAll) then {
    {
        if (isNull _x) then {
            GVAR(curatorObjects) deleteAt (GVAR(curatorObjects) find _x);
        } else {
            _player = (getAssignedCuratorUnit _x);
            [QGVAR(curatorLogout), [true], _player] call CBA_fnc_targetEvent;
        };
        false
    } count GVAR(curatorObjects);
    [QGVAR(adminHint), ["Kicked all"]] call CBA_fnc_globalEvent;
} else {
    [QGVAR(curatorLogout), [true], _player] call CBA_fnc_targetEvent;
    [QGVAR(adminHint), [format ["%1 kicked", name _player]]] call CBA_fnc_globalEvent;
};
