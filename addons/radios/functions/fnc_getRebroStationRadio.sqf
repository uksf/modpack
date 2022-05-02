#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Gets the radio from the rack for a rebro

    Parameter(s):
        0: Station mast <OBJECT>

    Return Value:
        Radio ID <STRING>
*/
params ["_mast"];


private _racks = ([_mast] call acre_api_fnc_getVehicleRacks) select {
    private _rackName = [_x, "getState", "shortName", (acre_sys_data_radioData getVariable _x)] call acre_sys_rack_fnc_getState;

    _rackName == RACK_NAME_REBRO
};
private _radios = _racks apply {[_x] call acre_api_fnc_getMountedRackRadio};

if (_radios isEqualTo []) exitWith {
    WARNING_1("Rebro station has no racks %1",_mast);
    ""
};

private _radioId = _radios#0;
TRACE_1("",_radioId);

_radioId
