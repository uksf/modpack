#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Selects a position from the list of the positions passed
        calls the spawn unit function for those positions
        _currenGrouptUnitCount is checked to create a group every 10 units
        _numberOfUnitsToSpawn is checked to make sure the number of units defined is spawned


    Parameters:
        0: _spawnPositions <ARRAY>
        1: _statics <ARRAY>
        2: _module <OBJECT>

    Return value:
        Nothing
*/

params ["_spawnPositions", "_statics", "_module"];

if (!isServer) exitWith {};

private _fnc_getArrayFromModule = {
    params ["_module", "_property"];

    private _value = _module getVariable [_property, []];

    if (_value isEqualType "") then {
        if (_value != "") then {
            _value = call compile _value;
        } else {
            _value = [];
        };
    };
    _value
};

private _unitPoolArray = [_module, QGVAR(unitPoolString)] call _fnc_getArrayFromModule;
private _spawnPercentage = _module getVariable [QGVAR(percentageOfPositionsToOccupy), 0];
private _numberOfPositionsToOccupy = round((count _spawnPositions) * (_spawnPercentage / 100));
private _numberOfUnitsToSpawn = _module getVariable [QGVAR(numberOfUnits), 0];
private _side = _module getVariable [QGVAR(side), 0];


if (_side isEqualTo 0) then {
    _side = east;
};

if (_side isEqualTo 1) then {
    _side = independent;
};

if (_side isEqualTo 2) then {
    _side = west;
};

// populate statics
_numberOfUnitsToSpawn = [_statics, _side, _unitPoolArray, _numberOfUnitsToSpawn] call FUNC(populateStatics);

// populate ai building positions and building positions
_numberOfUnitsToSpawn = [_spawnPositions, _numberOfPositionsToOccupy, _side, _unitPoolArray, _numberOfUnitsToSpawn] call FUNC(populateBuildingPositions);

// handle patrols
// if (_numberOfUnitsToSpawn > 0) then {
//     [_numberOfUnitsToSpawn, _side, _module, _unitPoolArray] call FUNC(createPatrols);
// ;}
