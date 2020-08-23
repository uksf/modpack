#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        creates a bomb at terrain level based on pilot POS and some corrections

    Parameters:
        0: _group <GROUP>
        
    Return value:
        Nothing
*/
params ["_vehicle"];

private _checkCount = 0;
private _bombPos = _vehicle getPos [random[50,75,100],random 360];
private _nearbyFriendlies = [];

private _fnc_getNearEnemies = {
    params ["_checkCount","_bombPos","_vehicle"];
    private _nearbyFriendlies = _bombPos nearEntities ["O_Soldier_base_F",100];
    
    if (count _nearbyFriendlies == 0) then {
        [{
            params ["_bombPos"];
            createVehicle ["Bomb_04_F",_bombPos,[],20,"NONE"];
        },[_bombPos],5] call cba_fnc_waitAndExecute;        
    } else {
        _checkCount = _checkCount + 1;
        if (_checkCount < 3) exitWith {
            [_checkCount,_bombPos,_vehicle] call _fnc_getNearEnemies;
        };
    };
};

[_checkCount,_bombPos,_vehicle] call _fnc_getNearEnemies;

