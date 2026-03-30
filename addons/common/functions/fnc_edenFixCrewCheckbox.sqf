#include "script_component.hpp"
/*
    Author:
        Tim

    Description:
        Fixes the "Place vehicles with crew" checkbox not being visible on initial Eden load.
        Vanilla bug: Display3DENPlace onLoad spawns placesubmode before controls are fully populated,
        causing the VehiclePanel to remain hidden. This re-runs the visibility check after a short delay.

    Parameter(s):
        0: Display <DISPLAY>

    Return Value:
        None

    Example:
        [_display] call uksf_common_fnc_edenFixCrewCheckbox
*/
params ["_display"];

[{
    params ["_display"];
    if (isNull _display) exitWith {};

    private _controlPanel = _display displayCtrl 1062;
    private _modes = _display displayCtrl 53;
    private _submodes = _display displayCtrl 54;

    _controlPanel ctrlShow (lbCurSel _modes == 0 && {lbCurSel _submodes != 4});

    private _toggle = _display displayCtrl 1063;
    _toggle cbSetChecked (get3DENActionState "TogglePlaceEmptyVehicle" == 0);
}, [_display], 0.1] call CBA_fnc_waitAndExecute;
