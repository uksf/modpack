#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Sets the map position on open to previous position

    Parameter(s):
        0: State <BOOL>

    Return Value:
        Nothing
*/
params ["_state"];

if (_state) then {
    if (!(isNil QGVAR(mapPosition)) && {!(isNil QGVAR(mapZoom))}) then {
        ctrlMapAnimClear ((findDisplay 12) displayCtrl 51);
        ((findDisplay 12) displayCtrl 51) ctrlMapAnimAdd [0, GVAR(mapZoom), GVAR(mapPosition)];
        ctrlMapAnimCommit ((findDisplay 12) displayCtrl 51);
    };
} else {
    GVAR(mapPosition) = ((findDisplay 12) displayCtrl 51) ctrlMapScreenToWorld [0.5, 0.5];
    GVAR(mapZoom) = ctrlMapScale ((findDisplay 12) displayCtrl 51);
    GVAR(mapPosition) set [1, (GVAR(mapPosition) select 1) - (110 * (GVAR(mapZoom) / 0.16))];
};
