#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Damage received provider setup. Listens to the ACE medical woundReceived event
        to track incoming hits on the local player with body part and damage type info.

        The woundReceived event fires locally on the wounded unit's machine with:
        [_unit, _allDamages, _shooter, _ammo]
        where _allDamages is an array of [damage, bodyPart, realDamage] entries.

    Parameters:
        None

    Return Value:
        None
*/
["ace_medical_woundReceived", {
    params ["_unit", "_allDamages", "_shooter", "_ammo"];
    private _startTime = diag_tickTime;

    if (_unit isEqualTo player) then {
        // Extract body parts that received damage above threshold
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
                ["damageType", _ammo]
            ]] call FUNC(addEvent);
        };
    };

    ["damageReceived", _startTime] call FUNC(addProviderTiming);
}] call CBA_fnc_addEventHandler;
