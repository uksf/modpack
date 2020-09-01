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
*/
params ["_vehicle"];

private _bombPos = _vehicle getPos [50 + random 50, random 360];
private _checkCount = 0;

[{
    params ["_args", "_idPFH"];
    _args params ["_vehicle", "_bombPos", "_checkCount"];

    if (_checkCount > 3) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
    };

    private _nearbyFriendlies = _bombPos nearEntities ["O_Soldier_base_F", 100];
    if (_nearbyFriendlies isEqualTo []) exitWith {
        [{createVehicle ["Bomb_04_F", _this, [], 20, "NONE"]}, _bombPos, 5] call CBA_fnc_waitAndExecute;
    };

    _this set [2, _checkCount + 1];
}, 1, [_vehicle, _bombPos]] call CBA_fnc_addPerFrameHandler;

// TODO: Would like this to actually drop a bomb from the plane and add possibility for more weapon usage.
// Could use the ZEN cas functionality (might have to just copy the weapon firing routines as that's designed around a zeus module)
