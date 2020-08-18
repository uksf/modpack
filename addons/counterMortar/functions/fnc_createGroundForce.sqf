#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        creates ground hunter force type, uses re-gear script units so must have re-gear script in place

    Parameters:
        None
        
    Return value:
        Nothing
*/

if (!isServer) exitWith {};


params ["_spawnPosition","_bluforMortarPos"];

private _group = createGroup EAST;

private _veh = createVehicle [selectRandom GVAR(groundVehicleTypes), _spawnPosition];
_veh setUnloadInCombat [true,true];
private _unitCount = count(fullCrew[_veh,"",true]);
private _currentUnitCount = _unitCount;

_veh addMPEventHandler ["MPHit", {
    [{
        GVAR(counterInProgress) = 0;
    },[],900] call cba_fnc_waitAndExecute; // 15 minute wait time between tasks so mortars dont get spammed each time they fire
}];

[{
    params ["_args","_idPFH"];
    _args params ["_spawnPosition","_group","_currentUnitCount","_veh"];
    _currentUnitCount = _currentUnitCount - 1;
    if (_currentUnitCount == 0) exitWith {
        [_idPFH] call cba_fnc_removePerFrameHandler;
        if ((count(fullCrew[_veh,"",false]) == 0)) then {deleteVehicle _veh;};
    };
    private _unit = _group createUnit [selectRandom GVAR(soldierList),getPos _veh,[],2,"NONE"];
    _unit moveInAny _veh;   

    _args set [2, _currentUnitCount];
},0.5,[_spawnPosition,_group,_currentUnitCount,_veh]] call cba_fnc_addPerFramehandler;

[_group,_bluforMortarPos] call FUNC(assignWaypoints);