#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Runs paradrop procedure from paradrop module

    Parameter(s):
        0: Units to drop <ARRAY>
        1: Drop start position <ARRAY>
        2: Drop end position <ARRAY>
        3: Drop altitude <SCALAR>

    Return Value:
        None
*/
#define BASE_SPEED 60
#define CREW_LOADOUT [[],[],[],[],["UKSF_V_Pilot",[]],[],"UK3CB_BAF_H_PilotHelmetHeli_A","",[],["ItemMap","","","ItemCompass","ItemWatch",""]]

params ["_units", "_dropStartPosition", "_dropEndPosition", ["_altitude", 6000]];

if (!isServer) exitWith {
    [QGVAR(paradrop), _this] call CBA_fnc_serverEvent;
};

_altitude = _altitude / 3.28084; // Convert feet to metres

["Paradrop for %1 units", count _units] call ace_zeus_fnc_showMessage;
[QEGVAR(common,textTiles), [parseText format ["<t align = 'center' size = '1.2' color = '#00CC00'>STANDBY FOR C-130 PICKUP</t>"], [0.25, 1, 0.5, 0.05], [1, 1], 2.5], _units] call CBA_fnc_targetEvent;

private _speed = BASE_SPEED + (random 10);
private _vectorDirection = _dropStartPosition vectorFromTo _dropEndPosition;
private _heading = (_vectorDirection#0) atan2 (_vectorDirection#1);
private _flightStartPosition = _dropStartPosition getPos [3000, _heading - 180];
private _flightEndPosition = _dropEndPosition getPos [1000, _heading];
private _unitReturnPosition = _dropStartPosition getPos [(_dropStartPosition distance2D _dropEndPosition) / 2, _heading];
_flightStartPosition set [2, _altitude];
_flightEndPosition set [2, _altitude];
_unitReturnPosition set [2, 0.05];

private _plane = createVehicle [QEGVAR(air_c130,raf), [0, 0, _altitude], [], 0, "FLY"];
createVehicleCrew _plane;
{_x setUnitLoadout CREW_LOADOUT} forEach crew _plane;
_plane setPosASL _flightStartPosition;
_plane setVectorDirAndUp [_vectorDirection, [0, 0, 1]];
_plane setVelocity (_vectorDirection vectorMultiply _speed);
_plane forceSpeed _speed;
_plane setVariable ["acex_headless_blacklist", true, true];

private _pilot = driver _plane;
_pilot disableAi "LIGHTS";
_plane setCollisionLight true;

private _group = group _pilot;
_group setVariable ["acex_headless_blacklist", true, true];
_group setSpeedMode "LIMITED";
_group setBehaviourStrong "CARELESS";

private _waypoint = _group addWaypoint [_flightEndPosition, -1]; // ASL when radius negative
_waypoint setWaypointCompletionRadius 0;
_waypoint setWaypointBehaviour "CARELESS";

_plane flyInHeight ((_altitude - 500) max 100);
_plane flyInHeightASL [_altitude, _altitude, _altitude];

[{
    params ["_args", "_idPFH"];
    _args params ["_plane", "_units", "_altitude", "_dropStartPosition", "_dropEndPosition", "_flightEndPosition", "_unitReturnPosition", ["_previousDistanceStart", 99999], ["_previousDistanceEnd", 99999], ["_states", [false, false, false, false]]];
    _states params ["_unitsIn", "_positionPreStartReached", "_flightStartPositionReached", "_flightEndPositionReached"];

    private _position = getPosASL _plane;
    if (!(alive _plane) || {(_position distance2D _flightEndPosition) < 100}) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
        private _remainingUnits = _units select {vehicle _x == _plane};
        {
            moveOut _x;
            [QGVAR(paradropFail), [_x, _unitReturnPosition], _x] call CBA_fnc_targetEvent;
        } forEach _remainingUnits;
        {deleteVehicle _x} forEach (crew _plane);
        deleteVehicle _plane;
    };

    if (!_unitsIn && {(_position distance2D _dropStartPosition) < 2500}) then {
        _states set [0, true];
        {
            [{
                [QGVAR(moveInCargo), _this, _this#0] call CBA_fnc_targetEvent;
            }, [_x, _plane], (0.5 * _forEachIndex) + 1] call CBA_fnc_waitAndExecute;
        } forEach _units;
    };

    if (!_positionPreStartReached && {(_position distance2D _dropStartPosition) < 1000}) then {
        _positionPreStartReached = true;
        _states set [1, true];
        [_plane, 1] call EFUNC(air_c130,jumpLightControl);
        [_plane, 1] call EFUNC(air_c130,rampControl);
        [QEGVAR(common,textTiles), [parseText format ["<t align = 'center' size = '1.2' color = '#FF0000'>RED LIGHT - STANDBY FOR JUMP</t>"], [0.25, 1, 0.5, 0.05], [1, 1], 2.5], _units] call CBA_fnc_targetEvent;
    };

    if (_positionPreStartReached && !_flightStartPositionReached) then {
        private _distance = _position distance2D _dropStartPosition;
        if (_distance > _previousDistanceStart) then {
            _states set [2, true];
            [_plane, 2] call EFUNC(air_c130,jumpLightControl);
            [QEGVAR(common,textTiles), [parseText format ["<t align = 'center' size = '1.2' color = '#00CC00'>GREEN LIGHT - JUMP</t>"], [0.25, 1, 0.5, 0.05], [1, 1], 2.5], _units] call CBA_fnc_targetEvent;
        };

        _args set [7, _distance];
    };

    if (_positionPreStartReached && _flightStartPositionReached && !_flightEndPositionReached) then {
        private _distance = _position distance2D _dropEndPosition;
        if (_distance > _previousDistanceEnd) then {
            _states set [3, true];
            [_plane, 0] call EFUNC(air_c130,rampControl);
            [_plane, 1] call EFUNC(air_c130,jumpLightControl);
            private _remainingUnits = assignedCargo _plane;
            {
                [QEGVAR(common,textTiles), [parseText format ["<t align = 'center' size = '1.2' color = '#FF0000'>RED LIGHT - DON'T JUMP</t>"], [0.25, 1, 0.5, 0.05], [1, 1], 5], _x] call CBA_fnc_targetEvent;
            } forEach _remainingUnits;
        };

        _args set [8, _distance];
    };

    _args set [9, _states];
}, 3, [_plane, _units, _altitude, _dropStartPosition, _dropEndPosition, _flightEndPosition, _unitReturnPosition]] call CBA_fnc_addPerFrameHandler;
