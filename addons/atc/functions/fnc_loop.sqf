/*
	Author:
		Tim Beswick

	Description:
		ATC Radar loop and markers

	Parameter(s):
		0: Object <OBJECT>
		1: Unit <OBJECT>

	Return Value:
		None
*/
#include "script_component.hpp"

params ["_object", "_unit"];

if(local _unit) then {
	_object setVariable [QGVAR(radarOn), true, true];
	_object setVariable [QGVAR(operator), _unit, true];
	_unit setVariable [QGVAR(markers), [], true];
	_unit setVariable [QGVAR(isOperator), true, true];

	_radarHandle = [{
		params ["_args"];
		_args params ["_object"];

		_unit = _object getVariable [QGVAR(operator), objNull];
		if(isNull _unit) exitWith { _object setVariable [QGVAR(radarOn), false, true]; };
		if(!(alive _object) || !(alive _unit)) exitWith { _object setVariable [QGVAR(radarOn), false, true]; };

		_allMarkers = _unit getVariable [QGVAR(markers), []];
		{ deleteMarker _x } forEach (_allMarkers);

		_allTargets = [_object, _unit] call UKSF_Scripts_ATC_fnc_getTargets;
		_allTargets params ["_airTargetsHostile", "_airTargetsFriendly"];
		if(count _airTargetsHostile > 0) then {
			[_object, _airTargetsHostile]  call UKSF_Scripts_ATC_fnc_updateMarkers;
		};
		if(count _airTargetsFriendly > 0) then {
			[_object, _airTargetsFriendly]  call UKSF_Scripts_ATC_fnc_updateMarkers;
		};
	}, 0.5, [_object]] call CBA_fnc_addPerFrameHandler;

	[{!((_this select 0) getVariable [QGVAR(radarOn), false]) || ((_this select 0) distance2D (_this select 1)) > 10}, {
		[_this select 2] call CBA_fnc_removePerFrameHandler;
		{ deleteMarker _x } forEach ((_this select 1) getVariable [QGVAR(markers), []]);
		(_this select 0) setVariable [QGVAR(radarOn), false, true];
		(_this select 0) setVariable [QGVAR(operator), objNull, true];
		(_this select 1) setVariable [QGVAR(markers), [], true];
		(_this select 1) setVariable [QGVAR(isOperator), false, true];
	}, [_object, _unit, _radarHandle]] call CBA_fnc_waitUntilAndExecute;
};