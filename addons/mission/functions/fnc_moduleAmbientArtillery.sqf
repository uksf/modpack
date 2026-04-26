#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Makes units fire at given position when condition is true

    Parameters:
        0: logic <OBJECT>

    Return value:
        Nothing
*/

(_this select 1) params ["_logic"];

if !(local _logic) exitWith {};
if (_logic getVariable [QGVAR(initialised), false]) exitWith {};

private _timeBetweenShots = parseNumber str (_logic getVariable [QGVAR(timeBetweenShots), 600]);
private _timeBetweenShotsOffset = parseNumber str (_logic getVariable [QGVAR(timeBetweenShotsOffset), 30]);
private _numberOfShots = parseNumber str (_logic getVariable [QGVAR(numberOfShots), 2]);
private _numberOfShotsOffset = parseNumber str (_logic getVariable [QGVAR(numberOfShotsOffset), 2]);
private _targetArea = _logic getVariable [QGVAR(targetArea), ""];
private _deleteRoundOnShot = (_logic getVariable [QGVAR(deleteRoundOnShot), false]) isEqualTo true;
private _conditionString = _logic getVariable [QGVAR(condition), "true"];

if (_targetArea isEqualTo "") exitWith {
    WARNING("Ambient artillery module has no target area configured");
};

private _condition = compile _conditionString;
private _conditionResult = call _condition;
if !(_conditionResult isEqualType true) then {
    WARNING("Ambient artillery module condition is invalid. Defaulting to true");
    _condition = {true};
};

private _artilleryPieces = synchronizedObjects _logic;
if (_artilleryPieces isEqualTo []) exitWith {
    WARNING("Ambient artillery module has no synced artillery pieces");
};

{
    private _artilleryPiece = _x;

    if (isNull _artilleryPiece || {!alive _artilleryPiece}) exitWith {};
	if (_deleteRoundOnShot) then {
		_artilleryPiece addEventHandler ["Fired", {
			deleteVehicle (_this#6);
		}];
	};

	[{
		params ["_args", "_idPFH"];
		_args params ["_artilleryPiece", "_targetArea", "_numberOfShots", "_numberOfShotsOffset", "_condition"];

		if (!local _artilleryPiece) exitWith {};
		if (!alive _artilleryPiece) exitWith {
			[_idPFH] call CBA_fnc_removePerFrameHandler;
		};

		if ((call _condition) isNotEqualTo true) exitWith {};

		private _position = [_targetArea] call CBA_fnc_randPosArea;
		if (_position isEqualTo []) exitWith {};

		private _rounds = floor (_numberOfShots + random _numberOfShotsOffset) max 1;
		private _magazine = currentMagazine _artilleryPiece;

		_artilleryPiece doArtilleryFire [_position, _magazine, _rounds];
		_artilleryPiece setVehicleAmmo 1;
	}, _timeBetweenShots + random _timeBetweenShotsOffset, [_artilleryPiece, _targetArea, _numberOfShots, _numberOfShotsOffset, _condition]] call CBA_fnc_addPerFrameHandler;
} forEach _artilleryPieces;
