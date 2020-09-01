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

private _pilotGroup = createGroup EAST;
private _passengerGroup = createGroup EAST;

private _veh = createVehicle [selectRandom GVAR(airVehiclePool), _spawnPosition];
_veh setUnloadInCombat [true,true];
private _unitCount = count(fullCrew[_veh,"",true]);
private _currentUnitCount = _unitCount;

_veh addMPEventHandler ["MPHit", {
    [{
        GVAR(counterInProgress) = 0;
    },[],900] call CBA_fnc_waitAndExecute; // 15 minute wait time between tasks so mortars dont get spammed each time they fire
}];

[{
    params ["_args","_idPFH"];
    _args params ["_spawnPosition","_pilotGroup","_currentUnitCount","_veh","_bluforMortarPos","_passengerGroup"];
    _currentUnitCount = _currentUnitCount - 1;
    if (_currentUnitCount == 0) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
        if ((count(fullCrew[_veh,"",false]) == 0)) then {deleteVehicle _veh;};
        // seperate passenger group from initial _pilotGroup
        {
            [_x] joinSilent _passengerGroup;
        } forEach assignedCargo _veh;
        [_passengerGroup, _bluforMortarPos, 0, "SAD","AWARE","YELLOW","NORMAL","LINE","[this] call uksf_aicountermortar_fnc_handleDelete;",[40,50,60]] call CBA_fnc_addWaypoint;
        [_pilotGroup,_bluforMortarPos] call FUNC(assignWaypoints);
    };
    private _unit = _pilotGroup createUnit [selectRandom GVAR(unitPool),getPos _veh,[],2,"NONE"];
    _unit moveInAny _veh;

    _args set [2, _currentUnitCount];
},0.5,[_spawnPosition,_pilotGroup,_currentUnitCount,_veh,_bluforMortarPos,_passengerGroup]] call CBA_fnc_addPerFramehandler;
