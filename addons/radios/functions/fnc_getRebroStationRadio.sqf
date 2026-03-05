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

private _vehicleRacks = [_vehicle] call acre_api_fnc_getVehicleRacks;
if (isNil "_vehicleRacks" || {_vehicleRacks isEqualTo []}) exitWith {["", ""]};

private _racks = _vehicleRacks select {
    private _radioData = acre_sys_data_radioData getVariable [_x, nil];
    if (isNil "_radioData") then {false} else {
        // No public API for rack short name — internal hash lookup required
        private _rackName = [_x, "getState", "shortName", _radioData] call acre_sys_rack_fnc_getState;
        _rackName == RACK_NAME_REBRO
    };
};

if (_racks isEqualTo []) exitWith {["", ""]};

private _rackId = _racks#0;
private _radioId = [_rackId] call acre_api_fnc_getMountedRackRadio;
if (isNil "_radioId") exitWith {[_rackId, ""]};

[_rackId, _radioId]
