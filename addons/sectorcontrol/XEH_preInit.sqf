#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"


// global hint
[QGVAR(globalHint), {
	params ["_newOwner", "_name"];
	private _side = "";
	if (_newOwner == 1) then {_side = "Friendlies"};
	if (_newOwner == 0) then {_side = "Enemies"};
	[format["%1 have taken %2!",_side, _name]] call EFUNC(common,hint);
}] call CBA_fnc_addEventHandler;


// local hint
[QGVAR(localHint), {
	params ["_capturePercentage"];
	[format [
		"Sector Capture Progress: <t color='#FF0000'>%1%%</t>",
		round _capturePercentage
	]] call EFUNC(common,hint);
}] call CBA_fnc_addEventHandler;


// owner change event
[QGVAR(sectorOwnerChanged), {
    params ["_newOwner", "_currentOwner", "_logic", "_lockAfterCapture", "_name"];
	if (_currentOwner != _newOwner) then {
		_logic setVariable [QGVAR(currentOwner), _newOwner, true];
		[QGVAR(globalHint), [_newOwner, _name]] call CBA_fnc_globalEvent;
		// update markers
		[_logic, _newOwner] call FUNC(updateSectorMarker);
	};

	if (_lockAfterCapture == 1) then {
		_logic setVariable [QGVAR(sectorLocked), true, true];
	};
}] call CBA_fnc_addEventHandler;

ADDON = true;
