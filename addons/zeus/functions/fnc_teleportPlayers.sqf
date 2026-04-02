#include "script_component.hpp"
/*
    Author:
        mharis001, 3Mydlo3 (ZEN), Tim (UKSF fix)

    Description:
        Allows Zeus to select a position or vehicle to teleport players to.
        Overrides zen_context_actions_fnc_teleportPlayers to fix map teleport
        position being wildly incorrect. ZEN's selectPosition derives the world
        position from a stale mousePos variable that is not updated when the map
        is open. This version re-derives the position from getMousePosition when
        the map is visible before performing the teleport.

    Parameter(s):
        N: Objects <OBJECT>

    Return Value:
        None

    Example:
        [_object] call uksf_zeus_fnc_teleportPlayers
*/

private _players = _this select {isPlayer _x};

[_players, {
    params ["_successful", "_players", "_position"];

    if (_successful) then {
        // ZEN's selectPosition passes position derived from a stale mousePos
        // variable when the map is open. Re-derive from actual cursor position.
        if (visibleMap) then {
            private _ctrlMap = findDisplay 312 displayCtrl 50;
            _position = AGLToASL (_ctrlMap posScreenToWorld getMousePosition);
        };

        curatorMouseOver params ["_type", "_entity"];

        if (_type == "OBJECT" && {_entity isKindOf "AllVehicles"} && {!(_entity isKindOf "CAManBase")}) then {
            [_players, _entity] call zen_common_fnc_teleportIntoVehicle;
        } else {
            if (count _players > 1) then {
                // setVehiclePosition places units on surface directly below position
                // Sometimes this will be the second surface below the selected position
                // Adding a small vertical offset allows units to be teleported consistently onto surfaces such as rooftops
                _position = ASLToATL _position vectorAdd [0, 0, 0.1];

                {
                    _x setVehiclePosition [_position, [], 0, "NONE"];
                } forEach _players;
            } else {
                (_players select 0) setPosASL _position;
            };
        };
    };
}, [], localize "STR_ZEN_Context_Actions_TeleportPlayers"] call zen_common_fnc_selectPosition;
