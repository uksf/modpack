#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Kills provider setup. Installs an EntityKilled mission event handler on the server
        to capture every entity death. Records killer UID, weapon, ammo, victim classname,
        victim side, whether victim is infantry or vehicle, and distance.

        Registered after ACE medical's handleKilledMission so killer/instigator info
        is corrected by ACE before we read it.

    Parameters:
        None

    Return Value:
        None
*/
addMissionEventHandler ["EntityKilled", {
    params ["_victim", "_killer", "_instigator"];
    private _startTime = diag_tickTime;

    // Use instigator if available (e.g. gunner in vehicle), fall back to killer
    private _attacker = if (!isNull _instigator) then {_instigator} else {_killer};

    // Only track kills by players
    if (!isPlayer _attacker) exitWith {
        ["kills", _startTime] call FUNC(addProviderTiming);
    };

    // Determine victim type
    private _victimType = "unknown";
    if (_victim isKindOf "CAManBase") then {
        _victimType = "man";
    } else {
        if (_victim isKindOf "LandVehicle" || {_victim isKindOf "Air"} || {_victim isKindOf "Ship"}) then {
            _victimType = "vehicle";
        } else {
            if (_victim isKindOf "StaticWeapon") then {
                _victimType = "static";
            };
        };
    };

    private _distance = if (isNull _attacker) then {0} else {_attacker distance _victim};

    // Get weapon info from the killer
    private _weapon = currentWeapon _attacker;

    // Get the ammo type from the current magazine
    private _ammo = "";
    private _currentMagazine = currentMagazine _attacker;
    if (_currentMagazine isNotEqualTo "") then {
        _ammo = getText (configFile >> "CfgMagazines" >> _currentMagazine >> "ammo");
    };

    private _event = createHashMapFromArray [
        ["type", "kill"],
        ["uid", getPlayerUID _attacker],
        ["weapon", _weapon],
        ["ammo", _ammo],
        ["victimClassname", typeOf _victim],
        ["victimSide", str (side group _victim)],
        ["victimType", _victimType],
        ["distance", round _distance]
    ];

    // Server-side events go directly into the server buffer
    GVAR(serverBuffer) pushBack _event;

    ["kills", _startTime] call FUNC(addProviderTiming);
}];
