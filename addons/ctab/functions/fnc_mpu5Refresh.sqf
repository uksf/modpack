#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Updates the controls of the shown MPU-5 app page and the status of the selected radio.

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
private _selectValue = {
    params ["_combo", "_value"];
    private _index = 0 max ((_combo getVariable [QGVAR(values), []]) find _value);
    if (isNull _combo || {lbCurSel _combo == _index}) exitWith {};
    _combo lbSetCurSel _index;
};
private _lines = [];
GVAR(mpu5Refreshing) = true;

switch (GVAR(mpu5Page)) do {
    case "slots": {
        private _slots = [_radioId] call acre_sys_mpu5_fnc_getTxSlots;
        {
            [_x, _slots select (_x getVariable QGVAR(slot))] call _selectValue;
        } forEach (uiNamespace getVariable [QGVAR(mpu5Slots), []]);
        ([_radioId, GVAR(mpu5AudioTalkgroup)] call acre_sys_mpu5_fnc_getMonitorAudio) params ["_volume", "_ear"];
        [APP_CTRL(mpu5Volume), _volume] call _selectValue;
        [APP_CTRL(mpu5Ear), _ear] call _selectValue;

        _lines pushBack "Hold the CBA key ACRE2 > MPU-5 TX slot N to transmit on that slot's talk group.";
        _lines pushBack "Talk groups in a TX slot are also heard.";
        _lines pushBack format ["TG %1 audio applies while it is monitored and is not the active talk group.", GVAR(mpu5AudioTalkgroup)];
        private _monitorAudio = [];
        {
            ([_radioId, _x] call acre_sys_mpu5_fnc_getMonitorAudio) params ["_volume", "_ear"];
            _monitorAudio pushBack format ["TG %1 %2%3 %4", _x, round (_volume * 100), "%", ["radio ear", "left", "both", "right"] select ((_ear + 2) min 3 max 0)];
        } forEach _monitors;
        _lines pushBack format ["Monitored: %1", ["none", _monitorAudio joinString ", "] select (_monitorAudio isNotEqualTo [])];
    };
    case "gateway": {
        ([_radioId] call acre_sys_mpu5_fnc_getGateway) params [["_gatewayRadio", ""], ["_gatewayTalkgroup", 0]];
        private _bridgeRadio = [_radioId] call acre_sys_mpu5_fnc_getBridge;
        [APP_CTRL(mpu5GatewayRadio), _gatewayRadio] call _selectValue;
        if (_gatewayRadio != "") then {
            [APP_CTRL(mpu5GatewayTalkgroup), _gatewayTalkgroup] call _selectValue;
        };
        [APP_CTRL(mpu5BridgeRadio), _bridgeRadio] call _selectValue;

        _lines pushBack (if (_gatewayRadio == "") then {"Gateway: off"} else {
            format ["Gateway: %1 channel %2 linked to TG %3 both ways", [_gatewayRadio] call acre_api_fnc_getBaseRadio, [_gatewayRadio] call acre_api_fnc_getRadioChannel, _gatewayTalkgroup]
        });
        _lines pushBack (if (_bridgeRadio == "") then {"Bridge: off"} else {
            format ["Bridge: %1 channel %2 copied to the BRIDGE channel", [_bridgeRadio] call acre_api_fnc_getBaseRadio, [_bridgeRadio] call acre_api_fnc_getRadioChannel]
        });
        _lines pushBack format ["Current channel: %1", [_radioId] call acre_sys_mpu5_fnc_getChannelDescription];
        _lines pushBack "Gateway and bridge radios must be powered, carried, and in a single-channel mode.";
    };
    default {
        APP_CTRL(mpu5Talkgroup) lbSetCurSel (_talkgroup - 1);
        {
            private _monitored = (_x getVariable QGVAR(talkgroup)) in _monitors;
            _x ctrlSetText format [["%1", "[%1]"] select _monitored, _x getVariable QGVAR(talkgroup)];
        } forEach (uiNamespace getVariable [QGVAR(mpu5Monitors), []]);

        _lines pushBack format ["Talk group: %1", [_talkgroup, "BRIDGE"] select (_talkgroup > MPU5_TALKGROUPS)];
        _lines pushBack format ["Monitoring: %1", ["none", _monitors joinString ", "] select (_monitors isNotEqualTo [])];
        _lines pushBack "Emergency TG 16 is always heard.";
    };
};

GVAR(mpu5Refreshing) = false;

APP_CTRL(mpu5Power) ctrlSetText (["Power: off", "Power: on"] select _on);
if (_on) then {
    ([_radioId] call acre_sys_mpu5_fnc_getMeshStatus) params ["_links", "_reachable"];
    _lines pushBack format ["Mesh: %1 direct links, %2 reachable nodes", _links, _reachable];
} else {
    _lines pushBack "Mesh: radio off";
};

[APP_CTRL(mpu5Info), _lines] call FUNC(setInfo);
