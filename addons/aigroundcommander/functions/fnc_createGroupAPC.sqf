#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        create APC with only crew, no dismounts

    Parameters:
        0: _spawnPosition <OBJECT>
        1: Callback once spawning complete <CODE> (Optional)
        2: Callback arguments <ARRAY> (Optional)
        
    Return value:
        created group and their spawn position
*/
#define TIMEOUT 20
#define SPAWN_DELAY 1

params ["_spawnPosition", ["_callback", {}, [{}]], ["_callbackArgs", [], [[]]]];

// Moved this, no point checking stuff you already know after you've creted the vehicle. Always exit as soon as possible.
if (!alive _spawnPosition || GVAR(currentUnitCount) >= GVAR(maxUnitcount)) exitWith {};

private _safeSpawn = _spawnPosition getPos [20, random 360];
_safeSpawn = +_safeSpawn;
_safeSpawn resize 2;
// private _nearRoads = _spawnPosition nearRoads 100;
// private _safeSpawn = selectRandom _nearRoads;

private _veh = createVehicle [selectRandom EGVAR(gear,gearAPC), _safeSpawn];
_veh setVectorUp (surfaceNormal (getPos _veh));
// _veh setDir (getDir _safeSpawn);

private _group = createGroup EAST;
_group addVehicle _veh;
// _veh engineOn true;

// if (!alive _spawnPosition || GVAR(currentUnitCount) >= GVAR(maxUnitcount)) exitWith {
//     if ((count(fullCrew[_veh,"",false]) == 0)) then {deleteVehicle _veh;};
// };

//////
// beswix
//////

[QEGVAR(caching,disableCache), _group] call CBA_fnc_serverEvent;

private _turrets = allTurrets [_veh, false]; 
private _count = (_veh emptyPositions "driver") + count _turrets;


[{
    params ["_args", "_idPFH"];
    _args params ["_group", "_veh", "_count", "_turrets", "_time", "_callback", "_callbackArgs"];

    
    private _allSpawned = (count (crew _veh)) >= _count;
    // diag_log format ["AI CMDR: allspawned %1, _count: %2, crew count: %3, turretCount: %4",_allSpawned,_count,count(crew _veh),count _turrets];
    if (!alive _veh || {_allSpawned} || {time > (_time + TIMEOUT)}) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;

        if (_allSpawned) then {
            _group selectLeader (commander _veh);
            _callbackArgs pushBack _group;           
            _callbackArgs call _callback;           
        };       
    };

    private _unit = _group createUnit [selectRandom EGVAR(gear,gearCrew), [0, 0, 2000], [], 0, "NONE"];
    GVAR(currentUnitCount) = GVAR(currentUnitCount) + 1;

    _unit addMPEventHandler ["MPKilled", {
       GVAR(currentUnitCount) = GVAR(currentUnitCount) - 1;
    }];

    if ((_veh emptyPositions "driver") > 0) exitWith {
        _unit assignAsDriver _veh;
        _unit moveInDriver _veh;
        _unit setVariable [QGVAR(assignedVehicle), assignedVehicle (_unit)];
    };

    if (isNull (_veh turretUnit (_turrets#0))) exitWith {
        _unit assignAsTurret [_veh, (_turrets#0)];
        _unit moveInTurret [_veh, (_turrets#0)];
        _turrets deleteAt 0;
    };

}, SPAWN_DELAY, [_group, _veh, _count, _turrets, time, _callback, _callbackArgs]] call CBA_fnc_addPerFrameHandler;

_group