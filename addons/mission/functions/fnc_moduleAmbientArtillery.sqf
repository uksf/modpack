#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Fires artillery at a target area to create ambient artillery.
        Not designed to work with triggers or anything.
        Will just fire on a loop until destroyed.

    Parameters:
        0: module <OBJECT>

    Return value:
        Nothing
*/

(_this select 1) params ["_logic"];

private _artyPieces = (synchronizedObjects _logic) select {typeOf _x != QGVAR(moduleAmbientArtilleryTargetArea)};
private _targetAreas = (synchronizedObjects _logic) select {typeOf _x == QGVAR(moduleAmbientArtilleryTargetArea)};

if (_artyPieces isEqualTo [] || _targetAreas isEqualTo []) exitWith {};

private _time = _logic getVariable [QGVAR(ambientArtilleryInterval), 600];
private _deleteRound = _logic getVariable [QGVAR(ambientArtilleryDeleteShell), false];
private _minimumRounds = _logic getVariable [QGVAR(ambientArtilleryMinimumNumberOfRounds), 0];
private _randomRounds = _logic getVariable [QGVAR(ambientArtilleryRandomNumberOfRounds), 0];

{

    if (!local _x) exitWith {};

    // delete round
    if (_deleteRound) then {
        _x addEventHandler ["fired", {
            deleteVehicle (_this select 6);
        }];
    };

    // firing loop
    [{
        params ["_args","_idPFH"];
        _args params ["_artyPiece", "_targetAreas", "_minimumRounds", "_randomRounds"];

        if (!alive _artyPiece) exitWith {
            [_idPFH] call CBA_fnc_removePerFrameHandler;
        };

        private _targetArea = selectRandom _targetAreas;
        private _areaArray = [_targetArea] call BIS_fnc_getArea;
        _areaArray deleteAt 5;
        private _position = [_areaArray] call CBA_fnc_randPosArea;

        TRACE_1("ambient arty", _position);

        _artyPiece doArtilleryFire [_position, currentMagazine _artyPiece, _minimumRounds + round (random _randomRounds)];

        // delay so it doesn't get interrupted
        [{_this setVehicleAmmo 1}, _artyPiece, 60] call CBA_fnc_waitAndExecute;

    }, _time, [_x, _targetAreas, _minimumRounds, _randomRounds]] call CBA_fnc_addPerFrameHandler;
} forEach _artyPieces;
