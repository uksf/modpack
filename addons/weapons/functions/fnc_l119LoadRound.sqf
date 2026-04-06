#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Wrapper for L119 submunition round loading (smoke, illumination).
        Reads fuse timer from the nearest round object before calling TBD's load,
        which deletes the round.

    Parameter(s):
        0: L119 vehicle <OBJECT>
        1: Round classname <STRING>
        2: Turret index <NUMBER>

    Return Value:
        Nothing

    Example:
        [_l119, "tbd_mortars_105mm_round_smoke_charge_1", 0] call uksf_weapons_fnc_l119LoadRound
*/
params ["_l119", "_shell", "_turret"];

private _rounds = nearestObjects [ACE_player, [_shell], 3];
{
    if ((typeOf _x) isEqualTo _shell) exitWith {
        private _fuseTime = _x getVariable ["tbd_mortars_105mm_DPICM_FUSE_TIMER", -1];
        if (_fuseTime >= 0) then {
            _l119 setVariable [QGVAR(fuseTime), _fuseTime, true];
        };
    };
} forEach _rounds;

[_l119, _shell, _turret] call tbd_m119_m119_fnc_load;
