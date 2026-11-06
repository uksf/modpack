#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Delivers a validated ammunition item or starts carrying a returned shell.

    Parameters:
        0: Recipient <OBJECT>
        1: Item or shell <STRING or OBJECT>

    Return value:
        Nothing

    Example:
        [_player, _shell] remoteExecCall ["uksf_weapons_fnc_l118Deliver", _player]
*/
params ["_player", "_delivery"];
if (!local _player) exitWith {};
if (_delivery isEqualType "") exitWith {
    if (_player canAdd _delivery) exitWith {_player addItem _delivery};
    private _holder = createVehicle ["GroundWeaponHolder", getPosATL _player, [], 0, "CAN_COLLIDE"];
    if (isClass (configFile >> "CfgMagazines" >> _delivery)) then {_holder addMagazineCargoGlobal [_delivery, 1]} else {_holder addItemCargoGlobal [_delivery, 1]};
};
if (_delivery isEqualType objNull && {!isNull _delivery}) then {[_player, _delivery] call ace_dragging_fnc_startCarry};
