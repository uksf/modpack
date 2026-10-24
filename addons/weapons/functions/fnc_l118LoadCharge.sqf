#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Loads the nearest L118 charge behind the loaded shell at the chosen charge.
        The gun gets the magazine for that shell and charge.

    Parameters:
        0: Gun <OBJECT>
        1: Player <OBJECT>
        2: Charge, 1 to 7 <NUMBER>

    Return value:
        Nothing

    Example:
        [_gun, player, 5] call uksf_weapons_fnc_l118LoadCharge
*/
params ["_gun", "_player", "_charge"];

private _round = _gun getVariable [QGVAR(l118Shell), ""];
private _piece = nearestObjects [_player, [QGVAR(105mm_charge)], 3] param [0, objNull];
if (_round isEqualTo "" || {isNull _piece}) exitWith {};

private _magazine = format ["tbd_mortars_105mm_round_%1_charge_mag_%2", _round, _charge];
["tbd_m119_m119_loadShell", [_gun, _magazine, 0], _gun, [0]] call CBA_fnc_turretEvent;
_gun setVariable [QGVAR(l118Shell), nil, true];
deleteVehicle _piece;

_gun animateSource ["magazine_laser_load_source", 0, true];
_gun animateSource ["magazine_laser_hide_source", 0, true];
_gun animateSource ["magazine_laser_load_source", 0.36, 0.2];
