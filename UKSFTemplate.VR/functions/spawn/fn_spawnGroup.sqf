/*
    Author:
        Tim Beswick

    Description:
        Spawns random AI group and gives patrol task

    Parameters:
        0: Spawner ID <STRING>
        1: Position <MARKER, TRIGGER, LOCATION>
        2: Faction Name (default: "") <SCALAR>

    Return value:
        Nothing
*/
#include "script_component.hpp"

#define PLAYERSAFEDISTANCE 500

params ["_ID", "_position", "_factionName"];

private _randomSpawn = [_position] call CBA_fnc_randPosArea;
if (({_x distance2D _randomSpawn < PLAYERSAFEDISTANCE} count (call CBA_fnc_players)) > 0) exitWith {};

missionNamespace setVariable [format ["%1_isSpawning", _ID], true, true];

([_factionName] call FUNC(selectGroup)) params ["_side", "_selectedGroup"];
if (count _selectedGroup < 1) exitWith { INFO("Invalid group. Exiting") };
private _group = [_randomSpawn, _side, _selectedGroup] call BIS_fnc_spawnGroup;

private _area = [_position] call CBA_fnc_getArea;
private _patrolRadius = (random [(_area select 1), ((_area select 1) + (_area select 2)) / 2, (_area select 2)]) max 50;
[_group, getPos (leader _group), _patrolRadius, 4, "MOVE", "SAFE", "YELLOW", "LIMITED", "COLUMN"] call CBA_fnc_taskPatrol;
_group setVariable [QEGVAR(support,spawnPosition), _randomSpawn, true];

private _currentGroupsActive = missionNamespace getVariable (format ["%1_currentGroupsActive", _ID]);
_currentGroupsActive pushBack _group;
missionNamespace setVariable [format ["%1_currentGroupsActive", _ID], _currentGroupsActive, true];

private _groupPoolSize = missionNamespace getVariable format ["%1_groupPoolSize", _ID];
missionNamespace setVariable [format ["%1_groupPoolSize", _ID], (_groupPoolSize - 1), true];

missionNamespace setVariable [format ["%1_isSpawning", _ID], false, true];
