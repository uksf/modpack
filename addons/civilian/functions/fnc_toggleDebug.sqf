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
*/
params [["_state", true, [true]]];

if (_state) then {
    [QGVAR(debugBroadcast)] call CBA_fnc_globalEvent;

    GVAR(debugDrawId) = [missionNamespace, "Draw3D", {
        {
            _x params ["_vehicle", "_sphere"];

            private _ignoreCommands = _vehicle getVariable [QGVAR(vehicle_ignoreCommands), false];
            private _boredom = _vehicle getVariable [QGVAR(boredom), 0];
            private _annoyed = _vehicle getVariable [QGVAR(annoyed), 0];
            private _text = format ["IgCom: %1 | B: %2/%3 | A: %4/%5", _ignoreCommands, _boredom, STOP_BOREDOM_THRESHOLD, _annoyed, STOP_ANNOYED_THRESHOLD];

            drawIcon3D ["", [0,0,0,1], getPosVisual _sphere, 0.5, 0.5, 0, _text, 0, 0.025, "TahomaB", "center"];
        } foreach GVAR(debugVehicleSpheres);

        {
            _x params ["_civilian", "_sphere"];

            private _ignoreCommands = _civilian getVariable [QGVAR(unit_ignoreCommands), false];
            private _boredom = _civilian getVariable [QGVAR(boredom), 0];
            private _annoyed = _civilian getVariable [QGVAR(annoyed), 0];
            private _text = format ["IgCom: %1 | B: %2/%3 | A: %4/%5", _ignoreCommands, _boredom, STOP_BOREDOM_THRESHOLD, _annoyed, STOP_ANNOYED_THRESHOLD];

            drawIcon3D ["", [0,0,0,1], getPosVisual _sphere, 0.5, 0.5, 0, _text, 0, 0.025, "TahomaB", "center"];
        } foreach GVAR(debugUnitSpheres);
    }] call CBA_fnc_addBISEventHandler;

    GVAR(debugPFHId) = [{
        private _deleteVehicleSpheres = GVAR(debugVehicleSpheres) select {_x params ["_vehicle", "_sphere"]; isNull _vehicle || {isNull _sphere}  || {(GVAR(debugVehicles) findIf {(_x#0) == _vehicle}) == -1}};
        {
            _x params ["_vehicle", "_sphere"];
            deleteVehicle _sphere;
            GVAR(debugVehicleSpheres) deleteAt (GVAR(debugVehicleSpheres) findIf {(_x#0) == _vehicle || {(_x#1) == _sphere}});
        } forEach _deleteVehicleSpheres;

        private _deleteUnitSpheres = GVAR(debugUnitSpheres) select {_x params ["_civilian", "_sphere"]; isNull _civilian || {(GVAR(debugUnits) findIf {(_x#0) == _civilian}) == -1}};
        {
            _x params ["_civilian", "_sphere"];
            deleteVehicle _sphere;
            GVAR(debugUnitSpheres) deleteAt (GVAR(debugUnitSpheres) findIf {(_x#0) == _civilian || {(_x#1) == _sphere}});
        } forEach _deleteUnitSpheres;

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
                if (_vehicle getVariable [QGVAR(vehicle_ignoreCommands), false]) exitWith {"#(rgb,8,8,3)color(0.9,1,0.8,1)"}; // Red
                if (_state == QGVAR(vehicle_state_enter)) exitWith {"#(rgb,8,8,3)color(1,0,0,1)"}; // Red
                if (_state == QGVAR(vehicle_state_stopping)) exitWith {"#(rgb,8,8,3)color(1,1,0,1)"}; // Yellow
                if (_state == QGVAR(vehicle_state_stopped)) exitWith {"#(rgb,8,8,3)color(0,1,0,1)"}; // Green
                if (_state == QGVAR(vehicle_state_move)) exitWith {"#(rgb,8,8,3)color(0.1,0.8,1,1)"}; // Cyan
                if (_state == QGVAR(vehicle_state_follow)) exitWith {"#(rgb,8,8,3)color(0.3,0.6,1,1)"}; // ?
                if (_state == QGVAR(vehicle_state_getOut)) exitWith {"#(rgb,8,8,3)color(0.2,0.4,0.2,1)"}; // ?
                if (_state == QGVAR(vehicle_state_getIn)) exitWith {"#(rgb,8,8,3)color(0.4,0.2,0.4,1)"}; // ?
                "#(rgb,8,8,3)color(1,1,1,1)"
            };
            _sphere setObjectTextureGlobal [0, _colour];

            _sphere = objNull;
            _index = GVAR(debugVehicleMoveCommandSpheres) findIf {(_x#0) == _vehicle};
            if (_index != -1) then {
                _sphere = GVAR(debugVehicleMoveCommandSpheres)#_index#1;
            };

            if (_state == QGVAR(vehicle_state_move)) then {
                private _commandPosition = _vehicle getVariable [QGVAR(vehicle_movePosition), []];
                if !(_commandPosition isEqualTo []) then {
                    if (isNull _sphere) then {
                        _sphere = createVehicle ["Sign_Sphere25cm_F", _commandPosition, [], 0, "CAN_COLLIDE"];
                        GVAR(debugVehicleMoveCommandSpheres) pushBack [_vehicle, _sphere];
                    } else {
                        _sphere setPos _commandPosition;
                    };
                } else {
                    if !(isNull _sphere) then {
                        _sphere setObjectTextureGlobal [0, "#(rgb,8,8,3)color(0,0,0,1)"];
                    };
                };
            } else {
                deleteVehicle _sphere;
                GVAR(debugVehicleMoveCommandSpheres) deleteAt (GVAR(debugVehicleMoveCommandSpheres) findIf {(_x#0) == _vehicle});
            };

            _sphere = objNull;
            _index = GVAR(debugVehicleFollowCommandSpheres) findIf {(_x#0) == _vehicle};
            if (_index != -1) then {
                _sphere = GVAR(debugVehicleFollowCommandSpheres)#_index#1;
            };

            if (_state == QGVAR(vehicle_state_follow)) then {
                private _driver = driver _vehicle;
                private _commander = _vehicle getVariable [QGVAR(vehicle_followCommander), _driver];
                if (_commander != _driver) then {
                    private _commandPosition = getPos _commander;
                    private _direction = (getPos _vehicle) vectorFromTo _commandPosition;
                    _commandPosition = _commandPosition vectorAdd (_direction vectorMultiply 2);
                    if (isNull _sphere) then {
                        _sphere = createVehicle ["Sign_Sphere25cm_F", _commandPosition, [], 0, "CAN_COLLIDE"];
                        GVAR(debugVehicleFollowCommandSpheres) pushBack [_vehicle, _sphere];
                        _sphere setObjectTextureGlobal [0, "#(rgb,8,8,3)color(1,0.5,0.5,1)"];
                    } else {
                        _sphere setPos _commandPosition;
                    };
                } else {
                    if !(isNull _sphere) then {
                        _sphere setObjectTextureGlobal [0, "#(rgb,8,8,3)color(1,0,0,1)"];
                    };
                };
            } else {
                deleteVehicle _sphere;
                GVAR(debugVehicleFollowCommandSpheres) deleteAt (GVAR(debugVehicleFollowCommandSpheres) findIf {(_x#0) == _vehicle});
            };
        } forEach GVAR(debugVehicles);

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
                if (_civilian getVariable [QGVAR(unit_ignoreCommands), false]) exitWith {"#(rgb,8,8,3)color(0.9,1,0.8,1)"}; // Red
                if (_state == QGVAR(unit_state_enter)) exitWith {"#(rgb,8,8,3)color(1,0,0,1)"}; // Red
                if (_state == QGVAR(unit_state_stopped)) exitWith {"#(rgb,8,8,3)color(0,1,0,1)"}; // Green
                if (_state == QGVAR(unit_state_move)) exitWith {"#(rgb,8,8,3)color(0.1,0.8,1,1)"}; // Cyan
                if (_state == QGVAR(unit_state_follow)) exitWith {"#(rgb,8,8,3)color(1,1,0,1)"}; // ?
                "#(rgb,8,8,3)color(1,1,1,1)"
            };
            _sphere setObjectTextureGlobal [0, _colour];

            _sphere = objNull;
            _index = GVAR(debugUnitMoveCommandSpheres) findIf {(_x#0) == _civilian};
            if (_index != -1) then {
                _sphere = GVAR(debugUnitMoveCommandSpheres)#_index#1;
            };

            if (_state == QGVAR(unit_state_move)) then {
                private _commandPosition = _civilian getVariable [QGVAR(unit_movePosition), []];
                if !(_commandPosition isEqualTo []) then {
                    if (isNull _sphere) then {
                        _sphere = createVehicle ["Sign_Sphere25cm_F", _commandPosition, [], 0, "CAN_COLLIDE"];
                        GVAR(debugUnitMoveCommandSpheres) pushBack [_civilian, _sphere];
                    } else {
                        _sphere setPos _commandPosition;
                    };
                } else {
                    if !(isNull _sphere) then {
                        _sphere setObjectTextureGlobal [0, "#(rgb,8,8,3)color(0,0,0,1)"];
                    };
                };
            } else {
                deleteVehicle _sphere;
                GVAR(debugUnitMoveCommandSpheres) deleteAt (GVAR(debugUnitMoveCommandSpheres) findIf {(_x#0) == _civilian});
            };

            _sphere = objNull;
            _index = GVAR(debugUnitFollowCommandSpheres) findIf {(_x#0) == _civilian};
            if (_index != -1) then {
                _sphere = GVAR(debugUnitFollowCommandSpheres)#_index#1;
            };

            if (_state == QGVAR(unit_state_follow)) then {
                private _commander = _civilian getVariable [QGVAR(unit_followCommander), _civilian];
                if (_commander != _civilian) then {
                    private _commandPosition = getPos _commander;
                    private _direction = (getPos _civilian) vectorFromTo _commandPosition;
                    _commandPosition = _commandPosition vectorAdd (_direction vectorMultiply -2);
                    if (isNull _sphere) then {
                        _sphere = createVehicle ["Sign_Sphere25cm_F", _commandPosition, [], 0, "CAN_COLLIDE"];
                        GVAR(debugUnitFollowCommandSpheres) pushBack [_civilian, _sphere];
                        _sphere setObjectTextureGlobal [0, "#(rgb,8,8,3)color(1,0.5,0.5,1)"];
                    } else {
                        _sphere setPos _commandPosition;
                    };
                } else {
                    if !(isNull _sphere) then {
                        _sphere setObjectTextureGlobal [0, "#(rgb,8,8,3)color(1,0,0,1)"];
                    };
                };
            } else {
                deleteVehicle _sphere;
                GVAR(debugUnitFollowCommandSpheres) deleteAt (GVAR(debugUnitFollowCommandSpheres) findIf {(_x#0) == _civilian});
            };
        } forEach GVAR(debugUnits);
    }, 0] call CBA_fnc_addPerFrameHandler;
} else {
    [QGVAR(debugStopBroadcast)] call CBA_fnc_globalEvent;

    missionNamespace removeEventHandler ["Draw3D", GVAR(debugDrawId)];
    [GVAR(debugPFHId)] call CBA_fnc_removePerFrameHandler;

    {deleteVehicle (_x#1)} foreach GVAR(debugVehicleSpheres);
    {deleteVehicle (_x#1)} foreach GVAR(debugVehicleMoveCommandSpheres);
    {deleteVehicle (_x#1)} foreach GVAR(debugVehicleFollowCommandSpheres);
    {deleteVehicle (_x#1)} foreach GVAR(debugUnitSpheres);
    {deleteVehicle (_x#1)} foreach GVAR(debugUnitMoveCommandSpheres);
    {deleteVehicle (_x#1)} foreach GVAR(debugUnitFollowCommandSpheres);
    GVAR(debugVehicles) = [];
    GVAR(debugUnits) = [];
    GVAR(debugVehicleSpheres) = [];
    GVAR(debugVehicleMoveCommandSpheres) = [];
    GVAR(debugVehicleFollowCommandSpheres) = [];
    GVAR(debugUnitSpheres) = [];
    GVAR(debugUnitMoveCommandSpheres) = [];
    GVAR(debugUnitFollowCommandSpheres) = [];
};
