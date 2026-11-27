#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Sets up the PFH to monitor each placed sector control module

    Parameters:
        0: The module logic <OBJECT>

    Return value:
        Nothing

    Example:
        [_logic] call uksf_sectorcontrol_fnc_moduleSectorPFH
*/
if (is3DEN) exitWith {};

(_this#1) params ["_logic"];

if !(isServer) exitWith {};

private _conditionString = _logic getVariable [QGVAR(condition), true];
private _lockAfterCapture = _logic getVariable [QGVAR(lockAfterCapture), 0];
private _requiredDominance = _logic getVariable [QGVAR(requiredDominance), 0];
private _name = _logic getVariable [QGVAR(displayName), ""];
private _timeToCapture = _logic getVariable [QGVAR(timeToCapture), 0];
private _currentOwner = _logic getVariable [QGVAR(currentOwner), 2];
private _condition = compile (_conditionString);

[_logic, _currentOwner, _name] call FUNC(createSectorMarker);
private _markers = _logic getVariable [QGVAR(sectorMarkers), []];

[_logic, 0, 0, _timeToCapture] call FUNC(setOwnedSectorScores);

GVAR(sectors) pushBackUnique _logic;

if (!GVAR(enabled)) then {
    GVAR(enabled) = true;
    publicVariable QGVAR(enabled);
};

[{
    params ["_args", "_idPFH"];
    _args params ["_logic", "_condition", "_lockAfterCapture", "_requiredDominance", "_timeToCapture", "_markers", "_name"];

    private _locked = _logic getVariable [QGVAR(sectorLocked), false];
    if (_locked) exitWith {
        [_idPFH] call cba_fnc_removePerFrameHandler;
    };

    if !(call _condition) exitWith {};

    private _currentOpforScore = _logic getVariable [QGVAR(currentOpforScore), 0];
    private _currentBluforScore = _logic getVariable [QGVAR(currentbluforScore), 0];
    private _currentOwner = _logic getVariable [QGVAR(currentOwner), 2];

    private _areaMarker = _markers#0;
    private _entities = _areaMarker nearEntities [["Man", "Car", "APC", "Tank"], false, true, true];
    if (_entities findIf {_x isKindOf "Man" && {side _x in [east, west]}} == -1) exitWith {
        _logic setVariable [QGVAR(dominantSide), 2, true];
        private _sectorIsNeutral = _currentOwner == 2;
        if (_sectorIsNeutral) then {
            _currentBluforScore = (_currentBluforScore - 1) max 0;
            _currentOpforScore = (_currentOpforScore - 1) max 0;
            _logic setVariable [QGVAR(currentOpforScore), _currentOpforScore, true];
            _logic setVariable [QGVAR(currentbluforScore), _currentBluforScore, true];
        };
    };

    [_logic, _entities, _requiredDominance] call FUNC(calculateDominantSide);

    private _currentDominantSide = _logic getVariable [QGVAR(dominantSide), 2];
    if (_currentDominantSide isEqualTo _currentOwner && _currentBluforScore >= _timeToCapture) exitWith {};
    if (_currentDominantSide isEqualTo _currentOwner && _currentOpforScore >= _timeToCapture) exitWith {};

    if (_currentDominantSide == 0) then {
        _currentOpforScore = _currentOpforScore + 1;
        _currentBluforScore = _currentBluforScore - 1;
    };

    if (_currentDominantSide == 1) then {
        _currentBluforScore = _currentBluforScore + 1;
        _currentOpforScore = _currentOpforScore - 1;
    };

    _logic setVariable [QGVAR(currentOpforScore), _currentOpforScore, true];
    _logic setVariable [QGVAR(currentbluforScore), _currentBluforScore, true];

    [_entities, _currentbluforScore, _timeToCapture, _currentDominantSide] call FUNC(getSectorCaptureProgress);

    if (_currentOpforScore >= _timeToCapture && _currentOwner != 0) then {
        [QGVAR(sectorOwnerChanged), [0, _currentOwner, _logic, _lockAfterCapture, _name]] call CBA_fnc_localEvent;
    };

    if (_currentBluforScore >= _timeToCapture && _currentOwner != 1) then {
        [QGVAR(sectorOwnerChanged), [1, _currentOwner, _logic, _lockAfterCapture, _name]] call CBA_fnc_localEvent;
    };

}, 1, [_logic, _condition, _lockAfterCapture, _requiredDominance, _timeToCapture, _markers, _name]] call cba_fnc_addPerFrameHandler;
