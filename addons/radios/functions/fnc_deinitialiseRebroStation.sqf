#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Deinitialises the rack and radio for a rebroadcasting station

    Parameter(s):
        0: Station vehicle <OBJECT>

    Return Value:
        None
*/
if (!isServer) exitWith {
    [QGVAR(deinitialiseRebroStation), _this] call CBA_fnc_serverEvent;
};

params ["_vehicle"];

private _rebroData = [_vehicle] call FUNC(getRebroStationRadio);
_rebroData params ["_rackId", "_rebroId"];

if (_rebroId == "") exitWith {
    WARNING_2("Rebro station is not initialised during deinitialisation - Rack ID: %1, Radio ID: %2",_rackId,_rebroId);
};

[_vehicle, _rackId] call acre_api_fnc_removeRackFromVehicle;
REBRO_TRACE_3("Rebro deinitialised",_vehicle,_rackId,_rebroId);

GVAR(rebroStations) deleteAt (GVAR(rebroStations) find _vehicle);
GVAR(rebroStations) = GVAR(rebroStations) select {alive _x};
publicVariable QGVAR(rebroStations);
