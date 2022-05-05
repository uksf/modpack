#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Gets the radio from the rack for a rebro

    Parameter(s):
        0: Station vehicle <OBJECT>

    Return Value:
        [Rack ID, Radio ID] <ARRAY>
*/
params ["_vehicle"];

private _racks = ([_vehicle] call acre_api_fnc_getVehicleRacks) select {
    private _rackName = [_x, "getState", "shortName", (acre_sys_data_radioData getVariable _x)] call acre_sys_rack_fnc_getState;

    _rackName == RACK_NAME_REBRO
};

if (_racks isEqualTo []) exitWith {
    ["", ""]
};

private _rackId = _racks#0;
private _radioId = [_rackId] call acre_api_fnc_getMountedRackRadio;

[_rackId, _radioId]
