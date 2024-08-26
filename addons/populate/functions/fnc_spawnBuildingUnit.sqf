#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Spawns a unit at the passed position

    Parameters:
        0: _spawnPositions <ARRAY>
        1: _numberOfUnitsToSpawn <NUMBER>
        2: _numberOfPositionsToOccupy <NUMBER>
        3: _side <SIDE>
        4: _module <MODULE>
        5: _unitPoolArray <ARRAY>
        6: _statics <ARRAY>

    Return value:
        Nothing
*/

params ["_spawnPositions", "_numberOfUnitsToSpawn", "_numberOfPositionsToOccupy", "_side", "_module", "_unitPoolArray", "_statics"];

private _group = grpNull;
private _currenGrouptUnitCount = 0;
systemchat format ["st 1: %1", _statics];

[{
    params ["_args", "_idPFH"];
    _args params ["_spawnPositions", "_numberOfUnitsToSpawn", "_numberOfPositionsToOccupy", "_side", "_module", "_unitPoolArray", "_currenGrouptUnitCount", "_group", "_statics"];

    if (_numberOfPositionsToOccupy <= 1) exitWith {
        [_idPFH] call cba_fnc_removePerFrameHandler;
        [QEGVAR(virtualisation,include), _group] call CBA_fnc_serverEvent;
        if (_numberOfUnitsToSpawn > 0) then {
            [_numberOfUnitsToSpawn, _side, _module, _unitPoolArray] call FUNC(createPatrols);
        ;}
    };

    // create a group if the _currenGrouptUnitCount is == 0
    if (_currenGrouptUnitCount isEqualTo 0) then {
        _group = createGroup _side;
        [QEGVAR(virtualisation,exclude), _group] call CBA_fnc_serverEvent;
    };

    private _unitType = selectRandom _unitPoolArray;
    private _unit = _group createUnit [_unitType, [0,0,0], [], 0, "NONE"];

    _currenGrouptUnitCount = _currenGrouptUnitCount + 1;

    // do statics
    if (_statics isNotEqualTo []) then {
        private _static = selectRandom _statics;
        _unit moveInAny _static;
        _statics deleteAt (_statics find _static);
        _numberOfPositionsToOccupy = _numberOfPositionsToOccupy - 1;
        _numberOfUnitsToSpawn = _numberOfUnitsToSpawn - 1;
    };

    private _pos = [0,0,0];
    private _dir = -1;
    private _spawnPos = selectRandom _spawnPositions;
    if (typeName _spawnPos == "OBJECT") then { // handle cba positions as theyre objects
        _pos = getPos _spawnPos;
        _dir = getDir _spawnPos;
    } else {
        _pos = _spawnPos;
    };

    TRACE_4("", _pos, _dir, typeName _spawnPos, _spawnPos);

    _unit setPos _pos;
    _unit setDir _dir; // groups will follow the group leaders dir most of the time
    _spawnPositions deleteAt (_spawnPositions find _spawnPos);
    _numberOfPositionsToOccupy = _numberOfPositionsToOccupy - 1;
    _numberOfUnitsToSpawn = _numberOfUnitsToSpawn - 1;

    _unit disableAI "PATH";

    if (_currenGrouptUnitCount == 10) then {
        _currenGrouptUnitCount = 0;
    };

    _args set [1, _numberOfUnitsToSpawn];
    _args set [2, _numberOfPositionsToOccupy];
    _args set [6, _currenGrouptUnitCount];
    _args set [7, _group];

}, 1, [_spawnPositions, _numberOfUnitsToSpawn, _numberOfPositionsToOccupy, _side, _module, _unitPoolArray, _currenGrouptUnitCount, _group, _statics]] call cba_fnc_addPerFrameHandler;
