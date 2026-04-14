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
_area params ["_a", "_b"];
private _searchRadius = (_a max _b) + 25;

private _statics = nearestObjects [_centre, ["StaticWeapon"], _searchRadius, true];
_statics = _statics select {[_x, _centre, _area] call EFUNC(common,objectInArea)};

private _occupiedCount = 0;
private _currentGroup = grpNull;
{
    if (alive _x && {isNull (gunner _x)}) then {
        if (isNull _currentGroup || {(count units _currentGroup) >= MAX_GROUP_SIZE}) then {
            _currentGroup = createGroup _side;
            _currentGroup deleteGroupWhenEmpty true;
        };

        if (!isNull _currentGroup) then {
            private _unit = _currentGroup createUnit [selectRandom _unitList, getPosATL _x, [], 0, "NONE"];

            if (!isNull _unit) then {
                _unit assignAsGunner _x;
                _unit moveInGunner _x;
            };

            if ((gunner _x) isNotEqualTo _unit) then {
                if (!isNull _unit) then {
                    deleteVehicle _unit;
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
