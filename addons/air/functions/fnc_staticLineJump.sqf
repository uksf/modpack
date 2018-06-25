/*
    Author:
        Tim Beswick

    Description:
        Ejects unit from plane with static line parachute

    Parameter(s):
        0: Vehicle <OBJECT>
        1: Unit <OBJECT>

    Return Value:
        None
*/
#include "script_component.hpp"

params ["_vehicle", "_unit"];

private _jumpPoints = getArray (configFile >> "CfgVehicles" >> typeOf _vehicle >> "CUP_JumpPoint");
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
        ((getPosATLVisual _this#1)#2) < 1
    }, {
        params ["_chute", "_unit"];

        moveOut _unit;
        deleteVehicle _chute;
        _unit switchMove "AmovPercMevaSrasWrflDf_AmovPknlMstpSrasWrflDnon";
        private _chuteLanded = "T10_Landed" createVehicle (getPos _unit);
	    _chuteLanded addAction ["Pack Parachute", QUOTE(_this call FUNC(packParachute))];
    }, _this] call CBA_fnc_waitUntilAndExecute;
}, _this, 1 + (random 1)] call CBA_fnc_waitAndExecute;
