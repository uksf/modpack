#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Combat damage provider setup. Listens to ACE damage events on the local
        machine and buffers damage attribution events for server sync.

        Infantry: listens to ace_medical_woundReceived (fires on unit-local machine)
        Vehicles: listens to ace_vehicle_damage_damageApplied (fires on vehicle-local machine)

        Only records data available on the local machine — instigator UID and damage
        amount for the damage ledger. Weapon and distance data comes from the client's
        hit events (projectile HitPart), not from here.

        Also emits damageReceived events when the local player is wounded (body parts
        hit), consolidating both concerns into a single woundReceived handler.

    Parameters:
        None

    Return Value:
        None

    Example:
        call uksf_statistics_fnc_providerCombatDamage
*/

// Infantry damage — fires on the machine where the wounded unit is local
["ace_medical_woundReceived", {
    if (GVAR(killswitch)) exitWith {};
    params ["_unit", "_allDamages", "_instigator", "_ammoType"];

    // Emit damageReceived for local player (body parts hit, regardless of who shot)
    if (hasInterface && {_unit isEqualTo player}) then {
        private _bodyPartsHit = [];
        {
            _x params ["_damage", "_bodyPart"];
            if (_damage > 1E-3) then {
                _bodyPartsHit pushBackUnique (toLower _bodyPart);
            };
        } forEach _allDamages;

        if (_bodyPartsHit isNotEqualTo []) then {
            [createHashMapFromArray [
                ["type", "damageReceived"],
                ["bodyParts", _bodyPartsHit],
                ["damageType", _ammoType]
            ]] call FUNC(addEvent);
        };
    };

    // Emit combatDamage for player-inflicted damage (API correlates with kills via targetNetId)
    if (isNull _instigator || {!isPlayer _instigator}) exitWith {};
    if (_unit isEqualTo _instigator) exitWith {};

    private _totalDamage = 0;
    {_totalDamage = _totalDamage + (_x#0)} forEach _allDamages;

    if (_totalDamage <= 0) exitWith {};

    [createHashMapFromArray [
        ["type", "combatDamage"],
        ["targetNetId", netId _unit],
        ["targetClassname", typeOf _unit],
        ["targetType", "infantry"],
        ["uid", getPlayerUID _instigator],
        ["damage", _totalDamage],
        ["damageType", _ammoType]
    ]] call FUNC(addEvent);
}] call CBA_fnc_addEventHandler;

// Vehicle damage — fires on the machine where the vehicle is local
// Self-vehicle-damage is intentionally tracked (crashes, collisions)
["ace_vehicle_damage_damageApplied", {
    if (GVAR(killswitch)) exitWith {};
    params ["_vehicle", "_hitPoint", "_damage", "_currentDamage", "_source", "_instigator"];

    if (isNull _instigator || {!isPlayer _instigator}) exitWith {};

    private _damageDelta = _damage - _currentDamage;
    if (_damageDelta <= 0) exitWith {};

    // ace_vehicle_damage_damageApplied does not provide an ammo type.
    // Emit empty sentinel so the field is always present on combatDamage events (infantry path sets this from _ammoType).
    [createHashMapFromArray [
        ["type", "combatDamage"],
        ["targetNetId", netId _vehicle],
        ["targetClassname", typeOf _vehicle],
        ["targetType", "vehicle"],
        ["uid", getPlayerUID _instigator],
        ["damage", _damageDelta],
        ["damageType", ""]
    ]] call FUNC(addEvent);
}] call CBA_fnc_addEventHandler;
