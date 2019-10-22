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

["CAManBase", "respawn", {
    call FUNC(addPersistenceActions);
}] call CBA_fnc_addClassEventHandler;

["ace_throwableThrown", {
    params ["", "_throwable"];
    if (_throwable isKindOf QGVAR(markerAmmo)) then {
        [QGVAR(addLogisticsMarker), _throwable] call CBA_fnc_serverEvent;
    };
}] call CBA_fnc_addEventHandler;

["created", {
    private _serializedMarker = call FUNC(serializeMarker);
    if (count _serializedMarker > 0) then {
        [QGVAR(markerCreated), [_serializedMarker]] call CBA_fnc_serverEvent;
    };
}] call CBA_fnc_addMarkerEventHandler;

["deleted", {
    [QGVAR(markerDeleted), _this] call CBA_fnc_serverEvent;
}] call CBA_fnc_addMarkerEventHandler;

[QGVAR(firstKilled), {
    GVAR(data) = _this;
    TRACE_1("Client first killed",GVAR(data));
    GVAR(data) params ["_position"];
    //_positionData params ["_position", "_leaderID", "_leaderPosition", "_leaderDirection", "_offset"];

    /*if (_leaderID != -1) then {
        private _leader = allPlayers select {(getPlayerUID _x) == _leaderID};
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

    GVAR(respawn) = createMarkerLocal [RESPAWN_MARKER, _position];
    GVAR(respawn) setMarkerTypeLocal "flag_UK";
    GVAR(respawn) setMarkerTextLocal RESPAWN_NAME;
}] call CBA_fnc_addEventHandler;

[QGVAR(firstRespawn), {
    GVAR(data) params ["_position", "_vehicleState", "_direction", "_animation", "_loadout", "_damage", "_aceStates", "_earplugs", "_attached", "_radios"];
    //_positionData params ["_position", "_leaderID", "_leaderPosition", "_leaderDirection", "_relativePosition"];

    if (!isNil QGVAR(respawn)) then {
        deleteMarkerLocal GVAR(respawn);
    };
    /*if (!isNil QGVAR(groupRespawn)) then {
        deleteMarkerLocal GVAR(groupRespawn);
    };*/

    if (count GVAR(data) > 0 && {(_position distance2D (getPos player)) < 10}) then {
        player setDir _direction;
        player setUnitLoadout _loadout;
        player setDamage _damage;
        [player, _aceStates] call EFUNC(common,deserializeAceMedical);
        player setVariable ["ACE_hasEarPlugsIn", _earplugs, true];
        {[player, player, [_x], true] call ace_attach_fnc_attach} forEach _attached;
        [{
            call EFUNC(radios,deserializeRadios);
        }, [_radios], 2] call CBA_fnc_waitAndExecute;

        _vehicleState params ["_vehicleId"];
        if (_vehicleId != "") then {
            [QGVAR(onPersistentVehicleExists), {
                params ["_vehicle", "_vehicleId", "_role", "_index"];
                [_thisType, _thisId] call CBA_fnc_removeEventHandler;

                if (isNull _vehicle) exitWith {};

                switch (toLower _role) do {
                    case "driver": {player moveInDriver _vehicle};
                    case "gunner": {player moveInGunner _vehicle};
                    case "commander": {player moveInCommander _vehicle};
                    case "turret": {player moveInTurret [_vehicle, _index]};
                    default {player moveInCargo [_vehicle, _index]};
                };
            }] call CBA_fnc_addEventHandlerArgs;
            [QGVAR(checkPersistentVehicleExists), [_vehicleState, player]] call CBA_fnc_serverEvent;
        } else {
            [{
                player playMove ([_this, ANIM_STANDING] select (_this == ANIM_STANDING));
            }, _animation, 0.2] call CBA_fnc_waitAndExecute;
        };

        [[true]] call ace_hearing_fnc_updateVolume;
        [] call ace_hearing_fnc_updateHearingProtection;
    };
}] call CBA_fnc_addEventHandler;
