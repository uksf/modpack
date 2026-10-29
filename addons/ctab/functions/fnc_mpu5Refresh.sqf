#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Updates the MPU-5 app controls and the mesh status of the selected radio.

    Parameter(s):
        None

    Return Value:
        Nothing

    Example:
        call uksf_ctab_fnc_mpu5Refresh
*/

if (isNull APP_CTRL(mpu5Info)) exitWith {};

private _radioId = GVAR(mpu5Radio);
private _talkgroup = [_radioId] call acre_api_fnc_getRadioChannel;
private _monitors = [_radioId] call acre_sys_mpu5_fnc_getMonitors;
private _on = ([_radioId, "getOnOffState"] call acre_sys_data_fnc_dataEvent) == 1;

APP_CTRL(mpu5Talkgroup) lbSetCurSel (_talkgroup - 1);
APP_CTRL(mpu5Power) ctrlSetText (["Power: off", "Power: on"] select _on);
{
    private _monitored = (_x getVariable QGVAR(talkgroup)) in _monitors;
    _x ctrlSetText format [["%1", "[%1]"] select _monitored, _x getVariable QGVAR(talkgroup)];
} forEach (uiNamespace getVariable [QGVAR(mpu5Monitors), []]);

private _lines = [
    format ["Talk group: %1", _talkgroup],
    format ["Monitoring: %1", ["none", _monitors joinString ", "] select (_monitors isNotEqualTo [])],
    "Emergency TG 16 is always heard."
];
if (_on) then {
    ([_radioId] call acre_sys_mpu5_fnc_getMeshStatus) params ["_links", "_reachable"];
    _lines pushBack format ["Mesh: %1 direct links, %2 reachable nodes", _links, _reachable];
} else {
    _lines pushBack "Mesh: radio off";
};

[APP_CTRL(mpu5Info), _lines] call FUNC(setInfo);
