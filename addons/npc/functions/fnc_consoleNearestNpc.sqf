#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Returns the nearest registered talkable NPC, preferring the addressed NPC.
*/
if (!isNull GVAR(targetNpc)) exitWith {GVAR(targetNpc)};
private _unit = call CBA_fnc_currentUnit;
private _npcs = (missionNamespace getVariable [QGVAR(talkerNetIds), []]) apply {objectFromNetId _x};
_npcs = _npcs select {!isNull _x && {alive _x} && {_x getVariable [QGVAR(talkable), false]} && {_unit distance _x <= HEARING_RADIUS}};
if (_npcs isEqualTo []) exitWith {objNull};
([_npcs, [], {_unit distance _x}, "ASCEND"] call BIS_fnc_sortBy)#0
