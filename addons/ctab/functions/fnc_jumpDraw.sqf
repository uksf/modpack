#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Draws the jump plan on a cTab map: the drop zone, the opening point with its canopy glide range, the release point, and the track between them.

    Parameter(s):
        0: Map control <CONTROL>

    Return Value:
        Nothing

    Example:
        [_map] call uksf_ctab_fnc_jumpDraw
*/
params ["_map"];

if (GVAR(jumpPlan) isEqualTo []) exitWith {};
GVAR(jumpPlan) params ["_release", "_open", "_glide"];

_map drawEllipse [_open, _glide, _glide, 0, COLOUR_JUMP, ""];
_map drawLine [_release, _open, COLOUR_JUMP];
_map drawLine [_open, GVAR(jumpZone), COLOUR_JUMP];
_map drawIcon [ICON_DOT, COLOUR_JUMP, _release, 20, 20, 0, "Release", 2, 0.05, "RobotoCondensedBold", "right"];
_map drawIcon [ICON_DOT, COLOUR_JUMP, _open, 20, 20, 0, "Open", 2, 0.05, "RobotoCondensedBold", "right"];
_map drawIcon [ICON_DZ, COLOUR_JUMP, GVAR(jumpZone), 24, 24, 0, "DZ", 2, 0.05, "RobotoCondensedBold", "right"];
