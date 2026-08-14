#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Opens the interactive inspector for one registered NPC.
*/
params [["_npc", objNull, [objNull]]];

if !(ADMIN_OR_WHITELISTED) exitWith {};
if (isNull _npc) exitWith {};
private _npcId = netId _npc;
private _registered = missionNamespace getVariable [QGVAR(registeredNetIds), []];
if !(_npcId in _registered) exitWith {};

private _existing = uiNamespace getVariable [QGVAR(consoleInspector), displayNull];
if (!isNull _existing) then {_existing closeDisplay 2};
private _parent = findDisplay 312;
if (isNull _parent) then {_parent = findDisplay 46};
if (isNull _parent) exitWith {};

GVAR(consoleInspectorNpc) = _npc;
private _display = _parent createDisplay QGVAR(consoleInspector);
if (isNull _display) exitWith {};
private _picker = _display displayCtrl IDC_CONSOLE_PICKER;

private _position = if (!isNull curatorCamera) then {positionCameraToWorld [0, 0, 0]} else {getPosATL (call CBA_fnc_currentUnit)};
private _npcIds = (missionNamespace getVariable [QGVAR(registeredNetIds), []]) + (missionNamespace getVariable [QGVAR(mutedNetIds), []]);
_npcIds = _npcIds arrayIntersect _npcIds;
private _npcs = _npcIds apply {objectFromNetId _x};
_npcs = _npcs select {!isNull _x};
if (isNull curatorCamera) then {
    _npcs = _npcs select {_position distance _x <= HEARING_RADIUS || {_x isEqualTo _npc}};
};
_npcs = [_npcs, [], {_position distance _x}, "ASCEND"] call BIS_fnc_sortBy;
{
    private _name = _x getVariable [QGVAR(personaName), name _x];
    private _suffix = [" [dead]", " [muted]"] select alive _x;
    if (_x getVariable [QGVAR(talkable), false]) then {_suffix = ""};
    private _index = _picker lbAdd format ["%1 (%2 m)%3", _name, round (_position distance _x), _suffix];
    _picker lbSetData [_index, netId _x];
    if (_x isEqualTo _npc) then {_picker lbSetCurSel _index};
} forEach _npcs;
_picker ctrlAddEventHandler ["LBSelChanged", {
    params ["_control", "_index"];
    private _selectedNpc = objectFromNetId (_control lbData _index);
    if (!isNull _selectedNpc) then {GVAR(consoleInspectorNpc) = _selectedNpc};
}];

_display displayAddEventHandler ["Unload", {
    if (GVAR(consoleInspectorPFH) >= 0) then {[GVAR(consoleInspectorPFH)] call CBA_fnc_removePerFrameHandler};
    GVAR(consoleInspectorPFH) = -1;
    GVAR(consoleInspectorNpc) = objNull;
}];

GVAR(consoleInspectorPFH) = [{call FUNC(consoleUpdateInspector)}, 0.2] call CBA_fnc_addPerFrameHandler;
call FUNC(consoleUpdateInspector);
