#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Reloads every smoke launcher from vehicle magazine cargo or an ACE-loaded crate.
        A dry run reports whether a reload is possible and does not move magazines.

    Parameters:
        0: Vehicle <OBJECT>
        1: Apply the reload <BOOLEAN> (default true)

    Return value:
        Reload happened, or is possible when dry <BOOLEAN>

    Example:
        [_vehicle, false] call uksf_vehicles_fnc_reloadSmoke
*/

params ["_vehicle", ["_apply", true]];

if (!alive _vehicle) exitWith { false };

private _did = false;
private _paths = [[-1]];
_paths append allTurrets [_vehicle, true];
private _cfgWeapons = configFile >> "CfgWeapons";

{
    private _path = _x;
    {
        private _weapon = _x;
        if (_weapon isKindOf ["SmokeLauncher", _cfgWeapons]) then {
            private _compatible = compatibleMagazines _weapon;
            if (_compatible isNotEqualTo []) then {
                private _loaded = magazinesAllTurrets [_vehicle, true] select {
                    _x params ["_mag", "_turret"];
                    _turret isEqualTo _path && { _mag in _compatible }
                };
                private _mag = if (_loaded isEqualTo []) then {
                    _compatible select 0
                } else {
                    _loaded select 0 select 0
                };
                private _full = getNumber (configFile >> "CfgMagazines" >> _mag >> "count");
                if (_full < 1) then { _full = 1 };

                private _cfgMags = getArray (([_vehicle, _path] call BIS_fnc_turretConfig) >> "magazines");
                private _wanted = { _x == _mag } count _cfgMags;
                if (_wanted < 1) then { _wanted = 1 max count _loaded };

                private _ammo = 0;
                { _ammo = _ammo + (_x select 2) } forEach _loaded;
                if (_ammo < _wanted * _full) then {
                    private _sources = [_vehicle];
                    _sources append ((_vehicle getVariable ["ace_cargo_loaded", []]) select {_x isEqualType objNull && {!isNull _x}});
                    {
                    private _source = _x;
                    (getMagazineCargo _source) params ["_cargoMags", "_cargoCounts"];
                    private _cargoIndex = _cargoMags find _mag;
                    if (_cargoIndex < 0) then {
                        private _alt = _compatible findIf { _x in _cargoMags };
                        if (_alt >= 0) then {
                            _mag = _compatible select _alt;
                            _cargoIndex = _cargoMags find _mag;
                            _full = getNumber (configFile >> "CfgMagazines" >> _mag >> "count");
                            if (_full < 1) then { _full = 1 };
                        };
                    };
                    if (_cargoIndex >= 0 && {(_cargoCounts select _cargoIndex) > 0}) then {
                        _did = true;
                        if (_apply) then {
                            private _take = _wanted - floor (_ammo / _full);
                            if (_take < 1) then { _take = 1 };
                            _take = _take min (_cargoCounts select _cargoIndex);
                            _source addMagazineCargoGlobal [_mag, -_take];
                            _vehicle removeMagazinesTurret [_mag, _path];
                            for "_i" from 1 to _take do {
                                _vehicle addMagazineTurret [_mag, _path];
                            };
                            {
                                _x params ["", "", "_left"];
                                if (_left > 0 && {_left < _full}) then {
                                    _vehicle addMagazineTurret [_mag, _path, _left];
                                };
                            } forEach _loaded;
                        };
                        break;
                    };
                    } forEach _sources;
                };
            };
        };
    } forEach (_vehicle weaponsTurret _path);
} forEach _paths;

_did
