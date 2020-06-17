#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Stops captive escort animations

    Parameters:
        0: Captive unit <OBJECT>

    Return value:
        Nothing
*/
params ["_unit"];

[GVAR(escortPFHID)] call CBA_fnc_removePerFrameHandler;

private _releaseCaptiveStance = ["ace_amovpercmstpscapwnondnon", "ace_amovpercmstpscapwnondnon"] select ((stance ACE_player) == "ERECT");
["ace_common_switchMove", [_unit, _releaseCaptiveStance]] call CBA_fnc_globalEvent;
["ace_common_playActionNow", [_unit, QGVAR(clearAction)]] call CBA_fnc_globalEvent;
["ace_common_playActionNow", [ACE_player, QGVAR(clearAction)]] call CBA_fnc_globalEvent;

// If moving and release hostage, set hostage position to player position
if ((vectorMagnitude (velocity ACE_player)) > 0) then {
    _unit setPos (ACE_player modelToWorld [-0.2, 0.9, 0]);
};
