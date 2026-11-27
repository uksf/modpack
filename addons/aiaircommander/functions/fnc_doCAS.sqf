#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        creates a bomb at terrain level based on pilot POS and some randomisation

    Parameters:
        0: Plane <GROUP>

    Return value:
        Nothing

    Example:
        [_vehicle] call uksf_aiaircommander_fnc_doCAS
*/
params ["_vehicle"];

private _bombPos = _vehicle getPos [50 + random 50, random 360];
[{
    params ["_args", "_idPFH"];
    _args params ["_vehicle", "_bombPos", "_checkCount"];

    if (_checkCount > 3) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
    };

    private _nearbyFriendlies = _bombPos nearEntities ["O_Soldier_base_F", 100];
    if (_nearbyFriendlies isEqualTo []) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
        [{createVehicle ["Bomb_04_F", _this, [], 20, "NONE"]}, _bombPos, 5] call CBA_fnc_waitAndExecute;
    };

    _args set [2, _checkCount + 1];
}, 1, [_vehicle, _bombPos, 0]] call CBA_fnc_addPerFrameHandler;

