#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Create a jet

    Parameters:
        0: _responseType <NUMBER>
        
    Return value:
        Nothing
*/

// Plane

private _cargo = [];

private _veh = createVehicle [selectRandom EGVAR(gear,gearPlane), (selectRandom GVAR(airSpawns))];
private _group = createGroup EAST;

private _vehPosition = count(fullCrew[_veh,"",true]);
for "_i" from 1 to _vehPosition do {
    _cargo pushBack (selectRandom EGVAR(gear,gearJetPilot));
};

private _crew = [[0,0,0],EAST,_cargo] call BIS_fnc_spawnGroup;

{_x moveInAny _veh; [_x] joinSilent _group} forEach units _crew;

// [_group] call EFUNC(gear,addGear);

// EGVAR(resupply,vehPoolCurrent) = EGVAR(resupply,vehPoolCurrent) - 1;

_group



