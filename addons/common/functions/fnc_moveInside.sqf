/*
    Author:
        Tim Beswick

    Description:
        Allows movement inside vehicle (C-130)

    Parameter(s):
        0: Vehicle <OBJECT>

    Return Value:
        Nothing
*/
#include "script_component.hpp"

#define TIMEOUT 5

params ["_vehicle"];
private _unit = missionNamespace getVariable ['bis_fnc_moduleRemoteControl_unit', player];
_unit allowDamage false;
[_unit, "blockDamage", QGVAR(moveInside), true] call ace_common_fnc_statusEffect_set;
_unit disableCollisionWith _vehicle;

_unit action ["eject", _vehicle];
[{
	params ["_unit"];
	(vehicle _unit) isEqualTo _unit
}, {
	params ["_unit"];
	_unit action ["SwitchWeapon", _unit, _unit, 100];
}, [_unit]] call CBA_fnc_waitUntilAndExecute;

private _position = _vehicle selectionPosition "moveInsidePos";
private _height = _position#2;
private _oldPosition = _position;
private _strafe = [0,0,0];
private _direction = 180;

hint format ["Press %1 [Lock Target Key] to return to seat", actionKeysNames "LockTarget"];
_unit forceWalk true;

[{
	params ["_args", "_idPFH"];
	_args params ["_vehicle", "_unit", "_position", "_oldPosition", "_strafe", "_direction", "_height", "_time"];

	if (inputAction "LockTarget" > 0) exitWith {
		[_idPFH] call CBA_fnc_removePerFrameHandler;
		_unit forceWalk false;
		_unit setVelocity [0,0,0];
		_unit moveInCargo _vehicle;
		_unit allowDamage true;
		[_unit, "blockDamage", QGVAR(moveInside), false] call ace_common_fnc_statusEffect_set;
	};

	if (inputAction "AimRight" > 0) then {
		_direction = _direction + (inputAction "AimRight");
	};
	if (inputAction "AimLeft" > 0) then {
		_direction = _direction - (inputAction "AimLeft");
	};
	_unit setDir ((getDirVisual _vehicle) + _direction);

	if (inputAction "moveForward" > 0) then {
		_position = _position vectorAdd (([(vectorDirVisual _unit), getDirVisual _vehicle] call BIS_fnc_rotateVector2D) vectorMultiply 0.03);
	};
	if (inputAction "moveBack" > 0) then {
		_position = _position vectorAdd (([(vectorDirVisual _unit), getDirVisual _vehicle] call BIS_fnc_rotateVector2D) vectorMultiply -0.03);
	};
	if (inputAction "turnLeft" > 0) then {
		_strafe = [vectorDirVisual _unit, (getDirVisual _vehicle) - 90] call BIS_fnc_rotateVector2D;
		_position = _position vectorAdd (_strafe vectorMultiply -0.03);
	};
	if (inputAction "turnRight" > 0) then {
		_strafe = [vectorDirVisual _unit, (getDirVisual _vehicle) + 90] call BIS_fnc_rotateVector2D;
		_position = _position vectorAdd (_strafe vectorMultiply -0.03);
	};

	private _testFrom = _vehicle modelToWorldVisualWorld [(_position#0) * 1.2, (_position#1) * 1.2, (_position#2) + 0.2];
	private _testTo = _vehicle modelToWorldVisualWorld (_oldPosition vectorAdd [0,0,0.2]);
	if (!(lineIntersects [_testFrom, _testTo])) then {
		_position set [2, _height];
		_oldPosition = _position;
	} else {
		_position = _oldPosition;
	};
	_unit setPosASL (_vehicle modelToWorldVisualWorld _position);
	_unit setVectorUp (vectorUpVisual _vehicle);
	_unit switchMove "";

	private _intersects = lineIntersects [((getPosASLVisual _unit) vectorAdd ((vectorUp _unit) vectorMultiply 1.25)), ((getPosASLVisual _unit) vectorAdd ((vectorUp _unit) vectorMultiply -4)), _unit];
	if (!_intersects && {time > (_time + TIMEOUT)}) exitWith {
		diag_log "EXIT";
		[_idPFH] call CBA_fnc_removePerFrameHandler;
		_unit setVelocity (velocity _vehicle);
		_unit forceWalk false;
		_unit playMoveNow "halofreefall_non";
		[{
			params ["_unit"];
			_unit allowDamage true;
			[_unit, "blockDamage", QGVAR(moveInside), false] call ace_common_fnc_statusEffect_set;
		}, [_unit], 2] call CBA_fnc_waitAndExecute;
	};

	_args set [2, _position];
	_args set [3, _oldPosition];
	_args set [4, _strafe];
	_args set [5, _direction];
}, 0, [_vehicle, _unit, _position, _oldPosition, _strafe, _direction, _height, time]] call CBA_fnc_addPerFrameHandler;
