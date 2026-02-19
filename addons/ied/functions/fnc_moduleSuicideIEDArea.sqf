#include "script_component.hpp"
/*
    Author:
        Bridg, Beswick

    Description:
        Suicide area spawning module

    Parameters:
        0: The module logic <OBJECT>

    Return value:
        Nothing
*/
(_this#1) params ["_logic"];

if !(isServer) exitWith {};

private _area = _logic getVariable ["objectarea", []];
if (_area isEqualTo []) exitWith {};

private _manClassesParsed = [_logic getVariable [QGVAR(suicideIEDClasses), []]] call EFUNC(common,convertToArray);
private _suicideItems = [_logic getVariable [QGVAR(suicideIEDItemClasses), []]] call EFUNC(common,convertToArray);
private _vehicleClassesParsed = [_logic getVariable [QGVAR(suicideIEDVehicleClasses), []]] call EFUNC(common,convertToArray);
private _useVehicle = _logic getVariable [QGVAR(suicideIEDInCarBoolean), false];

if (_manClassesParsed isEqualTo [] || _suicideItems isEqualTo []) exitWith {};

_area deleteAt 4;
private _areaArray = [getPos _logic] + _area;
private _position = [_areaArray] call CBA_fnc_randPosArea;
_position set [2, 0];

// create opfor group - civs don't seem to work, need to be enemy
private _group = createGroup east;
private _suicideUnit = _group createUnit [selectRandom _manClassesParsed, _position, [], 0, "NONE"];
_suicideUnit addBackpack (selectRandom _suicideItems);
[_suicideUnit] joinSilent _group;

_suicideUnit setVariable [QGVAR(sucideUnitGroup), _group, true];
_suicideUnit setVariable [QGVAR(areaArray), _areaArray, true];

_suicideUnit addMPEventHandler ["MPKilled", {
    params ["_suicideUnit", "_killer", "_instigator"];

    if !(isServer) exitWith {};

    TRACE_3("",_suicideUnit,_killer,_instigator);
    if (side _killer != west && side _instigator != west) exitWith {};

    [QGVAR(iedDestroyed), _suicideUnit] call CBA_fnc_serverEvent;
}];

if (_vehicleClassesParsed isNotEqualTo [] && _useVehicle) exitWith {
    private _suicideVehicle = createVehicle [selectRandom _vehicleClassesParsed, _position, [], 0, "NONE"];
    _suicideUnit moveInDriver _suicideVehicle;
    [_suicideUnit, false, true] call EFUNC(special,suicide);
    [_suicideUnit] call FUNC(setWaypoint);
};

[_suicideUnit, false, false] call EFUNC(special,suicide);
[_suicideUnit] call FUNC(setWaypoint);
