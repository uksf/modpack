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

private _artyPieces = (synchronizedObjects _logic) select {typeOf _x != "uksf_mission_moduleAmbientArtilleryTargetArea"};
private _targetAreas = (synchronizedObjects _logic) select {typeOf _x == "uksf_mission_moduleAmbientArtilleryTargetArea"};
private _time = _logic getVariable [QGVAR(ambientArtilleryInterval), 0];
private _deleteRound = _logic getVariable [QGVAR(ambientArtilleryDeleteShell), false];
private _minimumRounds = _logic getVariable [QGVAR(ambientArtilleryMinimumNumberOfRounds), 0];
private _randomRounds = _logic getVariable [QGVAR(ambientArtilleryRandomNumberOfRounds), 0];

{
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
            [_idPFH] call cba_fnc_removePerFrameHandler;
        };

        private _targetArea = selectRandom _targetAreas;
        private _areaArray = [_targetArea] call bis_fnc_getArea;
        _areaArray deleteAt 5;
        private _position = [_areaArray] call CBA_fnc_randPosArea;

        TRACE_1("ambient arty", _position);

        _artyPiece doArtilleryFire [_position, currentMagazine _artyPiece, _minimumRounds + round(_randomRounds)];

        // delay so it doesn't get interrupted
        [{
            params ["_artyPiece"];
            _artyPiece setVehicleAmmo 1;
        }, [_artyPiece], 60] call cba_fnc_waitAndExecute;

    }, _time, [_x, _targetAreas, _minimumRounds, _randomRounds]] call cba_fnc_addPerFrameHandler;
} forEach _artyPieces;
