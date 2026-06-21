#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Makes units fire at given position when condition is true

    Parameters:
        0: _artilleryPiece <OBJECT>
        1: _targetArea <STRING>
        2: _numberOfShots <NUMBER>
        3: _numberOfShotsOffset <NUMBER>
        4: _condition <CODE>

    Return value:
        Nothing
*/

params ["_artilleryPiece", "_targetArea", "_numberOfShots", "_numberOfShotsOffset", "_condition", "_timeBetweenShots", "_timeBetweenShotsOffset"];

[{
	params ["_args", "_idPFH"];
	_args params ["_artilleryPiece", "_targetArea", "_numberOfShots", "_numberOfShotsOffset", "_condition"];

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
