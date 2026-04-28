#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Variant C: stamina/fatigue spike. Bumps player fatigue, which drives
        Arma's built-in weapon sway and breathing animations. Recovers
        naturally over time as the unit's stamina regenerates.

    Parameters:
        0: Severity <SCALAR> (0..1)

    Return value:
        None

    Example:
        [1] call uksf_immersion_fnc_debugCloseMiss_fatigue
*/
params [["_severity", 1, [0]]];

private _add = _severity * 0.4;
private _newFatigue = ((getFatigue ACE_player) + _add) min 1;

ACE_player setFatigue _newFatigue;

systemChat format ["[immersion debug C] setFatigue add=%1 new=%2", _add, _newFatigue];
