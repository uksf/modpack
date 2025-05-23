#include "script_component.hpp"
/*
    Author:
        Bridg, Beswick

    Description:
        IED area spawning module

    Parameters:
        0: The module logic <OBJECT>

    Return value:
        Nothing
*/
(_this#1) params ["_logic"];

if !(isServer) exitWith {};

private _area = _logic getVariable ["objectarea", []];
if (_area isEqualTo []) exitWith {};

private _numberOfIEDsToSpawn = _logic getVariable [QGVAR(iedNumber), 0];
private _iedClassesParsed = [_logic getVariable [QGVAR(iedClasses), []]] call EFUNC(common,convertToArray);
private _hiddenClassesParsed = [_logic getVariable [QGVAR(iedHideClasses), []]] call EFUNC(common,convertToArray);
private _moduleHiddenChance = _logic getVariable [QGVAR(iedHideChance), 0];
private _moduleSecondaryChance = _logic getVariable [QGVAR(iedSecondaryChance), 0];
private _useRoads = _logic getVariable [QGVAR(useRoads), true];
private _usePlanters = _logic getVariable [QGVAR(useIEDPlanters), false];
private _planterBackpacks = [_logic getVariable [QGVAR(IEDPlanterBackpackClasses), []]] call EFUNC(common,convertToArray);

if (_iedClassesParsed isEqualTo []) exitWith {};

if (_usePlanters) then {
    [_logic, _area, _planterBackpacks] call FUNC(IEDPlanters);
};

[{
    params ["_args", "_idPFH"];
    _args params ["_numberOfIEDsToSpawn", "_logic", "_area", "_iedClassesParsed", "_hiddenClassesParsed", "_moduleHiddenChance", "_moduleSecondaryChance", "_useRoads"];

    if (_numberOfIEDsToSpawn < 1) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
    };

    _area deleteAt 4;
    private _areaArray = [getPos _logic] + _area;
    private _position = [_areaArray] call CBA_fnc_randPosArea;
    private _direction = random 360;
    _position set [2, 0];

    if (_useRoads) then {
        private _road = [_position] call EFUNC(common,findNearRoad);
        if !(isNull _road) then {
            private _sideOfRoadchance = random 10;

            if (_sideOfRoadchance > 5) then {
                ([_road, 1] call FUNC(getRoadSide)) params ["_roadSide", "_dir"];
                _position = _roadSide;
                _direction = _dir;
            } else {
                _position = getPos _road;
            };
        };
    };

    private _canCreate = [GVAR(iedExcludeAreas), {[_position, _x#0, _x#1] call EFUNC(common,objectInArea)}] call EFUNC(common,arrayNone);
    if (_canCreate) then {
        private _explosive = [objNull, _position, _direction, selectRandom _iedClassesParsed, "PressurePlate", []] call ace_explosives_fnc_placeExplosive;
        [_explosive] call FUNC(createIEDHelper);
        [QGVAR(revealMineToAllExceptBlufor), [_explosive]] call CBA_fnc_globalEvent;

        private _secondaryChance = random 1;
        if (_secondaryChance < _moduleSecondaryChance) then {
            private _randomDistance = random [20, 30, 40];
            private _secondaryPosition = _explosive getPos [_randomDistance, random 360]; // possible place for object check to avoid houses etc?
            private _explosiveSecondary = [objNull, _secondaryPosition, random 360, selectRandom _iedClassesParsed, "PressurePlate", []] call ace_explosives_fnc_placeExplosive;

            [_explosiveSecondary] call FUNC(createIEDHelper);
            [QGVAR(revealMineToAllExceptBlufor), [_explosiveSecondary]] call CBA_fnc_globalEvent;
        };

        if (_useRoads) then {
            private _hiddenChance = random 1;
            if (_hiddenClassesParsed isNotEqualTo [] && _hiddenChance < _moduleHiddenChance) then {
                private _hideObject = createVehicle [selectRandom _hiddenClassesParsed, _position, [], 0, "CAN_COLLIDE"];
                _hideObject setDir (random 360);
                _hideObject setVectorUp surfaceNormal position _hideObject;
                _hideObject enableSimulationGlobal false; // TODO: This is bad
            };
        };

        _args set [0, _numberOfIEDsToSpawn - 1];
    };
}, 0.2, [_numberOfIEDsToSpawn, _logic, _area, _iedClassesParsed, _hiddenClassesParsed, _moduleHiddenChance, _moduleSecondaryChance, _useRoads]] call CBA_fnc_addPerFrameHandler;
