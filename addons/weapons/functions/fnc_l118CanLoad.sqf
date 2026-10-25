#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Checks if an L118 piece can be loaded. The breech must be open and hold no round.
        A shell loads into an empty breech, and a charge loads behind a shell.

    Parameters:
        0: Gun <OBJECT>
        1: Player <OBJECT>
        2: Piece class, shell or charge <STRING>

    Return value:
        Can load <BOOL>

    Example:
        [_gun, player, "uksf_weapons_105mm_charge"] call uksf_weapons_fnc_l118CanLoad
*/
params ["_gun", "_player", "_class"];

private _shellLoaded = _gun getVariable [QGVAR(l118Shell), ""] isNotEqualTo "";

_gun getVariable ["tbd_m119_m119_breech", false]
&& {_gun magazinesTurret [0] isEqualTo []}
&& {_shellLoaded isEqualTo (_class isEqualTo QGVAR(105mm_charge))}
&& {nearestObjects [_player, [_class], 3] findIf {typeOf _x isEqualTo _class} != -1}
