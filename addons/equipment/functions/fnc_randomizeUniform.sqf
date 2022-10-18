#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Randomize uniform

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
if (_uniformClasses isEqualTo []) exitWith {};

private _uniform = selectRandomWeighted _uniformClasses;
if (uniform _unit == _uniform) exitWith {};

private _loadout = [_unit] call CBA_fnc_getLoadout;
_loadout#0#3 set [0, _uniform];
[_unit, _loadout] call CBA_fnc_setLoadout;
