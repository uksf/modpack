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
#define MAX_GROUP_SIZE 10

params ["_logic", "_area", "_side", "_unitList"];

if (!isServer) exitWith {0};
if (isNull _logic) exitWith {0};
if (_area isEqualTo []) exitWith {0};
if (_unitList isEqualTo []) exitWith {0};

private _centre = getPosATL _logic;
_area params ["_areaRadiusA", "_areaRadiusB"];
private _searchRadius = (_areaRadiusA max _areaRadiusB) + 25;

private _statics = nearestObjects [_centre, ["StaticWeapon"], _searchRadius, true];
_statics = _statics select {[_x, _centre, _area] call EFUNC(common,objectInArea)};

private _occupiedCount = 0;
private _currentGroup = grpNull;
{
    params ["_staticWeapon"];

    if (alive _staticWeapon && {isNull (gunner _staticWeapon)}) then {
        if (isNull _currentGroup || {(count units _currentGroup) >= MAX_GROUP_SIZE}) then {
            _currentGroup = createGroup _side;
            _currentGroup deleteGroupWhenEmpty true;
        };

        if (!isNull _currentGroup) then {
            private _gunnerUnit = _currentGroup createUnit [selectRandom _unitList, getPosATL _staticWeapon, [], 0, "NONE"];

            if (!isNull _gunnerUnit) then {
                _gunnerUnit assignAsGunner _staticWeapon;
                _gunnerUnit moveInGunner _staticWeapon;
            };

            if ((gunner _staticWeapon) isNotEqualTo _gunnerUnit) then {
                if (!isNull _gunnerUnit) then {
                    deleteVehicle _gunnerUnit;
                };

                if ((units _currentGroup) isEqualTo []) then {
                    deleteGroup _currentGroup;
                    _currentGroup = grpNull;
                };
            } else {
                _occupiedCount = _occupiedCount + 1;
            };
        };
    };
} forEach _statics;

_occupiedCount
