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

// get logic variables
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

// creating the IED PFH
[{
    params ["_args", "_idPFH"];
    _args params ["_numberOfIEDsToSpawn", "_logic", "_area", "_iedClassesParsed", "_hiddenClassesParsed", "_moduleHiddenChance", "_moduleSecondaryChance", "_useRoads"];

    // exit asap
    if (_numberOfIEDsToSpawn < 1) then {
        {
            CIVILIAN revealMine _x;
            EAST revealMine _x;
        } forEach allMines;
        [_idPFH] call cba_fnc_removePerFrameHandler;
    };

    // get a position
    _area deleteAt 4;
    private _areaArray = [(getPos _logic)] + _area;
    private _position = [_areaArray] call CBA_fnc_randPosArea;
    private _road = [_position] call EFUNC(common,findNearRoad);

    // RNG Values
    private _sideOfRoadchance = random 10;
    private _hiddenChanceRNG = random 1;
    private _secondaryChanceRNG = random 1;

    // allows for reference in other scopes - might be a better way to do this
    private _currentExplosive = [];

    // check position isn't in any exclusion area, then continue
    if (
        [GVAR(iedExcludeAreas), {
            [_position, _x#0, _x#1] call EFUNC(common,objectInArea)
        }] call EFUNC(common,arrayNone)
    ) then {
        if (_useRoads) then {
            if (_sideOfRoadchance > 5) then {
                ([_road, 1] call FUNC(getRoadSide)) params  ["_roadSide", "_dir"];
                ([objNull, _roadSide, _dir, selectRandom _iedClassesParsed, "PressurePlate", []] call ACE_Explosives_fnc_placeExplosive) params ["_explosive"];
                _explosive setVectorUp surfaceNormal position _explosive;
                _currentExplosive pushBack _explosive;

                // chance to spawn IED cover object
                if (_hiddenChanceRNG < _moduleHiddenChance) then {
                    private _hideObject = createVehicle [selectRandom _hiddenClassesParsed, _roadSide, [], 0, "CAN_COLLIDE"];
                    _hideObject setDir (random 360);
                    _hideObject setVectorUp surfaceNormal position _hideObject;
                    _hiddenObject enableSimulationGlobal false;
                };
            } else {
                ([objNull, getPos _road, random 360, selectRandom _iedClassesParsed, "PressurePlate", []] call ACE_Explosives_fnc_placeExplosive) params ["_explosive"];
                _currentExplosive pushBack _explosive;
            };
        } else {
            ([objNull, _position, random 360, selectRandom _iedClassesParsed, "PressurePlate", []] call ACE_Explosives_fnc_placeExplosive) params ["_explosive"];
            _currentExplosive pushBack _explosive;
        };

        // create secondary
        if (_secondaryChanceRNG < _moduleSecondaryChance) then {
            private _randomDistance = random [20,30,40];
            private _secondaryPosition = (_currentExplosive select 0) getPos [_randomDistance, random 360]; // possible place for object check to avoid houses etc?
            ([objNull, _secondaryPosition, random 360, selectRandom _iedClassesParsed, "PressurePlate", []] call ACE_Explosives_fnc_placeExplosive) params ["_explosiveSecondary"];
        };
        _currentExplosive deleteAt 0;
        _args set [0, _numberOfIEDsToSpawn - 1];
    };
}, 1, [_numberOfIEDsToSpawn, _logic, _area, _iedClassesParsed, _hiddenClassesParsed, _moduleHiddenChance, _moduleSecondaryChance, _useRoads]] call cba_fnc_addPerFrameHandler;
