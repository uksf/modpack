#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Randomize equipment

    Parameters:
        0: Unit <OBJECT>

    Return value:
        Nothing
*/
params ["_unit"];

if (!local _unit) exitWith {};
if (is3DEN || _unit getvariable ["saved3DENInventory", false]) exitwith {};
if (_unit getVariable [QGVAR(skipRandomization), false]) exitWith {};

private _type = typeOf _unit;
private _config = configOf _unit;
private _skipRandomization = [format [QUOTE(GVAR(skipRandomization)_%1), _type], {_config >> QGVAR(skipRandomization)}, 0] call EFUNC(common,readCacheValues);
if (_skipRandomization == 1) exitWith {};

private _uniformClasses = [format [QUOTE(GVAR(randomUniforms)_%1), _type], {_config >> QGVAR(randomUniforms)}, []] call EFUNC(common,readCacheValues);
private _vestClasses = [format [QUOTE(GVAR(randomVests)_%1), _type], {_config >> QGVAR(randomVests)}, []] call EFUNC(common,readCacheValues);
private _secondaryWeaponClasses = [format [QUOTE(GVAR(randomSecondaryWeapons)_%1), _type], {_config >> QGVAR(randomSecondaryWeapons)}, []] call EFUNC(common,readCacheValues);
if (
    _uniformClasses isEqualTo []
    && _vestClasses isEqualTo []
    && _secondaryWeaponClasses isEqualTo []
) exitWith {};

private _currentUniform = uniform _unit;
private _uniform = selectRandomWeighted _uniformClasses;
if (isNil "_uniform") then {
    _uniform = _currentUniform;
};

private _currentVest = vest _unit;
private _vest = selectRandomWeighted _vestClasses;
if (isNil "_vest") then {
    _vest = _currentVest;
};

private _currentSecondaryWeapon = secondaryWeapon _unit;
private _secondaryWeapon = selectRandomWeighted _secondaryWeaponClasses;
if (isNil "_secondaryWeapon") then {
    _secondaryWeapon = _currentSecondaryWeapon;
};

if (
    _currentUniform == _uniform
    && _currentVest == _vest
    && _currentSecondaryWeapon == _secondaryWeapon
) exitWith {};

private _loadout = [_unit] call CBA_fnc_getLoadout;
_loadout#0#1 set [0, _secondaryWeapon];
_loadout#0#3 set [0, _uniform];
_loadout#0#4 set [0, _vest];
[_unit, _loadout] call CBA_fnc_setLoadout;
