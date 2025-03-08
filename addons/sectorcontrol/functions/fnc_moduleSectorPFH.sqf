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
*/
(_this#1) params ["_logic"];

if !(isServer) exitWith {};

private _conditionString = _logic getVariable [QGVAR(condition), true];
private _lockAfterCapture = _logic getVariable [QGVAR(lockAfterCapture), 0];
private _requiredDominance = _logic getVariable [QGVAR(requiredDominance), 0];
private _name = _logic getVariable [QGVAR(displayName), ""];
private _timeToCapture = _logic getVariable [QGVAR(timeToCapture), 0];
private _currentOwner = _logic getVariable [QGVAR(currentOwner), 2]; // 2 is no-one
private _condition = compile (_conditionString);

// leaving this out for now - Id rather we see all the points we have to capture
// private _result = call _condition;
// if (_result) then {
//     [_logic, _sizeXandY, _currentOwner, _name] call FUNC(createSectorMarker);
// };


// TODO: Handle markers being different when they're not able to be captured at mission start. Can't use grey as its used for not owned sectors.
// Could add text??
// Will need to reassess all sectors on a sector update because the condition box could be anything
[_logic, _currentOwner, _name] call FUNC(createSectorMarker);
private _markers = _logic getVariable [QGVAR(sectorMarkers), []];

// set scores to 100 for owned sectors
[_logic, 0, 0, _timeToCapture] call FUNC(setOwnedSectorScores);


[{
    params ["_args", "_idPFH"];
    _args params ["_logic", "_condition", "_lockAfterCapture", "_requiredDominance", "_timeToCapture", "_markers", "_name"];

    // exit if locked
    private _locked = _logic getVariable [QGVAR(sectorLocked), false];
    if (_locked) exitWith {
        [_idPFH] call cba_fnc_removePerFrameHandler;
    };

    // exit on false condition
    if !(call _condition) exitWith {};

    private _currentOpforScore = _logic getVariable [QGVAR(currentOpforScore), 0];
    private _currentBluforScore = _logic getVariable [QGVAR(currentbluforScore), 0];
    private _currentOwner = _logic getVariable [QGVAR(currentOwner), 2]; // 2 is no-one

    // exit on no-one nearby, decay the scores
    private _areaMarker = _markers#0;
    private _entities = _areaMarker nearEntities [["Man", "Car", "APC", "Tank"], false, true, true];
    if (_entities isEqualTo []) exitWith {
        if (_currentOwner == 2) then { // decay if the sector is neutral
            _currentBluforScore = (_currentBluforScore - 1) max 0;
            _currentOpforScore = (_currentOpforScore - 1) max 0;
            _logic setVariable [QGVAR(currentOpforScore), _currentOpforScore, true];
            _logic setVariable [QGVAR(currentBluforScore), _currentBluforScore, true];
        };
    };

    // calculate dominance
    [_logic, _entities, _requiredDominance] call FUNC(calculateDominantSide);

    // start updating timeToCapture/score
    private _currentDominantSide = _logic getVariable [QGVAR(dominantSide), sideEmpty];
    if (_currentDominantSide isEqualTo _currentOwner && _currentBluforScore >= _timeToCapture) exitWith {};
    if (_currentDominantSide isEqualTo _currentOwner && _currentOpforScore >= _timeToCapture) exitWith {};

    // one up one down
    if (_currentDominantSide == 0) then {
        _currentOpforScore = _currentOpforScore + 1;
        _currentBluforScore = _currentBluforScore - 1;
    };

    if (_currentDominantSide == 1) then {
        _currentBluforScore = _currentBluforScore + 1;
        _currentOpforScore = _currentOpforScore - 1;
    };

    _logic setVariable [QGVAR(currentOpforScore), _currentOpforScore, true];
    _logic setVariable [QGVAR(currentBluforScore), _currentbluforScore, true];

    // show a hint percentage
    // TODO: Make this not reliant on a particular side, the below relies on players being blufor
    [_entities, _currentbluforScore, _timeToCapture, _currentDominantSide] call FUNC(getSectorCaptureProgress);

    // fire ownerChanged event on score/time to capture met
    if (_currentOpforScore >= _timeToCapture && _currentOwner != 0) then {
        [QGVAR(sectorOwnerChanged), [0, _currentOwner, _logic, _lockAfterCapture, _name]] call CBA_fnc_localEvent; // local because this runs on the server
    };

    if (_currentBluforScore >= _timeToCapture && _currentOwner != 1) then {
        [QGVAR(sectorOwnerChanged), [1, _currentOwner, _logic, _lockAfterCapture, _name]] call CBA_fnc_localEvent;
    };

}, 1, [_logic, _condition, _lockAfterCapture, _requiredDominance, _timeToCapture, _markers, _name]] call cba_fnc_addPerFrameHandler;
