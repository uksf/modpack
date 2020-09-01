#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Create an AA vehicle

    Parameters:
        None

    Return value:
        Nothing
*/

params ["_emptyLocation"];

private _cargo = [];
private _veh = createVehicle [selectRandom EGVAR(gear,gearVehAA), (selectRandom GVAR(aaSpawns))];
private _group = createGroup EAST;

private _vehCrewPositions = count(fullCrew[_veh,"",true]);
for "_i" from 1 to _vehCrewPositions do {
    _cargo pushBack (selectRandom EGVAR(gear,gearCrew));
};

private _crew = [[0,0,0],EAST,_cargo] call BIS_fnc_spawnGroup;
{_x moveInAny _veh; [_x] joinSilent _group} forEach units _crew;

[_group,_emptyLocation,50,"MOVE","SAFE","YELLOW","NORMAL","","(vehicle this) setFuel 0; (group this) setBehaviour 'AWARE'"] call cba_fnc_addWaypoint;

