#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        create Infantry group

    Parameters:
        None.
        
    Return value:
        Nothing
*/

params ["_spawnPosition"];

private _unitCount = ceil(random[6,8,10]);
private _currentUnitCount = _unitCount;
private _group = createGroup EAST;

private _safeSpawn = _spawnPosition getPos [10,random 360];

[{
    params ["_args","_idPFH"];
    _args params ["_safeSpawn","_group","_currentUnitCount"];
    _currentUnitCount = _currentUnitCount - 1;

    if (_currentUnitCount == 0 || (GVAR(currentUnitCount) >= GVAR(maxUnitcount))) exitWith {
        [_idPFH] call cba_fnc_removePerFrameHandler;
    };
    private _unit = _group createUnit [selectRandom EGVAR(gear,gearSoldier),_safeSpawn,[],2,"NONE"];
    GVAR(currentUnitCount) = GVAR(currentUnitCount) + 1;   

    _unit addMPEventHandler ["MPKilled", {
       GVAR(currentUnitCount) = GVAR(currentUnitCount) - 1;
        private _killedUnitGroup = group (_this#0);
        if ({alive _x} count units (_this#0) <= 2) then {
            GVAR(responseGroups) deleteAt (GVAR(responseGroups) find _killedUnitGroup);
        };
    }];

    _args set [2, _currentUnitCount];
},2,[_safeSpawn,_group,_currentUnitCount]] call cba_fnc_addPerFramehandler;

_group