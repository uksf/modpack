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
private _skipRandomization = [format [QUOTE(GVAR(skipRandomization)_%1), _type], {_config >> QGVAR(skipRandomization)}, false] call EFUNC(common,readCacheValues);
if (_skipRandomization) exitWith {};

private _uniformClasses = [format [QUOTE(GVAR(randomUniforms)_%1), _type], {_config >> QGVAR(randomUniforms)}, []] call EFUNC(common,readCacheValues);
if (_uniformClasses isEqualTo []) exitWith {};

private _uniform = selectRandomWeighted _uniformClasses;

_unit forceAddUniform _uniform;
