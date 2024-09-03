#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Sets the settings from the module up as global vars

    Parameters:
        0: The module object <OBJECT>

    Return value:
        Nothing
*/

params ["_spawnPositions", "_numberOfPositionsToOccupy", "_side", "_unitPoolArray", "_numberOfUnitsToSpawn"];

private _updatedNumberOfUnitsToSpawn = _numberOfUnitsToSpawn;
private _group = grpNull;
private _currenGrouptUnitCount = 0;


[{
    params ["_args", "_idPFH"];
    _args params ["_spawnPositions", "_numberOfPositionsToOccupy", "_side", "_unitPoolArray", "_updatedNumberOfUnitsToSpawn", "_currenGrouptUnitCount", "_group"];

    if (_numberOfPositionsToOccupy <= 1) exitWith {
        [_idPFH] call cba_fnc_removePerFrameHandler;
        [QEGVAR(virtualisation,include), _group] call CBA_fnc_serverEvent;
        _updatedNumberOfUnitsToSpawn
    };

    // create a group if the _currenGrouptUnitCount is == 0
    if (_currenGrouptUnitCount isEqualTo 0) then {
        _group = createGroup _side;
        [QEGVAR(virtualisation,exclude), _group] call CBA_fnc_serverEvent;
    };

    private _unitType = selectRandom _unitPoolArray;
    private _unit = _group createUnit [_unitType, [0,0,0], [], 0, "NONE"];
    _currenGrouptUnitCount = _currenGrouptUnitCount + 1;

    private _pos = selectRandom _spawnPositions;
    if (_pos isEqualType []) then {
        _unit setPos _pos;
    } else {
        _unit setPos (getPos _pos);
    };

    _spawnPositions deleteAt (_spawnPositions find _pos);

    // TRACE_4("", _pos, _dir, typeName _spawnPos, _spawnPos);

    _numberOfPositionsToOccupy = _numberOfPositionsToOccupy - 1;
    _updatedNumberOfUnitsToSpawn = _updatedNumberOfUnitsToSpawn - 1;

    _unit disableAI "PATH";

    if (_currenGrouptUnitCount == 10) then {
        _currenGrouptUnitCount = 0;
    };

    _args set [0, _spawnPositions];
    _args set [1, _numberOfPositionsToOccupy];
    _args set [4, _updatedNumberOfUnitsToSpawn];
    _args set [5, _currenGrouptUnitCount];
    _args set [6, _group];

}, 1, [_spawnPositions, _numberOfPositionsToOccupy, _side, _unitPoolArray, _updatedNumberOfUnitsToSpawn, _currenGrouptUnitCount, _group]] call cba_fnc_addPerFrameHandler;

