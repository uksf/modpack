#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Builds the MPU-5 gateway and bridge page.
        The gateway links a carried single-channel radio to one talk group in both directions over radio over IP.
        The bridge copies a carried single-channel radio's channel into the MPU-5 as its BRIDGE channel.

    Parameter(s):
        0: App content group <CONTROL>

    Return Value:
        Nothing

    Example:
        [_group] call uksf_ctab_fnc_mpu5PageGateway
*/

params ["_group"];

private _legacy = call FUNC(mpu5LegacyRadios);
([GVAR(mpu5Radio)] call acre_sys_mpu5_fnc_getGateway) params [["_gatewayRadio", ""], ["_gatewayTalkgroup", 1]];

private _talkgroups = [];
for "_talkgroup" from 1 to MPU5_TALKGROUPS do {
    _talkgroups pushBack [format ["TG %1", _talkgroup], _talkgroup];
};

private _applyGateway = {
    if (GVAR(mpu5Refreshing)) exitWith {};
    private _value = {
        params ["_combo"];
        (_combo getVariable QGVAR(values)) select (0 max lbCurSel _combo)
    };
    [GVAR(mpu5Radio), [APP_CTRL(mpu5GatewayRadio)] call _value, [APP_CTRL(mpu5GatewayTalkgroup)] call _value] call acre_sys_mpu5_fnc_setGateway;
    call FUNC(mpu5Refresh);
};
[_group, "cTab_RscText", [0.03, 0.12, 0.25, 0.07], "Gateway"] call FUNC(createCtrl);
uiNamespace setVariable [QGVAR(mpu5GatewayRadio), [_group, [0.25, 0.12, 0.5, 0.07], _legacy, _gatewayRadio, _applyGateway] call FUNC(createCombo)];
uiNamespace setVariable [QGVAR(mpu5GatewayTalkgroup), [_group, [0.77, 0.12, 0.2, 0.07], _talkgroups, _gatewayTalkgroup, _applyGateway] call FUNC(createCombo)];

[_group, "cTab_RscText", [0.03, 0.21, 0.25, 0.07], "Bridge"] call FUNC(createCtrl);
uiNamespace setVariable [QGVAR(mpu5BridgeRadio), [_group, [0.25, 0.21, 0.5, 0.07], _legacy, [GVAR(mpu5Radio)] call acre_sys_mpu5_fnc_getBridge, {
    params ["_radioId"];
    if (GVAR(mpu5Refreshing)) exitWith {};
    [GVAR(mpu5Radio), _radioId] call acre_sys_mpu5_fnc_setBridge;
    call FUNC(mpu5Refresh);
}] call FUNC(createCombo)];
[_group, [0.77, 0.21, 0.2, 0.07], "Refresh", {call FUNC(mpu5Refresh)}] call FUNC(createButton);

uiNamespace setVariable [QGVAR(mpu5Info), [_group, [0.03, 0.31, 0.94, 0.66]] call FUNC(createInfo)];
