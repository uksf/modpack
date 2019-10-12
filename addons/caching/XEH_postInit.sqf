#include "script_component.hpp"
#define SERVER_DELAY 3
#define CLIENT_DELAY 1

if (!GVAR(enabled)) exitWith {
    INFO("Caching is disabled.");
    // enableDynamicSimulationSystem false;
};

INFO("Caching is enabled.");
// enableDynamicSimulationSystem true;
// "Group" setDynamicSimulationDistance GVAR(distance);
// "Vehicle" setDynamicSimulationDistance GVAR(distance);
// "EmptyVehicle" setDynamicSimulationDistance 250;
// "Prop" setDynamicSimulationDistance 50;
// "IsMoving" setDynamicSimulationDistanceCoef 1.5;

if (isServer) then {
    [{
        private _groups = allGroups select {!(_x getVariable [QGVAR(excluded), false])};
        private _count = count _groups;
        private _perFrame = ceil (_count / (diag_fpsMin * SERVER_DELAY));
        [{
            params ["_args", "_idPFH"];
            _args params ["_groups", "_count", "_perFrame", "_index"];
            
            if (_index > _count) exitWith {
                [_idPFH] call CBA_fnc_removePerFrameHandler;
            };

            [_groups select [_index, _perFrame]] call FUNC(checkGroupsServer);

            _args set [3, _index + _perFrame];
        }, 0, [_groups, _count, _perFrame, 0]] call cba_fnc_addPerFrameHandler;
    }, SERVER_DELAY, []] call cba_fnc_addPerFrameHandler;
};

if (hasInterface) then {
    [{
        private _groups = allGroups select {!(_x getVariable [QGVAR(excluded), false])};
        private _count = count _groups;
        private _perFrame = ceil (_count / diag_fpsMin);
        [{
            params ["_args", "_idPFH"];
            _args params ["_groups", "_count", "_perFrame", "_index"];
            
            if (_index > _count) exitWith {
                [_idPFH] call CBA_fnc_removePerFrameHandler;
            };

            [_groups select [_index, _perFrame]] call FUNC(checkGroupsClient);

            _args set [3, _index + _perFrame];
        }, 0, [_groups, _count, _perFrame, 0]] call cba_fnc_addPerFrameHandler;
    }, CLIENT_DELAY, []] call cba_fnc_addPerFrameHandler;
};

// Debug shizzle
/*
onEachFrame {
    ACE_controlledUAV params ["", "_player", "", "_seat"];
    if (isNull _player) then {
        _player = call ace_common_fnc_player;
        _seat = "GUNNER"
    };
    if (_seat != "GUNNER") exitWith {};
    private _objectViewDistance = (getObjectViewDistance#0);
    {
        private _leader = leader _x;
        if (!(isPlayer _leader)) then {
            private _colour = [1,0,0,1];
            if ((_leader distance _player) <= uksf_caching_distance) then {
                _colour = [0,0,1,1];
            };
            if ((_leader distance _player) < _objectViewDistance && {[_leader, _player, true, true] call uksf_common_fnc_lineOfSight}) then {
                _colour = [0,1,0,1];
            };
            private _text = ((_leader getVariable ["uksf_caching_time", CBA_missionTime]) - CBA_missionTime) toFixed 0;
            drawIcon3D ["\a3\ui_f_curator\data\logos\arma3_curator_eye_32_ca.paa", _colour, getPos _leader, 0.5, 0.5, 0, _text, 0, 0.025, "TahomaB", "center", true];
        };
    } count allGroups;
};
onEachFrame {
    ACE_controlledUAV params ["", "_player", "", "_seat"];
    if (isNull _player) then {
        _player = call ace_common_fnc_player;
        _seat = "GUNNER"
    };
    if (_seat != "GUNNER") exitWith {};
    (call CBA_fnc_getFov) params ["", "_zoom"];
    {
        private _leader = leader _x;
        if (!(isPlayer _leader)) then {
            private _colour = [1,0,0,1];
            private _pos = worldToScreen (getPos _leader);
            private _inView = ((count _pos) > 0 &&
                {_pos#0 > uksf_common_bufferedSafeX && _pos#0 < uksf_common_bufferedSafeW && (_pos#1 / _zoom) > uksf_common_bufferedSafeY && (_pos#1 / _zoom) < uksf_common_bufferedSafeH});
            if (_inView) then {
                _colour = [1,1,0,1];
                private _los = ([_player, "VIEW", (vehicle _player)] checkVisibility [eyePos _player, eyePos _leader]) > 0;
                if (_los) then {
                    _colour = [0,1,0,1];
                };
            };
            private _text = _leader getVariable ["uksf_caching_time", 0];
            drawIcon3D ["\a3\ui_f_curator\data\logos\arma3_curator_eye_32_ca.paa", _colour, getPosVisual _leader, 0.5, 0.5, 0, _text, 0, 0.05, "TahomaB", "center", true];
        };
    } count allGroups;
};
onEachFrame {
    ACE_controlledUAV params ["", "_player", "", "_seat"];
    if (isNull _player) then {
        _player = call ace_common_fnc_player;
        _seat = "GUNNER"
    };
    if (_seat != "GUNNER") exitWith {};
    (call CBA_fnc_getFov) params ["", "_zoom"];
    {
        private _leader = leader _x;
        if (!(isPlayer _leader)) then {
            private _colour = [1,0,0,1];
            private _pos = worldToScreen (getPos _leader);
            private _inView = ((count _pos) > 0 &&
                {_pos#0 > uksf_common_bufferedSafeX && _pos#0 < uksf_common_bufferedSafeW && (_pos#1 / _zoom) > uksf_common_bufferedSafeY && (_pos#1 / _zoom) < uksf_common_bufferedSafeH});
            if (_inView) then {
                _colour = [1,1,0,1];
                private _los = ([_player, "VIEW", (vehicle _player)] checkVisibility [eyePos _player, eyePos _leader]) > 0;
                if (_los) then {
                    _colour = [0,1,0,1];
                };
            };
            private _text = format ["%1", count _pos];
            if ((count _pos) > 0) then {
                _text = format ["%1, %2", _pos#0, (_pos#1 / _zoom)];
            };
            drawIcon3D ["\a3\ui_f_curator\data\logos\arma3_curator_eye_32_ca.paa", _colour, getPosVisual _leader, 0.5, 0.5, 0, _text, 0, 0.05, "TahomaB", "center", true];
        };
    } count allGroups;
};
onEachFrame {
    ACE_controlledUAV params ["", "_player", "", "_seat"];
    if (isNull _player) then {
        _player = call ace_common_fnc_player;
        _seat = "GUNNER"
    };
    if (_seat != "GUNNER") exitWith {};
    (call CBA_fnc_getFov) params ["", "_zoom"];
    {
        private _leader = leader _x;
        if (!(isPlayer _leader)) then {
            private _colour = [1,0,0,1];
            private _pos = worldToScreen (getPos _leader);
            private _inView = ((count _pos) > 0 &&
                {_pos#0 > uksf_common_bufferedSafeX && _pos#0 < uksf_common_bufferedSafeW && (_pos#1 / _zoom) > uksf_common_bufferedSafeY && (_pos#1 / _zoom) < uksf_common_bufferedSafeH});
            if (_inView) then {
                _colour = [1,1,0,1];
                private _los = ([_player, "VIEW", (vehicle _player)] checkVisibility [eyePos _player, eyePos _leader]) > 0;
                if (_los) then {
                    _colour = [0,1,0,1];
                };
            };
            private _text = format ["%1", count _pos];
            if ((count _pos) > 0) then {
                _text = format ["%1, %2", _pos#0, (_pos#1 / _zoom)];
            };
            drawIcon3D ["\a3\ui_f_curator\data\logos\arma3_curator_eye_32_ca.paa", _colour, getPosVisual _leader, 0.5, 0.5, 0, _text, 0, 0.05, "TahomaB", "center", true];
        };
    } count allGroups;
};
onEachFrame {
    ACE_controlledUAV params ["", "_player", "", "_seat"];
    if (isNull _player) then {
        _player = call ace_common_fnc_player;
        _seat = "GUNNER"
    };
    if (_seat != "GUNNER") exitWith {};
    {
        private _leader = leader _x;
        if (!(isPlayer _leader)) then {
            private _colour = [1,0,0,1];
            private _los = [_leader, _player, true, true] call uksf_common_fnc_lineOfSight;
            if (_los) then {
                _colour = [0,1,0,1];
            };
            private _text = "CANNOT MOVE";
            if (simulationEnabled _leader) then {
                _text = "CAN MOVE";
            };
            drawIcon3D ["\a3\ui_f_curator\data\logos\arma3_curator_eye_32_ca.paa", _colour, getPosVisual _leader, 0.5, 0.5, 0, _text, 0, 0.01, "TahomaB", "center", true];
        };
    } count allGroups;
};
/*
onEachFrame {
    ACE_controlledUAV params ["", "_player", "", "_seat"];
    if (isNull _player) then {
        _player = call ace_common_fnc_player;
        _seat = "GUNNER"
    };
    if (_seat != "GUNNER") exitWith {};
    {
        if (!(isPlayer _x)) then {
            private _colour = [1,0,0,1];
            private _pos = worldToScreen (getPosVisual _x);
            private _onScreen = (count _pos) > 0 && {_pos#0 > uksf_common_bufferedSafeX && _pos#0 < uksf_common_bufferedSafeW && _pos#1 > uksf_common_bufferedSafeY && _pos#1 < uksf_common_bufferedSafeH};
            if (_onScreen) then {
                _colour = [1,1,0,1];
                private _distanceMultiplier = (200 + (4 * 200 * (((currentVisionMode _player) - 1) max 0)));
                if (!((vehicle _x) isKindOf "CAManBase")) then {
                    _distanceMultiplier = _distanceMultiplier * 2.5;
                };
                private _distance = (getObjectViewDistance select 0) min (1000 + (_distanceMultiplier * ((call CBA_fnc_getFov) select 1)));
                private _zoom = ((_x distance _player) < _distance);
                if (_zoom) then {
                    _colour = [0,0,1,1];
                    private _los = ([_player, "VIEW", (vehicle _player)] checkVisibility [eyePos _player, eyePos _x]) > 0;
                    if (_los) then {
                        _colour = [0,1,0,1];
                    };
                };
            };
            private _text = "CANNOT MOVE";
            if (simulationEnabled _x) then {
                _text = "CAN MOVE";
            };
            drawIcon3D ["\a3\ui_f_curator\data\logos\arma3_curator_eye_32_ca.paa", _colour, getPosVisual _x, 0.5, 0.5, 0, _text, 0, 0.01, "TahomaB", "center", true];
        };
    } count allUnits;
};
onEachFrame {
    ACE_controlledUAV params ["", "_player", "", "_seat"];
    if (isNull _player) then {
        _player = call ace_common_fnc_player;
        _seat = "GUNNER"
    };
    if (_seat != "GUNNER") exitWith {};
    {
        private _unit = leader _x;
        if (!(isPlayer _unit)) then {
            private _colour = [1,0,0,1];
            private _pos = worldToScreen (getPos _unit);
            private _onScreen = (count _pos) > 0 && {_pos#0 > uksf_common_bufferedSafeX && _pos#0 < uksf_common_bufferedSafeW && _pos#1 > uksf_common_bufferedSafeY && _pos#1 < uksf_common_bufferedSafeH};
            if (_onScreen) then {
                _colour = [1,1,0,1];
                private _distance = (getObjectViewDistance select 0) min (1000 + ((200 + (4 * 200 * ((currentVisionMode _player) - 1) max 0)) * ((call CBA_fnc_getFov) select 1)));
                private _zoom = ((_unit distance _player) < _distance);
                if (_zoom) then {
                    _colour = [0,0,1,1];
                    private _los = ([_player, "VIEW", (vehicle _player)] checkVisibility [eyePos _player, eyePos _unit]) > 0;
                    if (_los) then {
                        _colour = [0,1,0,1];
                    };
                };
            };
            private _text = ((_unit getVariable ["uksf_caching_time", CBA_missionTime]) - CBA_missionTime) toFixed 0;
            drawIcon3D ["\a3\ui_f_curator\data\logos\arma3_curator_eye_32_ca.paa", _colour, getPos _unit, 0.5, 0.5, 0, _text, 0, 0.025, "TahomaB", "center", true];
        };
    } count allGroups;
};
onEachFrame {
    {
        if (!(isPlayer _x)) then {
            private _colour = [1,0,0,1];
            if (simulationEnabled _x) then {
                _colour = [0,1,0,1];
            };
            drawIcon3D ["\a3\ui_f_curator\data\logos\arma3_curator_eye_32_ca.paa", _colour, getPosVisual _x, 0.5, 0.5, 0, "", 0, 0.025, "TahomaB", "center", true];
        };
    } count allUnits;
};
                if ((abs (_pos select 0)) < (safeZoneW - abs safeZoneX) && (abs (_pos select 1)) < (safeZoneH - abs safeZoneY)) then {
                    _colour = [0,1,0,1];
                };
onEachFrame { 
    { 
        private _unit = leader _x; 
        if (!(isPlayer _unit)) then { 
            private _colour = [1,0,0,1];               
            private _pos = worldToScreen (getPos _unit);
            if (!(_pos isEqualTo [])) then {
                private _text = format ["%1,%2", _pos select 0, _pos select 1];
                if (_pos#0 > uksf_common_bufferedSafeX && _pos#0 < uksf_common_bufferedSafeW && _pos#1 > uksf_common_bufferedSafeY && _pos#1 < uksf_common_bufferedSafeH) then {
                    _colour = [0,1,0,1];
                };
                drawIcon3D ["\a3\ui_f_curator\data\logos\arma3_curator_eye_32_ca.paa", _colour, getPos _unit, 0.5, 0.5, 0, _text, 0, 0.025, "TahomaB", "center", true];
            }; 
        };
    } count allGroups;
    drawLine3D [screenToWorld [safeZoneX, safeZoneY], screenToWorld [safeZoneX + safeZoneW, safeZoneY], [0,0,1,1]];
    drawLine3D [screenToWorld [safeZoneX + safeZoneW, safeZoneY], screenToWorld [safeZoneX + safeZoneW, safeZoneY + safeZoneH], [0,0,1,1]];
    drawLine3D [screenToWorld [safeZoneX + safeZoneW, safeZoneY + safeZoneH], screenToWorld [safeZoneX, safeZoneY + safeZoneH], [0,0,1,1]];
    drawLine3D [screenToWorld [safeZoneX, safeZoneY + safeZoneH], screenToWorld [safeZoneX, safeZoneY], [0,0,1,1]];
};
*/


