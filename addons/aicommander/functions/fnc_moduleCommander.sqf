#include "script_component.hpp"
/*
    Author:
        Codex

    Description:
        Initialize commander module runtime state.

    Parameters:
        1: Arguments array with module object at index 0 <ARRAY>

    Return Value:
        None
*/

if (!isServer) exitWith {};

(_this select 1) params ["_module"];
if (isNull _module) exitWith {};
if (_module getVariable [QGVAR(initialized), false]) exitWith {};

private _fnc_toNumber = {
    params ["_value", "_default"];
    if (_value isEqualType 0) exitWith {_value};
    if (_value isEqualType "") exitWith {parseNumber _value};
    _default
};

_module setVariable [QGVAR(initialized), true];
_module setVariable [QGVAR(isCommander), true];

private _sideNumber = _module getVariable [QGVAR(sideNumber), 0];
private _managedGroupCap = [_module getVariable [QGVAR(managedGroupCap), 9], 9] call _fnc_toNumber;
private _maxConcurrentActions = 3;
private _maxWaveSize = [_module getVariable [QGVAR(maxWave), 3], 3] call _fnc_toNumber;
private _loopInterval = [_module getVariable [QGVAR(loopInterval), 60], 60] call _fnc_toNumber;
private _contactConfirmDelay = [_module getVariable [QGVAR(contactConfirmDelaySec), 2], 2] call _fnc_toNumber;
private _followupContactCooldown = [_module getVariable [QGVAR(followupContactCooldownSec), 30], 30] call _fnc_toNumber;
private _sitrepInterval = [_module getVariable [QGVAR(sitrepIntervalSec), 180], 180] call _fnc_toNumber;
private _intelStaleTtl = [_module getVariable [QGVAR(intelStaleTtlSec), 600], 600] call _fnc_toNumber;
private _ineffectiveThreshold = [_module getVariable [QGVAR(ineffectiveCasualtyThreshold), 0.5], 0.5] call _fnc_toNumber;

_module setVariable [QGVAR(side), [_sideNumber] call FUNC(getSideFromIndex)];
_module setVariable [QGVAR(lastAssessmentByObjective), createHashMap];
_module setVariable [QGVAR(debugAssessments), []];
_module setVariable [QGVAR(maxConcurrentActions), _maxConcurrentActions];
_module setVariable [QGVAR(maxWave), (_maxWaveSize max 1) min 3];
_module setVariable [QGVAR(managedGroupsCap), (_managedGroupCap max 1)];
_module setVariable [QGVAR(loopInterval), (_loopInterval max 5)];
_module setVariable [QGVAR(managedGroups), []];
_module setVariable [QGVAR(spawnQueue), []];
_module setVariable [QGVAR(actionRequests), []];
_module setVariable [QGVAR(groupCatalog), []];
_module setVariable [QGVAR(nextSpawnAt), 0];
_module setVariable [QGVAR(contactConfirmDelaySec), (_contactConfirmDelay max 2)];
_module setVariable [QGVAR(followupContactCooldownSec), (_followupContactCooldown max 5)];
_module setVariable [QGVAR(sitrepIntervalSec), (_sitrepInterval max 30)];
_module setVariable [QGVAR(intelStaleTtlSec), (_intelStaleTtl max 60)];
_module setVariable [QGVAR(ineffectiveCasualtyThreshold), (_ineffectiveThreshold max 0.1) min 1];
_module setVariable [QGVAR(contactSessions), createHashMap];
_module setVariable [QGVAR(intelGrid), createHashMap];

private _commanderIndex = count GVAR(commanders);
private _phaseOffset = (_commanderIndex * 0.37) mod 2;
_module setVariable [QGVAR(spawnPhaseOffset), _phaseOffset];

if ((GVAR(commanders) find _module) == -1) then {
    GVAR(commanders) pushBack _module;
};

[
    {
        params ["_commander"];

        if (isNull _commander) exitWith {};

        [_commander] call FUNC(buildGroupCatalog);
        [_commander] call FUNC(refreshManagedGroups);

        [_commander] call FUNC(assessCommander);

        private _assessPFH = [{
            params ["_args", "_idPFH"];
            _args params ["_commanderPFH"];

            if (isNull _commanderPFH) exitWith {
                [_idPFH] call CBA_fnc_removePerFrameHandler;
            };

            [_commanderPFH] call FUNC(assessCommander);
        }, (_commander getVariable [QGVAR(loopInterval), 60]) max 5, [_commander]] call CBA_fnc_addPerFrameHandler;

        _commander setVariable [QGVAR(assessPFH), _assessPFH];

        _commander setVariable [
            QGVAR(nextSpawnAt),
            (if (!isNil "CBA_missionTime") then {CBA_missionTime} else {time}) + (_commander getVariable [QGVAR(spawnPhaseOffset), 0])
        ];

        private _dispatchPFH = [{
            params ["_args", "_idPFH"];
            _args params ["_commanderPFH"];

            if (isNull _commanderPFH) exitWith {
                [_idPFH] call CBA_fnc_removePerFrameHandler;
            };

            [_commanderPFH] call FUNC(dispatchSpawnQueue);
        }, 0.5, [_commander]] call CBA_fnc_addPerFrameHandler;

        _commander setVariable [QGVAR(dispatchPFH), _dispatchPFH];

        private _intelPFH = [{
            params ["_args", "_idPFH"];
            _args params ["_commanderPFH"];

            if (isNull _commanderPFH) exitWith {
                [_idPFH] call CBA_fnc_removePerFrameHandler;
            };

            [_commanderPFH] call FUNC(decayIntelGrid);
        }, 30, [_commander]] call CBA_fnc_addPerFrameHandler;

        _commander setVariable [QGVAR(intelPFH), _intelPFH];
    },
    [_module],
    10
] call CBA_fnc_waitAndExecute;

GVAR(enabled) = true;
