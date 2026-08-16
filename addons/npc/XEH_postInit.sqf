#include "script_component.hpp"

if (isServer) then {
    if (!isDedicated) exitWith {
        WARNING("NPC speech is dedicated-server only (no API session off-dedi); skipping NPC registration");
    };

    GVAR(registerDeadline) = diag_tickTime + 60;
    [
        { !isNil {EGVAR(api,sessionId)} || {diag_tickTime > GVAR(registerDeadline)} },
        {
            if (isNil {EGVAR(api,sessionId)}) exitWith {
                WARNING("NPC register: API sessionId not set within 60s; NPCs were not registered");
            };
            TRACE_1("sessionId present, calling registerNpcs",EGVAR(api,sessionId));
            call FUNC(registerNpcs);
        }
    ] call CBA_fnc_waitUntilAndExecute;

    addMissionEventHandler ["EntityKilled", {
        params ["_unit"];
        [_unit] call FUNC(handleNpcDeath);
    }];
    [QGVAR(unconscious), { _this call FUNC(handleNpcUnconscious); }] call CBA_fnc_addEventHandler;

    [{ [GVAR(rxBuffers), GVAR(rxBufferTimes), 30, "rx"] call FUNC(sweepBuffers); }, 10, []] call CBA_fnc_addPerFrameHandler;

    [{
        private _now = diag_tickTime;
        {
            _y params ["", "", "_dispatchTime", "_durationMs"];
            if (_now - _dispatchTime > _durationMs / 1000) then { GVAR(activeClips) deleteAt _x };
        } forEach GVAR(activeClips);
        {
            _y params ["", "", ["_touched", 0]];
            if (_now - _touched > GVAR(streamStale)) then {
                GVAR(activeStreams) deleteAt _x;
            };
        } forEach GVAR(activeStreams);
        {
            if (_now - _y > 60) then { GVAR(cancelledTurns) deleteAt _x };
        } forEach GVAR(cancelledTurns);
    }, 10, []] call CBA_fnc_addPerFrameHandler;
};

["ace_unconscious", {
    params ["_unit", "_active"];
    if (!local _unit) exitWith {};
    private _playerCaused = false;
    if (_active) then {
        private _instigator = _unit getVariable ["ace_medical_lastInstigator", objNull];
        _playerCaused = !isNull _instigator && {isPlayer _instigator};
        _unit setVariable [QGVAR(unconByPlayer), _playerCaused, true];
    };
    if (isServer) then {
        [_unit, _active, _playerCaused] call FUNC(handleNpcUnconscious);
    } else {
        [QGVAR(unconscious), [_unit, _active, _playerCaused]] call CBA_fnc_serverEvent;
    };
}] call CBA_fnc_addEventHandler;

if (!hasInterface) exitWith {};

call FUNC(consoleAddActions);
call FUNC(consoleRegisterDebugProvider);

addMissionEventHandler ["ExtensionCallback", {
    params ["_name", "_function", "_data"];
    if (_name isEqualTo "uksf" && {_function isEqualTo "sttTranscript"}) then {
        _data call FUNC(onTranscript);
    };
}];

call FUNC(sttStart);
call FUNC(sttPushNames);
QGVAR(sttNames) addPublicVariableEventHandler { call FUNC(sttPushNames) };
call FUNC(requestFillers);

GVAR(micGateOpen) = true;
[true] call acre_sys_core_fnc_setMicCaptureGate;
["acre_sys_io_connected", {
    if (GVAR(micGateOpen)) then { [true] call acre_sys_core_fnc_setMicCaptureGate; };
}] call CBA_fnc_addEventHandler;
[
    { [] call acre_api_fnc_isVOIPConnected },
    { if (GVAR(micGateOpen)) then { [true] call acre_sys_core_fnc_setMicCaptureGate; }; }
] call CBA_fnc_waitUntilAndExecute;

[FUNC(gateTick), 0.2, []] call CBA_fnc_addPerFrameHandler;
[FUNC(proximityPull), 0.5, []] call CBA_fnc_addPerFrameHandler;
[{ [GVAR(clipRxBuffers), GVAR(clipRxBufferTimes), 30, "clip"] call FUNC(sweepBuffers); }, 10, []] call CBA_fnc_addPerFrameHandler;
addMissionEventHandler ["Draw3D", { call FUNC(drawEmotes); }];
