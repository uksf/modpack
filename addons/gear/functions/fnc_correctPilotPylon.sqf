/*
    Author:
        Tim Beswick

    Description:
        Correct the weapon loadout for use by the pilot

    Parameter(s):
        0: Vehicle <OBJECT>

    Return Value:
        None
*/
#include "script_component.hpp"

params ["_vehicle"];

if (!local _vehicle) exitWith {};

private _pylons = configProperties [configFile >> "CfgVehicles" >> typeOf _vehicle >> "Components" >> "TransportPylonsComponent" >> "Pylons", "isClass _x"];
private _magazines = getPylonMagazines _vehicle;

{
    private _magazine = configFile >> "CfgMagazines" >> _x;
    if (isNumber (_magazine >> QGVAR(pilotControl)) && {(getNumber (_magazine >> QGVAR(pilotControl))) > 0}) then {
        _vehicle removeWeaponTurret [getText (_magazine >> "pylonWeapon"), [0]];
        _vehicle setPylonLoadOut [configName (_pylons select _forEachIndex), _x, true, []];
    };
} forEach _magazines;
