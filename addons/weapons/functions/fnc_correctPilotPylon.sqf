#include "script_component.hpp"
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
params ["_vehicle"];

if (!local _vehicle) exitWith {
    [QGVAR(correctPilotPylon), _this, _vehicle] call CBA_fnc_targetEvent;
};

private _magazines = getPylonMagazines _vehicle;

{
    private _magazine = EGVAR(common,configMagazines) >> _x;
    if (isNumber (_magazine >> QGVAR(pilotControl)) && {(getNumber (_magazine >> QGVAR(pilotControl))) > 0}) then {
        _vehicle removeWeaponTurret [getText (_magazine >> "pylonWeapon"), [0]];
        private _ammo = (_vehicle ammoOnPylon (_forEachIndex + 1));
        _vehicle setPylonLoadOut [(_forEachIndex + 1), _x, true, []];
        _vehicle setAmmoOnPylon [(_forEachIndex + 1), _ammo];
    };
} forEach _magazines;
