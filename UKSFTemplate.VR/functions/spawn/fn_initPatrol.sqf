/*
    Author:
        Tim Beswick
        
    Description:
        Sets up patrol spawning on given position.
        Position can be a marker, trigger, or location.

    Parameters:
        0: Position <MARKER, TRIGGER, LOCATION>
        1: Max enemy groups spawned at once (default: 5) <SCALAR>
        2: Enemy pool size (default: 10) <SCALAR>
        3: Faction (default: "") <STRING>

    Return value:
        Nothing

    Called from:
        ["MyMarker", 20, 40, "CUP_O_RU"] call uksf_mission_fnc_spawnOnMarker;
*/
#include "script_component.hpp"

params [
    ["_position", objNull, [objNull, "", locationNull]],
    ["_maxGroupsActive", 5],
    ["_groupPoolSize", 10],
    ["_factionName", ""]
];

if (!isServer) exitWith { INFO("Called on client. Exiting.") };
if (_position isEqualTo objNull) exitWith { INFO("Invalid position. Exiting.") };

if (_position isEqualType "") then {
    _position setMarkerAlpha 0;
};

private _ID = format ["spawner_%1", call FUNC(assignID)];
missionNamespace setVariable [format ["%1_currentGroupsActive", _ID], [], true];
missionNamespace setVariable [format ["%1_groupPoolSize", _ID], _groupPoolSize, true];
missionNamespace setVariable [format ["%1_isSpawning", _ID], false, true];

[{
    params ["_args", "_idPFH"];
    _args params ["_ID", "_position", "_maxGroupsActive", "_factionName"];

    private _groupPoolSize = missionNamespace getVariable [format ["%1_groupPoolSize", _ID], 0];
    if (_groupPoolSize <= 0) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
    };

    private _currentGroupsActive = missionNamespace getVariable [format ["%1_currentGroupsActive", _ID], []];
    _currentGroupsActive = _currentGroupsActive select {({alive _x} count (units _x)) > 0};
    missionNamespace setVariable [format ["%1_currentGroupsActive", _ID], _currentGroupsActive, true];

    if ((count _currentGroupsActive) < _maxGroupsActive && {!(missionNamespace getVariable [format ["%1_isSpawning", _ID], false])}) then {
        [QGVAR(spawnGroup), [_ID, _position, _factionName], selectRandom EGVAR(common,HCs)] call CBA_fnc_targetEvent;
    };
}, 30, [_ID, _position, _maxGroupsActive, _factionName]] call CBA_fnc_addPerFrameHandler;
