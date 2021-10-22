#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        sets up a waypoint for the IED planter to follow

    Parameters:
        0: planter <OBJECT>

    Return value:
        Nothing
*/
#define MAX_RETRIES 5

params ["_planter", ["_retries", 0]];

if (_retries >= MAX_RETRIES) exitWith {};

_planter addItemToBackpack "IEDUrbanSmall_Remote_Mag";

private _module = _planter getVariable [QGVAR(moduleObject), objNull];
private _area = _planter getVariable [QGVAR(area), []];

_area deleteAt 4;
private _areaArray = [(getPos _module)] + _area;
private _position = [_areaArray] call CBA_fnc_randPosArea;
_position set [2, 0];

private _inExcludeArea = [GVAR(iedExcludeAreas), {[_position, _x#0, _x#1] call EFUNC(common,objectInArea)}] call EFUNC(common,arrayAny);
if (_inExcludeArea) exitWith {
    [_planter, _retries + 1] call FUNC(setWaypointPlanter);
};

private _planterHome = _planter getVariable [QGVAR(planterHome), objNull];
[_planter, _position, 2, "MOVE", "SAFE", "YELLOW", "LIMITED", "COLUMN", "[this] call uksf_ied_fnc_layIED;"] call CBA_fnc_addWaypoint;
[_planter, _planterHome, 0, "MOVE", "CARELESS", "YELLOW", "LIMITED", "COLUMN", "[this] call uksf_ied_fnc_setWaypointPlanter", [60, 180, 240]] call CBA_fnc_addWaypoint;
