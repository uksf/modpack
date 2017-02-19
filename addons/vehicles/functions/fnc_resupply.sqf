/*
    Author:
        Tim Beswick

    Description:
        Resupply from inventory

    Parameter(s):
        0: Vehicle <OBJECT>

    Return Value:
        None
*/
#include "script_component.hpp"

params ["_vehicle"];

private _resupply = false;
if ((alive player) && {alive _vehicle} && {(player isEqualTo commander _vehicle) || {player isEqualTo gunner _vehicle}}) then {
    {
        if ((_x select 0) isEqualTo player) then {
            private _turret = _x select 3;            
            if (((weaponState [_vehicle, _turret]) select 4) < 1) then {
                private _weapon = (_vehicle weaponsTurret _turret) select 0;
                private _magazineNames = getArray(configFile >> "CfgWeapons" >> _weapon >> "magazines");            
                private _magazines = (getMagazineCargo _vehicle) select 0;
                private _magName = "";
                {
                    if (_x in _magazines) exitWith { 
                        _magName = _x;
                    };
                    false;
                } count _magazineNames;
                
                if (_magName != "") exitWith {
                    [_vehicle, _turret, _magName] call FUNC(addMagazine);
                    _resupply = true;
                };
            };
        };
        false;
    } count (fullCrew _vehicle);    
};

_resupply
