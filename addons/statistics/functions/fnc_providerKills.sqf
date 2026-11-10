#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Kills provider setup. Installs an EntityKilled mission event handler on the server
        to capture every entity death.

        The credited killer is the instigator when that person is a player, otherwise the
        killer. fnc_creditedShooter resolves a UAV crew or UAV vehicle to the player in
        the firing role. Zeus remote control is not credited.

        A UAV kill prefers the fire-time controller stored on lastHit when that hit is
        marked as a UAV shot and is less than 5 seconds old. The stamp is written at
        impact, so a player who leaves the terminal between launch and impact is still
        the killer. Older stamps are ignored so a later UAV death does not inherit an
        earlier hit.

        Respawn self-kills (victim equals killer, instigator null) are skipped. They are
        the engine deleting a spawn body on join, redeploy, or relog.

        When the engine attacker is not a credited player, ACE medical's
        ace_medical_lastInstigator, then ace_medical_lastDamageSource, supplies chain
        reaction attribution (explosion, fire, cookoff). Those names are ACE literals,
        not uksf variables. That path is indirect. Zeus puppets are still excluded.

        Weapon and ammo come from lastHit only when its shooter uid matches the killer.
        Assist correlation is API-side, joining combatDamage to kills on targetNetId.

    Parameters:
        None

    Return Value:
        None

    Example:
        call uksf_statistics_fnc_providerKills
*/
addMissionEventHandler ["EntityKilled", {
    params ["_victim", "_killer", "_instigator"];

    if (isNull _victim) exitWith {};
    if (_killer isEqualTo _victim && {isNull _instigator}) exitWith {};

    private _attacker = if (!isNull _instigator) then {_instigator} else {_killer};
    private _killerUid = "";
    private _indirect = false;
    private _uavKillWindow = 5;

    private _uavActor = (!isNull _attacker) && {unitIsUAV _attacker || {unitIsUAV vehicle _attacker}};
    if (_uavActor) then {
        private _firedHit = _victim getVariable [QGVAR(lastHit), []];
        if (count _firedHit >= 5) then {
            _firedHit params ["", "", "_firedShooterUid", "_firedTime", "_firedUav"];
            if (_firedUav && {_firedShooterUid isNotEqualTo ""} && {time - _firedTime < _uavKillWindow}) then {
                _killerUid = _firedShooterUid;
            };
        };
    };

    if (_killerUid isEqualTo "") then {
        private _credited = [_attacker] call FUNC(creditedShooter);
        if (!isNull _credited) then {
            _killerUid = getPlayerUID _credited;
        };
    };

    if (_killerUid isEqualTo "") then {
        private _aceInstigator = _victim getVariable ["ace_medical_lastInstigator", objNull];
        if (isNull _aceInstigator) then {
            _aceInstigator = _victim getVariable ["ace_medical_lastDamageSource", objNull];
        };
        private _credited = [_aceInstigator] call FUNC(creditedShooter);
        if (!isNull _credited) then {
            _killerUid = getPlayerUID _credited;
            _indirect = true;
        };
    };

    if (_killerUid isEqualTo "") exitWith {};

    private _targetType = if (_victim isKindOf "CAManBase") then {
        "infantry"
    } else {
        if (_victim isKindOf "LandVehicle" || {_victim isKindOf "Air"} || {_victim isKindOf "Ship"}) then {
            "vehicle"
        } else {
            if (_victim isKindOf "Building") then {
                "structure"
            } else {
                ""
            };
        };
    };

    if (_targetType isEqualTo "") exitWith {};

    private _sideIndex = getNumber (configOf _victim >> "side");
    private _sides = [west, east, resistance, civilian];
    private _targetSide = if (_sideIndex >= 0 && {_sideIndex < count _sides}) then {
        str (_sides select _sideIndex)
    } else {
        "unknown"
    };

    private _weapon = "";
    private _ammo = "";
    private _lastHit = _victim getVariable [QGVAR(lastHit), []];
    if (_lastHit isNotEqualTo []) then {
        _lastHit params ["_hitWeapon", "_hitAmmo", "_hitShooterUid"];
        if (_hitShooterUid isEqualTo _killerUid) then {
            _weapon = _hitWeapon;
            _ammo = _hitAmmo;
        };
    };

    private _event = createHashMapFromArray [
        ["type", "kill"],
        ["killerUid", _killerUid],
        ["indirect", _indirect],
        ["targetNetId", netId _victim],
        ["targetClassname", typeOf _victim],
        ["targetSide", _targetSide],
        ["targetType", _targetType],
        ["weapon", _weapon],
        ["ammo", _ammo]
    ];

    [_event] call FUNC(addEvent);
}];
