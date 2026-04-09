#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Occupies empty static weapons in the module area with gunner units.

    Parameters:
        0: Module logic <OBJECT>
        1: Area array <ARRAY>
        2: Group side <SIDE>
        3: Unit class pool <ARRAY>

    Return Value:
        Number of occupied statics <NUMBER>

    Example:
        [_logic, _area, _side, _unitList] call uksf_autoplace_fnc_occupyEmptyStatics
*/
params ["_logic", "_area", "_side", "_unitList"];

if (!isServer) exitWith {0};
if (isNull _logic) exitWith {0};
if (_area isEqualTo []) exitWith {0};
if (_unitList isEqualTo []) exitWith {0};

private _centre = getPosATL _logic;
_area params ["_a", "_b"];
private _searchRadius = (_a max _b) + 25;

private _statics = nearestObjects [_centre, ["StaticWeapon"], _searchRadius, true];
_statics = _statics select {[_x, _centre, _area] call EFUNC(common,objectInArea)};

private _occupiedCount = 0;
{
    if (alive _x && {isNull (gunner _x)}) then {
        private _group = createGroup _side;
        _group deleteGroupWhenEmpty true;
        [QEGVAR(caching,disableCache), _group] call CBA_fnc_serverEvent;
        [QEGVAR(virtualisation,exclude), _group] call CBA_fnc_serverEvent;

        private _unit = _group createUnit [selectRandom _unitList, getPosATL _x, [], 0, "NONE"];
        _unit assignAsGunner _x;
        _unit moveInGunner _x;

        if ((gunner _x) isNotEqualTo _unit) then {
            deleteVehicle _unit;
            deleteGroup _group;
        } else {
            [QEGVAR(caching,enableCache), _group] call CBA_fnc_serverEvent;
            [QEGVAR(virtualisation,include), _group] call CBA_fnc_serverEvent;
            _occupiedCount = _occupiedCount + 1;
        };
    };
} forEach _statics;

_occupiedCount
