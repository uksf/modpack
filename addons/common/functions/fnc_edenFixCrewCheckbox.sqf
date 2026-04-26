#include "script_component.hpp"
/*
    Author:
        Tim

    Description:
        Fixes the "Place vehicles with crew" checkbox not being visible on initial Eden load.
        Vanilla bug: Display3DEN onLoad spawns submode before action states are set,
        so get3DENActionState "SelectObjectMode" returns 0 and the VehiclePanel stays hidden.
        This re-runs the visibility check after a short delay.

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
    _controlPanel ctrlShow (get3DENActionState "SelectObjectMode" > 0 && {get3DENActionState "SelectSubmode5" == 0});

    private _toggle = _display displayCtrl 1063;
    _toggle cbSetChecked (get3DENActionState "TogglePlaceEmptyVehicle" == 0);
}, [_display], 0.1] call CBA_fnc_waitAndExecute;
