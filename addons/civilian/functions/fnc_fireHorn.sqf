#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Fires vehicle horn given number of times if it exists

    Parameters:
        0: Vehicle <OBJECT>
        1: Unit <OBJECT> (Optional)

    Return value:
        Nothing
*/
params ["_vehicle", ["_unit", objNull], ["_count", 2]];

if !(local _vehicle) exitWith {
    [QGVAR(fireHorn), _this, _vehicle] call CBA_fnc_targetEvent;
};

if (isNull _unit) then {
    _unit = driver _vehicle;
};

private _weapons = weapons _vehicle;
private _index = _weapons findIf {"horn" in (toLower _x)};
if (index == -1) exitWith {};

private _horn = _weapons#_index;
_vehicle selectWeapon _horn;
_unit forceWeaponFire [_horn, _horn];

_unit forceWeaponFire [_horn, _horn];
_count = _count - 1;
for "_i" from 1 to _count do {
    [{_this#0 forceWeaponFire [_this#1, _this#1];}, [_unit, _horn], 1 * _count * (random 1)] call CBA_fnc_waitAndExecute;
};
