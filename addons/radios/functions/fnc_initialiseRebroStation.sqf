#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Initialises the racks and radio for a rebroadcasting station

    Parameter(s):
        0: Station vehicle <OBJECT>

    Return Value:
        None
*/
if (!isServer) exitWith {
    [QGVAR(initialiseRebroStation), _this] call CBA_fnc_serverEvent;
};

params ["_vehicle"];

private _rebroData = [_vehicle] call FUNC(getRebroStationRadio);
_rebroData params ["_rackId", "_rebroId"];

if (_rebroId != "") exitWith {
    WARNING_2("Rebro station is already initialised - Rack ID: %1, Radio ID: %2",_rackId,_rebroId);
};

[_vehicle, ["ACRE_VRC103", "ReBro Rack", RACK_NAME_REBRO, false, [], [], "ACRE_PRC117F", [], []], !([_vehicle] call acre_api_fnc_areVehicleRacksInitialized), {true}] call acre_api_fnc_addRackToVehicle;

_vehicle addEventHandler ["Killed", {[QGVAR(deinitialiseRebroStation), _this] call CBA_fnc_serverEvent}];

[{
    params ["_vehicle"];

    _vehicle getVariable ["acre_sys_rack_initialized", false]
    && {
        private _rebroData = [_vehicle] call FUNC(getRebroStationRadio);
        _rebroData params ["_rackId", "_rebroId"];

        _rebroId != ""
    }
}, {
    params ["_vehicle"];

    private _rebroData = [_vehicle] call FUNC(getRebroStationRadio);
    _rebroData params ["_rackId", "_rebroId"];

    if (_rebroId == "") exitWith {
        WARNING_1("Failed to initialise rebro station %1",_this);
    };

    if (_vehicle isKindOf QGVAR(rebroStationMast)) then {
        [_rebroId, 0, "ACRE_643CM_VHF_TNC", call acre_main_fnc_fastHashCreate, true] call acre_sys_components_fnc_attachSimpleComponent;

        _vehicle setVariable ["acre_sys_gsa_connectedRadio", _rebroId, true];
        [_rebroId, "setState", ["externalAntennaConnected", [true, _vehicle]]] call acre_sys_data_fnc_dataEvent;
    };

    GVAR(rebroStations) pushBack _vehicle;
    publicVariable QGVAR(rebroStations);
    REBRO_TRACE_3("Rebro initialised",_vehicle,_rackId,_rebroId);
}, [_vehicle], 15, {
    WARNING_1("Failed to initialise rebro station after timeout %1",_this);
}] call CBA_fnc_waitUntilAndExecute;
