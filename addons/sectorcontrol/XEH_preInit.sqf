#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"


// global hint
[QGVAR(globalHint), {
	params ["_newOwner", "_name"];
	private _sideAndColour = [];
	if (_newOwner == 1) then {_sideAndColour = ["Friendlies", '#0000FF']};
	if (_newOwner == 0) then {_sideAndColour = ["Enemies", '#FF0000']};
	[format["<t color='%1'>%2</t> have taken %3!",_sideAndColour#1, _sideAndColour#0, _name]] call EFUNC(common,hint);
}] call CBA_fnc_addEventHandler;


// local hint
[QGVAR(localHint), {
	params ["_capturePercentage", "_currentDominantSide"];
	private _colour = "";
	if (_currentDominantSide == 1) then {_colour = '#0000FF'};
	if (_currentDominantSide == 0) then {_colour = '#FF0000'};
	[format [
		"Sector Capture Progress: <t color='%1'>%2</t>",
		_colour,
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
		_logic setVariable [QGVAR(sectorContested), false, true];
	};

	if (_lockAfterCapture == 1) then {
		_logic setVariable [QGVAR(sectorLocked), true, true];
		// add locked to the marker name
		private _markers = _logic getVariable [QGVAR(sectorMarkers), []];
		private _sectorMarkerName = _markers#1;
		private _name = _logic getVariable [QGVAR(displayName), ""];
		_sectorMarkerName setMarkerTextLocal _name+" [Locked]";
	};
}] call CBA_fnc_addEventHandler;

ADDON = true;
