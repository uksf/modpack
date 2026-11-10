#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Shots and hits provider setup. Runs on every machine, because Fired is local
        to the shooter. Listens to ACE player fired events, and to non-player vehicle
        fired events when the vehicle is a UAV.

        The credited player is fnc_creditedShooter at the moment of firing: the
        player on foot or in the seat, or the UAVControl role that owns the turret
        (DRIVER for turret [-1], GUNNER otherwise). Zeus remote control is not
        recorded, so client sync cannot stamp the curator.

        Each shot is recorded with that player's uid, weapon, ammo, magazine, fire
        mode, and fired position. Ammo classname is what the API buckets as munitions.
        Each projectile is tagged with shotId, weapon, ammo, fired position, shooter
        uid, and whether the shot was from a UAV. HitPart and HitExplosion on that
        projectile emit the hit on the same machine.

        lastHit on the victim is public, so the server kill handler can read it:
        [weapon, ammo, shooterUid, mission time, uav shot].

    Parameters:
        None

    Return Value:
        None

    Example:
        call uksf_statistics_fnc_providerShots
*/
GVAR(shotCounter) = 0;
GVAR(shotProducer) = format ["%1_%2_%3", clientOwner, (systemTimeUTC apply {str _x}) joinString "-", floor random 1000000000];

GVAR(getTargetType) = {
    params ["_entity"];
    if (_entity isKindOf "CAManBase") exitWith {"infantry"};
    if (_entity isKindOf "LandVehicle" || {_entity isKindOf "Air"} || {_entity isKindOf "Ship"}) exitWith {"vehicle"};
    if (_entity isKindOf "Building") exitWith {"structure"};
    "unknown"
};

GVAR(getBodyPart) = {
    params ["_components"];
    private _componentsLower = _components apply {toLower _x};
    if (_componentsLower findIf {_x find "head" != -1 || {_x find "face" != -1} || {_x find "neck" != -1}} != -1) exitWith {"head"};
    if (_componentsLower findIf {_x find "leg" != -1 || {_x find "foot" != -1}} != -1) exitWith {"legs"};
    if (_componentsLower findIf {_x find "hand" != -1 || {_x find "arm" != -1}} != -1) exitWith {"arms"};
    "torso"
};

GVAR(handleFired) = {
    if (GVAR(killswitch)) exitWith {};
    params ["_unit", "_weapon", "_muzzle", "_fireMode", "_ammo", "_magazine", "_projectile"];

    private _shooter = [_unit, _weapon] call FUNC(creditedShooter);
    if (isNull _shooter) exitWith {};

    private _shooterUid = getPlayerUID _shooter;
    if (_shooterUid isEqualTo "") exitWith {};

    GVAR(shotCounter) = GVAR(shotCounter) + 1;
    private _shotId = format ["%1_%2_%3", _shooterUid, GVAR(shotProducer), GVAR(shotCounter)];
    private _firedPosition = getPosASL _unit;
    private _category = [_ammo] call FUNC(getAmmoCategory);
    private _uavShot = unitIsUAV _unit || {unitIsUAV vehicle _unit};

    if (!isNull _projectile) then {
        _projectile setVariable [QGVAR(shotId), _shotId];
        _projectile setVariable [QGVAR(weapon), _weapon];
        _projectile setVariable [QGVAR(firedPosition), _firedPosition];
        _projectile setVariable [QGVAR(ammo), _ammo];
        _projectile setVariable [QGVAR(category), _category];
        _projectile setVariable [QGVAR(shooterUid), _shooterUid];
        _projectile setVariable [QGVAR(uavShot), _uavShot];

        _projectile addEventHandler ["HitPart", {
            if (GVAR(killswitch)) exitWith {};
            params ["_projectile", "_hitEntity", "_projectileOwner", "_position", "_velocity", "_normal", "_components", "_radius", "_surfaceType"];

            if (isNull _hitEntity) exitWith {};
            if (_hitEntity isEqualTo _projectileOwner) exitWith {};

            private _targetType = [_hitEntity] call GVAR(getTargetType);
            if (_targetType isEqualTo "unknown") exitWith {};

            private _projectileShotId = _projectile getVariable [QGVAR(shotId), ""];
            private _projectileWeapon = _projectile getVariable [QGVAR(weapon), ""];
            private _projectileAmmo = _projectile getVariable [QGVAR(ammo), ""];
            private _projectileCategory = _projectile getVariable [QGVAR(category), "other"];
            private _projectileShooterUid = _projectile getVariable [QGVAR(shooterUid), ""];
            private _projectileFiredPosition = _projectile getVariable [QGVAR(firedPosition), []];
            private _projectileUavShot = _projectile getVariable [QGVAR(uavShot), false];

            private _bodyPart = "";
            if (_targetType isEqualTo "infantry") then {
                _bodyPart = [_components] call GVAR(getBodyPart);
            };

            private _distance2D = 0;
            private _distance3D = 0;
            if (_projectileFiredPosition isNotEqualTo []) then {
                _distance2D = round (_projectileFiredPosition distance2D _position);
                _distance3D = round (_projectileFiredPosition vectorDistance _position);
            };

            _hitEntity setVariable [QGVAR(lastHit), [_projectileWeapon, _projectileAmmo, _projectileShooterUid, time, _projectileUavShot], true];

            [createHashMapFromArray [
                ["type", "hit"],
                ["uid", _projectileShooterUid],
                ["shotId", _projectileShotId],
                ["weapon", _projectileWeapon],
                ["ammo", _projectileAmmo],
                ["category", _projectileCategory],
                ["targetClassname", typeOf _hitEntity],
                ["targetType", _targetType],
                ["bodyPart", _bodyPart],
                ["distance2D", _distance2D],
                ["distance3D", _distance3D]
            ]] call FUNC(addEvent);
        }];

        _projectile addEventHandler ["HitExplosion", {
            if (GVAR(killswitch)) exitWith {};
            params ["_projectile", "_hitEntity", "_projectileOwner", "_hitSelections"];

            if (isNull _hitEntity) exitWith {};
            if (_hitEntity isEqualTo _projectileOwner) exitWith {};

            private _targetType = [_hitEntity] call GVAR(getTargetType);
            if (_targetType isEqualTo "unknown") exitWith {};

            private _projectileShotId = _projectile getVariable [QGVAR(shotId), ""];
            private _projectileWeapon = _projectile getVariable [QGVAR(weapon), ""];
            private _projectileAmmo = _projectile getVariable [QGVAR(ammo), ""];
            private _projectileCategory = _projectile getVariable [QGVAR(category), "other"];
            private _projectileShooterUid = _projectile getVariable [QGVAR(shooterUid), ""];
            private _projectileFiredPosition = _projectile getVariable [QGVAR(firedPosition), []];
            private _projectileUavShot = _projectile getVariable [QGVAR(uavShot), false];

            private _impactPosition = if (count _hitSelections > 0) then {_hitSelections#0#0} else {getPosASL _projectile};
            private _distance2D = 0;
            private _distance3D = 0;
            if (_projectileFiredPosition isNotEqualTo []) then {
                _distance2D = round (_projectileFiredPosition distance2D _impactPosition);
                _distance3D = round (_projectileFiredPosition vectorDistance _impactPosition);
            };

            _hitEntity setVariable [QGVAR(lastHit), [_projectileWeapon, _projectileAmmo, _projectileShooterUid, time, _projectileUavShot], true];

            [createHashMapFromArray [
                ["type", "hit"],
                ["uid", _projectileShooterUid],
                ["shotId", _projectileShotId],
                ["weapon", _projectileWeapon],
                ["ammo", _projectileAmmo],
                ["category", _projectileCategory],
                ["targetClassname", typeOf _hitEntity],
                ["targetType", _targetType],
                ["bodyPart", ""],
                ["distance2D", _distance2D],
                ["distance3D", _distance3D]
            ]] call FUNC(addEvent);
        }];
    };

    [createHashMapFromArray [
        ["type", "shot"],
        ["uid", _shooterUid],
        ["shotId", _shotId],
        ["weapon", _weapon],
        ["ammo", _ammo],
        ["category", _category],
        ["magazine", _magazine],
        ["fireMode", _fireMode],
        ["firedPosition", _firedPosition]
    ]] call FUNC(addEvent);
};

["ace_firedPlayer", GVAR(handleFired)] call CBA_fnc_addEventHandler;
["ace_firedPlayerVehicle", GVAR(handleFired)] call CBA_fnc_addEventHandler;
["ace_firedNonPlayerVehicle", {
    params ["_unit"];
    if (!unitIsUAV _unit) exitWith {};
    _this call GVAR(handleFired);
}] call CBA_fnc_addEventHandler;
