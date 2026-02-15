#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Swaps unit with unconscious driver

    Parameter(s):
        0: Vehicle <OBJECT>
        1: Unit <OBJECT>

    Return Value:
        None
*/
params ["_vehicle", "_unit"];

if !(call FUNC(canSwapDriver)) exitWith {
    ["Cannot swap with driver"] call ace_common_fnc_displayTextStructured;
};

private _driver = driver _vehicle;
private _fullCrew = fullCrew [_vehicle, "", true];
(
    _fullCrew select (_fullCrew findIf {_x#0 == _unit})
) params ["", "_role", "_cargoIndex", "_currentTurret"];

private _driverMoveParams = [];
private _unitMoveBackCode = {};
private _unitMoveBackParams = [];

if (_role == "cargo") then {
    _driverMoveParams = [_vehicle, _driver, {(_this#0) moveInCargo (_this#1)}, [_vehicle, _cargoIndex], [], _cargoIndex];
    _unitMoveBackCode = {(_this#0) moveInCargo (_this#1)};
    _unitMoveBackParams = [_vehicle, _cargoIndex];
} else {
    _driverMoveParams = [_vehicle, _driver, {(_this#0) moveInTurret (_this#1)}, [_vehicle, _currentTurret], _currentTurret, -1];
    _unitMoveBackCode = {(_this#0) moveInTurret (_this#1)};
    _unitMoveBackParams = [_vehicle, _currentTurret];
};

[QGVAR(swapDriver), _driverMoveParams, _driver] call CBA_fnc_targetEvent;

[{
    params ["", "_unit", ""];
    _unit enableSimulation false;
    moveOut _unit;

    GVAR(frame) = diag_frameNo;
    [{
        params ["_vehicle", "_unit", "_currentTurret"];

        isNull (objectParent _unit)
        && {isNull (driver _vehicle)}
        && {_currentTurret isEqualTo [] || {local _vehicle == (_vehicle turretLocal _currentTurret)}}
    }, {
        params ["_vehicle", "_unit", "_currentTurret", "_moveBackCode", "_moveBackParams"];

        LOG_1("Player swap to driver available after %1 frames",diag_frameNo - GVAR(frame));

        GVAR(frame) = diag_frameNo;
        [{
            params ["_vehicle", "_unit"];

            _unit moveInDriver _vehicle;
            driver _vehicle == _unit
        }, {
            params ["", "_unit"];

            LOG_1("Player moved in to driver after %1 frames",diag_frameNo - GVAR(frame));
            _unit enableSimulation true;
        }, [_vehicle, _unit, _moveBackCode, _moveBackParams], SWAP_TIMEOUT, {
            params ["", "_unit", "_moveBackCode", "_moveBackParams"];

            WARNING_1("Failed player move in to driver after %1 frames",diag_frameNo - GVAR(frame));
            ["Failed to swap into driver seat"] call ace_common_fnc_displayTextStructured;
            [_unit, _moveBackParams] call _moveBackCode;
            _unit enableSimulation true;
        }] call CBA_fnc_waitUntilAndExecute;
    }, _this, SWAP_TIMEOUT * 2, {
        params ["_vehicle", "_unit"];

        LOG_1("Player swap to driver unavailable after %1 frames",diag_frameNo - GVAR(frame));
        _unit moveInAny _vehicle;
        _unit enableSimulation true;
    }] call CBA_fnc_waitUntilAndExecute;
}, [_vehicle, _unit, _currentTurret, _unitMoveBackCode, _unitMoveBackParams]] call CBA_fnc_execNextFrame;
