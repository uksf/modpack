#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Combat damage provider setup. Listens to ACE damage events on the local
        machine and buffers damage attribution events for server sync.

        Infantry: listens to ace_medical_woundReceived (fires on unit-local machine)
        Vehicles: listens to ace_vehicle_damage_damageApplied (fires on vehicle-local machine)

        Only records damage caused by players (isPlayer check on instigator).
        Uses ammo classname (infantry) or source vehicle type (vehicles) for weapon
        attribution instead of currentWeapon, which is unreliable across machines.

        Events are buffered locally and flushed to the server on the sync tick,
        same as all other providers. No per-event network traffic.

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

    if (isNull _instigator || {!isPlayer _instigator}) exitWith {};
    if (_unit isEqualTo _instigator) exitWith {};

    // Sum all damage across body parts
    private _totalDamage = 0;
    {_totalDamage = _totalDamage + (_x#0)} forEach _allDamages;

    if (_totalDamage <= 0) exitWith {};

    // Use launch position (stored by shots provider) for accurate engagement range
    private _launchPosition = _instigator getVariable [QGVAR(lastFiredPosition), getPosASL _instigator];
    private _targetPosition = getPosASL _unit;

    [createHashMapFromArray [
        ["type", "combatDamage"],
        ["targetNetId", netId _unit],
        ["targetClassname", typeOf _unit],
        ["targetType", "infantry"],
        ["uid", getPlayerUID _instigator],
        ["damage", _totalDamage],
        ["weapon", _ammoType],
        ["hitPoint", "body"],
        ["distance2D", round (_launchPosition distance2D _targetPosition)],
        ["distance3D", round (_launchPosition vectorDistance _targetPosition)]
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

    // Use source vehicle/weapon type for attribution — more reliable than currentWeapon across machines
    private _weapon = if (!isNull _source) then {typeOf _source} else {""};
    // Use launch position (stored by shots provider) for accurate engagement range
    private _launchPosition = _instigator getVariable [QGVAR(lastFiredPosition), getPosASL _instigator];
    private _targetPosition = getPosASL _vehicle;

    [createHashMapFromArray [
        ["type", "combatDamage"],
        ["targetNetId", netId _vehicle],
        ["targetClassname", typeOf _vehicle],
        ["targetType", "vehicle"],
        ["uid", getPlayerUID _instigator],
        ["damage", _damageDelta],
        ["weapon", _weapon],
        ["hitPoint", _hitPoint],
        ["distance2D", round (_launchPosition distance2D _targetPosition)],
        ["distance3D", round (_launchPosition vectorDistance _targetPosition)]
    ]] call FUNC(addEvent);
}] call CBA_fnc_addEventHandler;
