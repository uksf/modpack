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
GVAR(dontDeleteObjectIds) = [];
GVAR(unmarkedObjectIds) = [];
GVAR(persistentObjectIconsPFHID) = -1;
GVAR(abortedObjects) = [];
GVAR(abortedObjectInteractionObjects) = [];
GVAR(abortedObjectPFHID) = -1;
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

[QGVAR(receiveRedeployData), {
    GVAR(data) = _this;
    TRACE_1("Receiving redeploy data",GVAR(data));
    GVAR(data) params ["_position"];
    //_positionData params ["_position", "_leaderID", "_leaderPosition", "_leaderDirection", "_offset"];

    /*if (_leaderID != -1) then {
        private _leader = ALL_PLAYERS select {(getPlayerUID _x) == _leaderID};
        if (_leader > 0) then { // leader online, calculate relative position from leader position and offset
            _leader = _leader#0;
            _leaderPosition = getPosASL _leader;
            _leaderPosition = _leader modelToWorld _offset;
        } else { // leader offline, calculate relative position from stored position, direction, and offset

        };
        GVAR(groupRespawn) = createMarkerLocal [RESPAWN_GROUP_MARKER, _position];
        GVAR(groupRespawn) setMarkerTypeLocal "flag_UK";
        GVAR(groupRespawn) setMarkerTextLocal RESPAWN_GROUP_NAME;
    };*/

    if (_position isEqualTo [0,0,0] || _position distance2D [0,0,0] < 50) exitWith {
        ERROR_1("Invalid redeploy position: %1", _position);
    };

    GVAR(respawn) = createMarkerLocal [RESPAWN_MARKER, _position];
    GVAR(respawn) setMarkerTypeLocal "flag_UK";
    GVAR(respawn) setMarkerTextLocal RESPAWN_NAME;
}] call CBA_fnc_addEventHandler;

[QGVAR(receivePersistentObjectsHash), {GVAR(persistentObjects) = _this#0}] call CBA_fnc_addEventHandler;
[QGVAR(receiveAbortedObjects), {call FUNC(showAbortedObjects)}] call CBA_fnc_addEventHandler;

[QGVAR(firstRespawn), {
    GVAR(data) params ["_position", "_vehicleState", "_direction", "_animation", "_loadout", "_damage", "_aceStates", "_earplugs", "_attached", "_radios", ["_diveState", [false]]];
    TRACE_1("First respawn",GVAR(data));
    //_positionData params ["_position", "_leaderID", "_leaderPosition", "_leaderDirection", "_relativePosition"];

    if !(isNil QGVAR(respawn)) then {
        [{deleteMarkerLocal GVAR(respawn);}, [], 1] call CBA_fnc_waitAndExecute;
    };
    /*if !(isNil QGVAR(groupRespawn)) then {
        deleteMarkerLocal GVAR(groupRespawn);
    };*/

    TRACE_1("Respawned at",GVAR(selectedRespawn));

    if (count GVAR(data) > 0 && {GVAR(selectedRespawn) == RESPAWN_MARKER || {(_position distance2D (getPos player)) < 10}}) then {
        DEBUG("Respawn is persistence load");
        player setDir _direction;
        player setPosASL _position;
        player setUnitLoadout _loadout;
        player setDamage _damage;

        [player, _aceStates] call EFUNC(common,deserializeAceMedical);
        player setVariable ["ACE_hasEarPlugsIn", _earplugs, true];
        {[player, player, [_x], true] call ace_attach_fnc_attach} forEach _attached;

        [{call EFUNC(radios,deserializeRadios)}, [_radios], 2] call CBA_fnc_waitAndExecute;

        _vehicleState params ["_vehicleId"];
        if (_vehicleId != "") then {
            [QGVAR(onPersistentVehicleExists), {
                params ["_vehicle", "_vehicleId", "_role", "_index"];
                [_thisType, _thisId] call CBA_fnc_removeEventHandler;

                if (isNull _vehicle) exitWith {};

                switch (_role) do {
                    case "driver": {player moveInDriver _vehicle};
                    case "gunner": {player moveInGunner _vehicle};
                    case "commander": {player moveInCommander _vehicle};
                    case "turret": {player moveInTurret [_vehicle, _index]};
                    default {player moveInCargo [_vehicle, _index]};
                };

                if (objectParent player != _vehicle) then {
                    player moveInCargo _vehicle;
                };
            }] call CBA_fnc_addEventHandlerArgs;
            [QGVAR(checkPersistentVehicleExists), [_vehicleState, player]] call CBA_fnc_serverEvent;
        } else {
            [{
                params ["_position", "_animation"];

                player setPosASL _position;
                player playMove _animation;
            }, [_position, _animation], 0.5] call CBA_fnc_waitAndExecute;
        };

        [[true]] call ace_hearing_fnc_updateVolume;
        [] call ace_hearing_fnc_updateHearingProtection;

        [_diveState] call EFUNC(diving,deserialiseState);
    };
}] call CBA_fnc_addEventHandler;

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
