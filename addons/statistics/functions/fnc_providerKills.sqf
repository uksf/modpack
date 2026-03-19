#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Kills provider setup. Installs an EntityKilled mission event handler on the server
        to capture every entity death.

        Uses ACE medical's damage source tracking (ace_medical_lastDamageSource /
        ace_medical_lastInstigator) for chain reaction attribution when the engine's
        killer/instigator params are null or non-player.

        Assist correlation is handled API-side by joining combatDamage events
        to kill events on targetNetId.

    Parameters:
        None

    Return Value:
        None

    Example:
        call uksf_statistics_fnc_providerKills
*/
addMissionEventHandler ["EntityKilled", {
    params ["_victim", "_killer", "_instigator"];
    private _startTime = diag_tickTime;

    // Use instigator if available (e.g. gunner in vehicle), fall back to killer
    private _attacker = if (!isNull _instigator) then {_instigator} else {_killer};

    private _killerUid = if (isPlayer _attacker) then {getPlayerUID _attacker} else {""};
    private _indirect = false;

    // Chain reaction attribution via ACE medical tracking
    // ACE stores the last damage source/instigator on the victim — survives through
    // explosion chains, fire, cookoff, and vehicle damage propagation
    // Note: uses string literals, not QEGVAR — ACE's prefix is "ace", not "uksf"
    if (_killerUid isEqualTo "") then {
        private _aceInstigator = _victim getVariable ["ace_medical_lastInstigator", objNull];
        if (isNull _aceInstigator) then {
            _aceInstigator = _victim getVariable ["ace_medical_lastDamageSource", objNull];
        };
        if (!isNull _aceInstigator && {isPlayer _aceInstigator}) then {
            _killerUid = getPlayerUID _aceInstigator;
            _indirect = true;
        };
    };

    // Only emit event if a player was involved as the killer
    if (_killerUid isEqualTo "") exitWith {
        ["kills", _startTime] call FUNC(addProviderTiming);
    };

    // Determine target type
    private _targetType = "unknown";
    if (_victim isKindOf "CAManBase") then {
        _targetType = "infantry";
    } else {
        if (_victim isKindOf "LandVehicle" || {_victim isKindOf "Air"} || {_victim isKindOf "Ship"}) then {
            _targetType = "vehicle";
        } else {
            if (_victim isKindOf "StaticWeapon") then {
                _targetType = "static";
            };
        };
    };

    // Determine target side with bounds safety
    private _sideIndex = getNumber (configOf _victim >> "side");
    private _sides = [west, east, resistance, civilian];
    private _targetSide = if (_sideIndex >= 0 && {_sideIndex < count _sides}) then {
        str (_sides select _sideIndex)
    } else {
        "unknown"
    };

    private _event = createHashMapFromArray [
        ["type", "kill"],
        ["killerUid", _killerUid],
        ["indirect", _indirect],
        ["targetNetId", netId _victim],
        ["targetClassname", typeOf _victim],
        ["targetSide", _targetSide],
        ["targetType", _targetType]
    ];

    [_event] call FUNC(addEvent);

    ["kills", _startTime] call FUNC(addProviderTiming);
}];
