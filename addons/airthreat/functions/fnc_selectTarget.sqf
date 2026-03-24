#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Selects a random valid player target for air threat missions.
        Filters out players matching excluded classnames and players
        inside exclusion markers.

    Parameters:
        0: Require airborne <BOOL> - If true, only select players in air vehicles (default: false)

    Return Value:
        Target player <OBJECT> - objNull if no valid target found

    Example:
        [false] call uksf_airthreat_fnc_selectTarget
*/
params [["_requireAirborne", false, [false]]];

private _validTargets = ALL_PLAYERS select {
    private _player = _x;
    alive _player
    && {!(typeOf _player in GVAR(excludedClasses))}
    && {GVAR(exclusionMarkers) findIf {_player inArea _x} isEqualTo -1}
    && {!_requireAirborne || {vehicle _player isKindOf "Air" && {!isNull objectParent _player}}}
};

if (_validTargets isEqualTo []) exitWith { objNull };

selectRandom _validTargets
