#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Combat damage provider setup. Listens to ACE damage events on the local
        machine and buffers damage attribution events for server sync.

        Infantry: ace_medical_woundReceived, on the wounded unit's machine.
        Vehicles: ace_vehicle_damage_damageApplied, on the vehicle's machine.
        A player crashing their own vehicle is still recorded. Vehicle events have
        no ammo type, so damageType is an empty string; infantry uses the wound ammo.

        The credited player is fnc_creditedShooter on the instigator. A UAV crew
        instigator resolves to the player in that role at damage time. If the
        instigator is null and the source is a UAV, the source is resolved the
        same way. Zeus remote control is not credited. uid is set on the event so
        a later client sync cannot replace it.

        Weapon and distance stay on the hit events. This ledger is instigator uid
        and damage amount. damageReceived still records body parts when the local
        player is wounded, whoever shot them.

    Parameters:
        None

    Return Value:
        None

    Example:
        call uksf_statistics_fnc_providerCombatDamage
*/
["ace_medical_woundReceived", {
    if (GVAR(killswitch)) exitWith {};
    params ["_unit", "_allDamages", "_instigator", "_ammoType"];

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

    private _credited = [_instigator] call FUNC(creditedShooter);
    if (isNull _credited || {_unit isEqualTo _credited}) exitWith {};
    private _creditedUid = getPlayerUID _credited;
    if (_creditedUid isEqualTo "") exitWith {};

    private _totalDamage = 0;
    {_totalDamage = _totalDamage + (_x#0)} forEach _allDamages;

    if (_totalDamage <= 0) exitWith {};

    [createHashMapFromArray [
        ["type", "combatDamage"],
        ["targetNetId", netId _unit],
        ["targetClassname", typeOf _unit],
        ["targetType", "infantry"],
        ["uid", _creditedUid],
        ["damage", _totalDamage],
        ["damageType", _ammoType]
    ]] call FUNC(addEvent);
}] call CBA_fnc_addEventHandler;

["ace_vehicle_damage_damageApplied", {
    if (GVAR(killswitch)) exitWith {};
    params ["_vehicle", "_hitPoint", "_damage", "_currentDamage", "_source", "_instigator"];

    private _credited = [_instigator] call FUNC(creditedShooter);
    if (isNull _credited && {_source isEqualType objNull} && {!isNull _source} && {unitIsUAV _source}) then {
        _credited = [_source] call FUNC(creditedShooter);
    };
    if (isNull _credited) exitWith {};
    private _creditedUid = getPlayerUID _credited;
    if (_creditedUid isEqualTo "") exitWith {};

    private _damageDelta = _damage - _currentDamage;
    if (_damageDelta <= 0) exitWith {};

    [createHashMapFromArray [
        ["type", "combatDamage"],
        ["targetNetId", netId _vehicle],
        ["targetClassname", typeOf _vehicle],
        ["targetType", "vehicle"],
        ["uid", _creditedUid],
        ["damage", _damageDelta],
        ["damageType", ""]
    ]] call FUNC(addEvent);
}] call CBA_fnc_addEventHandler;
