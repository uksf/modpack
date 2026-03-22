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

_module setVariable [QGVAR(initialized), true];
_module setVariable [QGVAR(isCommander), true];

private _sideNumber = _module getVariable [QGVAR(sideNumber), 0];

_module setVariable [QGVAR(side), [_sideNumber] call FUNC(getSideFromIndex)];
_module setVariable [QGVAR(lastAssessmentByObjective), createHashMap];
_module setVariable [QGVAR(debugAssessments), []];

if ((GVAR(commanders) find _module) == -1) then {
    GVAR(commanders) pushBack _module;
};

[
    {
        params ["_commander"];

        if (isNull _commander) exitWith {};

        [_commander] call FUNC(assessCommander);

        private _pfhId = [{
            params ["_args", "_idPFH"];
            _args params ["_commanderPFH"];

            if (isNull _commanderPFH) exitWith {
                [_idPFH] call CBA_fnc_removePerFrameHandler;
            };

            [_commanderPFH] call FUNC(assessCommander);
        }, _commander getVariable [QGVAR(loopInterval), 60], [_commander]] call CBA_fnc_addPerFrameHandler;

        _commander setVariable [QGVAR(assessPFH), _pfhId];
    },
    [_module],
    10
] call CBA_fnc_waitAndExecute;

GVAR(enabled) = true;
