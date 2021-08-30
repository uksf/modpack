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

(_this select 1) params ["_logic"];

if !(isServer) exitWith {};

private _area = _logic getVariable ["objectarea", []];
if (_area isEqualTo []) exitWith {};

private _numberOfIEDsToSpawn = _logic getVariable [QGVAR(iedNumber), 0];
private _iedClassesParsed = parseSimpleArray (_logic getVariable [QGVAR(iedClasses), []]);
private _hiddenClassesParsed = parseSimpleArray (_logic getVariable [QGVAR(iedHideClasses), []]);
private _moduleHiddenChance = _logic getVariable [QGVAR(iedHideChance), 0];
private _moduleSecondaryChance = _logic getVariable [QGVAR(iedSecondaryChance), 0];
private _useRoads = _logic getVariable [QGVAR(useRoads), true];
private _usePlanters = _logic getVariable [QGVAR(useIEDPlanters), false];
private _planterBackpacks = parseSimpleArray (_logic getVariable [QGVAR(IEDPlanterBackpackClasses), []]);

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

    private _canCreate = [GVAR(iedExcludeAreas), {[_position, _x#0, _x#1] call EFUNC(common,objectInArea)}] call EFUNC(common,arrayNone);
    if (_canCreate) then {
        private _explosive = objNull;

        if (_useRoads) then {
            private _road = [_position] call EFUNC(common,findNearRoad);
            private _sideOfRoadchance = random 10;

            if (_sideOfRoadchance > 5) then {
                ([_road, 1] call FUNC(getRoadSide)) params  ["_roadSide", "_dir"];
                ([objNull, _roadSide, _dir, selectRandom _iedClassesParsed, "PressurePlate", []] call ACE_Explosives_fnc_placeExplosive) params ["_explosive"];
                _explosive setVectorUp surfaceNormal position _explosive;

                private _hiddenChance = random 1;
                if (_hiddenChance < _moduleHiddenChance) then {
                    private _hideObject = createVehicle [selectRandom _hiddenClassesParsed, _roadSide, [], 0, "CAN_COLLIDE"];
                    _hideObject setDir (random 360);
                    _hideObject setVectorUp surfaceNormal position _hideObject;
                    _hiddenObject enableSimulationGlobal false;
                };
            } else {
                ([objNull, getPos _road, random 360, selectRandom _iedClassesParsed, "PressurePlate", []] call ACE_Explosives_fnc_placeExplosive) params ["_explosive"];
            };
        } else {
            ([objNull, _position, random 360, selectRandom _iedClassesParsed, "PressurePlate", []] call ACE_Explosives_fnc_placeExplosive) params ["_explosive"];
        };

        private _secondaryChance = random 1;
        if (_secondaryChance < _moduleSecondaryChance) then {
            private _randomDistance = random [20,30,40];
            private _secondaryPosition = (_currentExplosive select 0) getPos [_randomDistance, random 360]; // possible place for object check to avoid houses etc?
            ([objNull, _secondaryPosition, random 360, selectRandom _iedClassesParsed, "PressurePlate", []] call ACE_Explosives_fnc_placeExplosive) params ["_explosiveSecondary"];
            [QGVAR(revealMineToAllExceptBlufor), [_explosiveSecondary]] call CBA_fnc_globalEvent;
        };

        [QGVAR(revealMineToAllExceptBlufor), [_explosive]] call CBA_fnc_globalEvent;
        _args set [0, _numberOfIEDsToSpawn - 1];
    };
}, 0.2, [_numberOfIEDsToSpawn, _logic, _area, _iedClassesParsed, _hiddenClassesParsed, _moduleHiddenChance, _moduleSecondaryChance, _useRoads]] call CBA_fnc_addPerFrameHandler;
