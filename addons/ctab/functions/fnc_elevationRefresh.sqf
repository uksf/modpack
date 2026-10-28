#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Updates the Elevation app panel with the observer, the progress, the share of visible ground, and the highest ground.

    Parameter(s):
        None

    Return Value:
        Nothing

    Example:
        call uksf_ctab_fnc_elevationRefresh
*/
if (isNull APP_CTRL(elevationInfo)) exitWith {};

if (GVAR(elevationObserver) isEqualTo []) exitWith {
    [APP_CTRL(elevationInfo), ["Click the map to place the observer."]] call FUNC(setInfo);
};

private _done = count GVAR(elevationCells);
private _visible = {_x select 1} count GVAR(elevationCells);
private _highest = -1e6;
{
    _highest = _highest max (_x select 2);
} forEach GVAR(elevationCells);

private _lines = [
    format ["Observer: %1", [GVAR(elevationObserver)] call ctab_core_fnc_gridPosition],
    format ["Ground: %1 m ASL", round GVAR(elevationGround)]
];
if (_done < GVAR(elevationTotal)) then {
    _lines pushBack format ["Calculating: %1%%", floor (100 * _done / (GVAR(elevationTotal) max 1))];
} else {
    _lines pushBack format ["Visible: %1%% of the area", round (100 * _visible / (_done max 1))];
    _lines pushBack format ["Highest ground: %1 m above observer", round _highest];
};

[APP_CTRL(elevationInfo), _lines] call FUNC(setInfo);
