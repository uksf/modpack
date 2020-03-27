#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Ejects unit from plane and deploys static line parachute

    Parameter(s):
        0: Vehicle <OBJECT>
        1: Unit <OBJECT>

    Return Value:
        None
*/
params ["_vehicle", "_unit"];

private _jumpPoints = getArray (EGVAR(common,configVehicles) >> typeOf _vehicle >> "CUP_JumpPoint");
private _jumpPosition = _vehicle modelToWorldVisualWorld (_vehicle selectionPosition (_jumpPoints select ((_vehicle getCargoIndex _unit) % 2)));
_unit allowDamage false;
moveOut _unit;
_unit setPosASL _jumpPosition;
_unit setDir ((getDirVisual _vehicle) - 180);
_unit setVelocity (velocity _vehicle);

[{
    params ["_vehicle", "_unit"];

    _unit action ["OpenParachute", _unit];
    _unit allowDamage true;
    _this set [0, vehicle _unit];

    [{
        ((getPosVisual (_this#1))#2) < 0.5
    }, {
        params ["_chute", "_unit"];

        _unit allowDamage false;
        moveOut _unit;
        _unit setPos (getPos _unit);
        [{
            isTouchingGround (_this#1);
        }, {
            params ["_chute", "_unit"];

            deleteVehicle _chute;
            _unit allowDamage true;
            _unit switchMove "AmovPercMevaSrasWrflDf_AmovPknlMstpSrasWrflDnon";
        }, _this] call CBA_fnc_waitUntilAndExecute;
    }, _this] call CBA_fnc_waitUntilAndExecute;
}, _this, 2 + (random 0.5)] call CBA_fnc_waitAndExecute;
