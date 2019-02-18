/*
    Author:
        Tim Beswick

    Description:
        Sets up patrol spawning on given position.
        Position can be a marker, trigger, or location.
        Markers must be area markers. In editor: Markers > Areas (Circle overlapping rectangle icon)

        Parameters for function call:
            0: position - This can be a marker name passed as a string, a trigger object, or a location
            1: maxGroupsActive (default: 5) - The maximum number of groups that will be active on this position at any time
            2: groupPoolSize (default: 10) - The total number of enemy groups that will ever spawn on this position
            3: factionName (default: "") - The name of the faction to spawn

        Format:
            ["markername"/trigger object/location, maxGroupsActive, groupPoolSize, factionName] call uksf_mission_fnc_initPatrol;

    Parameters:
        0: Position <MARKER, TRIGGER, LOCATION>
        1: Max enemy groups spawned at once (default: 5) <SCALAR>
        2: Enemy pool size (default: 10) <SCALAR>
        3: Faction (default: "") <STRING>

    Return value:
        Nothing

    Examples:
        Marker: ["markerName", 10, 15, "CUP_O_RU"] call uksf_mission_fnc_initPatrol; (NOTE: The marker name must be given)
        Trigger: [thisTrigger, 4, 100, "CUP_I_UN"] call uksf_mission_fnc_initPatrol; (NOTE: The trigger object)
        Location: [location, 10, 15, "CUP_B_GB"] call uksf_mission_fnc_initPatrol; (NOTE: Custom locations will not work)
*/
#include "script_component.hpp"

params [["_position", objNull, [objNull, "", locationNull]], ["_maxGroupsActive", 5], ["_groupPoolSize", 10], ["_factionName", ""]];

if (!isServer) exitWith { INFO("Called on client. Exiting.") };
if (_position isEqualTo objNull) exitWith { INFO("Invalid position. Exiting.") };

if (_position isEqualType "") then {
    _position setMarkerAlpha 0;
};

private _id = format [QGVAR(spawner_%1), call FUNC(assignID)];
missionNamespace setVariable [format [QGVAR(currentGroupsActive_%1), _id], [], true];
missionNamespace setVariable [format [QGVAR(groupPoolSize_%1), _id], _groupPoolSize, true];
missionNamespace setVariable [format [QGVAR(isSpawning_%1), _id], false, true];

[{
    params ["_args", "_idPFH"];
    _args params ["_id", "_position", "_maxGroupsActive", "_factionName"];

    private _groupPoolSize = missionNamespace getVariable [format [QGVAR(groupPoolSize_%1), _id], 0];
    if (_groupPoolSize <= 0) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
    };

    private _currentGroupsActive = missionNamespace getVariable [format [QGVAR(currentGroupsActive_%1), _id], []];
    _currentGroupsActive = _currentGroupsActive select {({alive _x} count (units _x)) > 0};
    missionNamespace setVariable [format [QGVAR(currentGroupsActive_%1), _id], _currentGroupsActive, true];

    if ((count _currentGroupsActive) < _maxGroupsActive && {!(missionNamespace getVariable [format [QGVAR(isSpawning_%1), _id], false])}) then {
        [QGVAR(spawnGroup), [_id, _position, _factionName], selectRandom EGVAR(common,HCs)] call CBA_fnc_targetEvent;
    };
}, 20 + (random 10), [_id, _position, _maxGroupsActive, _factionName]] call CBA_fnc_addPerFrameHandler;
