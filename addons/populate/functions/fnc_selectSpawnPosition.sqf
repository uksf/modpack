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

    Return value:
        Nothing
*/

params ["_spawnPositions", "_module"];

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

private _numberOfUnitsToSpawn = [_module, QGVAR(numberOfUnits)] call _fnc_getArrayFromModule;
private _side = _module getVariable [QGVAR(side), 0];
private _currenGrouptUnitCount = 0;
private _group = grpNull;

[{
	params ["_args", "_idPFH"];
	_args params ["_spawnPositions", "_currenGrouptUnitCount", "_numberOfUnitsToSpawn", "_side", "_group"];

	if (_numberOfUnitsToSpawn <= 0 || (count _spawnPositions) <= 0) exitWith { // TODO: if _numberOfUnitsToSpawn has left over units, handle in some way, maybe a patrol??
		[_idPFH] call cba_fnc_removePerFrameHandler;
	};

    private _spawnPos = selectRandom _spawnPositions;

    // delete the position from the array to avoid doubling
    _spawnPositions deleteAt (_spawnPositions findIf {_x == _spawnPos});

    // create a group if the _currenGrouptUnitCount is == 0
    if (_currenGrouptUnitCount == 0) then {
        _group = createGroup _side;
    };

    // call a create unit function
    [_spawnPos, _module, _group] call FUNC(spawnUnit);
    _currenGrouptUnitCount = _currenGrouptUnitCount + 1;
    _numberOfUnitsToSpawn = _numberOfUnitsToSpawn - 1;
    if (_currenGrouptUnitCount == 10) then {
        _currenGrouptUnitCount = 0;
    };

    // update pfh vars
    _args set [0, _spawnPositions];
    _args set [1, _currenGrouptUnitCount];
    _args set [2, _numberOfUnitsToSpawn];
    _args set [4, _group];

}, 1, [_spawnPositions, _currenGrouptUnitCount, _numberOfUnitsToSpawn, _side, _group]] call cba_fnc_addPerFrameHandler;
