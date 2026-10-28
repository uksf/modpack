#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Returns the map control of the cTab Android dialog for the map type the player picked in cTab.

    Parameter(s):
        0: cTab display <DISPLAY>

    Return Value:
        Map control <CONTROL>

    Example:
        [_display] call uksf_ctab_fnc_currentMap
*/
params ["_display"];

private _mapTypes = [ANDROID_DIALOG, "mapTypes"] call cTab_fnc_getSettings;
private _mapType = [ANDROID_DIALOG, "mapType"] call cTab_fnc_getSettings;
_display displayCtrl ([_mapTypes, _mapType] call cTab_fnc_getFromPairs)
