#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Toggle debug visualisations

    Parameters:
        0: State <BOOLEAN>

    Return value:
        Nothing

    Example:
        [_state] call uksf_civilian_fnc_toggleDebug
*/
params [["_state", true, [true]]];

if (_state) then {
    [QGVAR(debugBroadcast)] call CBA_fnc_globalEvent;

    GVAR(debugDrawId) = [missionNamespace, "Draw3D", {
        {
            _x params ["_entity", "_sphere"];

            private _ignoreCommandsKey = if (_entity isKindOf "Car" || {_entity isKindOf "Tank"}) then {
                QGVAR(vehicle_ignoreCommands)
            } else {
                QGVAR(unit_ignoreCommands)
            };
            private _ignoreCommands = _entity getVariable [_ignoreCommandsKey, false];
            private _boredom = _entity getVariable [QGVAR(boredom), 0];
            private _annoyed = _entity getVariable [QGVAR(annoyed), 0];
            private _text = format ["IgCom: %1 | B: %2/%3 | A: %4/%5", _ignoreCommands, _boredom, STOP_BOREDOM_THRESHOLD, _annoyed, STOP_ANNOYED_THRESHOLD];

            drawIcon3D ["", [0,0,0,1], getPosVisual _sphere, 0.5, 0.5, 0, _text, 0, 0.025, "TahomaB", "center"];
        } forEach (GVAR(debugVehicleSpheres) + GVAR(debugUnitSpheres));
    }] call CBA_fnc_addBISEventHandler;

    GVAR(debugPFHId) = [{
        // Prune stale vehicle spheres
        private _deleteSpheres = GVAR(debugVehicleSpheres) select {_x params ["_vehicle", "_sphere"]; isNull _vehicle || {isNull _sphere} || {(GVAR(debugVehicles) findIf {(_x#0) == _vehicle}) == -1}};
        {
            _x params ["_vehicle", "_sphere"];
            deleteVehicle _sphere;
            GVAR(debugVehicleSpheres) deleteAt (GVAR(debugVehicleSpheres) findIf {(_x#0) == _vehicle || {(_x#1) == _sphere}});
        } forEach _deleteSpheres;

        // Prune stale unit spheres
        _deleteSpheres = GVAR(debugUnitSpheres) select {_x params ["_civilian"]; isNull _civilian || {(GVAR(debugUnits) findIf {(_x#0) == _civilian}) == -1}};
        {
            _x params ["_civilian", "_sphere"];
            deleteVehicle _sphere;
            GVAR(debugUnitSpheres) deleteAt (GVAR(debugUnitSpheres) findIf {(_x#0) == _civilian || {(_x#1) == _sphere}});
        } forEach _deleteSpheres;

        // Update vehicle spheres
        {
            _x params ["_vehicle", "_state"];

            private _index = GVAR(debugVehicleSpheres) findIf {(_x#0) == _vehicle};
            private _sphere = objNull;
            if (_index != -1) then {
                _sphere = GVAR(debugVehicleSpheres)#_index#1;
            } else {
                _sphere = "Sign_Sphere100cm_F" createVehicle [0,0,0];
                GVAR(debugVehicleSpheres) pushBack [_vehicle, _sphere];
                _sphere attachTo [_vehicle, [0,0,1]];
            };

            private _colour = _x call {
                params ["_vehicle", "_state"];
                if (_vehicle getVariable [QGVAR(vehicle_ignoreCommands), false]) exitWith {"#(rgb,8,8,3)color(0.9,1,0.8,1)"};
                if (_state == QGVAR(vehicle_state_enter)) exitWith {"#(rgb,8,8,3)color(1,0,0,1)"};
                if (_state == QGVAR(vehicle_state_stopping)) exitWith {"#(rgb,8,8,3)color(1,1,0,1)"};
                if (_state == QGVAR(vehicle_state_stopped)) exitWith {"#(rgb,8,8,3)color(0,1,0,1)"};
                if (_state == QGVAR(vehicle_state_move)) exitWith {"#(rgb,8,8,3)color(0.1,0.8,1,1)"};
                if (_state == QGVAR(vehicle_state_follow)) exitWith {"#(rgb,8,8,3)color(0.3,0.6,1,1)"};
                if (_state == QGVAR(vehicle_state_getOut)) exitWith {"#(rgb,8,8,3)color(0.2,0.4,0.2,1)"};
                if (_state == QGVAR(vehicle_state_getIn)) exitWith {"#(rgb,8,8,3)color(0.4,0.2,0.4,1)"};
                "#(rgb,8,8,3)color(1,1,1,1)"
            };
            _sphere setObjectTextureGlobal [0, _colour];
            _sphere setObjectMaterialGlobal [0, "A3\data_f\default.rvmat"];

            // Move command sphere
            private _movePosition = _vehicle getVariable [QGVAR(vehicle_movePosition), []];
            [_vehicle, _state == QGVAR(vehicle_state_move), GVAR(debugVehicleMoveCommandSpheres), _movePosition, "#(rgb,8,8,3)color(0,0,0,1)"] call FUNC(debugUpdateCommandSphere);

            // Follow command sphere
            private _followPosition = [];
            if (_state == QGVAR(vehicle_state_follow)) then {
                private _driver = driver _vehicle;
                private _commander = _vehicle getVariable [QGVAR(vehicle_followCommander), _driver];
                if (_commander != _driver) then {
                    _followPosition = getPos _commander;
                    private _direction = (getPos _vehicle) vectorFromTo _followPosition;
                    _followPosition = _followPosition vectorAdd (_direction vectorMultiply -3);
                };
            };

            private _followIndex = GVAR(debugVehicleFollowCommandSpheres) findIf {(_x#0) == _vehicle};
            private _followSphere = if (_followIndex != -1) then {GVAR(debugVehicleFollowCommandSpheres)#_followIndex#1} else {objNull};

            if (_state == QGVAR(vehicle_state_follow)) then {
                if (_followPosition isNotEqualTo []) then {
                    if (isNull _followSphere) then {
                        _followSphere = createVehicle ["Sign_Sphere25cm_F", _followPosition, [], 0, "CAN_COLLIDE"];
                        GVAR(debugVehicleFollowCommandSpheres) pushBack [_vehicle, _followSphere];
                        _followSphere setObjectTextureGlobal [0, "#(rgb,8,8,3)color(1,0.5,0.5,1)"];
                    } else {
                        _followSphere setPos _followPosition;
                    };
                } else {
                    if (!isNull _followSphere) then {
                        _followSphere setObjectTextureGlobal [0, "#(rgb,8,8,3)color(1,0,0,1)"];
                    };
                };
            } else {
                deleteVehicle _followSphere;
                if (_followIndex != -1) then {
                    GVAR(debugVehicleFollowCommandSpheres) deleteAt _followIndex;
                };
            };
        } forEach GVAR(debugVehicles);

        // Update unit spheres
        {
            _x params ["_civilian", "_state"];

            private _index = GVAR(debugUnitSpheres) findIf {(_x#0) == _civilian};
            private _sphere = objNull;
            if (_index != -1) then {
                _sphere = GVAR(debugUnitSpheres)#_index#1;
            } else {
                _sphere = "Sign_Sphere25cm_F" createVehicle [0,0,0];
                GVAR(debugUnitSpheres) pushBack [_civilian, _sphere];
                _sphere attachTo [_civilian, [0,0,2]];
            };

            private _colour = _x call {
                params ["_civilian", "_state"];
                if (_civilian getVariable [QGVAR(unit_ignoreCommands), false]) exitWith {"#(rgb,8,8,3)color(0.9,1,0.8,1)"};
                if (_state == QGVAR(unit_state_enter)) exitWith {"#(rgb,8,8,3)color(1,0,0,1)"};
                if (_state == QGVAR(unit_state_stopped)) exitWith {"#(rgb,8,8,3)color(0,1,0,1)"};
                if (_state == QGVAR(unit_state_move)) exitWith {"#(rgb,8,8,3)color(0.1,0.8,1,1)"};
                if (_state == QGVAR(unit_state_follow)) exitWith {"#(rgb,8,8,3)color(1,1,0,1)"};
                "#(rgb,8,8,3)color(1,1,1,1)"
            };
            _sphere setObjectTextureGlobal [0, _colour];
            _sphere setObjectMaterialGlobal [0, "A3\data_f\default.rvmat"];

            // Move command sphere
            private _movePosition = _civilian getVariable [QGVAR(unit_movePosition), []];
            [_civilian, _state == QGVAR(unit_state_move), GVAR(debugUnitMoveCommandSpheres), _movePosition, "#(rgb,8,8,3)color(0,0,0,1)"] call FUNC(debugUpdateCommandSphere);

            // Follow command sphere
            private _followPosition = [];
            if (_state == QGVAR(unit_state_follow)) then {
                private _commander = _civilian getVariable [QGVAR(unit_followCommander), _civilian];
                if (_commander != _civilian) then {
                    _followPosition = getPos _commander;
                    private _direction = (getPos _civilian) vectorFromTo _followPosition;
                    _followPosition = _followPosition vectorAdd (_direction vectorMultiply -2);
                };
            };

            private _followIndex = GVAR(debugUnitFollowCommandSpheres) findIf {(_x#0) == _civilian};
            private _followSphere = if (_followIndex != -1) then {GVAR(debugUnitFollowCommandSpheres)#_followIndex#1} else {objNull};

            if (_state == QGVAR(unit_state_follow)) then {
                if (_followPosition isNotEqualTo []) then {
                    if (isNull _followSphere) then {
                        _followSphere = createVehicle ["Sign_Sphere25cm_F", _followPosition, [], 0, "CAN_COLLIDE"];
                        GVAR(debugUnitFollowCommandSpheres) pushBack [_civilian, _followSphere];
                        _followSphere setObjectTextureGlobal [0, "#(rgb,8,8,3)color(1,0.5,0.5,1)"];
                    } else {
                        _followSphere setPos _followPosition;
                    };
                } else {
                    if (!isNull _followSphere) then {
                        _followSphere setObjectTextureGlobal [0, "#(rgb,8,8,3)color(1,0,0,1)"];
                    };
                };
            } else {
                deleteVehicle _followSphere;
                if (_followIndex != -1) then {
                    GVAR(debugUnitFollowCommandSpheres) deleteAt _followIndex;
                };
            };
        } forEach GVAR(debugUnits);
    }, 0] call CBA_fnc_addPerFrameHandler;
} else {
    [QGVAR(debugStopBroadcast)] call CBA_fnc_globalEvent;

    removeMissionEventHandler ["Draw3D", GVAR(debugDrawId)];
    [GVAR(debugPFHId)] call CBA_fnc_removePerFrameHandler;

    {deleteVehicle (_x#1)} forEach GVAR(debugVehicleSpheres);
    {deleteVehicle (_x#1)} forEach GVAR(debugVehicleMoveCommandSpheres);
    {deleteVehicle (_x#1)} forEach GVAR(debugVehicleFollowCommandSpheres);
    {deleteVehicle (_x#1)} forEach GVAR(debugUnitSpheres);
    {deleteVehicle (_x#1)} forEach GVAR(debugUnitMoveCommandSpheres);
    {deleteVehicle (_x#1)} forEach GVAR(debugUnitFollowCommandSpheres);
    GVAR(debugVehicles) = [];
    GVAR(debugUnits) = [];
    GVAR(debugVehicleSpheres) = [];
    GVAR(debugVehicleMoveCommandSpheres) = [];
    GVAR(debugVehicleFollowCommandSpheres) = [];
    GVAR(debugUnitSpheres) = [];
    GVAR(debugUnitMoveCommandSpheres) = [];
    GVAR(debugUnitFollowCommandSpheres) = [];
};
