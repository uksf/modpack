#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Reloads smoke launchers from vehicle cargo, ACE-loaded crates,
        or nearby R crates when reload is attempted.
        The server withdraws supplies and directs magazine additions to the turret owner.
        A dry run checks launcher capacity without scanning cargo. Results arrive asynchronously.

    Parameters:
        0: Vehicle <OBJECT>
        1: Apply the reload <BOOLEAN> (default true)
        2: Requesting unit <OBJECT> (optional)
        3: Gun already reloaded <BOOLEAN> (default false)

    Return value:
        Whether the launcher needs ammunition during a dry run <BOOLEAN>

    Example:
        [_vehicle, false] call uksf_vehicles_fnc_reloadSmoke
*/

params ["_vehicle", ["_apply", true], ["_unit", objNull], ["_gunReloaded", false]];

if (!alive _vehicle) exitWith { false };
if (_apply && {!isServer}) exitWith {
    [QGVAR(reloadSmoke), [_vehicle, true, _unit, _gunReloaded]] call CBA_fnc_serverEvent;
    false
};
if (_apply && {_vehicle getVariable [QGVAR(smokeBusy), false]}) exitWith {
    if (!isNull _unit) then {[QGVAR(smokeReloadResult), ["Reload in progress"], _unit] call CBA_fnc_targetEvent};
    false
};

private _did = false;
private _grants = [];
private _paths = [[-1]];
_paths append allTurrets [_vehicle, true];
private _cfgWeapons = configFile >> "CfgWeapons";
private _sources = [_vehicle];
_sources append ((_vehicle getVariable ["ace_cargo_loaded", []]) select {_x isEqualType objNull && {!isNull _x}});
if (_apply) then {
    _sources append ((nearestObjects [_vehicle, [QEGVAR(resupply,rx)], 10]) - _sources);
};

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
                    if (!_apply) exitWith { _did = true };
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
                        if (_cargoIndex >= 0 && {(_cargoCounts select _cargoIndex) > 0}) exitWith {
                            _did = true;
                            if (_apply) then {
                                private _take = _wanted - floor (_ammo / _full);
                                if (_take < 1) then { _take = 1 };
                                _take = _take min (_cargoCounts select _cargoIndex);
                                _source addMagazineCargoGlobal [_mag, -_take];
                                _grants pushBack [_mag, _path, _take];
                            };
                        };
                    } forEach _sources;
                };
            };
        };
    } forEach (_vehicle weaponsTurret _path);
} forEach _paths;

if (_apply && {_did}) then {
    _vehicle setVariable [QGVAR(smokeBusy), true];
    [{
        params ["_vehicle"];
        _vehicle setVariable [QGVAR(smokeBusy), false];
    }, [_vehicle], 2] call CBA_fnc_waitAndExecute;
    {
        _x params ["_magazine", "_path", "_count"];
        [QGVAR(addSmokeMagazine), [_vehicle, _magazine, _path, _count], _vehicle turretOwner _path] call CBA_fnc_ownerEvent;
    } forEach _grants;
    if (!isNull _unit) then {[QGVAR(smokeReloadResult), ["Smoke ammunition refilled."], _unit] call CBA_fnc_targetEvent};
};
if (_apply && {!_did} && {!_gunReloaded} && {!isNull _unit}) then {
    [QGVAR(smokeReloadResult), ["No smoke ammunition found within 10 metres."], _unit] call CBA_fnc_targetEvent;
};
if (_apply) exitWith {false};
_did
