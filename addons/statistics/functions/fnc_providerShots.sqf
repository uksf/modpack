#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Shots and hits provider setup. Listens to ACE fired events to capture every
        round fired by the local player, both on foot and in vehicles.

        Each shot is recorded with weapon, ammo, magazine, fire mode, and fired position.
        Each projectile is tagged with shotId, weapon, and fired position, then has
        HitPart (Projectile) and HitExplosion event handlers attached.

        When the projectile hits something, the hit event is generated on the same
        client with accurate weapon, distance, and target data — no cross-machine
        correlation needed. HitPart covers direct hits, HitExplosion covers splash.

    Parameters:
        None

    Return Value:
        None

    Example:
        call uksf_statistics_fnc_providerShots
*/
GVAR(shotCounter) = 0;

// Determines target type from an entity object
GVAR(getTargetType) = {
    params ["_entity"];
    if (_entity isKindOf "CAManBase") exitWith {"infantry"};
    if (_entity isKindOf "LandVehicle" || {_entity isKindOf "Air"} || {_entity isKindOf "Ship"}) exitWith {"vehicle"};
    if (_entity isKindOf "StaticWeapon") exitWith {"static"};
    "unknown"
};

// Determines body part from hit components (for infantry targets)
GVAR(getBodyPart) = {
    params ["_components"];
    private _componentsLower = _components apply {toLower _x};
    if (_componentsLower findIf {_x find "head" != -1 || {_x find "face" != -1} || {_x find "neck" != -1}} != -1) exitWith {"head"};
    if (_componentsLower findIf {_x find "leg" != -1 || {_x find "foot" != -1}} != -1) exitWith {"legs"};
    if (_componentsLower findIf {_x find "hand" != -1 || {_x find "arm" != -1}} != -1) exitWith {"arms"};
    "torso"
};

private _handleFired = {
    if (GVAR(killswitch)) exitWith {};
    params ["_unit", "_weapon", "_muzzle", "_mode", "_ammo", "_magazine", "_projectile"];
    private _startTime = diag_tickTime;

    GVAR(shotCounter) = GVAR(shotCounter) + 1;
    private _shotId = format ["%1_%2", getPlayerUID _unit, GVAR(shotCounter)];
    private _firedPosition = getPosASL _unit;

    if (!isNull _projectile) then {
        _projectile setVariable [QGVAR(shotId), _shotId];
        _projectile setVariable [QGVAR(weapon), _weapon];
        _projectile setVariable [QGVAR(firedPosition), _firedPosition];

        // HitPart (Projectile) — fires on this client for direct hits on any surface
        _projectile addEventHandler ["HitPart", {
            if (GVAR(killswitch)) exitWith {};
            params ["_projectile", "_hitEntity", "_projectileOwner", "_position", "_velocity", "_normal", "_components", "_radius", "_surfaceType"];

            if (isNull _hitEntity) exitWith {};
            if (_hitEntity isEqualTo _projectileOwner) exitWith {};

            private _hitStartTime = diag_tickTime;

            private _targetType = [_hitEntity] call GVAR(getTargetType);
            if (_targetType isEqualTo "unknown") exitWith {};

            private _projectileShotId = _projectile getVariable [QGVAR(shotId), ""];
            private _projectileWeapon = _projectile getVariable [QGVAR(weapon), ""];
            private _projectileFiredPosition = _projectile getVariable [QGVAR(firedPosition), []];

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

            [createHashMapFromArray [
                ["type", "hit"],
                ["shotId", _projectileShotId],
                ["weapon", _projectileWeapon],
                ["targetClassname", typeOf _hitEntity],
                ["targetType", _targetType],
                ["bodyPart", _bodyPart],
                ["distance2D", _distance2D],
                ["distance3D", _distance3D]
            ]] call FUNC(addEvent);

            ["hits", _hitStartTime] call FUNC(addProviderTiming);
        }];

        // HitExplosion — fires on this client for splash damage
        _projectile addEventHandler ["HitExplosion", {
            if (GVAR(killswitch)) exitWith {};
            params ["_projectile", "_hitEntity", "_projectileOwner", "_hitSelections"];

            if (isNull _hitEntity) exitWith {};
            if (_hitEntity isEqualTo _projectileOwner) exitWith {};

            private _hitStartTime = diag_tickTime;

            private _targetType = [_hitEntity] call GVAR(getTargetType);
            if (_targetType isEqualTo "unknown") exitWith {};

            private _projectileShotId = _projectile getVariable [QGVAR(shotId), ""];
            private _projectileWeapon = _projectile getVariable [QGVAR(weapon), ""];
            private _projectileFiredPosition = _projectile getVariable [QGVAR(firedPosition), []];

            private _impactPosition = if (count _hitSelections > 0) then {_hitSelections#0#0} else {getPosASL _projectile};
            private _distance2D = 0;
            private _distance3D = 0;
            if (_projectileFiredPosition isNotEqualTo []) then {
                _distance2D = round (_projectileFiredPosition distance2D _impactPosition);
                _distance3D = round (_projectileFiredPosition vectorDistance _impactPosition);
            };

            [createHashMapFromArray [
                ["type", "hit"],
                ["shotId", _projectileShotId],
                ["weapon", _projectileWeapon],
                ["targetClassname", typeOf _hitEntity],
                ["targetType", _targetType],
                ["bodyPart", ""],
                ["distance2D", _distance2D],
                ["distance3D", _distance3D]
            ]] call FUNC(addEvent);

            ["hits", _hitStartTime] call FUNC(addProviderTiming);
        }];
    };

    [createHashMapFromArray [
        ["type", "shot"],
        ["shotId", _shotId],
        ["weapon", _weapon],
        ["ammo", _ammo],
        ["magazine", _magazine],
        ["fireMode", _mode],
        ["firedPosition", _firedPosition]
    ]] call FUNC(addEvent);

    ["shots", _startTime] call FUNC(addProviderTiming);
};

["ace_firedPlayer", _handleFired] call CBA_fnc_addEventHandler;
["ace_firedPlayerVehicle", _handleFired] call CBA_fnc_addEventHandler;
