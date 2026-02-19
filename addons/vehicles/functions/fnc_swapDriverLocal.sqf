#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Swaps unconscious driver with swapper unit

    Parameter(s):
        0: Vehicle <OBJECT>
        1: Unit <OBJECT>
        2: Move in code <CODE>
        3: Move in params <ARRAY>
        4: Swapper turret path <ARRAY>
        5: Swapper cargo index <SCALAR>

    Return Value:
        None
*/
params ["", "_unit"];
TRACE_1("swap driver local",_this);

_unit enableSimulation false;
moveOut _unit;

GVAR(driverframe) = diag_frameNo;
[{
    params ["_vehicle", "_unit", "", "", "_swapperTurret", "_swapperCargoIndex"];


    isNull (objectParent _unit)
    && {local _vehicle == (_vehicle turretLocal [-1])}
    && {_swapperCargoIndex == -1 || {TRACE_1("",_vehicle getCargoIndex _swapperCargoIndex); isNull (_vehicle getCargoIndex _swapperCargoIndex)}}
    && {_swapperTurret isEqualTo [] || {TRACE_1("",_vehicle turretUnit _swapperTurret); isNull (_vehicle turretUnit _swapperTurret) && {local _vehicle == (_vehicle turretLocal _swapperTurret)}}}
}, {
    params ["_vehicle", "_unit", "_moveInCode", "_moveInParams"];
    TRACE_1("swap driver local available",_this);

    LOG_1("Unit swap out of driver available after %1 frames",diag_frameNo - GVAR(driverframe));

    GVAR(driverframe) = diag_frameNo;
    [{
        params ["", "_unit", "_moveInCode", "_moveInParams"];

        [_unit, _moveInParams] call _moveInCode;
        !isNull (objectParent _unit)
    }, {
        params ["", "_unit"];

        LOG_1("Unit move in of driver after %1 frames",diag_frameNo - GVAR(driverframe));
        _unit enableSimulation true;
        [{[_this#0, true] call ace_medical_engine_fnc_setUnconsciousAnim}, [_unit], 1] call CBA_fnc_waitAndExecute;
    }, _this, SWAP_TIMEOUT, {
        params ["_vehicle", "_unit"];

        WARNING_1("Failed unit move in of driver after %1 frames",diag_frameNo - GVAR(driverframe));
        ["Failed to swap into swapper seat"] call ace_common_fnc_displayTextStructured;
        _unit moveInDriver _vehicle;
        _unit enableSimulation true;
    }] call CBA_fnc_waitUntilAndExecute;
}, _this, SWAP_TIMEOUT * 2, {
    params ["_vehicle", "_unit"];

    LOG_1("Unit swap out of driver unavailable after %1 frames",diag_frameNo - GVAR(driverframe));
    _unit moveInAny _vehicle;
    _unit enableSimulation true;
}] call CBA_fnc_waitUntilAndExecute;

