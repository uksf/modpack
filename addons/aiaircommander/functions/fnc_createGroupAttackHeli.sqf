#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Create attack heli group

    Parameters:
        None

    Return value:
        created group and their spawn position
*/
private _cargo = [];
private _spawnBuilding = selectRandom GVAR(heliLocations);
if (isNull _spawnBuilding) exitWith {call FUNC(selectMission)};
private _helipads = nearestObjects [_spawnBuilding, ["Land_HelipadSquare_F","Land_HelipadCircle_F"],50,true];
private _spawnPosition = _spawnBuilding getPos [20,random 360];

if (count _helipads != 0) then {
    _spawnPosition = getPos (selectRandom _helipads);
};

private _veh = createVehicle [selectRandom EGVAR(gear,gearAttackHeli), _spawnPosition];
private _group = createGroup EAST;
private _vehPositionDriver = count(fullCrew[_veh,"driver",true]);
private _vehPositionCommander = count(fullCrew[_veh,"commander",true]);
private _vehPositionTurret = count(fullCrew[_veh,"turret",true]);
private _vehPositionGunner = count(fullCrew[_veh,"gunner",true]);
private _vehPositions = _vehPositionDriver + _vehPositionCommander + _vehPositionTurret + _vehPositionGunner;

for "_i" from 1 to _vehPositions do {
    _cargo pushBack (selectRandom EGVAR(gear,gearHeliPilot));
};

private _crew = [[0,0,0],EAST,_cargo] call BIS_fnc_spawnGroup;

{_x moveInAny _veh; [_x] joinSilent _group} forEach units _crew;

_veh flyInHeight 300;

_group


