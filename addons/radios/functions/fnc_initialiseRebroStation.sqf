#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Initialises the racks and radio for a rebroadcasting station

    Parameter(s):
        0: Station mast <OBJECT>

    Return Value:
        None
*/
if (!isServer) exitWith {
    [QGVAR(initialiseRebroStation), _this] call CBA_fnc_serverEvent;
};

params ["_mast"];

[_mast, ["ACRE_VRC103", "ReBro Rack", RACK_NAME_REBRO, false, [], [], "ACRE_PRC117F", [], []], true, {true}] call acre_api_fnc_addRackToVehicle;

[{
    (_this#0) getVariable ["acre_sys_rack_initialized", false]
}, {
    params ["_mast"];

    private _radioId = [_mast] call FUNC(getRebroStationRadio);
    if (_radioId == "") exitWith {
        WARNING_1("Failed to initialise rebro station",_this);
    };

    [_radioId, 0, "ACRE_643CM_VHF_TNC", call acre_main_fnc_fastHashCreate, true] call acre_sys_components_fnc_attachSimpleComponent;

    _mast setVariable ["acre_sys_gsa_connectedRadio", _radioId, true];
    [_radioId, "setState", ["externalAntennaConnected", [true, _mast]]] call acre_sys_data_fnc_dataEvent;

    [QGVAR(addRebroStation), _mast] call CBA_fnc_globalEvent;
}, [_mast], 30, {
    WARNING_1("Failed to initialise rebro station",_this);
}] call CBA_fnc_waitUntilAndExecute;
