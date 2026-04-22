#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Occupies empty statics in spatially coherent groups using rolling PFH pacing (one chunk per tick).

    Parameters:
        0: Module logic <OBJECT>
        1: Area array <ARRAY>
        2: Group side <SIDE>
        3: Unit class pool <ARRAY>
        4: Completion callback <CODE>
        5: Callback args <ARRAY>

    Return Value:
        Nothing

    Example:
        [_logic, _area, _side, _unitList, _callback, _callbackArgs] call uksf_autoplace_fnc_occupyStatics
*/
params ["_logic", "_area", "_side", "_unitList", ["_callback", {}], ["_callbackArgs", []]];

if (!isServer) exitWith {};
if (isNull _logic) exitWith {};
if (_area isEqualTo []) exitWith {
    _callbackArgs call _callback;
};
if (_unitList isEqualTo []) exitWith {
    _callbackArgs call _callback;
};

private _centre = getPosATL _logic;
_area params ["_areaRadiusA", "_areaRadiusB"];
private _searchRadius = (_areaRadiusA max _areaRadiusB) + 25;

private _statics = nearestObjects [_centre, ["StaticWeapon"], _searchRadius, true];
_statics = _statics select {alive _x && {isNull (gunner _x)} && {[_x, _centre, _area] call EFUNC(common,objectInArea)}};

private _positions = _statics apply {[getPosATL _x, getDir _x, _x]};

if (_positions isEqualTo []) exitWith {
    _callbackArgs call _callback;
};

[{
    params ["_args", "_idPFH"];
    _args params ["_logic", "_positions", "_side", "_unitList", "_lastSpawn", "_callback", "_callbackArgs"];

    if (isNull _logic) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
    };

    if (_positions isEqualTo []) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
        _callbackArgs call _callback;
    };

    if (diag_fps < 20 && {_lastSpawn > CBA_missionTime}) exitWith {};

    private _chunk = [_positions] call FUNC(takeChunk);
    if (_chunk isEqualTo []) exitWith {};

    private _group = createGroup _side;
    _group deleteGroupWhenEmpty true;

    {
        _x params ["_position", "", "_staticWeapon"];
        private _unit = _group createUnit [selectRandom _unitList, _position, [], 0, "CAN_COLLIDE"];
        if (!isNull _unit) then {
            _unit setPosATL _position;
            _unit assignAsGunner _staticWeapon;
            _unit moveInGunner _staticWeapon;

            if ((gunner _staticWeapon) isNotEqualTo _unit) then {
                deleteVehicle _unit;
            };
        };
    } forEach _chunk;

    _args set [4, CBA_missionTime + 0.5];
}, 0, [_logic, _positions, _side, _unitList, 0, _callback, _callbackArgs]] call CBA_fnc_addPerFrameHandler;
