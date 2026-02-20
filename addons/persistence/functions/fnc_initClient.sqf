#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Initialises persistence event handlers on client

    Parameter(s):
        None

    Return Value:
        None
*/

GVAR(persistentObjects) = [];
GVAR(abortedObjectIds) = [];
GVAR(unmarkedObjectIds) = [];
GVAR(persistentObjectIconsPFHID) = -1;
GVAR(abortedObjects) = [];
GVAR(abortedObjectInteractionObjects) = [];
GVAR(abortedObjectPFHID) = -1;
GVAR(persistenceMarkersPFHID) = -1;
GVAR(persistenceMarkerPositions) = [];
GVAR(disconnectedPositionsPFHID) = -1;
GVAR(disconnectedPositionData) = [];
GVAR(saveProgressPFHID) = -1;
GVAR(selectedRespawn) = "";

["ace_throwableThrown", {
    params ["", "_throwable"];
    if (_throwable isKindOf QGVAR(markerAmmo)) then {
        [QGVAR(addLogisticsMarker), _throwable] call CBA_fnc_serverEvent;
    };
}] call CBA_fnc_addEventHandler;

addMissionEventHandler ["MarkerCreated", {
    params ["_marker", "_channelNumber", "", "_local"];

    if (!_local || _channelNumber != 1) exitWith {};

    private _serializedMarker = call FUNC(serializeMarker);
    if (count _serializedMarker > 0) then {
        [QGVAR(markerCreated), [_serializedMarker]] call CBA_fnc_serverEvent;
    };
}];

addMissionEventHandler ["MarkerUpdated", {
    params ["_marker", "_local"];

    if (!_local || (markerChannel _marker) != 1) exitWith {};

    private _serializedMarker = call FUNC(serializeMarker);
    if (count _serializedMarker > 0) then {
        [QGVAR(markerCreated), [_serializedMarker]] call CBA_fnc_serverEvent;
    };
}];

addMissionEventHandler ["MarkerDeleted", {
    params ["_marker", "_local"];

    if (!_local) exitWith {};

    [QGVAR(markerDeleted), _this] call CBA_fnc_serverEvent;
}];

["loadout", {
    player setVariable [QGVAR(facewear), goggles player, true];
}] call CBA_fnc_addPlayerEventHandler;

[QGVAR(receiveRedeployData), {
    GVAR(data) = _this;
    TRACE_1("Receiving redeploy data",GVAR(data));
    GVAR(data) params ["_position"];

    if (_position isEqualTo [0,0,0] || _position distance2D [0,0,0] < 50) exitWith {
        ERROR_1("Invalid redeploy position: %1",_position);
    };

    GVAR(respawn) = createMarkerLocal [RESPAWN_MARKER, _position];
    GVAR(respawn) setMarkerTypeLocal "flag_UK";
    GVAR(respawn) setMarkerTextLocal RESPAWN_NAME;
}] call CBA_fnc_addEventHandler;

[QGVAR(receivePersistentObjectsHash), {GVAR(persistentObjects) = _this#0}] call CBA_fnc_addEventHandler;
[QGVAR(receiveAbortedObjects), {call FUNC(showAbortedObjects)}] call CBA_fnc_addEventHandler;

[QGVAR(firstRespawn), {call FUNC(loadRedeployData)}] call CBA_fnc_addEventHandler;

[QGVAR(removeAbortedObject), {
    params ["_id"];

    private _interactionObjectIndex = GVAR(abortedObjectInteractionObjects) findIf {_x#0 == _id};
    if (_interactionObjectIndex != -1) then {
        deleteVehicle (GVAR(abortedObjectInteractionObjects)#_interactionObjectIndex#1);
    };
    GVAR(abortedObjectInteractionObjects) deleteAt _interactionObjectIndex;
    GVAR(abortedObjects) deleteAt (GVAR(abortedObjects) findIf {_x#0 == _id});

    if (GVAR(abortedObjectPFHID) != -1 && {GVAR(abortedObjects) isEqualTo []}) then {
        [GVAR(abortedObjectPFHID)] call CBA_fnc_removePerFrameHandler;
    };
}] call CBA_fnc_addEventHandler;

[QGVAR(receivePersistenceMarkers), {GVAR(persistenceMarkerPositions) = _this#0}] call CBA_fnc_addEventHandler;
[QGVAR(receiveDisconnectedPositions), {GVAR(disconnectedPositionData) = _this#0}] call CBA_fnc_addEventHandler;

[QGVAR(receiveInspectSavedData), {
    params ["_lines"];
    {systemChat _x} forEach _lines;
}] call CBA_fnc_addEventHandler;

