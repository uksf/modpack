#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Loads player re-deploy data on first respawn

    Parameter(s):
        None

    Return Value:
        None

    Example:
        [_position, _vehicleState, _direction, _animation, _loadout, _damage, _aceStates, _earplugs, _attached, _radios, _diveState] call uksf_persistence_fnc_loadRedeployData
*/

TRACE_1("First respawn",GVAR(data));

if (isNil QGVAR(data) || {GVAR(data) isEqualTo []}) exitWith {
    WARNING("No redeploy data");
};

// Convert API hashmap format to positional array for downstream compatibility
if (GVAR(data) isEqualType createHashMap) then {
    private _d = GVAR(data);

    // vehicleState: {"vehicleId": ..., "role": ..., "index": ...} → [vehicleId, role, index]
    private _vsHm = _d getOrDefault ["vehicleState", createHashMap];
    private _vehicleState = if (_vsHm isEqualType createHashMap && count _vsHm > 0) then {
        [_vsHm getOrDefault ["vehicleId", ""], _vsHm getOrDefault ["role", ""], _vsHm getOrDefault ["index", -1]]
    } else {
        ["", "", -1]
    };

    // loadout — convert hashmap back to setUnitLoadout positional array
    private _convertWeaponSlotBack = {
        params ["_slot"];
        if (count _slot == 0) exitWith { [] };
        if !(_slot isEqualType createHashMap) exitWith { _slot };
        private _pm = _slot getOrDefault ["primaryMagazine", createHashMap];
        private _sm = _slot getOrDefault ["secondaryMagazine", createHashMap];
        [
            _slot getOrDefault ["weapon", ""],
            _slot getOrDefault ["muzzle", ""],
            _slot getOrDefault ["pointer", ""],
            _slot getOrDefault ["optic", ""],
            if (_pm isEqualType createHashMap && count _pm > 0) then { [_pm getOrDefault ["className", ""], _pm getOrDefault ["ammo", 0]] } else { [] },
            if (_sm isEqualType createHashMap && count _sm > 0) then { [_sm getOrDefault ["className", ""], _sm getOrDefault ["ammo", 0]] } else { [] },
            _slot getOrDefault ["bipod", ""]
        ]
    };

    private _convertContainerSlotBack = {
        params ["_slot"];
        if (count _slot == 0) exitWith { [] };
        if !(_slot isEqualType createHashMap) exitWith { _slot };
        [
            _slot getOrDefault ["className", ""],
            (_slot getOrDefault ["items", []]) apply {
                if (_x isEqualType createHashMap) then {
                    private _base = [_x getOrDefault ["className", ""], _x getOrDefault ["count", 0]];
                    private _ammo = _x getOrDefault ["ammo", nil];
                    if (!isNil "_ammo") then { _base pushBack _ammo };
                    _base
                } else { _x }
            }
        ]
    };

    private _convertLinkedItemsBack = {
        params ["_items"];
        if (count _items == 0) exitWith { ["","","","","",""] };
        if !(_items isEqualType createHashMap) exitWith { _items };
        [
            _items getOrDefault ["map", ""],
            _items getOrDefault ["gps", ""],
            _items getOrDefault ["radio", ""],
            _items getOrDefault ["compass", ""],
            _items getOrDefault ["watch", ""],
            _items getOrDefault ["nvg", ""]
        ]
    };

    private _loadoutHm = _d getOrDefault ["loadout", createHashMap];
    private _loadout = if (_loadoutHm isEqualType createHashMap && count _loadoutHm > 0) then {
        [
            [_loadoutHm getOrDefault ["primaryWeapon", createHashMap]] call _convertWeaponSlotBack,
            [_loadoutHm getOrDefault ["secondaryWeapon", createHashMap]] call _convertWeaponSlotBack,
            [_loadoutHm getOrDefault ["handgun", createHashMap]] call _convertWeaponSlotBack,
            [_loadoutHm getOrDefault ["uniform", createHashMap]] call _convertContainerSlotBack,
            [_loadoutHm getOrDefault ["vest", createHashMap]] call _convertContainerSlotBack,
            [_loadoutHm getOrDefault ["backpack", createHashMap]] call _convertContainerSlotBack,
            _loadoutHm getOrDefault ["headgear", ""],
            _loadoutHm getOrDefault ["facewear", ""],
            [_loadoutHm getOrDefault ["binoculars", createHashMap]] call _convertWeaponSlotBack,
            [_loadoutHm getOrDefault ["linkedItems", createHashMap]] call _convertLinkedItemsBack
        ]
    } else {
        _d getOrDefault ["loadout", []]
    };

    // radios: [{"type": ..., "channel": ..., "volume": ..., "spatial": ..., "pttIndex": ...}] → [[type, channel, volume, spatial, pttIndex]]
    private _radios = (_d getOrDefault ["radios", []]) apply {
        if (_x isEqualType createHashMap) then {
            [_x getOrDefault ["type", ""], _x getOrDefault ["channel", 0], _x getOrDefault ["volume", 1], _x getOrDefault ["spatial", "CENTER"], _x getOrDefault ["pttIndex", 0]]
        } else { _x }
    };

    // diveState: {"isDiving": ...} → [isDiving]
    private _dsHm = _d getOrDefault ["diveState", createHashMap];
    private _diveState = if (_dsHm isEqualType createHashMap && count _dsHm > 0) then {
        [_dsHm getOrDefault ["isDiving", false]]
    } else {
        [false]
    };

    GVAR(data) = [
        _d getOrDefault ["position", [0,0,0]],
        _vehicleState,
        _d getOrDefault ["direction", 0],
        _d getOrDefault ["animation", ""],
        _loadout,
        _d getOrDefault ["damage", 0],
        _d getOrDefault ["aceMedical", createHashMap],
        _d getOrDefault ["earplugs", false],
        _d getOrDefault ["attachedItems", []],
        _radios,
        _diveState
    ]
};

GVAR(data) params ["_position", "_vehicleState", "_direction", "_animation", "_loadout", "_damage", "_aceStates", "_earplugs", "_attached", "_radios", ["_diveState", [false]]];

private _playerPosition = getPosASL player;
if (GVAR(selectedRespawn) == "") then { // TODO: Doesn't handle objects
    WARNING("No respawn selected");
    private _respawnMarkers = allMapMarkers select {"respawn_west_" in _x};
    if (_respawnMarkers isEqualTo []) exitWith {
        WARNING("No respawn markers found");
    };
    _respawnMarkers = _respawnMarkers apply {[_playerPosition distance (markerPos _x), _x]};
    _respawnMarkers sort true;

    GVAR(selectedRespawn) = _respawnMarkers#0#1;
};

if !(isNil QGVAR(respawn)) then {
    [{deleteMarkerLocal GVAR(respawn)}, [], 1] call CBA_fnc_waitAndExecute;
};

TRACE_1("Respawned at",GVAR(selectedRespawn));
if (GVAR(selectedRespawn) != RESPAWN_MARKER && (_position distance _playerPosition) > 2) exitWith {
    WARNING("Different respawn selected");
};

DEBUG("Respawn is redeploy");

player setUnitLoadout _loadout;
player setDamage _damage;

player setVariable ["ACE_hasEarPlugsIn", _earplugs, true];
[true] call ace_hearing_fnc_updateVolume;
[] call ace_hearing_fnc_updateHearingProtection;
{[player, player, [_x], true] call ace_attach_fnc_attach} forEach _attached;

[{call EFUNC(radios,deserializeRadios)}, [_radios], 2] call CBA_fnc_waitAndExecute;
[_diveState] call EFUNC(diving,deserialiseState);
[player, _aceStates] call ace_medical_fnc_deserializeState;

_vehicleState params ["_vehicleId"];
if (_vehicleId != "") exitWith {
    [QGVAR(onPersistentVehicleExists), {
        params ["_vehicle", "_vehicleId", "_role", "_index"];
        [_thisType, _thisId] call CBA_fnc_removeEventHandler;

        if (isNull _vehicle) exitWith {};

        switch (_role) do {
            case "driver": {player moveInDriver _vehicle};
            case "gunner": {player moveInGunner _vehicle};
            case "commander": {player moveInCommander _vehicle};
            case "turret": {player moveInTurret [_vehicle, _index]};
            default {player moveInCargo [_vehicle, _index]};
        };

        if (objectParent player != _vehicle) then {
            player moveInCargo _vehicle;
        };
    }] call CBA_fnc_addEventHandlerArgs;
    [QGVAR(checkPersistentVehicleExists), [_vehicleState, player]] call CBA_fnc_serverEvent;
};

[{
    params ["_position", "_direction"];

    if (((getPosASL player) distance _position) <= 1 && (round (getDir player)) == _direction) exitWith {
        true
    };

    player setDir _direction;
    player setPosASL _position;

    false
}, {}, [_position, round _direction], 0.5] call CBA_fnc_waitUntilAndExecute;

// Don't set animation if diving, does not work
if (_diveState#0 && _position#2 < 0) exitWith {};

[{
    params ["_animation"];

    if (animationState player == _animation) exitWith {
        true
    };

    player switchMove _animation;

    false
}, {}, [_animation], 0.5] call CBA_fnc_waitUntilAndExecute;
