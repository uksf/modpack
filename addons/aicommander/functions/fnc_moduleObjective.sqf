#include "script_component.hpp"
/*
    Author:
        Codex

    Description:
        Initialize objective module runtime state.

    Parameters:
        1: Arguments array with module object at index 0 <ARRAY>

    Return Value:
        None
*/

if (is3DEN) exitWith {};
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
_module setVariable [QGVAR(isObjective), true];

private _objectiveName = _module getVariable [QGVAR(objectiveName), ""];
if (_objectiveName isEqualTo "") then {
    _objectiveName = format ["OBJ-%1", round random 999];
};
_module setVariable [QGVAR(objectiveName), _objectiveName];

private _priority = [_module getVariable [QGVAR(priority), 5], 5] call _fnc_toNumber;
private _initialOwnerIndex = [_module getVariable [QGVAR(initialOwner), -1], -1] call _fnc_toNumber;
private _forcePool = [_module getVariable [QGVAR(forcePoolGroups), 6], 6] call _fnc_toNumber;
private _threshold = [_module getVariable [QGVAR(contestedLosingThreshold), 2], 2] call _fnc_toNumber;
private _evalInterval = [_module getVariable [QGVAR(evalInterval), 10], 10] call _fnc_toNumber;

_module setVariable [QGVAR(priority), _priority];
_module setVariable [QGVAR(initialOwner), _initialOwnerIndex];
_module setVariable [QGVAR(forcePoolGroups), _forcePool max 0];
_module setVariable [QGVAR(forcePoolStartGroups), _forcePool max 0];
_module setVariable [QGVAR(contestedLosingThreshold), _threshold max 1];
_module setVariable [QGVAR(evalInterval), _evalInterval max 1];

private _ownerSide = [_initialOwnerIndex] call FUNC(getSideFromIndex);
private _initialState = if (_ownerSide isEqualTo sideUnknown) then {"not_owned"} else {"owned_secure"};
_module setVariable [QGVAR(ownerSide), _ownerSide];
_module setVariable [QGVAR(currentState), _initialState];

if ((GVAR(objectives) find _module) == -1) then {
    GVAR(objectives) pushBack _module;
};

[_module] call FUNC(evalObjective);

private _pfhId = [{
    params ["_args", "_idPFH"];
    _args params ["_objective"];

    if (isNull _objective) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
    };

    [_objective] call FUNC(evalObjective);
}, _module getVariable [QGVAR(evalInterval), 10], [_module]] call CBA_fnc_addPerFrameHandler;

_module setVariable [QGVAR(evalPFH), _pfhId];
GVAR(enabled) = true;
